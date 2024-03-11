/*
Copyright (c) 2024 Eugene Kirian

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Direct3D7.hxx"
#include "Direct3DDevice.hxx"
#include "Direct3DDevice2.hxx"
#include "Direct3DDevice3.hxx"
#include "Direct3DDevice7.hxx"
#include "Direct3DVertexBuffer7.hxx"
#include "DirectDrawSurface7.hxx"

#include <AgentLogger.hxx>
#include <Direct3DDevice7Logger.hxx>

#define Direct3DDevice7LogMethod(L, M) AgentLogMethod(L, Direct3DDevice7, M)
#define Direct3DDevice7LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DDevice7, M, C, PARAMS)

#define Direct3DDevice7LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DDevice7, AddRef, R)
#define Direct3DDevice7LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DDevice7, Release, R)

#define Direct3DDevice7LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DDevice7, M, R)
#define Direct3DDevice7LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DDevice7, M, R, C, PARAMS)

#define Direct3DDevice7LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3DDevice7, M, C, PARAMS)
#define Direct3DDevice7LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3DDevice7, M, R, C, PARAMS)

typedef struct EnumTextureFormatsCallbackContext
{
    Direct3DDevice7* Self;
    LPLOGGER Logger;
    LPD3DENUMPIXELFORMATSCALLBACK EnumTextureFormatsCallback;
    LPVOID Context;
} ENUMTEXTUREFORMATSCALLBACKCONTEXT, * LPENUMTEXTUREFORMATSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumTextureFormatsCallback(LPDDPIXELFORMAT lpDDPixFmt, LPVOID lpContext)
{
    LPENUMTEXTUREFORMATSCALLBACKCONTEXT context = (LPENUMTEXTUREFORMATSCALLBACKCONTEXT)lpContext;

    Direct3DDevice7LogMethodCallbackValue(TRACEDEBUG, EnumTextureFormats, 2, (context->Self, lpDDPixFmt));

    CONST HRESULT result = context->EnumTextureFormatsCallback(lpDDPixFmt, context->Context);

    Direct3DDevice7LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumTextureFormats, result, 2, (context->Self, lpDDPixFmt));
}

Direct3DDevice7::Direct3DDevice7(AgentConstructorParameters(Direct3DDevice7))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DDevice7);
}

Direct3DDevice7::~Direct3DDevice7()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DDevice7);
}

HRESULT Direct3DDevice7::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DDevice7LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DDevice, riid)) { *ppvObj = ActivateAgent(Direct3DDevice, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice2, riid)) { *ppvObj = ActivateAgent(Direct3DDevice2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice3, riid)) { *ppvObj = ActivateAgent(Direct3DDevice3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice7, riid)) { *ppvObj = ActivateAgent(Direct3DDevice7, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DDevice7::AddRef()
{
    Direct3DDevice7LogMethod(DEBUG, AddRef);
    Direct3DDevice7LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3DDevice7::Release()
{
    Direct3DDevice7LogMethod(DEBUG, Release);
    Direct3DDevice7LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves the capabilities of the Direct3D device.
HRESULT Direct3DDevice7::GetCaps(LPD3DDEVICEDESC7 lpD3DDevDesc)
{
    Direct3DDevice7LogMethodValue(TRACE, GetCaps, 1, (lpD3DDevDesc));

    CONST HRESULT result = this->State.Self->GetCaps(lpD3DDevDesc);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 1, (lpD3DDevDesc));
}

// Queries the current driver for a list of supported texture formats.
HRESULT Direct3DDevice7::EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK lpd3dEnumPixelProc, LPVOID lpContext)
{
    Direct3DDevice7LogMethodValue(DEBUGINFO, EnumTextureFormats, 2, (lpd3dEnumPixelProc, lpContext));

    if (lpd3dEnumPixelProc == NULL) { Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, EnumTextureFormats, DDERR_INVALIDPARAMS, 2, (lpd3dEnumPixelProc, lpContext)); }

    ENUMTEXTUREFORMATSCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumTextureFormatsCallback = lpd3dEnumPixelProc;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumTextureFormats(EnumTextureFormatsCallback, &context);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, EnumTextureFormats, result, 2, (lpd3dEnumPixelProc, lpContext));
}

// Begins a scene.
HRESULT Direct3DDevice7::BeginScene()
{
    Direct3DDevice7LogMethod(DEBUG, BeginScene);

    CONST HRESULT result = this->State.Self->BeginScene();

    Direct3DDevice7LogMethodResult(DEBUGINFO, BeginScene, result);
}

// Ends a scene.
HRESULT Direct3DDevice7::EndScene()
{
    Direct3DDevice7LogMethod(DEBUG, EndScene);

    CONST HRESULT result = this->State.Self->EndScene();

    Direct3DDevice7LogMethodResult(DEBUGINFO, EndScene, result);
}

// Retrieves the Direct3D object for this device.
HRESULT Direct3DDevice7::GetDirect3D(LPDIRECT3D7* lplpD3D)
{
    Direct3DDevice7LogMethodValue(TRACE, GetDirect3D, 1, (lplpD3D));

    CONST HRESULT result = this->State.Self->GetDirect3D(lplpD3D);

    if (SUCCEEDED(result)) { *lplpD3D = ActivateAgentDelegate(Direct3D7, *lplpD3D); }

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetDirect3D, result, 1, (lplpD3D));
}

// Permits the application to easily route rendering output to a new DirectDraw surface as a render target.
HRESULT Direct3DDevice7::SetRenderTarget(LPDIRECTDRAWSURFACE7 lpNewRenderTarget, DWORD dwFlags)
{
    Direct3DDevice7LogMethodValue(TRACE, SetRenderTarget, 2, (lpNewRenderTarget, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface7, lpNewRenderTarget);

    CONST HRESULT result = this->State.Self->SetRenderTarget(lpNewRenderTarget, dwFlags);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetRenderTarget, result, 2, (ActivateAgent(DirectDrawSurface7, lpNewRenderTarget), dwFlags));
}

// Retrieves a pointer to the DirectDraw surface that is being used as a render target.
HRESULT Direct3DDevice7::GetRenderTarget(LPDIRECTDRAWSURFACE7* lplpRenderTarget)
{
    Direct3DDevice7LogMethodValue(TRACE, GetRenderTarget, 1, (lplpRenderTarget));

    CONST HRESULT result = this->State.Self->GetRenderTarget(lplpRenderTarget);

    if (SUCCEEDED(result)) { *lplpRenderTarget = ActivateAgentDelegate(DirectDrawSurface7, *lplpRenderTarget); }

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetRenderTarget, result, 1, (lplpRenderTarget));
}

// Clears the viewport (or a set of rectangles in the viewport) to a specified RGBA color,
// clears the depth buffer, and erases the stencil buffer.
HRESULT Direct3DDevice7::Clear(DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags, D3DCOLOR dwColor, D3DVALUE dvZ, DWORD dwStencil)
{
    Direct3DDevice7LogMethodValue(TRACE, Clear, 6, (dwCount, lpRects, dwFlags, dwColor, dvZ, dwStencil));

    CONST HRESULT result = this->State.Self->Clear(dwCount, lpRects, dwFlags, dwColor, dvZ, dwStencil);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, Clear, result, 6, (dwCount, lpRects, dwFlags, dwColor, dvZ, dwStencil));
}

// Sets a single Direct3DDevice transformation-related state.
HRESULT Direct3DDevice7::SetTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice7LogMethodValue(TRACE, SetTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->SetTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Gets a matrix describing a transformation state.
HRESULT Direct3DDevice7::GetTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice7LogMethodValue(TRACE, GetTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->GetTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Sets the viewport parameters for the device.
HRESULT Direct3DDevice7::SetViewport(LPD3DVIEWPORT7 lpViewport)
{
    Direct3DDevice7LogMethodValue(TRACE, SetViewport, 1, (lpViewport));

    CONST HRESULT result = this->State.Self->SetViewport(lpViewport);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetViewport, result, 1, (lpViewport));
}

// Multiplies a device's world, view, or projection matrices by a specified matrix.
// The multiplication order is lpD3DMatrix times dtstTransformStateType.
HRESULT Direct3DDevice7::MultiplyTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice7LogMethodValue(TRACE, MultiplyTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->MultiplyTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, MultiplyTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Retrieves the viewport parameters currently set for the device.
HRESULT Direct3DDevice7::GetViewport(LPD3DVIEWPORT7 lpViewport)
{
    Direct3DDevice7LogMethodValue(TRACE, GetViewport, 1, (lpViewport));

    CONST HRESULT result = this->State.Self->GetViewport(lpViewport);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetViewport, result, 1, (lpViewport));
}

// Sets the material properties for the device.
HRESULT Direct3DDevice7::SetMaterial(LPD3DMATERIAL7 lpMaterial)
{
    Direct3DDevice7LogMethodValue(TRACE, SetMaterial, 1, (lpMaterial));

    CONST HRESULT result = this->State.Self->SetMaterial(lpMaterial);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetMaterial, result, 1, (lpMaterial));
}

// Retrieves the current material properties for the device.
HRESULT Direct3DDevice7::GetMaterial(LPD3DMATERIAL7 lpMaterial)
{
    Direct3DDevice7LogMethodValue(TRACE, GetMaterial, 1, (lpMaterial));

    CONST HRESULT result = this->State.Self->GetMaterial(lpMaterial);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetMaterial, result, 1, (lpMaterial));
}

// Assigns a set of lighting properties for this device.
HRESULT Direct3DDevice7::SetLight(DWORD dwLightIndex, LPD3DLIGHT7 lpLight)
{
    Direct3DDevice7LogMethodValue(TRACE, SetLight, 2, (dwLightIndex, lpLight));

    CONST HRESULT result = this->State.Self->SetLight(dwLightIndex, lpLight);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetLight, result, 2, (dwLightIndex, lpLight));
}

// Retrieves a set of lighting properties that this device uses.
HRESULT Direct3DDevice7::GetLight(DWORD dwLightIndex, LPD3DLIGHT7 lpLight)
{
    Direct3DDevice7LogMethodValue(TRACE, GetLight, 2, (dwLightIndex, lpLight));

    CONST HRESULT result = this->State.Self->GetLight(dwLightIndex, lpLight);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetLight, result, 2, (dwLightIndex, lpLight));
}

// Sets a single Direct3DDevice render-state parameter.
HRESULT Direct3DDevice7::SetRenderState(D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState)
{
    Direct3DDevice7LogMethodValue(TRACE, SetRenderState, 2, (dwRenderStateType, dwRenderState));

    CONST HRESULT result = this->State.Self->SetRenderState(dwRenderStateType, dwRenderState);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetRenderState, result, 2, (dwRenderStateType, dwRenderState));
}

// Gets a single Direct3DDevice rendering-state parameter.
HRESULT Direct3DDevice7::GetRenderState(D3DRENDERSTATETYPE dwRenderStateType, LPDWORD lpdwRenderState)
{
    Direct3DDevice7LogMethodValue(TRACE, GetRenderState, 2, (dwRenderStateType, lpdwRenderState));

    CONST HRESULT result = this->State.Self->GetRenderState(dwRenderStateType, lpdwRenderState);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetRenderState, result, 2, (dwRenderStateType, lpdwRenderState));
}

// Signals Direct3D to begin recording a device state block.
HRESULT Direct3DDevice7::BeginStateBlock()
{
    Direct3DDevice7LogMethod(DEBUG, BeginStateBlock);

    CONST HRESULT result = this->State.Self->BeginStateBlock();

    Direct3DDevice7LogMethodResult(DEBUGINFO, BeginStateBlock, result);
}

// Signals Direct3D to stop recording a device state block and retrieve a handle to the state block.
HRESULT Direct3DDevice7::EndStateBlock(LPDWORD lpdwBlockHandle)
{
    Direct3DDevice7LogMethodValue(TRACE, EndStateBlock, 1, (lpdwBlockHandle));

    CONST HRESULT result = this->State.Self->EndStateBlock(lpdwBlockHandle);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, EndStateBlock, result, 1, (lpdwBlockHandle));
}

// Instructs the Direct3D texture manager to load a managed texture into video memory.
HRESULT Direct3DDevice7::PreLoad(LPDIRECTDRAWSURFACE7 lpddsTexture)
{
    Direct3DDevice7LogMethodValue(TRACE, PreLoad, 1, (lpddsTexture));

    AttemptAccessAgentValue(DirectDrawSurface7, lpddsTexture);

    CONST HRESULT result = this->State.Self->PreLoad(lpddsTexture);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, PreLoad, result, 1, (ActivateAgent(DirectDrawSurface7, lpddsTexture)));
}

// Renders the specified array of vertices as a sequence of geometric primitives of the specified type.
HRESULT Direct3DDevice7::DrawPrimitive(D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags)
{
    Direct3DDevice7LogMethodValue(TRACE, DrawPrimitive, 5, (dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawPrimitive(dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitive, result, 5, (dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags));
}

// Renders the specified geometric primitive, based on indexing into an array of vertices.
HRESULT Direct3DDevice7::DrawIndexedPrimitive(D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags)
{
    Direct3DDevice7LogMethodValue(TRACE, DrawIndexedPrimitive, 7, (d3dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitive(d3dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitive, result, 7, (d3dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));
}

// Sets the current clip status.
HRESULT Direct3DDevice7::SetClipStatus(LPD3DCLIPSTATUS lpD3DClipStatus)
{
    Direct3DDevice7LogMethodValue(TRACE, SetClipStatus, 1, (lpD3DClipStatus));

    CONST HRESULT result = this->State.Self->SetClipStatus(lpD3DClipStatus);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetClipStatus, result, 1, (lpD3DClipStatus));
}

// Gets the current clip status.
HRESULT Direct3DDevice7::GetClipStatus(LPD3DCLIPSTATUS lpD3DClipStatus)
{
    Direct3DDevice7LogMethodValue(TRACE, GetClipStatus, 1, (lpD3DClipStatus));

    CONST HRESULT result = this->State.Self->GetClipStatus(lpD3DClipStatus);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetClipStatus, result, 1, (lpD3DClipStatus));
}

// Renders the specified array of strided vertices as a sequence of geometric primitives.
// For more information, see Strided Vertex Format.
HRESULT Direct3DDevice7::DrawPrimitiveStrided(D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, DWORD dwFlags)
{
    Direct3DDevice7LogMethodValue(TRACE, DrawPrimitiveStrided, 5, (dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawPrimitiveStrided(dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, dwFlags);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitiveStrided, result, 5, (dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, dwFlags));
}

// Renders a geometric primitive, based on indexing into an array of strided vertices.
// For more information, see Strided Vertex Format.
HRESULT Direct3DDevice7::DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags)
{
    Direct3DDevice7LogMethodValue(TRACE, DrawIndexedPrimitiveStrided, 7, (d3dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitiveStrided(d3dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, lpwIndices, dwIndexCount, dwFlags);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitiveStrided, result, 7, (d3dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));
}

// Renders an array of vertices in a vertex buffer as a sequence of geometric primitives.
HRESULT Direct3DDevice7::DrawPrimitiveVB(D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER7 lpd3dVertexBuffer, DWORD dwStartVertex, DWORD dwNumVertices, DWORD dwFlags)
{
    Direct3DDevice7LogMethodValue(TRACE, DrawPrimitiveVB, 5, (d3dptPrimitiveType, lpd3dVertexBuffer, dwStartVertex, dwNumVertices, dwFlags));

    AttemptAccessAgentValue(Direct3DVertexBuffer7, lpd3dVertexBuffer);

    CONST HRESULT result = this->State.Self->DrawPrimitiveVB(d3dptPrimitiveType, lpd3dVertexBuffer, dwStartVertex, dwNumVertices, dwFlags);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitiveVB, result, 5, (d3dptPrimitiveType, ActivateAgent(Direct3DVertexBuffer7, lpd3dVertexBuffer), dwStartVertex, dwNumVertices, dwFlags));
}

// Renders a geometric primitive based on indexing into an array of vertices within a vertex buffer.
HRESULT Direct3DDevice7::DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER7 lpd3dVertexBuffer, DWORD dwStartVertex, DWORD dwNumVertices, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags)
{
    Direct3DDevice7LogMethodValue(TRACE, DrawIndexedPrimitiveVB, 7, (d3dptPrimitiveType, lpd3dVertexBuffer, dwStartVertex, dwNumVertices, lpwIndices, dwIndexCount, dwFlags));

    AttemptAccessAgentValue(Direct3DVertexBuffer7, lpd3dVertexBuffer);

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitiveVB(d3dptPrimitiveType, lpd3dVertexBuffer, dwStartVertex, dwNumVertices, lpwIndices, dwIndexCount, dwFlags);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitiveVB, result, 7, (d3dptPrimitiveType, ActivateAgent(Direct3DVertexBuffer7, lpd3dVertexBuffer), dwStartVertex, dwNumVertices, lpwIndices, dwIndexCount, dwFlags));
}

// Calculates the visibility (complete, partial, or no visibility) of an array of spheres within the current viewport for this device.
HRESULT Direct3DDevice7::ComputeSphereVisibility(LPD3DVECTOR lpCenters, LPD3DVALUE lpRadii, DWORD dwNumSpheres, DWORD dwFlags, LPDWORD lpdwReturnValues)
{
    Direct3DDevice7LogMethodValue(TRACE, ComputeSphereVisibility, 5, (lpCenters, lpRadii, dwNumSpheres, dwFlags, lpdwReturnValues));

    CONST HRESULT result = this->State.Self->ComputeSphereVisibility(lpCenters, lpRadii, dwNumSpheres, dwFlags, lpdwReturnValues);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, ComputeSphereVisibility, result, 5, (lpCenters, lpRadii, dwNumSpheres, dwFlags, lpdwReturnValues));
}

// Retrieves a texture assigned to a given stage for a device.
HRESULT Direct3DDevice7::GetTexture(DWORD dwStage, LPDIRECTDRAWSURFACE7* lplpTexture)
{
    Direct3DDevice7LogMethodValue(TRACE, GetTexture, 2, (dwStage, lplpTexture));

    CONST HRESULT result = this->State.Self->GetTexture(dwStage, lplpTexture);

    if (SUCCEEDED(result)) { *lplpTexture = ActivateAgentDelegate(DirectDrawSurface7, *lplpTexture); }

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetTexture, result, 2, (dwStage, lplpTexture));
}

// Assigns a texture to a given stage for a device.
HRESULT Direct3DDevice7::SetTexture(DWORD dwStage, LPDIRECTDRAWSURFACE7 lpTexture)
{
    Direct3DDevice7LogMethodValue(TRACE, SetTexture, 2, (dwStage, lpTexture));

    AttemptAccessAgentValue(DirectDrawSurface7, lpTexture);

    CONST HRESULT result = this->State.Self->SetTexture(dwStage, lpTexture);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetTexture, result, 2, (dwStage, ActivateAgent(DirectDrawSurface7, lpTexture)));
}

// Retrieves a state value for a currently assigned texture.
HRESULT Direct3DDevice7::GetTextureStageState(DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, LPDWORD lpdwValue)
{
    Direct3DDevice7LogMethodValue(TRACE, GetTextureStageState, 3, (dwStage, dwState, lpdwValue));

    CONST HRESULT result = this->State.Self->GetTextureStageState(dwStage, dwState, lpdwValue);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetTextureStageState, result, 3, (dwStage, dwState, lpdwValue));
}

// Sets the state value for a currently assigned texture.
HRESULT Direct3DDevice7::SetTextureStageState(DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, DWORD dwValue)
{
    Direct3DDevice7LogMethodValue(TRACE, SetTextureStageState, 3, (dwStage, dwState, dwValue));

    CONST HRESULT result = this->State.Self->SetTextureStageState(dwStage, dwState, dwValue);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetTextureStageState, result, 3, (dwStage, dwState, dwValue));
}

// Reports the device's ability to render the currently set texture-blending operations and arguments in a single pass.
HRESULT Direct3DDevice7::ValidateDevice(LPDWORD lpdwPasses)
{
    Direct3DDevice7LogMethodValue(TRACE, ValidateDevice, 1, (lpdwPasses));

    CONST HRESULT result = this->State.Self->ValidateDevice(lpdwPasses);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, ValidateDevice, result, 1, (lpdwPasses));
}

// Applies an existing device-state block to the rendering device.
HRESULT Direct3DDevice7::ApplyStateBlock(DWORD dwBlockHandle)
{
    Direct3DDevice7LogMethodValue(TRACE, ApplyStateBlock, 1, (dwBlockHandle));

    CONST HRESULT result = this->State.Self->ApplyStateBlock(dwBlockHandle);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, ApplyStateBlock, result, 1, (dwBlockHandle));
}

// Updates the values within an existing state block to the values currently set for the device.
HRESULT Direct3DDevice7::CaptureStateBlock(DWORD dwBlockHandle)
{
    Direct3DDevice7LogMethodValue(TRACE, CaptureStateBlock, 1, (dwBlockHandle));

    CONST HRESULT result = this->State.Self->CaptureStateBlock(dwBlockHandle);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, CaptureStateBlock, result, 1, (dwBlockHandle));
}

// Deletes a previously recorded device state block.
HRESULT Direct3DDevice7::DeleteStateBlock(DWORD dwBlockHandle)
{
    Direct3DDevice7LogMethodValue(TRACE, DeleteStateBlock, 1, (dwBlockHandle));

    CONST HRESULT result = this->State.Self->DeleteStateBlock(dwBlockHandle);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, DeleteStateBlock, result, 1, (dwBlockHandle));
}

// Creates a new state block that contains the current values for all device states, vertex-related states, or pixel-related states.
HRESULT Direct3DDevice7::CreateStateBlock(D3DSTATEBLOCKTYPE d3dsbType, LPDWORD lpdwBlockHandle)
{
    Direct3DDevice7LogMethodValue(TRACE, CreateStateBlock, 2, (d3dsbType, lpdwBlockHandle));

    CONST HRESULT result = this->State.Self->CreateStateBlock(d3dsbType, lpdwBlockHandle);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, CreateStateBlock, result, 2, (d3dsbType, lpdwBlockHandle));
}

// Loads a rectangular area of a source texture to a specified point in a destination texture or to faces within a cubic environment map.
HRESULT Direct3DDevice7::Load(LPDIRECTDRAWSURFACE7 lpDestTex, LPPOINT lpDestPoint, LPDIRECTDRAWSURFACE7 lpSrcTex, LPRECT lprcSrcRect, DWORD dwFlags)
{
    Direct3DDevice7LogMethodValue(TRACE, Load, 5, (lpDestTex, lpDestPoint, lpSrcTex, lprcSrcRect, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDestTex);
    AttemptAccessAgentValue(DirectDrawSurface7, lpSrcTex);

    CONST HRESULT result = this->State.Self->Load(lpDestTex, lpDestPoint, lpSrcTex, lprcSrcRect, dwFlags);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, Load, result, 5, (ActivateAgent(DirectDrawSurface7, lpDestTex), lpDestPoint, ActivateAgent(DirectDrawSurface7, lpSrcTex), lprcSrcRect, dwFlags));
}

// Enables or disables a set of lighting parameters within a device.
HRESULT Direct3DDevice7::LightEnable(DWORD dwLightIndex, BOOL bEnable)
{
    Direct3DDevice7LogMethodValue(TRACE, LightEnable, 2, (dwLightIndex, bEnable));

    CONST HRESULT result = this->State.Self->LightEnable(dwLightIndex, bEnable);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, LightEnable, result, 2, (dwLightIndex, bEnable));
}

// Retrieves the activity status—enabled or disabled—for a set of lighting parameters within a device.
HRESULT Direct3DDevice7::GetLightEnable(DWORD dwLightIndex, LPBOOL pbEnable)
{
    Direct3DDevice7LogMethodValue(TRACE, GetLightEnable, 2, (dwLightIndex, pbEnable));

    CONST HRESULT result = this->State.Self->GetLightEnable(dwLightIndex, pbEnable);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetLightEnable, result, 2, (dwLightIndex, pbEnable));
}

// Sets the coefficients of a user-defined clipping plane for the device.
HRESULT Direct3DDevice7::SetClipPlane(DWORD dwIndex, D3DVALUE* pPlaneEquation)
{
    Direct3DDevice7LogMethodValue(TRACE, SetClipPlane, 2, (dwIndex, pPlaneEquation));

    CONST HRESULT result = this->State.Self->SetClipPlane(dwIndex, pPlaneEquation);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, SetClipPlane, result, 2, (dwIndex, pPlaneEquation));
}

// Retrieves the coefficients of a user-defined clipping plane for the device.
HRESULT Direct3DDevice7::GetClipPlane(DWORD dwIndex, D3DVALUE* pPlaneEquation)
{
    Direct3DDevice7LogMethodValue(TRACE, GetClipPlane, 2, (dwIndex, pPlaneEquation));

    CONST HRESULT result = this->State.Self->GetClipPlane(dwIndex, pPlaneEquation);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetClipPlane, result, 2, (dwIndex, pPlaneEquation));
}

// Retrieves information about the rendering device.
// Information can pertain to Direct3D or the underlying device driver.
HRESULT Direct3DDevice7::GetInfo(DWORD dwDevInfoID, LPVOID pDevInfoStruct, DWORD dwSize)
{
    Direct3DDevice7LogMethodValue(TRACE, GetInfo, 3, (dwDevInfoID, pDevInfoStruct, dwSize));

    CONST HRESULT result = this->State.Self->GetInfo(dwDevInfoID, pDevInfoStruct, dwSize);

    Direct3DDevice7LogMethodResultValue(TRACEDEBUGINFO, GetInfo, result, 3, (dwDevInfoID, pDevInfoStruct, dwSize));
}
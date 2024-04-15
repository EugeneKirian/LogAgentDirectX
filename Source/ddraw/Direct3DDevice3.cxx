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

#include "Direct3D3.hxx"
#include "Direct3DDevice.hxx"
#include "Direct3DDevice2.hxx"
#include "Direct3DDevice3.hxx"
#include "Direct3DDevice7.hxx"
#include "Direct3DTexture2.hxx"
#include "Direct3DViewport3.hxx"
#include "Direct3DVertexBuffer.hxx"
#include "DirectDrawSurface4.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <Direct3DDevice3Logger.hxx>

#define Direct3DDevice3LogMethod(L, M) AgentLogMethod(L, Direct3DDevice3, M)
#define Direct3DDevice3LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DDevice3, M, C, PARAMS)

#define Direct3DDevice3LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DDevice3, AddRef, R)
#define Direct3DDevice3LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DDevice3, Release, R)

#define Direct3DDevice3LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DDevice3, M, R)
#define Direct3DDevice3LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DDevice3, M, R, C, PARAMS)

#define Direct3DDevice3LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3DDevice3, M, C, PARAMS)
#define Direct3DDevice3LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3DDevice3, M, R, C, PARAMS)

typedef struct EnumTextureFormatsCallbackContext
{
    Direct3DDevice3* Self;
    LPLOGGER Logger;
    LPD3DENUMPIXELFORMATSCALLBACK EnumTextureFormatsCallback;
    LPVOID Context;
} ENUMTEXTUREFORMATSCALLBACKCONTEXT, * LPENUMTEXTUREFORMATSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumTextureFormatsCallback(LPDDPIXELFORMAT lpDDPixFmt, LPVOID Context)
{
    LPENUMTEXTUREFORMATSCALLBACKCONTEXT context = (LPENUMTEXTUREFORMATSCALLBACKCONTEXT)Context;

    Direct3DDevice3LogMethodCallbackValue(TRACEDEBUG, EnumTextureFormats, 2, (context->Self, lpDDPixFmt));

    CONST HRESULT result = context->EnumTextureFormatsCallback(lpDDPixFmt, context->Context);

    Direct3DDevice3LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumTextureFormats, result, 2, (context->Self, lpDDPixFmt));
}

Direct3DDevice3::Direct3DDevice3(AgentConstructorParameters(Direct3DDevice3))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DDevice3);
}

Direct3DDevice3::~Direct3DDevice3()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DDevice3);
}

HRESULT Direct3DDevice3::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DDevice3LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DDevice, riid)) { *ppvObj = ActivateAgent(Direct3DDevice, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice2, riid)) { *ppvObj = ActivateAgent(Direct3DDevice2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice3, riid)) { *ppvObj = ActivateAgent(Direct3DDevice3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice7, riid)) { *ppvObj = ActivateAgent(Direct3DDevice7, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DDevice3::AddRef()
{
    Direct3DDevice3LogMethod(TRACE, AddRef);
    Direct3DDevice3LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DDevice3::Release()
{
    Direct3DDevice3LogMethod(TRACE, Release);
    Direct3DDevice3LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves the capabilities of the Direct3D device.
HRESULT Direct3DDevice3::GetCaps(LPD3DDEVICEDESC lpD3DHWDevDesc, LPD3DDEVICEDESC lpD3DHELDevDesc)
{
    Direct3DDevice3LogMethodValue(TRACE, GetCaps, 2, (lpD3DHWDevDesc, lpD3DHELDevDesc));

    CONST HRESULT result = this->State.Self->GetCaps(lpD3DHWDevDesc, lpD3DHELDevDesc);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 2, (lpD3DHWDevDesc, lpD3DHELDevDesc));
}

// This method is not currently implemented.
HRESULT Direct3DDevice3::GetStats(LPD3DSTATS lpD3DStats)
{
    Direct3DDevice3LogMethodValue(TRACE, GetStats, 1, (lpD3DStats));

    CONST HRESULT result = this->State.Self->GetStats(lpD3DStats);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetStats, result, 1, (lpD3DStats));
}

// Adds the specified viewport to the list of viewport objects associated with the device
// and increments the reference count of the viewport.
HRESULT Direct3DDevice3::AddViewport(LPDIRECT3DVIEWPORT3 lpDirect3DViewport)
{
    Direct3DDevice3LogMethodValue(TRACE, AddViewport, 1, (lpDirect3DViewport));

    AttemptAccessAgentValue(Direct3DViewport3, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->AddViewport(lpDirect3DViewport);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, AddViewport, result, 1, (ActivateAgent(Direct3DViewport3, lpDirect3DViewport)));
}

// Removes the specified viewport from the list of viewport objects associated with the device
// and decrements the reference count of the viewport.
HRESULT Direct3DDevice3::DeleteViewport(LPDIRECT3DVIEWPORT3 lpDirect3DViewport)
{
    Direct3DDevice3LogMethodValue(TRACE, DeleteViewport, 1, (lpDirect3DViewport));

    AttemptAccessAgentValue(Direct3DViewport3, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->DeleteViewport(lpDirect3DViewport);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, DeleteViewport, result, 1, (ActivateAgent(Direct3DViewport3, lpDirect3DViewport)));
}

// Enumerates the viewports associated with the device.
HRESULT Direct3DDevice3::NextViewport(LPDIRECT3DVIEWPORT3 lpDirect3DViewport, LPDIRECT3DVIEWPORT3* lplpAnotherViewport, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, NextViewport, 3, (lpDirect3DViewport, lplpAnotherViewport, dwFlags));

    AttemptAccessAgentValue(Direct3DViewport3, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->NextViewport(lpDirect3DViewport, lplpAnotherViewport, dwFlags);

    if (SUCCEEDED(result)) { *lplpAnotherViewport = ActivateAgent(Direct3DViewport3, *lplpAnotherViewport); }

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, NextViewport, result, 3, (ActivateAgent(Direct3DViewport3, lpDirect3DViewport), lplpAnotherViewport, dwFlags));
}

// Queries the current driver for a list of supported texture formats.
HRESULT Direct3DDevice3::EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK lpd3dEnumTextureProc, LPVOID lpContext)
{
    Direct3DDevice3LogMethodValue(TRACEDEBUG, EnumTextureFormats, 2, (lpd3dEnumTextureProc, lpContext));

    if (lpd3dEnumTextureProc == NULL) { Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, EnumTextureFormats, DDERR_INVALIDPARAMS, 2, (lpd3dEnumTextureProc, lpContext)); }

    ENUMTEXTUREFORMATSCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumTextureFormatsCallback = lpd3dEnumTextureProc;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumTextureFormats(EnumTextureFormatsCallback, &context);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, EnumTextureFormats, result, 2, (lpd3dEnumTextureProc, lpContext));
}

// Begins a scene.
HRESULT Direct3DDevice3::BeginScene()
{
    Direct3DDevice3LogMethod(TRACE, BeginScene);

    CONST HRESULT result = this->State.Self->BeginScene();

    Direct3DDevice3LogMethodResult(TRACEDEBUGINFO, BeginScene, result);
}

// Ends a scene.
HRESULT Direct3DDevice3::EndScene()
{
    Direct3DDevice3LogMethod(TRACE, EndScene);

    CONST HRESULT result = this->State.Self->EndScene();

    Direct3DDevice3LogMethodResult(TRACEDEBUGINFO, EndScene, result);
}

// Retrieves the Direct3D object for this device.
HRESULT Direct3DDevice3::GetDirect3D(LPDIRECT3D3* lplpD3D)
{
    Direct3DDevice3LogMethodValue(TRACE, GetDirect3D, 1, (lplpD3D));

    CONST HRESULT result = this->State.Self->GetDirect3D(lplpD3D);

    if (SUCCEEDED(result)) { *lplpD3D = ActivateAgent(Direct3D3, *lplpD3D); }

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetDirect3D, result, 1, (lplpD3D));
}

// Sets the current viewport.
HRESULT Direct3DDevice3::SetCurrentViewport(LPDIRECT3DVIEWPORT3 lpd3dViewport)
{
    Direct3DDevice3LogMethodValue(TRACE, SetCurrentViewport, 1, (lpd3dViewport));

    AttemptAccessAgentValue(Direct3DViewport3, lpd3dViewport);

    CONST HRESULT result = this->State.Self->SetCurrentViewport(lpd3dViewport);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, SetCurrentViewport, result, 1, (ActivateAgent(Direct3DViewport3, lpd3dViewport)));
}

// Retrieves the current viewport.
HRESULT Direct3DDevice3::GetCurrentViewport(LPDIRECT3DVIEWPORT3* lplpd3dViewport)
{
    Direct3DDevice3LogMethodValue(TRACE, GetCurrentViewport, 1, (lplpd3dViewport));

    CONST HRESULT result = this->State.Self->GetCurrentViewport(lplpd3dViewport);

    if (SUCCEEDED(result)) { *lplpd3dViewport = ActivateAgent(Direct3DViewport3, *lplpd3dViewport); }

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetCurrentViewport, result, 1, (lplpd3dViewport));
}

// Permits the application to easily route rendering output to a new DirectDraw surface as a render target.
HRESULT Direct3DDevice3::SetRenderTarget(LPDIRECTDRAWSURFACE4 lpNewRenderTarget, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, SetRenderTarget, 2, (lpNewRenderTarget, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface4, lpNewRenderTarget);

    CONST HRESULT result = this->State.Self->SetRenderTarget(lpNewRenderTarget, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, SetRenderTarget, result, 2, (ActivateAgent(DirectDrawSurface4, lpNewRenderTarget), dwFlags));
}

// Retrieves a pointer to the DirectDraw surface that is being used as a render target.
HRESULT Direct3DDevice3::GetRenderTarget(LPDIRECTDRAWSURFACE4* lplpRenderTarget)
{
    Direct3DDevice3LogMethodValue(TRACE, GetRenderTarget, 1, (lplpRenderTarget));

    CONST HRESULT result = this->State.Self->GetRenderTarget(lplpRenderTarget);

    if (SUCCEEDED(result)) { *lplpRenderTarget = ActivateAgent(DirectDrawSurface4, *lplpRenderTarget); }

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetRenderTarget, result, 1, (lplpRenderTarget));
}

// Indicates the start of a sequence of rendered primitives.
HRESULT Direct3DDevice3::Begin(D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, Begin, 3, (dptPrimitiveType, dwVertexTypeDesc, dwFlags));

    CONST HRESULT result = this->State.Self->Begin(dptPrimitiveType, dwVertexTypeDesc, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, Begin, result, 3, (dptPrimitiveType, dwVertexTypeDesc, dwFlags));
}

// Defines the start of a primitive based on indexing into an array of vertices.
HRESULT Direct3DDevice3::BeginIndexed(D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwNumVertices, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, BeginIndexed, 5, (dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwNumVertices, dwFlags));

    CONST HRESULT result = this->State.Self->BeginIndexed(dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwNumVertices, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, BeginIndexed, result, 5, (dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwNumVertices, dwFlags));
}

// Adds a new Direct3D vertex to the primitive sequence started with a previous call to the IDirect3DDevice3::Begin method.
HRESULT Direct3DDevice3::Vertex(LPVOID lpVertex)
{
    Direct3DDevice3LogMethodValue(TRACE, Vertex, 1, (lpVertex));

    CONST HRESULT result = this->State.Self->Vertex(lpVertex);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, Vertex, result, 1, (lpVertex));
}

// Adds a new index to the primitive sequence started with a previous call to the IDirect3DDevice3::BeginIndexed method.
HRESULT Direct3DDevice3::Index(WORD wVertexIndex)
{
    Direct3DDevice3LogMethodValue(TRACE, Index, 1, (wVertexIndex));

    CONST HRESULT result = this->State.Self->Index(wVertexIndex);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, Index, result, 1, (wVertexIndex));
}

// Signals the completion of a primitive sequence.
HRESULT Direct3DDevice3::End(DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, End, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->End(dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, End, result, 1, (dwFlags));
}

// Gets a single Direct3DDevice rendering state parameter.
HRESULT Direct3DDevice3::GetRenderState(D3DRENDERSTATETYPE dwRenderStateType, LPDWORD lpdwRenderState)
{
    Direct3DDevice3LogMethodValue(TRACE, GetRenderState, 2, (dwRenderStateType, lpdwRenderState));

    CONST HRESULT result = this->State.Self->GetRenderState(dwRenderStateType, lpdwRenderState);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetRenderState, result, 2, (dwRenderStateType, lpdwRenderState));
}

//  Sets a single Direct3DDevice rendering state parameter.
HRESULT Direct3DDevice3::SetRenderState(D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState)
{
    Direct3DDevice3LogMethodValue(TRACE, SetRenderState, 2, (dwRenderStateType, dwRenderState));

    CONST HRESULT result = this->State.Self->SetRenderState(dwRenderStateType, dwRenderState);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, SetRenderState, result, 2, (dwRenderStateType, dwRenderState));
}

// Gets a single Direct3D device lighting-related state value.
HRESULT Direct3DDevice3::GetLightState(D3DLIGHTSTATETYPE dwLightStateType, LPDWORD lpdwLightState)
{
    Direct3DDevice3LogMethodValue(TRACE, GetLightState, 2, (dwLightStateType, lpdwLightState));

    CONST HRESULT result = this->State.Self->GetLightState(dwLightStateType, lpdwLightState);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetLightState, result, 2, (dwLightStateType, lpdwLightState));
}

// Sets a single Direct3DDevice lighting-related state value.
HRESULT Direct3DDevice3::SetLightState(D3DLIGHTSTATETYPE dwLightStateType, DWORD dwLightState)
{
    Direct3DDevice3LogMethodValue(TRACE, SetLightState, 2, (dwLightStateType, dwLightState));

    CONST HRESULT result = this->State.Self->SetLightState(dwLightStateType, dwLightState);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, SetLightState, result, 2, (dwLightStateType, dwLightState));
}

// Sets a single Direct3DDevice transformation-related state.
HRESULT Direct3DDevice3::SetTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice3LogMethodValue(TRACE, SetTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->SetTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, SetTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Gets a matrix describing a transformation state.
HRESULT Direct3DDevice3::GetTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice3LogMethodValue(TRACE, GetTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->GetTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Multiplies a device's world, view, or projection matrices by a specified matrix.
// The multiplication order is lpD3DMatrix times dtstTransformStateType.
HRESULT Direct3DDevice3::MultiplyTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice3LogMethodValue(TRACE, MultiplyTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->MultiplyTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, MultiplyTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Renders the specified array of vertices as a sequence of geometric primitives of the specified type.
HRESULT Direct3DDevice3::DrawPrimitive(D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, DrawPrimitive, 5, (dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawPrimitive(dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitive, result, 5, (dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, dwFlags));
}

// Renders the specified geometric primitive based on indexing into an array of vertices.
HRESULT Direct3DDevice3::DrawIndexedPrimitive(D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, DrawIndexedPrimitive, 7, (d3dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitive(d3dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitive, result, 7, (d3dptPrimitiveType, dwVertexTypeDesc, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));
}

// Sets the current clip status.
HRESULT Direct3DDevice3::SetClipStatus(LPD3DCLIPSTATUS lpD3DClipStatus)
{
    Direct3DDevice3LogMethodValue(TRACE, SetClipStatus, 1, (lpD3DClipStatus));

    CONST HRESULT result = this->State.Self->SetClipStatus(lpD3DClipStatus);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, SetClipStatus, result, 1, (lpD3DClipStatus));
}

// Gets the current clip status.
HRESULT Direct3DDevice3::GetClipStatus(LPD3DCLIPSTATUS lpD3DClipStatus)
{
    Direct3DDevice3LogMethodValue(TRACE, GetClipStatus, 1, (lpD3DClipStatus));

    CONST HRESULT result = this->State.Self->GetClipStatus(lpD3DClipStatus);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetClipStatus, result, 1, (lpD3DClipStatus));
}

// Renders the specified array of strided vertices as a sequence of geometric primitives.
HRESULT Direct3DDevice3::DrawPrimitiveStrided(D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, DrawPrimitiveStrided, 5, (dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawPrimitiveStrided(dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitiveStrided, result, 5, (dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, dwFlags));
}

// Renders a geometric primitive based on indexing into an array of strided vertices.
HRESULT Direct3DDevice3::DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, DrawIndexedPrimitiveStrided, 7, (d3dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitiveStrided(d3dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, lpwIndices, dwIndexCount, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitiveStrided, result, 7, (d3dptPrimitiveType, dwVertexTypeDesc, lpVertexArray, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));
}

// Renders an array of vertices in a vertex buffer as a sequence of geometric primitives.
HRESULT Direct3DDevice3::DrawPrimitiveVB(D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER lpd3dVertexBuffer, DWORD dwStartVertex, DWORD dwNumVertices, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, DrawPrimitiveVB, 5, (d3dptPrimitiveType, lpd3dVertexBuffer, dwStartVertex, dwNumVertices, dwFlags));

    AttemptAccessAgentValue(Direct3DVertexBuffer, lpd3dVertexBuffer);

    CONST HRESULT result = this->State.Self->DrawPrimitiveVB(d3dptPrimitiveType, lpd3dVertexBuffer, dwStartVertex, dwNumVertices, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitiveVB, result, 5, (d3dptPrimitiveType, ActivateAgent(Direct3DVertexBuffer, lpd3dVertexBuffer), dwStartVertex, dwNumVertices, dwFlags));
}

// Renders a geometric primitive based on indexing into an array of vertices within a vertex buffer.
HRESULT Direct3DDevice3::DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER lpd3dVertexBuffer, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags)
{
    Direct3DDevice3LogMethodValue(TRACE, DrawIndexedPrimitiveVB, 5, (d3dptPrimitiveType, lpd3dVertexBuffer, lpwIndices, dwIndexCount, dwFlags));

    AttemptAccessAgentValue(Direct3DVertexBuffer, lpd3dVertexBuffer);

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitiveVB(d3dptPrimitiveType, lpd3dVertexBuffer, lpwIndices, dwIndexCount, dwFlags);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitiveVB, result, 5, (d3dptPrimitiveType, ActivateAgent(Direct3DVertexBuffer, lpd3dVertexBuffer), lpwIndices, dwIndexCount, dwFlags));
}

// Calculates the visibility (complete, partial, or no visibility) of an array spheres within the current viewport for this device.
HRESULT Direct3DDevice3::ComputeSphereVisibility(LPD3DVECTOR lpCenters, LPD3DVALUE lpRadii, DWORD dwNumSpheres, DWORD dwFlags, LPDWORD lpdwReturnValues)
{
    Direct3DDevice3LogMethodValue(TRACE, ComputeSphereVisibility, 5, (lpCenters, lpRadii, dwNumSpheres, dwFlags, lpdwReturnValues));

    CONST HRESULT result = this->State.Self->ComputeSphereVisibility(lpCenters, lpRadii, dwNumSpheres, dwFlags, lpdwReturnValues);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, ComputeSphereVisibility, result, 5, (lpCenters, lpRadii, dwNumSpheres, dwFlags, lpdwReturnValues));
}

// Retrieves a texture assigned to a given stage for a device.
HRESULT Direct3DDevice3::GetTexture(DWORD dwStage, LPDIRECT3DTEXTURE2* lplpTexture)
{
    Direct3DDevice3LogMethodValue(TRACE, GetTexture, 2, (dwStage, lplpTexture));

    CONST HRESULT result = this->State.Self->GetTexture(dwStage, lplpTexture);

    if (SUCCEEDED(result)) { *lplpTexture = ActivateAgent(Direct3DTexture2, *lplpTexture); }

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetTexture, result, 2, (dwStage, lplpTexture));
}

// Assigns a texture to a given stage for a device.
HRESULT Direct3DDevice3::SetTexture(DWORD dwStage, LPDIRECT3DTEXTURE2 lpTexture)
{
    Direct3DDevice3LogMethodValue(TRACE, SetTexture, 2, (dwStage, lpTexture));

    AttemptAccessAgentValue(Direct3DTexture2, lpTexture);

    CONST HRESULT result = this->State.Self->SetTexture(dwStage, lpTexture);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, SetTexture, result, 2, (dwStage, ActivateAgent(Direct3DTexture2, lpTexture)));
}

// Retrieves a state value for a currently assigned texture.
HRESULT Direct3DDevice3::GetTextureStageState(DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, LPDWORD lpdwValue)
{
    Direct3DDevice3LogMethodValue(TRACE, GetTextureStageState, 3, (dwStage, dwState, lpdwValue));

    CONST HRESULT result = this->State.Self->GetTextureStageState(dwStage, dwState, lpdwValue);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, GetTextureStageState, result, 3, (dwStage, dwState, lpdwValue));
}

// Sets the state value for a currently assigned texture.
HRESULT Direct3DDevice3::SetTextureStageState(DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, DWORD dwValue)
{
    Direct3DDevice3LogMethodValue(TRACE, SetTextureStageState, 3, (dwStage, dwState, dwValue));

    CONST HRESULT result = this->State.Self->SetTextureStageState(dwStage, dwState, dwValue);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, SetTextureStageState, result, 3, (dwStage, dwState, dwValue));
}

// Reports the device's ability to render the currently set texture blending operations and arguments in a single pass.
HRESULT Direct3DDevice3::ValidateDevice(LPDWORD lpdwPasses)
{
    Direct3DDevice3LogMethodValue(TRACE, ValidateDevice, 1, (lpdwPasses));

    CONST HRESULT result = this->State.Self->ValidateDevice(lpdwPasses);

    Direct3DDevice3LogMethodResultValue(TRACEDEBUGINFO, ValidateDevice, result, 1, (lpdwPasses));
}
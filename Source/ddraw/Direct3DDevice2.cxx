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

#include "Direct3D2.hxx"
#include "Direct3DDevice.hxx"
#include "Direct3DDevice2.hxx"
#include "Direct3DDevice3.hxx"
#include "Direct3DDevice7.hxx"
#include "Direct3DTexture2.hxx"
#include "Direct3DViewport2.hxx"
#include "DirectDrawSurface.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <Direct3DDevice2Logger.hxx>

#define Direct3DDevice2LogMethod(L, M) AgentLogMethod(L, Direct3DDevice2, M)
#define Direct3DDevice2LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DDevice2, M, C, PARAMS)

#define Direct3DDevice2LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DDevice2, AddRef, R)
#define Direct3DDevice2LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DDevice2, Release, R)

#define Direct3DDevice2LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DDevice2, M, R)
#define Direct3DDevice2LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DDevice2, M, R, C, PARAMS)

#define Direct3DDevice2LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3DDevice2, M, C, PARAMS)
#define Direct3DDevice2LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3DDevice2, M, R, C, PARAMS)

typedef struct EnumTextureFormatsCallbackContext
{
    Direct3DDevice2* Self;
    LPLOGGER Logger;
    LPD3DENUMTEXTUREFORMATSCALLBACK EnumTextureFormatsCallback;
    LPVOID Context;
} ENUMTEXTUREFORMATSCALLBACKCONTEXT, * LPENUMTEXTUREFORMATSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumTextureFormatsCallback(LPDDSURFACEDESC lpDdsd, LPVOID lpContext)
{
    LPENUMTEXTUREFORMATSCALLBACKCONTEXT context = (LPENUMTEXTUREFORMATSCALLBACKCONTEXT)lpContext;

    Direct3DDevice2LogMethodCallbackValue(TRACEDEBUG, EnumTextureFormats, 2, (context->Self, lpDdsd));

    CONST HRESULT result = context->EnumTextureFormatsCallback(lpDdsd, context->Context);

    Direct3DDevice2LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumTextureFormats, result, 2, (context->Self, lpDdsd));
}

Direct3DDevice2::Direct3DDevice2(AgentConstructorParameters(Direct3DDevice2))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DDevice2);
}

Direct3DDevice2::~Direct3DDevice2()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DDevice2);
}

HRESULT Direct3DDevice2::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DDevice2LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

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

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DDevice2::AddRef()
{
    Direct3DDevice2LogMethod(TRACE, AddRef);
    Direct3DDevice2LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DDevice2::Release()
{
    Direct3DDevice2LogMethod(TRACE, Release);
    Direct3DDevice2LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves the capabilities of the Direct3D device.
HRESULT Direct3DDevice2::GetCaps(LPD3DDEVICEDESC lpD3DHWDevDesc, LPD3DDEVICEDESC lpD3DHELDevDesc)
{
    Direct3DDevice2LogMethodValue(TRACE, GetCaps, 2, (lpD3DHWDevDesc, lpD3DHELDevDesc));

    CONST HRESULT result = this->State.Self->GetCaps(lpD3DHWDevDesc, lpD3DHELDevDesc);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 2, (lpD3DHWDevDesc, lpD3DHELDevDesc));
}

// Swaps two texture handles.
HRESULT Direct3DDevice2::SwapTextureHandles(LPDIRECT3DTEXTURE2 lpD3DTex1, LPDIRECT3DTEXTURE2 lpD3DTex2)
{
    Direct3DDevice2LogMethodValue(TRACE, SwapTextureHandles, 2, (lpD3DTex1, lpD3DTex2));

    AttemptAccessAgentValue(Direct3DTexture2, lpD3DTex1);
    AttemptAccessAgentValue(Direct3DTexture2, lpD3DTex2);

    CONST HRESULT result = this->State.Self->SwapTextureHandles(lpD3DTex1, lpD3DTex2);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, SwapTextureHandles, result, 2, (ActivateAgent(Direct3DTexture2, lpD3DTex1), ActivateAgent(Direct3DTexture2, lpD3DTex2)));
}

// Retrieves statistics about a device.
HRESULT Direct3DDevice2::GetStats(LPD3DSTATS lpD3DStats)
{
    Direct3DDevice2LogMethodValue(TRACE, GetStats, 1, (lpD3DStats));

    CONST HRESULT result = this->State.Self->GetStats(lpD3DStats);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetStats, result, 1, (lpD3DStats));
}

// Adds the specified viewport to the list of viewport objects associated with the device
// and increments the reference count of the viewport.
HRESULT Direct3DDevice2::AddViewport(LPDIRECT3DVIEWPORT2 lpDirect3DViewport)
{
    Direct3DDevice2LogMethodValue(TRACE, AddViewport, 1, (lpDirect3DViewport));

    AttemptAccessAgentValue(Direct3DViewport2, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->AddViewport(lpDirect3DViewport);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, AddViewport, result, 1, (ActivateAgent(Direct3DViewport2, lpDirect3DViewport)));
}

// Removes the specified viewport from the list of viewport objects associated with the device
// and decrements the reference count of the viewport.
HRESULT Direct3DDevice2::DeleteViewport(LPDIRECT3DVIEWPORT2 lpDirect3DViewport)
{
    Direct3DDevice2LogMethodValue(TRACE, DeleteViewport, 1, (lpDirect3DViewport));

    AttemptAccessAgentValue(Direct3DViewport2, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->DeleteViewport(lpDirect3DViewport);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, DeleteViewport, result, 1, (ActivateAgent(Direct3DViewport2, lpDirect3DViewport)));
}

// Enumerates the viewports associated with the device.
HRESULT Direct3DDevice2::NextViewport(LPDIRECT3DVIEWPORT2 lpDirect3DViewport, LPDIRECT3DVIEWPORT2* lplpAnotherViewport, DWORD dwFlags)
{
    Direct3DDevice2LogMethodValue(TRACE, NextViewport, 3, (lpDirect3DViewport, lplpAnotherViewport, dwFlags));
    
    AttemptAccessAgentValue(Direct3DViewport2, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->NextViewport(lpDirect3DViewport, lplpAnotherViewport, dwFlags);

    if (SUCCEEDED(result)) { *lplpAnotherViewport = ActivateAgent(Direct3DViewport2, *lplpAnotherViewport); }

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, NextViewport, result, 3, (ActivateAgent(Direct3DViewport2, lpDirect3DViewport), lplpAnotherViewport, dwFlags));
}

// Queries the current driver for a list of supported texture formats.
HRESULT Direct3DDevice2::EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK lpd3dEnumTextureProc, LPVOID lpContext)
{
    Direct3DDevice2LogMethodValue(TRACEDEBUG, EnumTextureFormats, 2, (lpd3dEnumTextureProc, lpContext));

    if (lpd3dEnumTextureProc == NULL) { Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, EnumTextureFormats, DDERR_INVALIDPARAMS, 2, (lpd3dEnumTextureProc, lpContext)); }

    ENUMTEXTUREFORMATSCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumTextureFormatsCallback = lpd3dEnumTextureProc;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumTextureFormats(EnumTextureFormatsCallback, &context);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, EnumTextureFormats, result, 2, (lpd3dEnumTextureProc, lpContext));
}

// Begins a scene.
HRESULT Direct3DDevice2::BeginScene()
{
    Direct3DDevice2LogMethod(TRACE, BeginScene);

    CONST HRESULT result = this->State.Self->BeginScene();

    Direct3DDevice2LogMethodResult(TRACEDEBUGINFO, BeginScene, result);
}

// Ends a scene.
HRESULT Direct3DDevice2::EndScene()
{
    Direct3DDevice2LogMethod(TRACE, EndScene);

    CONST HRESULT result = this->State.Self->EndScene();

    Direct3DDevice2LogMethodResult(TRACEDEBUGINFO, EndScene, result);
}

// Retrieves the Direct3D object for this device.
HRESULT Direct3DDevice2::GetDirect3D(LPDIRECT3D2* lplpD3D)
{
    Direct3DDevice2LogMethodValue(TRACE, GetDirect3D, 1, (lplpD3D));

    CONST HRESULT result = this->State.Self->GetDirect3D(lplpD3D);

    if (SUCCEEDED(result)) { *lplpD3D = ActivateAgent(Direct3D2, *lplpD3D); }

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetDirect3D, result, 1, (lplpD3D));
}

// Sets the current viewport.
HRESULT Direct3DDevice2::SetCurrentViewport(LPDIRECT3DVIEWPORT2 lpd3dViewport)
{
    Direct3DDevice2LogMethodValue(TRACE, SetCurrentViewport, 1, (lpd3dViewport));

    AttemptAccessAgentValue(Direct3DViewport2, lpd3dViewport);

    CONST HRESULT result = this->State.Self->SetCurrentViewport(lpd3dViewport);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, SetCurrentViewport, result, 1, (ActivateAgent(Direct3DViewport2, lpd3dViewport)));
}

// Retrieves the current viewport.
HRESULT Direct3DDevice2::GetCurrentViewport(LPDIRECT3DVIEWPORT2* lplpd3dViewport)
{
    Direct3DDevice2LogMethodValue(TRACE, GetCurrentViewport, 1, (lplpd3dViewport));

    CONST HRESULT result = this->State.Self->GetCurrentViewport(lplpd3dViewport);

    if (SUCCEEDED(result)) { *lplpd3dViewport = ActivateAgent(Direct3DViewport2, *lplpd3dViewport); }

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetCurrentViewport, result, 1, (lplpd3dViewport));
}

// Permits the application to easily route rendering output to a new DirectDraw surface as a render target.
HRESULT Direct3DDevice2::SetRenderTarget(LPDIRECTDRAWSURFACE lpNewRenderTarget, DWORD dwFlags)
{
    Direct3DDevice2LogMethodValue(TRACE, SetRenderTarget, 2, (lpNewRenderTarget, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface, lpNewRenderTarget);

    CONST HRESULT result = this->State.Self->SetRenderTarget(lpNewRenderTarget, dwFlags);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, SetRenderTarget, result, 2, (ActivateAgent(DirectDrawSurface, lpNewRenderTarget), dwFlags));
}

// Retrieves a pointer to the DirectDraw surface that is being used as a render target.
HRESULT Direct3DDevice2::GetRenderTarget(LPDIRECTDRAWSURFACE* lplpRenderTarget)
{
    Direct3DDevice2LogMethodValue(TRACE, GetRenderTarget, 1, (lplpRenderTarget));

    CONST HRESULT result = this->State.Self->GetRenderTarget(lplpRenderTarget);

    if (SUCCEEDED(result)) { *lplpRenderTarget = ActivateAgent(DirectDrawSurface, *lplpRenderTarget); }

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetRenderTarget, result, 1, (lplpRenderTarget));
}

// Indicates the start of a sequence of rendered primitives.
HRESULT Direct3DDevice2::Begin(D3DPRIMITIVETYPE dptPrimitiveType, D3DVERTEXTYPE dptVertexType, DWORD dwFlags)
{
    Direct3DDevice2LogMethodValue(TRACE, Begin, 3, (dptPrimitiveType, dptVertexType, dwFlags));

    CONST HRESULT result = this->State.Self->Begin(dptPrimitiveType, dptVertexType, dwFlags);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, Begin, result, 3, (dptPrimitiveType, dptVertexType, dwFlags));
}

// Defines the start of a primitive based on indexing into an array of vertices.
HRESULT Direct3DDevice2::BeginIndexed(D3DPRIMITIVETYPE dptPrimitiveType, D3DVERTEXTYPE dptVertexType, LPVOID lpvVertices, DWORD dwNumVertices, DWORD dwFlags)
{
    Direct3DDevice2LogMethodValue(TRACE, BeginIndexed, 5, (dptPrimitiveType, dptVertexType, lpvVertices, dwNumVertices, dwFlags));

    CONST HRESULT result = this->State.Self->BeginIndexed(dptPrimitiveType, dptVertexType, lpvVertices, dwNumVertices, dwFlags);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, BeginIndexed, result, 5, (dptPrimitiveType, dptVertexType, lpvVertices, dwNumVertices, dwFlags));
}

// Adds a new Direct3D vertex to the primitive sequence started with a previous call to the IDirect3DDevice2::Begin method.
HRESULT Direct3DDevice2::Vertex(LPVOID lpVertex)
{
    Direct3DDevice2LogMethodValue(TRACE, Vertex, 1, (lpVertex));

    CONST HRESULT result = this->State.Self->Vertex(lpVertex);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, Vertex, result, 1, (lpVertex));
}

// Adds a new index to the primitive sequence started with a previous call to the IDirect3DDevice3::BeginIndexed method.
HRESULT Direct3DDevice2::Index(WORD wVertexIndex)
{
    Direct3DDevice2LogMethodValue(TRACE, Index, 1, (wVertexIndex));

    CONST HRESULT result = this->State.Self->Index(wVertexIndex);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, Index, result, 1, (wVertexIndex));
}

// Signals the completion of a primitive sequence.
HRESULT Direct3DDevice2::End(DWORD dwFlags)
{
    Direct3DDevice2LogMethodValue(TRACE, End, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->End(dwFlags);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, End, result, 1, (dwFlags));
}

// Gets a single Direct3DDevice rendering state parameter.
HRESULT Direct3DDevice2::GetRenderState(D3DRENDERSTATETYPE dwRenderStateType, LPDWORD lpdwRenderState)
{
    Direct3DDevice2LogMethodValue(TRACE, GetRenderState, 2, (dwRenderStateType, lpdwRenderState));

    CONST HRESULT result = this->State.Self->GetRenderState(dwRenderStateType, lpdwRenderState);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetRenderState, result, 2, (dwRenderStateType, lpdwRenderState));
}

//  Sets a single Direct3DDevice rendering state parameter.
HRESULT Direct3DDevice2::SetRenderState(D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState)
{
    Direct3DDevice2LogMethodValue(TRACE, SetRenderState, 2, (dwRenderStateType, dwRenderState));

    CONST HRESULT result = this->State.Self->SetRenderState(dwRenderStateType, dwRenderState);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, SetRenderState, result, 2, (dwRenderStateType, dwRenderState));
}

// Gets a single Direct3D device lighting-related state value.
HRESULT Direct3DDevice2::GetLightState(D3DLIGHTSTATETYPE dwLightStateType, LPDWORD lpdwLightState)
{
    Direct3DDevice2LogMethodValue(TRACE, GetLightState, 2, (dwLightStateType, lpdwLightState));

    CONST HRESULT result = this->State.Self->GetLightState(dwLightStateType, lpdwLightState);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetLightState, result, 2, (dwLightStateType, lpdwLightState));
}

// Sets a single Direct3DDevice lighting-related state value.
HRESULT Direct3DDevice2::SetLightState(D3DLIGHTSTATETYPE dwLightStateType, DWORD dwLightState)
{
    Direct3DDevice2LogMethodValue(TRACE, SetLightState, 2, (dwLightStateType, dwLightState));

    CONST HRESULT result = this->State.Self->SetLightState(dwLightStateType, dwLightState);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, SetLightState, result, 2, (dwLightStateType, dwLightState));
}

// Sets a single Direct3DDevice transformation-related state.
HRESULT Direct3DDevice2::SetTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice2LogMethodValue(TRACE, SetTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->SetTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, SetTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Gets a matrix describing a transformation state.
HRESULT Direct3DDevice2::GetTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice2LogMethodValue(TRACE, GetTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->GetTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Multiplies a device's world, view, or projection matrices by a specified matrix.
// The multiplication order is lpD3DMatrix times dtstTransformStateType.
HRESULT Direct3DDevice2::MultiplyTransform(D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDevice2LogMethodValue(TRACE, MultiplyTransform, 2, (dtstTransformStateType, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->MultiplyTransform(dtstTransformStateType, lpD3DMatrix);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, MultiplyTransform, result, 2, (dtstTransformStateType, lpD3DMatrix));
}

// Renders the specified array of vertices as a sequence of geometric primitives of the specified type.
HRESULT Direct3DDevice2::DrawPrimitive(D3DPRIMITIVETYPE dptPrimitiveType, D3DVERTEXTYPE dptVertexType, LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags)
{
    Direct3DDevice2LogMethodValue(TRACE, DrawPrimitive, 5, (dptPrimitiveType, dptVertexType, lpvVertices, dwVertexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawPrimitive(dptPrimitiveType, dptVertexType, lpvVertices, dwVertexCount, dwFlags);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitive, result, 5, (dptPrimitiveType, dptVertexType, lpvVertices, dwVertexCount, dwFlags));
}

// Renders the specified geometric primitive based on indexing into an array of vertices.
HRESULT Direct3DDevice2::DrawIndexedPrimitive(D3DPRIMITIVETYPE d3dptPrimitiveType, D3DVERTEXTYPE dptVertexType, LPVOID lpvVertices, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags)
{
    Direct3DDevice2LogMethodValue(TRACE, DrawIndexedPrimitive, 7, (d3dptPrimitiveType, dptVertexType, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitive(d3dptPrimitiveType, dptVertexType, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitive, result, 7, (d3dptPrimitiveType, dptVertexType, lpvVertices, dwVertexCount, lpwIndices, dwIndexCount, dwFlags));
}

// Sets the current clip status.
HRESULT Direct3DDevice2::SetClipStatus(LPD3DCLIPSTATUS lpD3DClipStatus)
{
    Direct3DDevice2LogMethodValue(TRACE, SetClipStatus, 1, (lpD3DClipStatus));

    CONST HRESULT result = this->State.Self->SetClipStatus(lpD3DClipStatus);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, SetClipStatus, result, 1, (lpD3DClipStatus));
}

// Gets the current clip status.
HRESULT Direct3DDevice2::GetClipStatus(LPD3DCLIPSTATUS lpD3DClipStatus)
{
    Direct3DDevice2LogMethodValue(TRACE, GetClipStatus, 1, (lpD3DClipStatus));

    CONST HRESULT result = this->State.Self->GetClipStatus(lpD3DClipStatus);

    Direct3DDevice2LogMethodResultValue(TRACEDEBUGINFO, GetClipStatus, result, 1, (lpD3DClipStatus));
}
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

#include "Direct3D.hxx"
#include "Direct3DDevice.hxx"
#include "Direct3DDevice2.hxx"
#include "Direct3DDevice3.hxx"
#include "Direct3DDevice7.hxx"
#include "Direct3DExecuteBuffer.hxx"
#include "Direct3DTexture.hxx"
#include "Direct3DTexture.hxx"
#include "Direct3DTexture2.hxx"
#include "Direct3DViewport.hxx"
#include "DirectDrawColorControl.hxx"
#include "DirectDrawGammaControl.hxx"
#include "DirectDrawSurface.hxx"
#include "DirectDrawSurface2.hxx"
#include "DirectDrawSurface3.hxx"
#include "DirectDrawSurface4.hxx"

#include <AgentLogger.hxx>
#include <Direct3DDeviceLogger.hxx>

#define Direct3DDeviceLogMethod(L, M) AgentLogMethod(L, Direct3DDevice, M)
#define Direct3DDeviceLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DDevice, M, C, PARAMS)

#define Direct3DDeviceLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DDevice, AddRef, R)
#define Direct3DDeviceLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DDevice, Release, R)

#define Direct3DDeviceLogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DDevice, M, R)
#define Direct3DDeviceLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DDevice, M, R, C, PARAMS)

#define Direct3DDeviceLogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3DDevice, M, C, PARAMS)
#define Direct3DDeviceLogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3DDevice, M, R, C, PARAMS)

typedef struct EnumTextureFormatsCallbackContext
{
    Direct3DDevice* Self;
    LPLOGGER Logger;
    LPD3DENUMTEXTUREFORMATSCALLBACK EnumTextureFormatsCallback;
    LPVOID Context;
} ENUMTEXTUREFORMATSCALLBACKCONTEXT, * LPENUMTEXTUREFORMATSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumTextureFormatsCallback(LPDDSURFACEDESC lpDdsd, LPVOID lpContext)
{
    LPENUMTEXTUREFORMATSCALLBACKCONTEXT context = (LPENUMTEXTUREFORMATSCALLBACKCONTEXT)lpContext;

    Direct3DDeviceLogMethodCallbackValue(TRACEDEBUG, EnumTextureFormats, 2, (context->Self, lpDdsd));

    CONST HRESULT result = context->EnumTextureFormatsCallback(lpDdsd, context->Context);

    Direct3DDeviceLogMethodCallbackResultValue(TRACEDEBUGINFO, EnumTextureFormats, result, 2, (context->Self, lpDdsd));
}

Direct3DDevice::Direct3DDevice(AgentConstructorParameters(Direct3DDevice))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DDevice);
}

Direct3DDevice::~Direct3DDevice()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DDevice);
}

HRESULT Direct3DDevice::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DDeviceLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DDevice, riid)) { *ppvObj = ActivateAgent(Direct3DDevice, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice2, riid)) { *ppvObj = ActivateAgent(Direct3DDevice2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice3, riid)) { *ppvObj = ActivateAgent(Direct3DDevice3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice7, riid)) { *ppvObj = ActivateAgent(Direct3DDevice7, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture, riid)) { *ppvObj = ActivateAgent(Direct3DTexture, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture2, riid)) { *ppvObj = ActivateAgent(Direct3DTexture2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawColorControl, riid)) { *ppvObj = ActivateAgent(DirectDrawColorControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawGammaControl, riid)) { *ppvObj = ActivateAgent(DirectDrawGammaControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface2, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface3, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface3, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface4, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface7, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface4, *ppvObj); }
            else { *ppvObj = ActivateAgent(Direct3DDevice, *ppvObj); } // NOTE: Surface Caps must have DDSCAPS_3DDEVICE flag set.
        }
    }

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DDevice::AddRef()
{
    Direct3DDeviceLogMethod(DEBUG, AddRef);
    Direct3DDeviceLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3DDevice::Release()
{
    Direct3DDeviceLogMethod(DEBUG, Release);
    Direct3DDeviceLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT Direct3DDevice::Initialize(LPDIRECT3D lpd3d, LPGUID lpGUID, LPD3DDEVICEDESC lpd3ddvdesc)
{
    Direct3DDeviceLogMethodValue(TRACE, Initialize, 3, (lpd3d, lpGUID, lpd3ddvdesc));

    AttemptAccessAgentValue(Direct3D, lpd3d);

    CONST HRESULT result = this->State.Self->Initialize(lpd3d, lpGUID, lpd3ddvdesc);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 3, (ActivateAgent(Direct3D, lpd3d), lpGUID, lpd3ddvdesc));
}

// Retrieves the capabilities of the Direct3D device.
HRESULT Direct3DDevice::GetCaps(LPD3DDEVICEDESC lpD3DHWDevDesc, LPD3DDEVICEDESC lpD3DHELDevDesc)
{
    Direct3DDeviceLogMethodValue(TRACE, GetCaps, 2, (lpD3DHWDevDesc, lpD3DHELDevDesc));

    CONST HRESULT result = this->State.Self->GetCaps(lpD3DHWDevDesc, lpD3DHELDevDesc);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 2, (lpD3DHWDevDesc, lpD3DHELDevDesc));
}

// Swaps two texture handles.
HRESULT Direct3DDevice::SwapTextureHandles(LPDIRECT3DTEXTURE lpD3DTex1, LPDIRECT3DTEXTURE lpD3DTex2)
{
    Direct3DDeviceLogMethodValue(TRACE, SwapTextureHandles, 2, (lpD3DTex1, lpD3DTex2));

    AttemptAccessAgentValue(Direct3DTexture, lpD3DTex1);
    AttemptAccessAgentValue(Direct3DTexture, lpD3DTex2);

    CONST HRESULT result = this->State.Self->SwapTextureHandles(lpD3DTex1, lpD3DTex2);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, SwapTextureHandles, result, 2, (ActivateAgent(Direct3DTexture, lpD3DTex1), ActivateAgent(Direct3DTexture, lpD3DTex2)));
}

// Allocates an execute buffer for a display list.
HRESULT Direct3DDevice::CreateExecuteBuffer(LPD3DEXECUTEBUFFERDESC lpDesc, LPDIRECT3DEXECUTEBUFFER* lplpDirect3DExecuteBuffer, LPUNKNOWN pUnkOuter)
{
    Direct3DDeviceLogMethodValue(TRACE, CreateExecuteBuffer, 3, (lpDesc, lplpDirect3DExecuteBuffer, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateExecuteBuffer(lpDesc, lplpDirect3DExecuteBuffer, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDirect3DExecuteBuffer = ActivateAgentDelegate(Direct3DExecuteBuffer, *lplpDirect3DExecuteBuffer); }

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, CreateExecuteBuffer, result, 3, (lpDesc, lplpDirect3DExecuteBuffer, pUnkOuter));
}

// Retrieves statistics about a device.
HRESULT Direct3DDevice::GetStats(LPD3DSTATS lpD3DStats)
{
    Direct3DDeviceLogMethodValue(TRACE, GetStats, 1, (lpD3DStats));

    CONST HRESULT result = this->State.Self->GetStats(lpD3DStats);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, GetStats, result, 1, (lpD3DStats));
}

// Executes a buffer.
HRESULT Direct3DDevice::Execute(LPDIRECT3DEXECUTEBUFFER lpDirect3DExecuteBuffer, LPDIRECT3DVIEWPORT lpDirect3DViewport, DWORD dwFlags)
{
    Direct3DDeviceLogMethodValue(TRACE, Execute, 3, (lpDirect3DExecuteBuffer, lpDirect3DViewport, dwFlags));

    AttemptAccessAgentValue(Direct3DExecuteBuffer, lpDirect3DExecuteBuffer);
    AttemptAccessAgentValue(Direct3DViewport, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->Execute(lpDirect3DExecuteBuffer, lpDirect3DViewport, dwFlags);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, Execute, result, 3, (ActivateAgent(Direct3DExecuteBuffer, lpDirect3DExecuteBuffer), ActivateAgent(Direct3DViewport, lpDirect3DViewport), dwFlags));
}

// Adds the specified viewport to the list of viewport objects associated with the device
// and increments the reference count of the viewport.
HRESULT Direct3DDevice::AddViewport(LPDIRECT3DVIEWPORT lpDirect3DViewport)
{
    Direct3DDeviceLogMethodValue(TRACE, AddViewport, 1, (lpDirect3DViewport));

    AttemptAccessAgentValue(Direct3DViewport, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->AddViewport(lpDirect3DViewport);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, AddViewport, result, 1, (ActivateAgent(Direct3DViewport, lpDirect3DViewport)));
}

// removes the specified viewport from the list of viewport objects associated with the device
// and decrements the reference count of the viewport.
HRESULT Direct3DDevice::DeleteViewport(LPDIRECT3DVIEWPORT lpDirect3DViewport)
{
    Direct3DDeviceLogMethodValue(TRACE, DeleteViewport, 1, (lpDirect3DViewport));

    AttemptAccessAgentValue(Direct3DViewport, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->DeleteViewport(lpDirect3DViewport);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, DeleteViewport, result, 1, (ActivateAgent(Direct3DViewport, lpDirect3DViewport)));
}

// Enumerates the viewports associated with the device.
HRESULT Direct3DDevice::NextViewport(LPDIRECT3DVIEWPORT lpDirect3DViewport, LPDIRECT3DVIEWPORT* lplpAnotherViewport, DWORD dwFlags)
{
    Direct3DDeviceLogMethodValue(TRACE, NextViewport, 3, (lpDirect3DViewport, lplpAnotherViewport, dwFlags));

    AttemptAccessAgentValue(Direct3DViewport, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->NextViewport(lpDirect3DViewport, lplpAnotherViewport, dwFlags);

    if (SUCCEEDED(result)) { *lplpAnotherViewport = ActivateAgentDelegate(Direct3DViewport, *lplpAnotherViewport); }

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, NextViewport, result, 3, (ActivateAgent(Direct3DViewport, lpDirect3DViewport), lplpAnotherViewport, dwFlags));
}

// Executes a buffer without performing any rendering,
// but returns a z-ordered list of offsets to the primitives that intersect the upper-left corner of the rectangle specified by lpRect.
HRESULT Direct3DDevice::Pick(LPDIRECT3DEXECUTEBUFFER lpDirect3DExecuteBuffer, LPDIRECT3DVIEWPORT lpDirect3DViewport, DWORD dwFlags, LPD3DRECT lpRect)
{
    Direct3DDeviceLogMethodValue(TRACE, Pick, 4, (lpDirect3DExecuteBuffer, lpDirect3DViewport, dwFlags, lpRect));

    AttemptAccessAgentValue(Direct3DExecuteBuffer, lpDirect3DExecuteBuffer);
    AttemptAccessAgentValue(Direct3DViewport, lpDirect3DViewport);

    CONST HRESULT result = this->State.Self->Pick(lpDirect3DExecuteBuffer, lpDirect3DViewport, dwFlags, lpRect);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, Pick, result, 4, (ActivateAgent(Direct3DExecuteBuffer, lpDirect3DExecuteBuffer), ActivateAgent(Direct3DViewport, lpDirect3DViewport), dwFlags, lpRect));
}

// Retrieves the pick records for a device.
HRESULT Direct3DDevice::GetPickRecords(LPDWORD lpCount, LPD3DPICKRECORD lpD3DPickRec)
{
    Direct3DDeviceLogMethodValue(TRACE, GetPickRecords, 2, (lpCount, lpD3DPickRec));

    CONST HRESULT result = this->State.Self->GetPickRecords(lpCount, lpD3DPickRec);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, GetPickRecords, result, 2, (lpCount, lpD3DPickRec));
}

// Queries the current driver for a list of supported texture formats.
HRESULT Direct3DDevice::EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK lpd3dEnumTextureProc, LPVOID lpContext)
{
    Direct3DDeviceLogMethodValue(DEBUGINFO, EnumTextureFormats, 2, (lpd3dEnumTextureProc, lpContext));

    if (lpd3dEnumTextureProc == NULL) { Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, EnumTextureFormats, DDERR_INVALIDPARAMS, 2, (lpd3dEnumTextureProc, lpContext)); }

    ENUMTEXTUREFORMATSCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumTextureFormatsCallback = lpd3dEnumTextureProc;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumTextureFormats(EnumTextureFormatsCallback, &context);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, EnumTextureFormats, result, 2, (lpd3dEnumTextureProc, lpContext));
}

// Creates a matrix.
HRESULT Direct3DDevice::CreateMatrix(LPD3DMATRIXHANDLE lpD3DMatHandle)
{
    Direct3DDeviceLogMethodValue(TRACE, CreateMatrix, 1, (lpD3DMatHandle));

    CONST HRESULT result = this->CreateMatrix(lpD3DMatHandle);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, CreateMatrix, result, 1, (lpD3DMatHandle));
}

// Applies a matrix to a matrix handle.
HRESULT Direct3DDevice::SetMatrix(D3DMATRIXHANDLE d3dMatHandle, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDeviceLogMethodValue(TRACE, SetMatrix, 2, (d3dMatHandle, lpD3DMatrix));

    CONST HRESULT result = this->SetMatrix(d3dMatHandle, lpD3DMatrix);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, SetMatrix, result, 2, (d3dMatHandle, lpD3DMatrix));
}

// Retrieves a matrix from a matrix handle.
HRESULT Direct3DDevice::GetMatrix(D3DMATRIXHANDLE d3dMatHandle, LPD3DMATRIX lpD3DMatrix)
{
    Direct3DDeviceLogMethodValue(TRACE, GetMatrix, 2, (d3dMatHandle, lpD3DMatrix));

    CONST HRESULT result = this->State.Self->GetMatrix(d3dMatHandle, lpD3DMatrix);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, GetMatrix, result, 2, (d3dMatHandle, lpD3DMatrix));
}

// Deletes a matrix handle.
HRESULT Direct3DDevice::DeleteMatrix(D3DMATRIXHANDLE d3dMatHandle)
{
    Direct3DDeviceLogMethodValue(TRACE, DeleteMatrix, 1, (d3dMatHandle));

    CONST HRESULT result = this->State.Self->DeleteMatrix(d3dMatHandle);

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, DeleteMatrix, result, 1, (d3dMatHandle));
}

// Begins a scene.
HRESULT Direct3DDevice::BeginScene()
{
    Direct3DDeviceLogMethod(DEBUG, BeginScene);

    CONST HRESULT result = this->State.Self->BeginScene();

    Direct3DDeviceLogMethodResult(DEBUGINFO, BeginScene, result);
}

// Ends a scene.
HRESULT Direct3DDevice::EndScene()
{
    Direct3DDeviceLogMethod(DEBUG, EndScene);

    CONST HRESULT result = this->State.Self->EndScene();

    Direct3DDeviceLogMethodResult(DEBUGINFO, EndScene, result);
}

// Retrieves the Direct3D object for this device.
HRESULT Direct3DDevice::GetDirect3D(LPDIRECT3D* lplpD3D)
{
    Direct3DDeviceLogMethodValue(TRACE, GetDirect3D, 1, (lplpD3D));

    CONST HRESULT result = this->State.Self->GetDirect3D(lplpD3D);

    if (SUCCEEDED(result)) { *lplpD3D = ActivateAgentDelegate(Direct3D, *lplpD3D); }

    Direct3DDeviceLogMethodResultValue(TRACEDEBUGINFO, GetDirect3D, result, 1, (lplpD3D));
}
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
#include "Direct3D2.hxx"
#include "Direct3D3.hxx"
#include "Direct3D7.hxx"
#include "Direct3DDevice3.hxx"
#include "Direct3DLight.hxx"
#include "Direct3DMaterial3.hxx"
#include "Direct3DVertexBuffer.hxx"
#include "Direct3DViewport3.hxx"
#include "DirectDraw.hxx"
#include "DirectDraw2.hxx"
#include "DirectDraw4.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawSurface4.hxx"
#include "DirectDrawVideoPortContainer.hxx"

#include <AgentLogger.hxx>
#include <Direct3D3Logger.hxx>

#define Direct3D3LogMethod(L, M) AgentLogMethod(L, Direct3D3, M)
#define Direct3D3LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3D3, M, C, PARAMS)

#define Direct3D3LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3D3, AddRef, R)
#define Direct3D3LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3D3, Release, R)

#define Direct3D3LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3D3, M, R)
#define Direct3D3LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3D3, M, R, C, PARAMS)

#define Direct3D3LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3D3, M, C, PARAMS)
#define Direct3D3LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3D3, M, R, C, PARAMS)

typedef struct EnumDevicesCallbackContext
{
    Direct3D3* Self;
    LPLOGGER Logger;
    LPD3DENUMDEVICESCALLBACK EnumDevicesCallback;
    LPVOID Context;
} ENUMDEVICESCALLBACKCONTEXT, * LPENUMDEVICESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumDevicesCallback(GUID FAR* lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName, LPD3DDEVICEDESC lpD3DHWDeviceDesc, LPD3DDEVICEDESC lpD3DHELDeviceDesc, LPVOID lpContext)
{
    LPENUMDEVICESCALLBACKCONTEXT context = (LPENUMDEVICESCALLBACKCONTEXT)lpContext;

    Direct3D3LogMethodCallbackValue(TRACEDEBUG, EnumDevices, 6, (context->Self, lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc));

    CONST HRESULT result = context->EnumDevicesCallback(lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc, context->Context);

    Direct3D3LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumDevices, result, 6, (context->Self, lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc));
}

typedef struct EnumZBufferFormatsCallbackContext
{
    Direct3D3* Self;
    LPLOGGER Logger;
    LPD3DENUMPIXELFORMATSCALLBACK EnumCallback;
    LPVOID Context;
} ENUMZBUFFERFORMATSCALLBACKCONTEXT, * LPENUMZBUFFERFORMATSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumZBufferFormatsCallback(LPDDPIXELFORMAT lpDDPixFmt, LPVOID lpContext)
{
    LPENUMZBUFFERFORMATSCALLBACKCONTEXT context = (LPENUMZBUFFERFORMATSCALLBACKCONTEXT)lpContext;

    Direct3D3LogMethodCallbackValue(TRACEDEBUG, EnumZBufferFormats, 2, (context->Self, lpDDPixFmt));

    CONST HRESULT result = context->EnumCallback(lpDDPixFmt, context->Context);

    Direct3D3LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumZBufferFormats, result, 2, (context->Self, lpDDPixFmt));
}

Direct3D3::Direct3D3(AgentConstructorParameters(Direct3D3))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3D3);
}

Direct3D3::~Direct3D3()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3D3);
}

HRESULT Direct3D3::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3D3LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3D, riid)) { *ppvObj = ActivateAgent(Direct3D, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D2, riid)) { *ppvObj = ActivateAgent(Direct3D2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D3, riid)) { *ppvObj = ActivateAgent(Direct3D3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D7, riid)) { *ppvObj = ActivateAgent(Direct3D7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDraw, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw2, riid)) { *ppvObj = ActivateAgent(DirectDraw2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw4, riid)) { *ppvObj = ActivateAgent(DirectDraw4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw7, riid)) { *ppvObj = ActivateAgent(DirectDraw7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawVideoPortContainer, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPortContainer, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3D3::AddRef()
{
    Direct3D3LogMethod(DEBUG, AddRef);
    Direct3D3LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3D3::Release()
{
    Direct3D3LogMethod(DEBUG, Release);
    Direct3D3LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Enumerates all Direct3D device drivers installed on the system.
HRESULT Direct3D3::EnumDevices(LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpContext)
{
    Direct3D3LogMethodValue(DEBUGINFO, EnumDevices, 2, (lpEnumDevicesCallback, lpContext));

    if (lpEnumDevicesCallback == NULL) { Direct3D3LogMethodResultValue(TRACEDEBUGINFO, EnumDevices, DDERR_INVALIDPARAMS, 2, (lpEnumDevicesCallback, lpContext)); }

    ENUMDEVICESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumDevicesCallback = lpEnumDevicesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumDevices(EnumDevicesCallback, &context);

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, EnumDevices, result, 2, (lpEnumDevicesCallback, lpContext));
}

// Allocates a Direct3DLight object.
// This object can then be associated with a viewport by using the IDirect3DViewport3::AddLight method.
HRESULT Direct3D3::CreateLight(LPDIRECT3DLIGHT* lplpDirect3DLight, LPUNKNOWN pUnkOuter)
{
    Direct3D3LogMethodValue(TRACE, CreateLight, 2, (lplpDirect3DLight, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateLight(lplpDirect3DLight, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDirect3DLight = ActivateAgentDelegate(Direct3DLight, *lplpDirect3DLight); }

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, CreateLight, result, 2, (lplpDirect3DLight, pUnkOuter));
}

// Allocates a Direct3DMaterial3 object.
HRESULT Direct3D3::CreateMaterial(LPDIRECT3DMATERIAL3* lplpDirect3DMaterial, LPUNKNOWN pUnkOuter)
{
    Direct3D3LogMethodValue(TRACE, CreateMaterial, 2, (lplpDirect3DMaterial, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateMaterial(lplpDirect3DMaterial, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDirect3DMaterial = ActivateAgentDelegate(Direct3DMaterial3, *lplpDirect3DMaterial); }

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, CreateMaterial, result, 2, (lplpDirect3DMaterial, pUnkOuter));
}

// Creates a Direct3DViewport object.
// The viewport is associated with a Direct3DDevice object by using the IDirect3DDevice3::AddViewport method.
HRESULT Direct3D3::CreateViewport(LPDIRECT3DVIEWPORT3* lplpD3DViewport, LPUNKNOWN pUnkOuter)
{
    Direct3D3LogMethodValue(TRACE, CreateViewport, 2, (lplpD3DViewport, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateViewport(lplpD3DViewport, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpD3DViewport = ActivateAgentDelegate(Direct3DViewport3, *lplpD3DViewport); }

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, CreateViewport, result, 2, (lplpD3DViewport, pUnkOuter));
}

// Finds a device with specified characteristics and retrieves a description of it.
HRESULT Direct3D3::FindDevice(LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR)
{
    Direct3D3LogMethodValue(TRACE, FindDevice, 2, (lpD3DFDS, lpD3DFDR));

    CONST HRESULT result = this->State.Self->FindDevice(lpD3DFDS, lpD3DFDR);

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, FindDevice, result, 2, (lpD3DFDS, lpD3DFDR));
}

// Creates a Direct3D device to be used with the DrawPrimitive methods.
HRESULT Direct3D3::CreateDevice(REFCLSID rclsid, LPDIRECTDRAWSURFACE4 lpDDS, LPDIRECT3DDEVICE3* lplpD3DDevice, LPUNKNOWN pUnkOuter)
{
    Direct3D3LogMethodValue(TRACE, CreateDevice, 4, (rclsid, lpDDS, lplpD3DDevice, pUnkOuter));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDS);

    CONST HRESULT result = this->State.Self->CreateDevice(rclsid, lpDDS, lplpD3DDevice, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpD3DDevice = ActivateAgentDelegate(Direct3DDevice3, *lplpD3DDevice); }

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, CreateDevice, result, 4, (rclsid, ActivateAgent(DirectDrawSurface4, lpDDS), lplpD3DDevice, pUnkOuter));
}

// Creates a vertex buffer object.
HRESULT Direct3D3::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC lpVBDesc, LPDIRECT3DVERTEXBUFFER* lpD3DVertexBuffer, DWORD dwFlags, LPUNKNOWN pUnkOuter)
{
    Direct3D3LogMethodValue(TRACE, CreateVertexBuffer, 4, (lpVBDesc, lpD3DVertexBuffer, dwFlags, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateVertexBuffer(lpVBDesc, lpD3DVertexBuffer, dwFlags, pUnkOuter);

    if (SUCCEEDED(result)) { *lpD3DVertexBuffer = ActivateAgentDelegate(Direct3DVertexBuffer, *lpD3DVertexBuffer); }

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, CreateVertexBuffer, result, 4, (lpVBDesc, lpD3DVertexBuffer, dwFlags, pUnkOuter));
}

// Enumerates the supported depth-buffer formats for a specified device.
HRESULT Direct3D3::EnumZBufferFormats(REFCLSID rclsid, LPD3DENUMPIXELFORMATSCALLBACK lpEnumCallback, LPVOID lpContext)
{
    Direct3D3LogMethodValue(DEBUGINFO, EnumZBufferFormats, 3, (rclsid, lpEnumCallback, lpContext));

    if (lpEnumCallback == NULL) { Direct3D3LogMethodResultValue(TRACEDEBUGINFO, EnumZBufferFormats, DDERR_INVALIDPARAMS, 3, (rclsid, lpEnumCallback, lpContext)); }

    ENUMZBUFFERFORMATSCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumCallback = lpEnumCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumZBufferFormats(rclsid, EnumZBufferFormatsCallback, &context);

    Direct3D3LogMethodResultValue(TRACEDEBUGINFO, EnumZBufferFormats, result, 3, (rclsid, lpEnumCallback, lpContext));
}

// Evicts all managed textures from local or nonlocal video memory.
HRESULT Direct3D3::EvictManagedTextures()
{
    Direct3D3LogMethod(DEBUG, EvictManagedTextures);

    CONST HRESULT result = this->State.Self->EvictManagedTextures();

    Direct3D3LogMethodResult(DEBUGINFO, EvictManagedTextures, result);
}
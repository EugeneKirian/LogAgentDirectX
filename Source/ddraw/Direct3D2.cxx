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
#include "Direct3DDevice2.hxx"
#include "Direct3DLight.hxx"
#include "Direct3DMaterial2.hxx"
#include "Direct3DViewport2.hxx"
#include "DirectDraw.hxx"
#include "DirectDraw2.hxx"
#include "DirectDraw4.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawSurface.hxx"
#include "DirectDrawVideoPortContainer.hxx"

#include <AgentLogger.hxx>
#include <Direct3D2Logger.hxx>

#define Direct3D2LogMethod(L, M) AgentLogMethod(L, Direct3D2, M)
#define Direct3D2LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3D2, M, C, PARAMS)

#define Direct3D2LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3D2, AddRef, R)
#define Direct3D2LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3D2, Release, R)

#define Direct3D2LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3D2, M, R)
#define Direct3D2LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3D2, M, R, C, PARAMS)

#define Direct3D2LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3D2, M, C, PARAMS)
#define Direct3D2LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3D2, M, R, C, PARAMS)

typedef struct EnumDevicesCallbackContext
{
    Direct3D2* Self;
    LPLOGGER Logger;
    LPD3DENUMDEVICESCALLBACK EnumDevicesCallback;
    LPVOID Context;
} ENUMDEVICESCALLBACKCONTEXT, * LPENUMDEVICESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumDevicesCallback(GUID FAR* lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName, LPD3DDEVICEDESC lpD3DHWDeviceDesc, LPD3DDEVICEDESC lpD3DHELDeviceDesc, LPVOID lpContext)
{
    LPENUMDEVICESCALLBACKCONTEXT context = (LPENUMDEVICESCALLBACKCONTEXT)lpContext;

    Direct3D2LogMethodCallbackValue(DEBUG, EnumDevices, 6, (context->Self, lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc));

    CONST HRESULT result = context->EnumDevicesCallback(lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc, context->Context);

    Direct3D2LogMethodCallbackResultValue(DEBUGINFO, EnumDevices, result, 6, (context->Self, lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc));
}

Direct3D2::Direct3D2(AgentConstructorParameters(Direct3D2))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, Direct3D2);
}

Direct3D2::~Direct3D2()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, Direct3D2);
}

HRESULT Direct3D2::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3D2LogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

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

    Direct3D2LogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3D2::AddRef()
{
    Direct3D2LogMethod(DEBUG, AddRef);
    Direct3D2LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3D2::Release()
{
    Direct3D2LogMethod(DEBUG, Release);
    Direct3D2LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Enumerates all Direct3D device drivers installed on the system.
HRESULT Direct3D2::EnumDevices(LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpContext)
{
    Direct3D2LogMethodValue(DEBUGINFO, EnumDevices, 2, (lpEnumDevicesCallback, lpContext));

    if (lpEnumDevicesCallback == NULL) { Direct3D2LogMethodResultValue(DEBUGINFO, EnumDevices, DDERR_INVALIDPARAMS, 2, (lpEnumDevicesCallback, lpContext)); }

    ENUMDEVICESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumDevicesCallback = lpEnumDevicesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumDevices(EnumDevicesCallback, &context);

    Direct3D2LogMethodResultValue(DEBUGINFO, EnumDevices, result, 2, (lpEnumDevicesCallback, lpContext));
}

// Allocates a Direct3DLight object.
// This object can then be associated with a viewport by using the IDirect3DViewport2::AddLight method.
HRESULT Direct3D2::CreateLight(LPDIRECT3DLIGHT* lplpDirect3DLight, LPUNKNOWN pUnkOuter)
{
    Direct3D2LogMethodValue(DEBUG, CreateLight, 2, (lplpDirect3DLight, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateLight(lplpDirect3DLight, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDirect3DLight = ActivateAgentDelegate(Direct3DLight, *lplpDirect3DLight); }

    Direct3D2LogMethodResultValue(DEBUGINFO, CreateLight, result, 2, (lplpDirect3DLight, pUnkOuter));
}

// Allocates a Direct3DMaterial2 object.
HRESULT Direct3D2::CreateMaterial(LPDIRECT3DMATERIAL2* lplpDirect3DMaterial, LPUNKNOWN pUnkOuter)
{
    Direct3D2LogMethodValue(DEBUG, CreateMaterial, 2, (lplpDirect3DMaterial, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateMaterial(lplpDirect3DMaterial, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDirect3DMaterial = ActivateAgentDelegate(Direct3DMaterial2, *lplpDirect3DMaterial); }

    Direct3D2LogMethodResultValue(DEBUGINFO, CreateMaterial, result, 2, (lplpDirect3DMaterial, pUnkOuter));
}

// Creates a Direct3DViewport object.
// The viewport is associated with a Direct3DDevice object by using the IDirect3DDevice2::AddViewport method.
HRESULT Direct3D2::CreateViewport(LPDIRECT3DVIEWPORT2* lplpD3DViewport, LPUNKNOWN pUnkOuter)
{
    Direct3D2LogMethodValue(DEBUG, CreateViewport, 2, (lplpD3DViewport, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateViewport(lplpD3DViewport, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpD3DViewport = ActivateAgentDelegate(Direct3DViewport2, *lplpD3DViewport); }

    Direct3D2LogMethodResultValue(DEBUGINFO, CreateViewport, result, 2, (lplpD3DViewport, pUnkOuter));
}

// Finds a device with specified characteristics and retrieves a description of it.
HRESULT Direct3D2::FindDevice(LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR)
{
    Direct3D2LogMethodValue(DEBUG, FindDevice, 2, (lpD3DFDS, lpD3DFDR));

    CONST HRESULT result = this->State.Self->FindDevice(lpD3DFDS, lpD3DFDR);

    Direct3D2LogMethodResultValue(DEBUGINFO, FindDevice, result, 2, (lpD3DFDS, lpD3DFDR));
}

// Creates a Direct3D device to be used with the DrawPrimitive methods.
HRESULT Direct3D2::CreateDevice(REFCLSID rclsid, LPDIRECTDRAWSURFACE lpDDS, LPDIRECT3DDEVICE2* lplpD3DDevice)
{
    Direct3D2LogMethodValue(DEBUG, CreateDevice, 3, (rclsid, lpDDS, lplpD3DDevice));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDS);

    CONST HRESULT result = this->State.Self->CreateDevice(rclsid, lpDDS, lplpD3DDevice);

    if (SUCCEEDED(result)) { *lplpD3DDevice = ActivateAgentDelegate(Direct3DDevice2, *lplpD3DDevice); }

    Direct3D2LogMethodResultValue(DEBUGINFO, CreateDevice, result, 3, (rclsid, ActivateAgent(DirectDrawSurface, lpDDS), lplpD3DDevice));
}
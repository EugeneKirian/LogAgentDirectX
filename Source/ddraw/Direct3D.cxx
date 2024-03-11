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
#include "Direct3DLight.hxx"
#include "Direct3DMaterial.hxx"
#include "Direct3DViewport.hxx"
#include "DirectDraw.hxx"
#include "DirectDraw2.hxx"
#include "DirectDraw4.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawVideoPortContainer.hxx"

#include <AgentLogger.hxx>
#include <Direct3DLogger.hxx>

#define Direct3DLogMethod(L, M) AgentLogMethod(L, Direct3D, M)
#define Direct3DLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3D, M, C, PARAMS)

#define Direct3DLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3D, AddRef, R)
#define Direct3DLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3D, Release, R)

#define Direct3DLogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3D, M, R)
#define Direct3DLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3D, M, R, C, PARAMS)

#define Direct3DLogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3D, M, C, PARAMS)
#define Direct3DLogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3D, M, R, C, PARAMS)

typedef struct EnumDevicesCallbackContext
{
    Direct3D* Self;
    LPLOGGER Logger;
    LPD3DENUMDEVICESCALLBACK EnumDevicesCallback;
    LPVOID Context;
} ENUMDEVICESCALLBACKCONTEXT, * LPENUMDEVICESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumDevicesCallback(GUID FAR* lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName, LPD3DDEVICEDESC lpD3DHWDeviceDesc, LPD3DDEVICEDESC lpD3DHELDeviceDesc, LPVOID lpContext)
{
    LPENUMDEVICESCALLBACKCONTEXT context = (LPENUMDEVICESCALLBACKCONTEXT)lpContext;

    Direct3DLogMethodCallbackValue(TRACEDEBUG, EnumDevices, 6, (context->Self, lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc));

    CONST HRESULT result = context->EnumDevicesCallback(lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc, context->Context);

    Direct3DLogMethodCallbackResultValue(TRACEDEBUGINFO, EnumDevices, result, 6, (context->Self, lpGuid, lpDeviceDescription, lpDeviceName, lpD3DHWDeviceDesc, lpD3DHELDeviceDesc));
}

Direct3D::Direct3D(AgentConstructorParameters(Direct3D))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3D);
}

Direct3D::~Direct3D()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3D);
}

HRESULT Direct3D::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

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

    Direct3DLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3D::AddRef()
{
    Direct3DLogMethod(DEBUG, AddRef);
    Direct3DLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3D::Release()
{
    Direct3DLogMethod(DEBUG, Release);
    Direct3DLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT Direct3D::Initialize(REFCLSID rclsid)
{
    Direct3DLogMethodValue(TRACE, Initialize, 1, (rclsid));

    CONST HRESULT result = this->State.Self->Initialize(rclsid);

    Direct3DLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (rclsid));
}

// Enumerates all Direct3D device drivers installed on the system.
HRESULT Direct3D::EnumDevices(LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpContext)
{
    Direct3DLogMethodValue(DEBUGINFO, EnumDevices, 2, (lpEnumDevicesCallback, lpContext));

    if (lpEnumDevicesCallback == NULL) { Direct3DLogMethodResultValue(TRACEDEBUGINFO, EnumDevices, DDERR_INVALIDPARAMS, 2, (lpEnumDevicesCallback, lpContext)); }

    ENUMDEVICESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumDevicesCallback = lpEnumDevicesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumDevices(EnumDevicesCallback, &context);

    Direct3DLogMethodResultValue(TRACEDEBUGINFO, EnumDevices, result, 2, (lpEnumDevicesCallback, lpContext));
}

// Allocates a Direct3DLight object.
HRESULT Direct3D::CreateLight(LPDIRECT3DLIGHT* lplpDirect3DLight, LPUNKNOWN pUnkOuter)
{
    Direct3DLogMethodValue(TRACE, CreateLight, 2, (lplpDirect3DLight, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateLight(lplpDirect3DLight, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDirect3DLight = ActivateAgentDelegate(Direct3DLight, *lplpDirect3DLight); }

    Direct3DLogMethodResultValue(TRACEDEBUGINFO, CreateLight, result, 2, (lplpDirect3DLight, pUnkOuter));
}

// Allocates a Direct3DMaterial object.
HRESULT Direct3D::CreateMaterial(LPDIRECT3DMATERIAL* lplpDirect3DMaterial, LPUNKNOWN pUnkOuter)
{
    Direct3DLogMethodValue(TRACE, CreateMaterial, 2, (lplpDirect3DMaterial, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateMaterial(lplpDirect3DMaterial, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDirect3DMaterial = ActivateAgentDelegate(Direct3DMaterial, *lplpDirect3DMaterial); }

    Direct3DLogMethodResultValue(TRACEDEBUGINFO, CreateMaterial, result, 2, (lplpDirect3DMaterial, pUnkOuter));
}

// Creates a Direct3DViewport object.
HRESULT Direct3D::CreateViewport(LPDIRECT3DVIEWPORT* lplpD3DViewport, LPUNKNOWN pUnkOuter)
{
    Direct3DLogMethodValue(TRACE, CreateViewport, 2, (lplpD3DViewport, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateViewport(lplpD3DViewport, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpD3DViewport = ActivateAgentDelegate(Direct3DViewport, *lplpD3DViewport); }

    Direct3DLogMethodResultValue(TRACEDEBUGINFO, CreateViewport, result, 2, (lplpD3DViewport, pUnkOuter));
}

// Finds a device with specified characteristics and retrieves a description of it.
HRESULT Direct3D::FindDevice(LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR)
{
    Direct3DLogMethodValue(TRACE, FindDevice, 2, (lpD3DFDS, lpD3DFDR));

    CONST HRESULT result = this->State.Self->FindDevice(lpD3DFDS, lpD3DFDR);

    Direct3DLogMethodResultValue(TRACEDEBUGINFO, FindDevice, result, 2, (lpD3DFDS, lpD3DFDR));
}
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

#include "Direct3D8.hxx"
#include "Direct3DDevice8.hxx"

#include <AgentLogger.hxx>
#include <Direct3D8Logger.hxx>

#define Direct3D8LogMethod(L, M) AgentLogMethod(L, Direct3D8, M)
#define Direct3D8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3D8, M, C, PARAMS)

#define Direct3D8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3D8, AddRef, R)
#define Direct3D8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3D8, Release, R, TRUE)

#define Direct3D8LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3D8, M, R)
#define Direct3D8LogMethodCustomResult(L, M, R, F, T) AgentLogMethodCustomResult(L, Direct3D8, M, R, F, T)

#define Direct3D8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3D8, M, R, C, PARAMS)
#define Direct3D8LogMethodCustomResultValue(L, M, R, F, T, C, PARAMS) AgentLogMethodCustomResultValue(L, Direct3D8, M, R, F, T, C, PARAMS)

Direct3D8::Direct3D8(AgentConstructorParameters(Direct3D8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3D8);
}

Direct3D8::~Direct3D8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3D8);
}

HRESULT Direct3D8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3D8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3D8, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3D8, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3D8::AddRef()
{
   Direct3D8LogMethod(TRACE, AddRef);
   Direct3D8LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3D8::Release()
{
   Direct3D8LogMethod(TRACE, Release);
   Direct3D8LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Registers a pluggable software device with Microsoft® Direct3D®.
// Because the pluggable software device feature is no longer supported in Microsoft DirectX® 8.x, do not use this method.
HRESULT Direct3D8::RegisterSoftwareDevice(LPVOID pInitializeFunction)
{
    Direct3D8LogMethodValue(TRACE, RegisterSoftwareDevice, 1, (pInitializeFunction));

    CONST HRESULT result = this->State.Self->RegisterSoftwareDevice(pInitializeFunction);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, RegisterSoftwareDevice, result, 1, (pInitializeFunction));
}

// Returns the number of adapters on the system.
UINT Direct3D8::GetAdapterCount()
{
    Direct3D8LogMethod(TRACE, GetAdapterCount);

    CONST UINT result = this->State.Self->GetAdapterCount();

    Direct3D8LogMethodCustomResult(TRACEDEBUGINFO, GetAdapterCount, result, FALSE, UINT);
}

// Describes the physical display adapters present in the system when the IDirect3D8 interface was instantiated.
HRESULT Direct3D8::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8* pIdentifier)
{
    Direct3D8LogMethodValue(TRACE, GetAdapterIdentifier, 3, (Adapter, Flags, pIdentifier));

    CONST HRESULT result = this->State.Self->GetAdapterIdentifier(Adapter, Flags, pIdentifier);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, GetAdapterIdentifier, result, 3, (Adapter, Flags, pIdentifier));
}

// Returns the number of display modes available on this adapter.
UINT Direct3D8::GetAdapterModeCount(UINT Adapter)
{
    Direct3D8LogMethodValue(TRACE, GetAdapterModeCount, 1, (Adapter));

    CONST UINT result = this->State.Self->GetAdapterModeCount(Adapter);

    Direct3D8LogMethodCustomResultValue(TRACEDEBUGINFO, GetAdapterModeCount, result, FALSE, UINT, 1, (Adapter));
}

// Enumerates the display modes of an adapter.
HRESULT Direct3D8::EnumAdapterModes(UINT Adapter, UINT Mode, D3DDISPLAYMODE* pMode)
{
    Direct3D8LogMethodValue(TRACE, EnumAdapterModes, 3, (Adapter, Mode, pMode));

    CONST HRESULT result = this->State.Self->EnumAdapterModes(Adapter, Mode, pMode);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, EnumAdapterModes, result, 3, (Adapter, Mode, pMode));
}

// Retrieves the current display mode of the adapter.
HRESULT Direct3D8::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
    Direct3D8LogMethodValue(TRACE, GetAdapterDisplayMode, 2, (Adapter, pMode));

    CONST HRESULT result = this->State.Self->GetAdapterDisplayMode(Adapter, pMode);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, GetAdapterDisplayMode, result, 2, (Adapter, pMode));
}

// Verifies whether or not a certain device type can be used on this adapter and expect hardware acceleration using the given formats.
HRESULT Direct3D8::CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
    Direct3D8LogMethodValue(TRACE, CheckDeviceType, 5, (Adapter, CheckType, DisplayFormat, BackBufferFormat, Windowed));

    CONST HRESULT result = this->State.Self->CheckDeviceType(Adapter, CheckType, DisplayFormat, BackBufferFormat, Windowed);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, CheckDeviceType, result, 5, (Adapter, CheckType, DisplayFormat, BackBufferFormat, Windowed));
}

// Determines whether a surface format is available as a specified resource type and can be used as a texture,
// depth-stencil buffer, or render target, or any combination of the three, on a device representing this adapter.
HRESULT Direct3D8::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE ResourceType, D3DFORMAT CheckFormat)
{
    Direct3D8LogMethodValue(TRACE, CheckDeviceFormat, 6, (Adapter, DeviceType, AdapterFormat, Usage, ResourceType, CheckFormat));

    CONST HRESULT result = this->State.Self->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, ResourceType, CheckFormat);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, CheckDeviceFormat, result, 6, (Adapter, DeviceType, AdapterFormat, Usage, ResourceType, CheckFormat));
}

// Determines if a multisampling technique is available on this device.
HRESULT Direct3D8::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType)
{
    Direct3D8LogMethodValue(TRACE, CheckDeviceMultiSampleType, 5, (Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType));

    CONST HRESULT result = this->State.Self->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, CheckDeviceMultiSampleType, result, 5, (Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType));
}

// Determines whether or not a depth-stencil format is compatible with a render target format in a particular display mode.
HRESULT Direct3D8::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    Direct3D8LogMethodValue(TRACE, CheckDepthStencilMatch, 5, (Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat));

    CONST HRESULT result = this->State.Self->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, CheckDepthStencilMatch, result, 5, (Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat));
}

// Retrieves device-specific information about a device. 
HRESULT Direct3D8::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS8* pCaps)
{
    Direct3D8LogMethodValue(TRACE, GetDeviceCaps, 3, (Adapter, DeviceType, pCaps));

    CONST HRESULT result = this->State.Self->GetDeviceCaps(Adapter, DeviceType, pCaps);

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, GetDeviceCaps, result, 3, (Adapter, DeviceType, pCaps));
}

// Returns the handle of the monitor associated with the Microsoft® Direct3D® object.
HMONITOR Direct3D8::GetAdapterMonitor(UINT Adapter)
{
    Direct3D8LogMethodValue(TRACE, GetAdapterMonitor, 1, (Adapter));

    CONST HMONITOR result = this->State.Self->GetAdapterMonitor(Adapter);

    Direct3D8LogMethodCustomResultValue(TRACEDEBUGINFO, GetAdapterMonitor, result, FALSE, HMONITOR, 1, (Adapter));
}

// Creates a device to represent the display adapter.
HRESULT Direct3D8::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice8** ppReturnedDeviceInterface)
{
    Direct3D8LogMethodValue(TRACE, CreateDevice, 6, (Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface));

    CONST HRESULT result = this->State.Self->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);

    if (SUCCEEDED(result)) { *ppReturnedDeviceInterface = ActivateAgentDelegate(Direct3DDevice8, *ppReturnedDeviceInterface); }

    Direct3D8LogMethodResultValue(TRACEDEBUGINFO, CreateDevice, result, 6, (Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface));
}
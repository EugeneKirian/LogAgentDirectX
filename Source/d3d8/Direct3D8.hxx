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

#pragma once

#include "Base.hxx"

class Direct3D8 : public IDirect3D8
{
public:
    Direct3D8(AgentConstructorParameters(Direct3D8));
    virtual ~Direct3D8();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirect3D8 ***/

    STDMETHOD(RegisterSoftwareDevice)(THIS_ LPVOID pInitializeFunction);
    STDMETHOD_(UINT, GetAdapterCount)(THIS);
    STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8* pIdentifier);
    STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter);
    STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter, UINT Mode, D3DDISPLAYMODE* pMode);
    STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter, D3DDISPLAYMODE* pMode);
    STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed);
    STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat);
    STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType);
    STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat);
    STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS8* pCaps);
    STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter);
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice8** ppReturnedDeviceInterface);

protected:
    AgentStateStruct(Direct3D8);
};
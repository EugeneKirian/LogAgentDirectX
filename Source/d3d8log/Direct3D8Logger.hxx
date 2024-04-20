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

typedef struct Direct3D8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3D8QUERYINTERFACEMETHODVALUE, * LPDIRECT3D8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3D8AddRefMethodValue
{

} DIRECT3D8ADDREFMETHODVALUE, * LPDIRECT3D8ADDREFMETHODVALUE;

typedef struct Direct3D8ReleaseMethodValue
{

} DIRECT3D8RELEASEMETHODVALUE, * LPDIRECT3D8RELEASEMETHODVALUE;

typedef struct Direct3D8RegisterSoftwareDeviceMethodValue
{
    LPVOID InitializeFunction;
} DIRECT3D8REGISTERSOFTWAREDEVICEMETHODVALUE, * LPDIRECT3D8REGISTERSOFTWAREDEVICEMETHODVALUE;

typedef struct Direct3D8GetAdapterCountMethodValue
{

} DIRECT3D8GETADAPTERCOUNTMETHODVALUE, * LPDIRECT3D8GETADAPTERCOUNTMETHODVALUE;

typedef struct Direct3D8GetAdapterIdentifierMethodValue
{
    UINT Adapter;
    DWORD Options;
    D3DADAPTER_IDENTIFIER8* Identifier;
} DIRECT3D8GETADAPTERIDENTIFIERMETHODVALUE, * LPDIRECT3D8GETADAPTERIDENTIFIERMETHODVALUE;

typedef struct Direct3D8GetAdapterModeCountMethodValue
{
    UINT Adapter;
} DIRECT3D8GETADAPTERMODECOUNTMETHODVALUE, * LPDIRECT3D8GETADAPTERMODECOUNTMETHODVALUE;

typedef struct Direct3D8EnumAdapterModesMethodValue
{
    UINT Adapter;
    UINT ModeIndex;
    D3DDISPLAYMODE* Mode;
} DIRECT3D8ENUMADAPTERMODESMETHODVALUE, * LPDIRECT3D8ENUMADAPTERMODESMETHODVALUE;

typedef struct Direct3D8GetAdapterDisplayModeMethodValue
{
    UINT Adapter;
    D3DDISPLAYMODE* Mode;
} DIRECT3D8GETADAPTERDISPLAYMODEMETHODVALUE, * LPDIRECT3D8GETADAPTERDISPLAYMODEMETHODVALUE;

typedef struct Direct3D8CheckDeviceTypeMethodValue
{
    UINT Adapter;
    D3DDEVTYPE CheckType;
    D3DFORMAT DisplayFormat;
    D3DFORMAT BackBufferFormat;
    BOOL Windowed;
} DIRECT3D8CHECKDEVICETYPEMETHODVALUE, * LPDIRECT3D8CHECKDEVICETYPEMETHODVALUE;

typedef struct Direct3D8CheckDeviceFormatMethodValue
{
    UINT Adapter;
    D3DDEVTYPE DeviceType;
    D3DFORMAT AdapterFormat;
    DWORD Usage;
    D3DRESOURCETYPE ResourceType;
    D3DFORMAT CheckFormat;
} DIRECT3D8CHECKDEVICEFORMATMETHODVALUE, * LPDIRECT3D8CHECKDEVICEFORMATMETHODVALUE;

typedef struct Direct3D8CheckDeviceMultiSampleTypeMethodValue
{
    UINT Adapter;
    D3DDEVTYPE DeviceType;
    D3DFORMAT SurfaceFormat;
    BOOL Windowed;
    D3DMULTISAMPLE_TYPE MultiSampleType;
} DIRECT3D8CHECKDEVICEMULTISAMPLETYPEMETHODVALUE, * LPDIRECT3D8CHECKDEVICEMULTISAMPLETYPEMETHODVALUE;

typedef struct Direct3D8CheckDepthStencilMatchMethodValue
{
    UINT Adapter;
    D3DDEVTYPE DeviceType;
    D3DFORMAT AdapterFormat;
    D3DFORMAT RenderTargetFormat;
    D3DFORMAT DepthStencilFormat;
} DIRECT3D8CHECKDEPTHSTENCILMATCHMETHODVALUE, * LPDIRECT3D8CHECKDEPTHSTENCILMATCHMETHODVALUE;

typedef struct Direct3D8GetDeviceCapsMethodValue
{
    UINT Adapter;
    D3DDEVTYPE DeviceType;
    D3DCAPS8* Caps;
} DIRECT3D8GETDEVICECAPSMETHODVALUE, * LPDIRECT3D8GETDEVICECAPSMETHODVALUE;

typedef struct Direct3D8GetAdapterMonitorMethodValue
{
    UINT Adapter;
} DIRECT3D8GETADAPTERMONITORMETHODVALUE, * LPDIRECT3D8GETADAPTERMONITORMETHODVALUE;

typedef struct Direct3D8CreateDeviceMethodValue
{
    UINT Adapter;
    D3DDEVTYPE DeviceType;
    HWND Window;
    DWORD BehaviorFlags;
    D3DPRESENT_PARAMETERS* PresentationParameters;
    IDirect3DDevice8** ReturnedDeviceInterface;
} DIRECT3D8CREATEDEVICEMETHODVALUE, * LPDIRECT3D8CREATEDEVICEMETHODVALUE;
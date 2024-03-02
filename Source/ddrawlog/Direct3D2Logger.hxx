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

typedef struct Direct3D2QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3D2QUERYINTERFACEMETHODVALUE, * LPDIRECT3D2QUERYINTERFACEMETHODVALUE;

typedef struct Direct3D2AddRefMethodValue
{

} DIRECT3D2ADDREFMETHODVALUE, * LPDIRECT3D2ADDREFMETHODVALUE;

typedef struct Direct3D2ReleaseMethodValue
{

} DIRECT3D2RELEASEMETHODVALUE, * LPDIRECT3D2RELEASEMETHODVALUE;

typedef struct Direct3D2EnumDevicesMethodValue
{
    LPD3DENUMDEVICESCALLBACK Callback;
    LPVOID Context;
} DIRECT3D2ENUMDEVICESMETHODVALUE, * LPDIRECT3D2ENUMDEVICESMETHODVALUE;

typedef struct Direct3D2CreateLightMethodValue
{
    LPDIRECT3DLIGHT* Light;
    LPUNKNOWN Unknown;
} DIRECT3D2CREATELIGHTMETHODVALUE, * LPDIRECT3D2CREATELIGHTMETHODVALUE;

typedef struct Direct3D2CreateMaterialMethodValue
{
    LPDIRECT3DMATERIAL2* Material;
    LPUNKNOWN Unknown;
} DIRECT3D2CREATEMATERIALMETHODVALUE, * LPDIRECT3D2CREATEMATERIALMETHODVALUE;

typedef struct Direct3D2CreateViewportMethodValue
{
    LPDIRECT3DVIEWPORT2* ViewPort;
    LPUNKNOWN Unknown;
} DIRECT3D2CREATEVIEWPORTMETHODVALUE, * LPDIRECT3D2CREATEVIEWPORTMETHODVALUE;

typedef struct Direct3D2FindDeviceMethodValue
{
    LPD3DFINDDEVICESEARCH Search;
    LPD3DFINDDEVICERESULT Result;
} DIRECT3D2FINDDEVICEMETHODVALUE, * LPDIRECT3D2FINDDEVICEMETHODVALUE;

typedef struct Direct3D2CreateDeviceMethodValue
{
    GUID ID;
    LPDIRECTDRAWSURFACE Surface;
    LPDIRECT3DDEVICE2* Device;
} DIRECT3D2CREATEDEVICEMETHODVALUE, * LPDIRECT3D2CREATEDEVICEMETHODVALUE;

typedef struct Direct3D2EnumDevicesMethodCallbackValue
{
    LPVOID Object;
    LPGUID ID;
    LPSTR Description;
    LPSTR Name;
    LPD3DDEVICEDESC HardwareDescriptor;
    LPD3DDEVICEDESC EmulationDescriptor;
} DIRECT3D2ENUMDEVICESMETHODCALLBACKVALUE, * LPDIRECT3D2ENUMDEVICESMETHODCALLBACKVALUE;
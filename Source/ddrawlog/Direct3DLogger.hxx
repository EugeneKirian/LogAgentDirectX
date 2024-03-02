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

typedef struct Direct3DQueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DQUERYINTERFACEMETHODVALUE, * LPDIRECT3DQUERYINTERFACEMETHODVALUE;

typedef struct Direct3DAddRefMethodValue
{

} DIRECT3DADDREFMETHODVALUE, * LPDIRECT3DADDREFMETHODVALUE;

typedef struct Direct3DReleaseMethodValue
{

} DIRECT3DRELEASEMETHODVALUE, * LPDIRECT3DRELEASEMETHODVALUE;

typedef struct Direct3DInitializeMethodValue
{
    GUID ID;
} DIRECT3DINITIALIZEMETHODVALUE, * LPDIRECT3DINITIALIZEMETHODVALUE;

typedef struct Direct3DEnumDevicesMethodValue
{
    LPD3DENUMDEVICESCALLBACK Callback;
    LPVOID Context;
} DIRECT3DENUMDEVICESMETHODVALUE, * LPDIRECT3DENUMDEVICESMETHODVALUE;

typedef struct Direct3DCreateLightMethodValue
{
    LPDIRECT3DLIGHT* Light;
    LPUNKNOWN Unknown;
} DIRECT3DCREATELIGHTMETHODVALUE, * LPDIRECT3DCREATELIGHTMETHODVALUE;

typedef struct Direct3DCreateMaterialMethodValue
{
    LPDIRECT3DMATERIAL* Material;
    LPUNKNOWN Unknown;
} DIRECT3DCREATEMATERIALMETHODVALUE, * LPDIRECT3DCREATEMATERIALMETHODVALUE;

typedef struct Direct3DCreateViewportMethodValue
{
    LPDIRECT3DVIEWPORT* ViewPort;
    LPUNKNOWN Unknown;
} DIRECT3DCREATEVIEWPORTMETHODVALUE, * LPDIRECT3DCREATEVIEWPORTMETHODVALUE;

typedef struct Direct3DFindDeviceMethodValue
{
    LPD3DFINDDEVICESEARCH Search;
    LPD3DFINDDEVICERESULT Result;
} DIRECT3DFINDDEVICEMETHODVALUE, * LPDIRECT3DFINDDEVICEMETHODVALUE;

typedef struct Direct3DEnumDevicesMethodCallbackValue
{
    LPVOID Object;
    LPGUID ID;
    LPSTR Description;
    LPSTR Name;
    LPD3DDEVICEDESC HardwareDescriptor;
    LPD3DDEVICEDESC EmulationDescriptor;
} DIRECT3DENUMDEVICESMETHODCALLBACKVALUE, * LPDIRECT3DENUMDEVICESMETHODCALLBACKVALUE;
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

typedef struct Direct3D7QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3D7QUERYINTERFACEMETHODVALUE, * LPDIRECT3D7QUERYINTERFACEMETHODVALUE;

typedef struct Direct3D7AddRefMethodValue
{

} DIRECT3D7ADDREFMETHODVALUE, * LPDIRECT3D7ADDREFMETHODVALUE;

typedef struct Direct3D7ReleaseMethodValue
{

} DIRECT3D7RELEASEMETHODVALUE, * LPDIRECT3D7RELEASEMETHODVALUE;

typedef struct Direct3D7EnumDevicesMethodValue
{
    LPD3DENUMDEVICESCALLBACK7 Callback;
    LPVOID Context;
} DIRECT3D7ENUMDEVICESMETHODVALUE, * LPDIRECT3D7ENUMDEVICESMETHODVALUE;

typedef struct Direct3D7CreateDeviceMethodValue
{
    GUID ID;
    LPDIRECTDRAWSURFACE7 Surface;
    LPDIRECT3DDEVICE7* Device;
} DIRECT3D7CREATEDEVICEMETHODVALUE, * LPDIRECT3D7CREATEDEVICEMETHODVALUE;

typedef struct Direct3D7CreateVertexBufferMethodValue
{
    LPD3DVERTEXBUFFERDESC Descriptor;
    LPDIRECT3DVERTEXBUFFER7* Buffer;
    DWORD Options;
} DIRECT3D7CREATEVERTEXBUFFERMETHODVALUE, * LPDIRECT3D7CREATEVERTEXBUFFERMETHODVALUE;

typedef struct Direct3D7EnumZBufferFormatsMethodValue
{
    GUID ID;
    LPD3DENUMPIXELFORMATSCALLBACK Callback;
    LPVOID Context;
} DIRECT3D7ENUMZBUFFERFORMATSMETHODVALUE, * LPDIRECT3D7ENUMZBUFFERFORMATSMETHODVALUE;

typedef struct Direct3D7EvictManagedTexturesMethodValue
{

} DIRECT3D7EVICTMANAGEDTEXTURESMETHODVALUE, * LPDIRECT3D7EVICTMANAGEDTEXTURESMETHODVALUE;

typedef struct Direct3D7EnumDevicesMethodCallbackValue
{
    LPVOID Object;
    LPSTR Description;
    LPSTR Name;
    LPD3DDEVICEDESC7 Descriptor;
} DIRECT3D7ENUMDEVICESMETHODCALLBACKVALUE, * LPDIRECT3D7ENUMDEVICESMETHODCALLBACKVALUE;

typedef struct Direct3D7EnumZBufferFormatsMethodCallbackValue
{
    LPVOID Object;
    LPDDPIXELFORMAT Format;
} DIRECT3D7ENUMZBUFFERFORMATSMETHODCALLBACKVALUE, * LPDIRECT3D7ENUMZBUFFERFORMATSMETHODCALLBACKVALUE;
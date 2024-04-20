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

typedef struct Direct3DResource8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DRESOURCE8QUERYINTERFACEMETHODVALUE, * LPDIRECT3DRESOURCE8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DResource8AddRefMethodValue
{

} DIRECT3DRESOURCE8ADDREFMETHODVALUE, * LPDIRECT3DRESOURCE8ADDREFMETHODVALUE;

typedef struct Direct3DResource8ReleaseMethodValue
{

} DIRECT3DRESOURCE8RELEASEMETHODVALUE, * LPDIRECT3DRESOURCE8RELEASEMETHODVALUE;

typedef struct Direct3DResource8GetDeviceMethodValue
{
    LPDIRECT3DDEVICE8* Device;
} DIRECT3DRESOURCE8GETDEVICEMETHODVALUE, * LPDIRECT3DRESOURCE8GETDEVICEMETHODVALUE;

typedef struct Direct3DResource8SetPrivateDataMethodValue
{
    REFGUID ID;
    LPCVOID Data;
    DWORD Size;
    DWORD Options;
} DIRECT3DRESOURCE8SETPRIVATEDATAMETHODVALUE, * LPDIRECT3DRESOURCE8SETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DResource8GetPrivateDataMethodValue
{
    REFGUID ID;
    LPVOID Data;
    DWORD* Size;
} DIRECT3DRESOURCE8GETPRIVATEDATAMETHODVALUE, * LPDIRECT3DRESOURCE8GETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DResource8FreePrivateDataMethodValue
{
    REFGUID ID;
} DIRECT3DRESOURCE8FREEPRIVATEDATAMETHODVALUE, * LPDIRECT3DRESOURCE8FREEPRIVATEDATAMETHODVALUE;

typedef struct Direct3DResource8SetPriorityMethodValue
{
    DWORD Priority;
} DIRECT3DRESOURCE8SETPRIORITYMETHODVALUE, * LPDIRECT3DRESOURCE8SETPRIORITYMETHODVALUE;

typedef struct Direct3DResource8GetPriorityMethodValue
{

} DIRECT3DRESOURCE8GETPRIORITYMETHODVALUE, * LPDIRECT3DRESOURCE8GETPRIORITYMETHODVALUE;

typedef struct Direct3DResource8PreLoadMethodValue
{

} DIRECT3DRESOURCE8PRELOADMETHODVALUE, * LPDIRECT3DRESOURCE8PRELOADMETHODVALUE;

typedef struct Direct3DResource8GetTypeMethodValue
{

} DIRECT3DRESOURCE8GETTYPEMETHODVALUE, * LPDIRECT3DRESOURCE8GETTYPEMETHODVALUE;
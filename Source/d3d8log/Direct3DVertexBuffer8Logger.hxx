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

typedef struct Direct3DVertexBuffer8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DVERTEXBUFFER8QUERYINTERFACEMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DVertexBuffer8AddRefMethodValue
{

} DIRECT3DVERTEXBUFFER8ADDREFMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8ADDREFMETHODVALUE;

typedef struct Direct3DVertexBuffer8ReleaseMethodValue
{

} DIRECT3DVERTEXBUFFER8RELEASEMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8RELEASEMETHODVALUE;

typedef struct Direct3DVertexBuffer8GetDeviceMethodValue
{
    LPDIRECT3DDEVICE8* Device;
} DIRECT3DVERTEXBUFFER8GETDEVICEMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8GETDEVICEMETHODVALUE;

typedef struct Direct3DVertexBuffer8SetPrivateDataMethodValue
{
    REFGUID ID;
    LPCVOID Data;
    DWORD Size;
    DWORD Options;
} DIRECT3DVERTEXBUFFER8SETPRIVATEDATAMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8SETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DVertexBuffer8GetPrivateDataMethodValue
{
    REFGUID ID;
    LPVOID Data;
    DWORD* Size;
} DIRECT3DVERTEXBUFFER8GETPRIVATEDATAMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8GETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DVertexBuffer8FreePrivateDataMethodValue
{
    REFGUID ID;
} DIRECT3DVERTEXBUFFER8FREEPRIVATEDATAMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8FREEPRIVATEDATAMETHODVALUE;

typedef struct Direct3DVertexBuffer8SetPriorityMethodValue
{
    DWORD Priority;
} DIRECT3DVERTEXBUFFER8SETPRIORITYMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8SETPRIORITYMETHODVALUE;

typedef struct Direct3DVertexBuffer8GetPriorityMethodValue
{

} DIRECT3DVERTEXBUFFER8GETPRIORITYMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8GETPRIORITYMETHODVALUE;

typedef struct Direct3DVertexBuffer8PreLoadMethodValue
{

} DIRECT3DVERTEXBUFFER8PRELOADMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8PRELOADMETHODVALUE;

typedef struct Direct3DVertexBuffer8GetTypeMethodValue
{

} DIRECT3DVERTEXBUFFER8GETTYPEMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8GETTYPEMETHODVALUE;

typedef struct Direct3DVertexBuffer8LockMethodValue
{
    UINT Offset;
    UINT Size;
    BYTE** Data;
    DWORD Options;
} DIRECT3DVERTEXBUFFER8LOCKMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8LOCKMETHODVALUE;

typedef struct Direct3DVertexBuffer8UnlockMethodValue
{

} DIRECT3DVERTEXBUFFER8UNLOCKMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8UNLOCKMETHODVALUE;

typedef struct Direct3DVertexBuffer8GetDescMethodValue
{
    D3DVERTEXBUFFER_DESC* Desc;
} DIRECT3DVERTEXBUFFER8GETDESCMETHODVALUE, * LPDIRECT3DVERTEXBUFFER8GETDESCMETHODVALUE;
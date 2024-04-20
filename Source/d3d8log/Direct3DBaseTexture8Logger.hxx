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

typedef struct Direct3DBaseTexture8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DBASETEXTURE8QUERYINTERFACEMETHODVALUE, * LPDIRECT3DBASETEXTURE8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DBaseTexture8AddRefMethodValue
{

} DIRECT3DBASETEXTURE8ADDREFMETHODVALUE, * LPDIRECT3DBASETEXTURE8ADDREFMETHODVALUE;

typedef struct Direct3DBaseTexture8ReleaseMethodValue
{

} DIRECT3DBASETEXTURE8RELEASEMETHODVALUE, * LPDIRECT3DBASETEXTURE8RELEASEMETHODVALUE;

typedef struct Direct3DBaseTexture8GetDeviceMethodValue
{
    LPDIRECT3DDEVICE8* Device;
} DIRECT3DBASETEXTURE8GETDEVICEMETHODVALUE, * LPDIRECT3DBASETEXTURE8GETDEVICEMETHODVALUE;

typedef struct Direct3DBaseTexture8SetPrivateDataMethodValue
{
    REFGUID ID;
    LPCVOID Data;
    DWORD Size;
    DWORD Options;
} DIRECT3DBASETEXTURE8SETPRIVATEDATAMETHODVALUE, * LPDIRECT3DBASETEXTURE8SETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DBaseTexture8GetPrivateDataMethodValue
{
    REFGUID ID;
    LPVOID Data;
    DWORD* Size;
} DIRECT3DBASETEXTURE8GETPRIVATEDATAMETHODVALUE, * LPDIRECT3DBASETEXTURE8GETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DBaseTexture8FreePrivateDataMethodValue
{
    REFGUID ID;
} DIRECT3DBASETEXTURE8FREEPRIVATEDATAMETHODVALUE, * LPDIRECT3DBASETEXTURE8FREEPRIVATEDATAMETHODVALUE;

typedef struct Direct3DBaseTexture8SetPriorityMethodValue
{
    DWORD Priority;
} DIRECT3DBASETEXTURE8SETPRIORITYMETHODVALUE, * LPDIRECT3DBASETEXTURE8SETPRIORITYMETHODVALUE;

typedef struct Direct3DBaseTexture8GetPriorityMethodValue
{

} DIRECT3DBASETEXTURE8GETPRIORITYMETHODVALUE, * LPDIRECT3DBASETEXTURE8GETPRIORITYMETHODVALUE;

typedef struct Direct3DBaseTexture8PreLoadMethodValue
{

} DIRECT3DBASETEXTURE8PRELOADMETHODVALUE, * LPDIRECT3DBASETEXTURE8PRELOADMETHODVALUE;

typedef struct Direct3DBaseTexture8GetTypeMethodValue
{

} DIRECT3DBASETEXTURE8GETTYPEMETHODVALUE, * LPDIRECT3DBASETEXTURE8GETTYPEMETHODVALUE;

typedef struct Direct3DBaseTexture8SetLODMethodValue
{
    DWORD LOD;
} DIRECT3DBaseTexture8SETLODMETHODVALUE, * LPDIRECT3DBASETEXTURE8SETLODMETHODVALUE;

typedef struct Direct3DBaseTexture8GetLODMethodValue
{

} DIRECT3DBASETEXTURE8GETLODMETHODVALUE, * LPDIRECT3DBASETEXTURE8GETLODMETHODVALUE;

typedef struct Direct3DBaseTexture8GetLevelCountMethodValue
{

} DIRECT3DBASETEXTURE8GETLEVELCOUNTMETHODVALUE, * LPDIRECT3DBASETEXTURE8GETLEVELCOUNTMETHODVALUE;
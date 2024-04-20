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

typedef struct Direct3DVolume8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DVOLUME8QUERYINTERFACEMETHODVALUE, * LPDIRECT3DVOLUME8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DVolume8AddRefMethodValue
{

} DIRECT3DVOLUME8ADDREFMETHODVALUE, * LPDIRECT3DVOLUME8ADDREFMETHODVALUE;

typedef struct Direct3DVolume8ReleaseMethodValue
{

} DIRECT3DVOLUME8RELEASEMETHODVALUE, * LPDIRECT3DVOLUME8RELEASEMETHODVALUE;

typedef struct Direct3DVolume8GetDeviceMethodValue
{
    LPDIRECT3DDEVICE8* Device;
} DIRECT3DVOLUME8GETDEVICEMETHODVALUE, * LPDIRECT3DVOLUME8GETDEVICEMETHODVALUE;

typedef struct Direct3DVolume8SetPrivateDataMethodValue
{
    REFGUID ID;
    LPCVOID Data;
    DWORD Size;
    DWORD Options;
} DIRECT3DVOLUME8SETPRIVATEDATAMETHODVALUE, * LPDIRECT3DVOLUME8SETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DVolume8GetPrivateDataMethodValue
{
    REFGUID ID;
    LPVOID Data;
    DWORD* Size;
} DIRECT3DVOLUME8GETPRIVATEDATAMETHODVALUE, * LPDIRECT3DVOLUME8GETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DVolume8FreePrivateDataMethodValue
{
    REFGUID ID;
} DIRECT3DVOLUME8FREEPRIVATEDATAMETHODVALUE, * LPDIRECT3DVOLUME8FREEPRIVATEDATAMETHODVALUE;

typedef struct Direct3DVolume8GetContainerMethodValue
{
    REFGUID ID;
    LPVOID* Container;
} DIRECT3DVOLUME8GETCONTAINERMETHODVALUE, * LPDIRECT3DVOLUME8GETCONTAINERMETHODVALUE;

typedef struct Direct3DVolume8GetDescMethodValue
{
    D3DVOLUME_DESC* Desc;
} DIRECT3DVOLUME8GETDESCMETHODVALUE, * LPDIRECT3DVOLUME8GETDESCMETHODVALUE;

typedef struct Direct3DVolume8LockBoxMethodValue
{
    D3DLOCKED_BOX* Volume;
    CONST D3DBOX* Box;
    DWORD Options;
} DIRECT3DVOLUME8LOCKBOXMETHODVALUE, * LPDIRECT3DVOLUME8LOCKBOXMETHODVALUE;

typedef struct Direct3DVolume8UnlockBoxMethodValue
{

} DIRECT3DVOLUME8UNLOCKBOXMETHODVALUE, * LPDIRECT3DVOLUME8UNLOCKBOXMETHODVALUE;
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

typedef struct Direct3DSurface8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DSURFACE8QUERYINTERFACEMETHODVALUE, * LPDIRECT3DSURFACE8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DSurface8AddRefMethodValue
{

} DIRECT3DSURFACE8ADDREFMETHODVALUE, * LPDIRECT3DSURFACE8ADDREFMETHODVALUE;

typedef struct Direct3DSurface8ReleaseMethodValue
{

} DIRECT3DSURFACE8RELEASEMETHODVALUE, * LPDIRECT3DSURFACE8RELEASEMETHODVALUE;

typedef struct Direct3DSurface8GetDeviceMethodValue
{
    LPDIRECT3DDEVICE8* Device;
} DIRECT3DSURFACE8GETDEVICEMETHODVALUE, * LPDIRECT3DSURFACE8GETDEVICEMETHODVALUE;

typedef struct Direct3DSurface8SetPrivateDataMethodValue
{
    REFGUID ID;
    LPCVOID Data;
    DWORD Size;
    DWORD Options;
} DIRECT3DSURFACE8SETPRIVATEDATAMETHODVALUE, * LPDIRECT3DSURFACE8SETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DSurface8GetPrivateDataMethodValue
{
    REFGUID ID;
    LPVOID Data;
    DWORD* Size;
} DIRECT3DSURFACE8GETPRIVATEDATAMETHODVALUE, * LPDIRECT3DSURFACE8GETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DSurface8FreePrivateDataMethodValue
{
    REFGUID ID;
} DIRECT3DSURFACE8FREEPRIVATEDATAMETHODVALUE, * LPDIRECT3DSURFACE8FREEPRIVATEDATAMETHODVALUE;

typedef struct Direct3DSurface8GetContainerMethodValue
{
    REFIID ID;
    LPVOID* Container;
} DIRECT3DSURFACE8GETCONTAINERMETHODVALUE, * LPDIRECT3DSURFACE8GETCONTAINERMETHODVALUE;

typedef struct Direct3DSurface8GetDescMethodValue
{
    D3DSURFACE_DESC* Desc;
} DIRECT3DSURFACE8GETDESCMETHODVALUE, * LPDIRECT3DSURFACE8GETDESCMETHODVALUE;

typedef struct Direct3DSurface8LockRectMethodValue
{
    D3DLOCKED_RECT* LockedRect;
    CONST RECT* Rect;
    DWORD Options;
} DIRECT3DSURFACE8LOCKRECTMETHODVALUE, * LPDIRECT3DSURFACE8LOCKRECTMETHODVALUE;

typedef struct Direct3DSurface8UnlockRectMethodValue
{

} DIRECT3DSURFACE8UNLOCKRECTMETHODVALUE, * LPDIRECT3DSURFACE8UNLOCKRECTMETHODVALUE;
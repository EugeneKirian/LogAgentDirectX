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

typedef struct Direct3DTexture8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DTEXTURE8QUERYINTERFACEMETHODVALUE, * LPDIRECT3DTEXTURE8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DTexture8AddRefMethodValue
{

} DIRECT3DTEXTURE8ADDREFMETHODVALUE, * LPDIRECT3DTEXTURE8ADDREFMETHODVALUE;

typedef struct Direct3DTexture8ReleaseMethodValue
{

} DIRECT3DTEXTURE8RELEASEMETHODVALUE, * LPDIRECT3DTEXTURE8RELEASEMETHODVALUE;

typedef struct Direct3DTexture8GetDeviceMethodValue
{
    LPDIRECT3DDEVICE8* Device;
} DIRECT3DTEXTURE8GETDEVICEMETHODVALUE, * LPDIRECT3DTEXTURE8GETDEVICEMETHODVALUE;

typedef struct Direct3DTexture8SetPrivateDataMethodValue
{
    REFGUID ID;
    LPCVOID Data;
    DWORD Size;
    DWORD Options;
} DIRECT3DTEXTURE8SETPRIVATEDATAMETHODVALUE, * LPDIRECT3DTEXTURE8SETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DTexture8GetPrivateDataMethodValue
{
    REFGUID ID;
    LPVOID Data;
    DWORD* Size;
} DIRECT3DTEXTURE8GETPRIVATEDATAMETHODVALUE, * LPDIRECT3DTEXTURE8GETPRIVATEDATAMETHODVALUE;

typedef struct Direct3DTexture8FreePrivateDataMethodValue
{
    REFGUID ID;
} DIRECT3DTEXTURE8FREEPRIVATEDATAMETHODVALUE, * LPDIRECT3DTEXTURE8FREEPRIVATEDATAMETHODVALUE;

typedef struct Direct3DTexture8SetPriorityMethodValue
{
    DWORD Priority;
} DIRECT3DTEXTURE8SETPRIORITYMETHODVALUE, * LPDIRECT3DTEXTURE8SETPRIORITYMETHODVALUE;

typedef struct Direct3DTexture8GetPriorityMethodValue
{

} DIRECT3DTEXTURE8GETPRIORITYMETHODVALUE, * LPDIRECT3DTEXTURE8GETPRIORITYMETHODVALUE;

typedef struct Direct3DTexture8PreLoadMethodValue
{

} DIRECT3DTEXTURE8PRELOADMETHODVALUE, * LPDIRECT3DTEXTURE8PRELOADMETHODVALUE;

typedef struct Direct3DTexture8GetTypeMethodValue
{

} DIRECT3DTEXTURE8GETTYPEMETHODVALUE, * LPDIRECT3DTEXTURE8GETTYPEMETHODVALUE;

typedef struct Direct3DTexture8SetLODMethodValue
{
    DWORD LOD;
} DIRECT3DTexture8SETLODMETHODVALUE, * LPDIRECT3DTEXTURE8SETLODMETHODVALUE;

typedef struct Direct3DTexture8GetLODMethodValue
{

} DIRECT3DTEXTURE8GETLODMETHODVALUE, * LPDIRECT3DTEXTURE8GETLODMETHODVALUE;

typedef struct Direct3DTexture8GetLevelCountMethodValue
{

} DIRECT3DTEXTURE8GETLEVELCOUNTMETHODVALUE, * LPDIRECT3DTEXTURE8GETLEVELCOUNTMETHODVALUE;

typedef struct Direct3DTexture8GetLevelDescMethodValue
{
    UINT Level;
    D3DSURFACE_DESC* Desc;
} DIRECT3DTEXTURE8GETLEVELDESCMETHODVALUE, * LPDIRECT3DTEXTURE8GETLEVELDESCMETHODVALUE;

typedef struct Direct3DTexture8GetSurfaceLevelMethodValue
{
    UINT Level;
    LPDIRECT3DSURFACE8* SurfaceLevel;
} DIRECT3DTEXTURE8GETSURFACELEVELMETHODVALUE, * LPDIRECT3DTEXTURE8GETSURFACELEVELMETHODVALUE;

typedef struct Direct3DTexture8LockRectMethodValue
{
    UINT Level;
    D3DLOCKED_RECT* LockedRect;
    CONST RECT* Rect;
    DWORD Options;
} DIRECT3DTEXTURE8LOCKRECTMETHODVALUE, * LPDIRECT3DTEXTURE8LOCKRECTMETHODVALUE;

typedef struct Direct3DTexture8UnlockRectMethodValue
{
    UINT Level;
} DIRECT3DTEXTURE8UNLOCKRECTMETHODVALUE, * LPDIRECT3DTEXTURE8UNLOCKRECTMETHODVALUE;

typedef struct Direct3DTexture8AddDirtyRectMethodValue
{
    CONST RECT* Rect;
} DIRECT3DTEXTURE8ADDDIRTYRECTMETHODVALUE, * LPDIRECT3DTEXTURE8ADDDIRTYRECTMETHODVALUE;
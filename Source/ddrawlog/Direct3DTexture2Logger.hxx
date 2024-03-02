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

typedef struct Direct3DTexture2QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DTEXTURE2QUERYINTERFACEMETHODVALUE, * LPDIRECT3DTEXTURE2QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DTexture2AddRefMethodValue
{

} DIRECT3DTEXTURE2ADDREFMETHODVALUE, * LPDIRECT3DTEXTURE2ADDREFMETHODVALUE;

typedef struct Direct3DTexture2ReleaseMethodValue
{

} DIRECT3DTEXTURE2RELEASEMETHODVALUE, * LPDIRECT3DTEXTURE2RELEASEMETHODVALUE;

typedef struct Direct3DTexture2GetHandleMethodValue
{
    LPDIRECT3DDEVICE2 Device;
    LPD3DTEXTUREHANDLE Handle;
} DIRECT3DTEXTURE2GETHANDLEMETHODVALUE, * LPDIRECT3DTEXTURE2GETHANDLEMETHODVALUE;

typedef struct Direct3DTexture2PaletteChangedMethodValue
{
    DWORD Start;
    DWORD Count;
} DIRECT3DTEXTURE2PALETTECHANGEDMETHODVALUE, * LPDIRECT3DTEXTURE2PALETTECHANGEDMETHODVALUE;

typedef struct Direct3DTexture2LoadMethodValue
{
    LPDIRECT3DTEXTURE2 Texture;
} DIRECT3DTEXTURE2LOADMETHODVALUE, * LPDIRECT3DTEXTURE2LOADMETHODVALUE;
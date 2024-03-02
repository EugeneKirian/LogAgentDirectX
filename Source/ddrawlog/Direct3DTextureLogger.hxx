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

typedef struct Direct3DTextureQueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DTEXTUREQUERYINTERFACEMETHODVALUE, * LPDIRECT3DTEXTUREQUERYINTERFACEMETHODVALUE;

typedef struct Direct3DTextureAddRefMethodValue
{

} DIRECT3DTEXTUREADDREFMETHODVALUE, * LPDIRECT3DTEXTUREADDREFMETHODVALUE;

typedef struct Direct3DTextureReleaseMethodValue
{

} DIRECT3DTEXTURERELEASEMETHODVALUE, * LPDIRECT3DTEXTURERELEASEMETHODVALUE;

typedef struct Direct3DTextureInitializeMethodValue
{
    LPDIRECT3DDEVICE Device;
    LPDIRECTDRAWSURFACE Surface;
} DIRECT3DTEXTUREINITIALIZEMETHODVALUE, * LPDIRECT3DTEXTUREINITIALIZEMETHODVALUE;

typedef struct Direct3DTextureGetHandleMethodValue
{
    LPDIRECT3DDEVICE Device;
    LPD3DTEXTUREHANDLE Handle;
} DIRECT3DTEXTUREGETHANDLEMETHODVALUE, * LPDIRECT3DTEXTUREGETHANDLEMETHODVALUE;

typedef struct Direct3DTexturePaletteChangedMethodValue
{
    DWORD Start;
    DWORD Count;
} DIRECT3DTEXTUREPALETTECHANGEDMETHODVALUE, * LPDIRECT3DTEXTUREPALETTECHANGEDMETHODVALUE;

typedef struct Direct3DTextureLoadMethodValue
{
    LPDIRECT3DTEXTURE Texture;
} DIRECT3DTEXTURELOADMETHODVALUE, * LPDIRECT3DTEXTURELOADMETHODVALUE;

typedef struct Direct3DTextureUnloadMethodValue
{

} DIRECT3DTEXTUREUNLOADMETHODVALUE, * LPDIRECT3DTEXTUREUNLOADMETHODVALUE;
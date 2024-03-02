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

typedef struct Direct3DLightQueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DLIGHTQUERYINTERFACEMETHODVALUE, * LPDIRECT3DLIGHTQUERYINTERFACEMETHODVALUE;

typedef struct Direct3DLightAddRefMethodValue
{

} DIRECT3DLIGHTADDREFMETHODVALUE, * LPDIRECT3DLIGHTADDREFMETHODVALUE;

typedef struct Direct3DLightReleaseMethodValue
{

} DIRECT3DLIGHTRELEASEMETHODVALUE, * LPDIRECT3DLIGHTRELEASEMETHODVALUE;

typedef struct Direct3DLightInitializeMethodValue
{
    LPDIRECT3D Object;
} DIRECT3DLIGHTINITIALIZEMETHODVALUE, * LPDIRECT3DLIGHTINITIALIZEMETHODVALUE;

typedef struct Direct3DLightSetLightMethodValue
{
    LPD3DLIGHT Light;
} DIRECT3DLIGHTSETLIGHTMETHODVALUE, * LPDIRECT3DLIGHTSETLIGHTMETHODVALUE;

typedef struct Direct3DLightGetLightMethodValue
{
    LPD3DLIGHT Light;
} DIRECT3DLIGHTGETLIGHTMETHODVALUE, * LPDIRECT3DLIGHTGETLIGHTMETHODVALUE;
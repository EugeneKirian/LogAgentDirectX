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

typedef struct Direct3DMaterial2QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DMATERIAL2QUERYINTERFACEMETHODVALUE, * LPDIRECT3DMATERIAL2QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DMaterial2AddRefMethodValue
{

} DIRECT3DMATERIAL2ADDREFMETHODVALUE, * LPDIRECT3DMATERIAL2ADDREFMETHODVALUE;

typedef struct Direct3DMaterial2ReleaseMethodValue
{

} DIRECT3DMATERIAL2RELEASEMETHODVALUE, * LPDIRECT3DMATERIAL2RELEASEMETHODVALUE;

typedef struct Direct3DMaterial2SetMaterialMethodValue
{
    LPD3DMATERIAL Material;
} DIRECT3DMATERIAL2SETMATERIALMETHODVALUE, * LPDIRECT3DMATERIAL2SETMATERIALMETHODVALUE;

typedef struct Direct3DMaterial2GetMaterialMethodValue
{
    LPD3DMATERIAL Material;
} DIRECT3DMATERIAL2GETMATERIALMETHODVALUE, * LPDIRECT3DMATERIAL2GETMATERIALMETHODVALUE;

typedef struct Direct3DMaterial2GetHandleMethodValue
{
    LPDIRECT3DDEVICE2 Device;
    LPD3DMATERIALHANDLE Handle;
} DIRECT3DMATERIAL2GETHANDLEMETHODVALUE, * LPDIRECT3DMATERIAL2GETHANDLEMETHODVALUE;
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

typedef struct Direct3DMaterial3QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DMATERIAL3QUERYINTERFACEMETHODVALUE, * LPDIRECT3DMATERIAL3QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DMaterial3AddRefMethodValue
{

} DIRECT3DMATERIAL3ADDREFMETHODVALUE, * LPDIRECT3DMATERIAL3ADDREFMETHODVALUE;

typedef struct Direct3DMaterial3ReleaseMethodValue
{

} DIRECT3DMATERIAL3RELEASEMETHODVALUE, * LPDIRECT3DMATERIAL3RELEASEMETHODVALUE;

typedef struct Direct3DMaterial3SetMaterialMethodValue
{
    LPD3DMATERIAL Material;
} DIRECT3DMATERIAL3SETMATERIALMETHODVALUE, * LPDIRECT3DMATERIAL3SETMATERIALMETHODVALUE;

typedef struct Direct3DMaterial3GetMaterialMethodValue
{
    LPD3DMATERIAL Material;
} DIRECT3DMATERIAL3GETMATERIALMETHODVALUE, * LPDIRECT3DMATERIAL3GETMATERIALMETHODVALUE;

typedef struct Direct3DMaterial3GetHandleMethodValue
{
    LPDIRECT3DDEVICE3 Device;
    LPD3DMATERIALHANDLE Handle;
} DIRECT3DMATERIAL3GETHANDLEMETHODVALUE, * LPDIRECT3DMATERIAL3GETHANDLEMETHODVALUE;
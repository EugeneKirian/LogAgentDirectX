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

typedef struct Direct3DMaterialQueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DMATERIALQUERYINTERFACEMETHODVALUE, * LPDIRECT3DMATERIALQUERYINTERFACEMETHODVALUE;

typedef struct Direct3DMaterialAddRefMethodValue
{

} DIRECT3DMATERIALADDREFMETHODVALUE, * LPDIRECT3DMATERIALADDREFMETHODVALUE;

typedef struct Direct3DMaterialReleaseMethodValue
{

} DIRECT3DMATERIALRELEASEMETHODVALUE, * LPDIRECT3DMATERIALRELEASEMETHODVALUE;

typedef struct Direct3DMaterialInitializeMethodValue
{
    LPDIRECT3D Object;
} DIRECT3DMATERIALINITIALIZEMETHODVALUE, * LPDIRECT3DMATERIALINITIALIZEMETHODVALUE;

typedef struct Direct3DMaterialSetMaterialMethodValue
{
    LPD3DMATERIAL Material;
} DIRECT3DMATERIALSETMATERIALMETHODVALUE, * LPDIRECT3DMATERIALSETMATERIALMETHODVALUE;

typedef struct Direct3DMaterialGetMaterialMethodValue
{
    LPD3DMATERIAL Material;
} DIRECT3DMATERIALGETMATERIALMETHODVALUE, * LPDIRECT3DMATERIALGETMATERIALMETHODVALUE;

typedef struct Direct3DMaterialGetHandleMethodValue
{
    LPDIRECT3DDEVICE Device;
    LPD3DMATERIALHANDLE Handle;
} DIRECT3DMATERIALGETHANDLEMETHODVALUE, * LPDIRECT3DMATERIALGETHANDLEMETHODVALUE;

typedef struct Direct3DMaterialReserveMethodValue
{

} DIRECT3DMATERIALRESERVEMETHODVALUE, * LPDIRECT3DMATERIALRESERVEMETHODVALUE;

typedef struct Direct3DMaterialUnreserveMethodValue
{

} DIRECT3DMATERIALUNRESERVEMETHODVALUE, * LPDIRECT3DMATERIALUNRESERVEMETHODVALUE;
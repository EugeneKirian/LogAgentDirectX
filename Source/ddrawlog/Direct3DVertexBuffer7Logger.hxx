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

typedef struct Direct3DVertexBuffer7QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DORECT3DVERTEXBUFFER7QUERYINTERFACEMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DVertexBuffer7AddRefMethodValue
{

} DORECT3DVERTEXBUFFER7ADDREFMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7ADDREFMETHODVALUE;

typedef struct Direct3DVertexBuffer7ReleaseMethodValue
{

} DORECT3DVERTEXBUFFER7RELEASEMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7RELEASEMETHODVALUE;

typedef struct Direct3DVertexBuffer7LockMethodValue
{
    DWORD Options;
    LPVOID* Value;
    LPDWORD Size;
} DIRECT3DVERTEXBUFFER7LOCKMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7LOCKMETHODVALUE;

typedef struct Direct3DVertexBuffer7UnlockMethodValue
{

} DIRECT3DVERTEXBUFFER7UNLOCKMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7UNLOCKMETHODVALUE;

typedef struct Direct3DVertexBuffer7ProcessVerticesMethodValue
{
    DWORD Operation;
    DWORD DestinationIndex;
    DWORD Count;
    LPDIRECT3DVERTEXBUFFER7 Buffer;
    DWORD SourceIndex;
    LPDIRECT3DDEVICE7 Device;
    DWORD Options;
} DIRECT3DVERTEXBUFFER7PROCESSVERTICESMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7PROCESSVERTICESMETHODVALUE;

typedef struct Direct3DVertexBuffer7GetVertexBufferDescMethodValue
{
    LPD3DVERTEXBUFFERDESC Descriptor;
} DIRECT3DVERTEXBUFFER7GETVERTEXBUFFERDESCMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7GETVERTEXBUFFERDESCMETHODVALUE;

typedef struct Direct3DVertexBuffer7OptimizeMethodValue
{
    LPDIRECT3DDEVICE7 Device;
    DWORD Options;
} DIRECT3DVERTEXBUFFER7OPTIMIZEMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7OPTIMIZEMETHODVALUE;

typedef struct Direct3DVertexBuffer7ProcessVerticesStridedMethodValue
{
    DWORD Operation;
    DWORD DestinationIndex;
    DWORD Count;
    LPD3DDRAWPRIMITIVESTRIDEDDATA Value;
    DWORD SourceIndex;
    LPDIRECT3DDEVICE7 Device;
    DWORD Options;
} DIRECT3DVERTEXBUFFER7PROCESSVERTICESSTRIDEDMETHODVALUE, * LPDIRECT3DVERTEXBUFFER7PROCESSVERTICESSTRIDEDMETHODVALUE;
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

typedef struct Direct3DVertexBufferQueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DVERTEXBUFFERQUERYINTERFACEMETHODVALUE, * LPDIRECT3DVERTEXBUFFERQUERYINTERFACEMETHODVALUE;

typedef struct Direct3DVertexBufferAddRefMethodValue
{

} DIRECT3DVERTEXBUFFERADDREFMETHODVALUE, * LPDIRECT3DVERTEXBUFFERADDREFMETHODVALUE;

typedef struct Direct3DVertexBufferReleaseMethodValue
{

} DIRECT3DVERTEXBUFFERRELEASEMETHODVALUE, * LPDIRECT3DVERTEXBUFFERRELEASEMETHODVALUE;

typedef struct Direct3DVertexBufferLockMethodValue
{
    DWORD Options;
    LPVOID* Value;
    LPDWORD Size;
} DIRECT3DVERTEXBUFFERLOCKMETHODVALUE, * LPDIRECT3DVERTEXBUFFERLOCKMETHODVALUE;

typedef struct Direct3DVertexBufferUnlockMethodValue
{

} DIRECT3DVERTEXBUFFERUNLOCKMETHODVALUE, * LPDIRECT3DVERTEXBUFFERUNLOCKMETHODVALUE;

typedef struct Direct3DVertexBufferProcessVerticesMethodValue
{
    DWORD Operation;
    DWORD DestinationIndex;
    DWORD Count;
    LPDIRECT3DVERTEXBUFFER Buffer;
    DWORD SourceIndex;
    LPDIRECT3DDEVICE3 Device;
    DWORD Options;
} DIRECT3DVERTEXBUFFERPROCESSVERTICESMETHODVALUE, * LPDIRECT3DVERTEXBUFFERPROCESSVERTICESMETHODVALUE;

typedef struct Direct3DVertexBufferGetVertexBufferDescMethodValue
{
    LPD3DVERTEXBUFFERDESC Descriptor;
} DIRECT3DVERTEXBUFFERGETVERTEXBUFFERDESCMETHODVALUE, * LPDIRECT3DVERTEXBUFFERGETVERTEXBUFFERDESCMETHODVALUE;

typedef struct Direct3DVertexBufferOptimizeMethodValue
{
    LPDIRECT3DDEVICE3 Device;
    DWORD Options;
} DIRECT3DVERTEXBUFFEROPTIMIZEMETHODVALUE, * LPDIRECT3DVERTEXBUFFEROPTIMIZEMETHODVALUE;
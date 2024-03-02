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

typedef struct Direct3DDevice2QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DDEVICE2QUERYINTERFACEMETHODVALUE, * LPDIRECT3DDEVICE2QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DDevice2AddRefMethodValue
{

} DIRECT3DDEVICE2ADDREFMETHODVALUE, * LPDIRECT3DDEVICE2ADDREFMETHODVALUE;

typedef struct Direct3DDevice2ReleaseMethodValue
{

} DIRECT3DDEVICE2RELEASEMETHODVALUE, * LPDIRECT3DDEVICE2RELEASEMETHODVALUE;

typedef struct Direct3DDevice2GetCapsMethodValue
{
    LPD3DDEVICEDESC HardwareDescriptor;
    LPD3DDEVICEDESC EmulationDescriptor;
} DIRECT3DDEVICE2GETCAPSMETHODVALUE, * LPDIRECT3DDEVICE2GETCAPSMETHODVALUE;

typedef struct Direct3DDevice2SwapTextureHandlesMethodValue
{
    LPDIRECT3DTEXTURE2 Texture1;
    LPDIRECT3DTEXTURE2 Texture2;
} DIRECT3DDEVICE2SWAPTEXTUREHANDLESMETHODVALUE, * LPDIRECT3DDEVICE2SWAPTEXTUREHANDLESMETHODVALUE;

typedef struct Direct3DDevice2GetStatsMethodValue
{
    LPD3DSTATS Statistics;
} DIRECT3DDEVICE2GETSTATSMETHODVALUE, * LPDIRECT3DDEVICE2GETSTATSMETHODVALUE;

typedef struct Direct3DDevice2AddViewportMethodValue
{
    LPDIRECT3DVIEWPORT2 ViewPort;
} DIRECT3DDEVICE2ADDVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE2ADDVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice2DeleteViewportMethodValue
{
    LPDIRECT3DVIEWPORT2 ViewPort;
} DIRECT3DDEVICE2DELETEVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE2DELETEVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice2NextViewportMethodValue
{
    LPDIRECT3DVIEWPORT2 ViewPort;
    LPDIRECT3DVIEWPORT2* NextViewPort;
    DWORD Options;
} DIRECT3DDEVICE2NEXTVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE2NEXTVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice2EnumTextureFormatsMethodValue
{
    LPD3DENUMTEXTUREFORMATSCALLBACK Callback;
    LPVOID Context;
} DIRECT3DDEVICE2ENUMTEXTUREFORMATSMETHODVALUE, * LPDIRECT3DDEVICE2ENUMTEXTUREFORMATSMETHODVALUE;

typedef struct Direct3DDevice2BeginSceneMethodValue
{

} DIRECT3DDEVICE2BEGINSCENEMETHODVALUE, * LPDIRECT3DDEVICE2BEGINSCENEMETHODVALUE;

typedef struct Direct3DDevice2EndSceneMethodValue
{

} DIRECT3DDEVICE2ENDSCENEMETHODVALUE, * LPDIRECT3DDEVICE2ENDSCENEMETHODVALUE;

typedef struct Direct3DDevice2GetDirect3DMethodValue
{
    LPDIRECT3D2* Object;
} DIRECT3DDEVICE2GETDIRECT3DMETHODVALUE, * LPDIRECT3DDEVICE2GETDIRECT3DMETHODVALUE;

typedef struct Direct3DDevice2SetCurrentViewportMethodValue
{
    LPDIRECT3DVIEWPORT2 ViewPort;
} DIRECT3DDEVICE2SETCURRENTVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE2SETCURRENTVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice2GetCurrentViewportMethodValue
{
    LPDIRECT3DVIEWPORT2* ViewPort;
} DIRECT3DDEVICE2GETCURRENTVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE2GETCURRENTVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice2SetRenderTargetMethodValue
{
    LPDIRECTDRAWSURFACE Surface;
    DWORD Options;
} DIRECT3DDEVICE2SETRENDERTARGETMETHODVALUE, * LPDIRECT3DDEVICE2SETRENDERTARGETMETHODVALUE;

typedef struct Direct3DDevice2GetRenderTargetMethodValue
{
    LPDIRECTDRAWSURFACE* Surface;
} DIRECT3DDEVICE2GETRENDERTARGETMETHODVALUE, * LPDIRECT3DDEVICE2GETRENDERTARGETMETHODVALUE;

typedef struct Direct3DDevice2BeginMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    D3DVERTEXTYPE VertexType;
    DWORD Options;
} DIRECT3DDEVICE2BEGINMETHODVALUE, * LPDIRECT3DDEVICE2BEGINMETHODVALUE;

typedef struct Direct3DDevice2BeginIndexedMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    D3DVERTEXTYPE VertexType;
    LPVOID Vertices;
    DWORD VertexCount;
    DWORD Options;
} DIRECT3DDEVICE2BEGININDEXEDMETHODVALUE, * LPDIRECT3DDEVICE2BEGININDEXEDMETHODVALUE;

typedef struct Direct3DDevice2VertexMethodValue
{
    LPVOID Vertex;
} DIRECT3DDEVICE2VERTEXMETHODVALUE, * LPDIRECT3DDEVICE2VERTEXMETHODVALUE;

typedef struct Direct3DDevice2IndexMethodValue
{
    WORD Index;
} DIRECT3DDEVICE2INDEXMETHODVALUE, * LPDIRECT3DDEVICE2INDEXMETHODVALUE;

typedef struct Direct3DDevice2EndMethodValue
{
    DWORD Options;
} DIRECT3DDEVICE2ENDMETHODVALUE, * LPDIRECT3DDEVICE2ENDMETHODVALUE;

typedef struct Direct3DDevice2GetRenderStateMethodValue
{
    D3DRENDERSTATETYPE RenderStateType;
    LPDWORD RenderState;
} DIRECT3DDEVICE2GETRENDERSTATEMETHODVALUE, * LPDIRECT3DDEVICE2GETRENDERSTATEMETHODVALUE;

typedef struct Direct3DDevice2SetRenderStateMethodValue
{
    D3DRENDERSTATETYPE RenderStateType;
    DWORD RenderState;
} DIRECT3DDEVICE2SETRENDERSTATEMETHODVALUE, * LPDIRECT3DDEVICE2SETRENDERSTATEMETHODVALUE;

typedef struct Direct3DDevice2GetLightStateMethodValue
{
    D3DLIGHTSTATETYPE LightStateType;
    LPDWORD LightState;
} DIRECT3DDEVICE2GETLIGHTSTATEMETHODVALUE, * LPDIRECT3DDEVICE2GETLIGHTSTATEMETHODVALUE;

typedef struct Direct3DDevice2SetLightStateMethodValue
{
    D3DLIGHTSTATETYPE LightStateType;
    DWORD LightState;
} DIRECT3DDEVICE2SETLIGHTSTATEMETHODVALUE, * LPDIRECT3DDEVICE2SETLIGHTSTATEMETHODVALUE;

typedef struct Direct3DDevice2SetTransformMethodValue
{
    D3DTRANSFORMSTATETYPE TransformStateType;
    LPD3DMATRIX Matrix;
} DIRECT3DDEVICE2SETTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE2SETTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice2GetTransformMethodValue
{
    D3DTRANSFORMSTATETYPE TransformStateType;
    LPD3DMATRIX Matrix;
} DIRECT3DDEVICE2GETTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE2GETTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice2MultiplyTransformMethodValue
{
    D3DTRANSFORMSTATETYPE TransformStateType;
    LPD3DMATRIX Matrix;
} DIRECT3DDEVICE2MULTIPLYTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE2MULTIPLYTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice2DrawPrimitiveMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    D3DVERTEXTYPE VertexType;
    LPVOID Vertices;
    DWORD VertexCount;
    DWORD Options;
} DIRECT3DDEVICE2DRAWPRIMITIVEMETHODVALUE, * LPDIRECT3DDEVICE2DRAWPRIMITIVEMETHODVALUE;

typedef struct Direct3DDevice2DrawIndexedPrimitiveMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    D3DVERTEXTYPE VertexType;
    LPVOID Vertices;
    DWORD VertexCount;
    LPWORD Indices;
    DWORD IndexCount;
    DWORD Options;
} DIRECT3DDEVICE2DRAWINDEXEDPRIMITIVEMETHODVALUE, * LPDIRECT3DDEVICE2DRAWINDEXEDPRIMITIVEMETHODVALUE;

typedef struct Direct3DDevice2SetClipStatusMethodValue
{
    LPD3DCLIPSTATUS Status;
} DIRECT3DDEVICE2SETCLIPSTATUSMETHODVALUE, * LPDIRECT3DDEVICE2SETCLIPSTATUSMETHODVALUE;

typedef struct Direct3DDevice2GetClipStatusMethodValue
{
    LPD3DCLIPSTATUS Status;
} DIRECT3DDEVICE2GETCLIPSTATUSMETHODVALUE, * LPDIRECT3DDEVICE2GETCLIPSTATUSMETHODVALUE;

typedef struct Direct3DDevice2EnumTextureFormatsMethodCallbackValue
{
    LPVOID Object;
    LPDDSURFACEDESC Descriptor;
} DIRECT3DDEVICE2ENUMTEXTUREFORMATSMETHODCALLBACKVALUE, * LPDIRECT3DDEVICE2ENUMTEXTUREFORMATSMETHODCALLBACKVALUE;
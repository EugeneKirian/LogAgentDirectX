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

typedef struct Direct3DDevice7QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DDEVICE7QUERYINTERFACEMETHODVALUE, * LPDIRECT3DDEVICE7QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DDevice7AddRefMethodValue
{

} DIRECT3DDEVICE7ADDREFMETHODVALUE, * LPDIRECT3DDEVICE7ADDREFMETHODVALUE;

typedef struct Direct3DDevice7ReleaseMethodValue
{

} DIRECT3DDEVICE7RELEASEMETHODVALUE, * LPDIRECT3DDEVICE7RELEASEMETHODVALUE;

typedef struct Direct3DDevice7GetCapsMethodValue
{
    LPD3DDEVICEDESC7 Descriptor;
} DIRECT3DDEVICE7GETCAPSMETHODVALUE, * LPDIRECT3DDEVICE7GETCAPSMETHODVALUE;

typedef struct Direct3DDevice7EnumTextureFormatsMethodValue
{
    LPD3DENUMPIXELFORMATSCALLBACK Callback;
    LPVOID Context;
} DIRECT3DDEVICE7ENUMTEXTUREFORMATSMETHODVALUE, * LPDIRECT3DDEVICE7ENUMTEXTUREFORMATSMETHODVALUE;

typedef struct Direct3DDevice7BeginSceneMethodValue
{

} DIRECT3DDEVICE7BEGINSCENEMETHODVALUE, * LPDIRECT3DDEVICE7BEGINSCENEMETHODVALUE;

typedef struct Direct3DDevice7EndSceneMethodValue
{

} DIRECT3DDEVICE7ENDSCENEMETHODVALUE, * LPDIRECT3DDEVICE7ENDSCENEMETHODVALUE;

typedef struct Direct3DDevice7GetDirect3DMethodValue
{
    LPDIRECT3D7* Object;
} DIRECT3DDEVICE7GETDIRECT3DMETHODVALUE, * LPDIRECT3DDEVICE7GETDIRECT3DMETHODVALUE;

typedef struct Direct3DDevice7SetRenderTargetMethodValue
{
    LPDIRECTDRAWSURFACE7 Surface;
    DWORD Options;
} DIRECT3DDEVICE7SETRENDERTARGETMETHODVALUE, * LPDIRECT3DDEVICE7SETRENDERTARGETMETHODVALUE;

typedef struct Direct3DDevice7GetRenderTargetMethodValue
{
    LPDIRECTDRAWSURFACE7* Surface;
} DIRECT3DDEVICE7GETRENDERTARGETMETHODVALUE, * LPDIRECT3DDEVICE7GETRENDERTARGETMETHODVALUE;

typedef struct Direct3DDevice7ClearMethodValue
{
    DWORD Count;
    LPD3DRECT Rects;
    DWORD Options;
    D3DCOLOR Color;
    D3DVALUE Z;
    DWORD Stencil;
} DIRECT3DDEVICE7CLEARMETHODVALUE, * LPDIRECT3DDEVICE7CLEARMETHODVALUE;

typedef struct Direct3DDevice7SetTransformMethodValue
{
    D3DTRANSFORMSTATETYPE TransformStateType;
    LPD3DMATRIX Matrix;
} DIRECT3DDEVICE7SETTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE7SETTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice7GetTransformMethodValue
{
    D3DTRANSFORMSTATETYPE TransformStateType;
    LPD3DMATRIX Matrix;
} DIRECT3DDEVICE7GETTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE7GETTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice7SetViewportMethodValue
{
    LPD3DVIEWPORT7 ViewPort;
} DIRECT3DDEVICE7SETVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE7SETVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice7MultiplyTransformMethodValue
{
    D3DTRANSFORMSTATETYPE TransformStateType;
    LPD3DMATRIX Matrix;
} DIRECT3DDEVICE7MULTIPLYTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE7MULTIPLYTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice7GetViewportMethodValue
{
    LPD3DVIEWPORT7 ViewPort;
} DIRECT3DDEVICE7GETVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE7GETVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice7SetMaterialMethodValue
{
    LPD3DMATERIAL7 Material;
} DIRECT3DDEVICE7SETMATERIALMETHODVALUE, * LPDIRECT3DDEVICE7SETMATERIALMETHODVALUE;

typedef struct Direct3DDevice7GetMaterialMethodValue
{
    LPD3DMATERIAL7 Material;
} DIRECT3DDEVICE7GETMATERIALMETHODVALUE, * LPDIRECT3DDEVICE7GETMATERIALMETHODVALUE;

typedef struct Direct3DDevice7SetLightMethodValue
{
    DWORD Index;
    LPD3DLIGHT7 Light;
} DIRECT3DDEVICE7SETLIGHTMETHODVALUE, * LPDIRECT3DDEVICE7SETLIGHTMETHODVALUE;

typedef struct Direct3DDevice7GetLightMethodValue
{
    DWORD Index;
    LPD3DLIGHT7 Light;
} DIRECT3DDEVICE7GETLIGHTMETHODVALUE, * LPDIRECT3DDEVICE7GETLIGHTMETHODVALUE;

typedef struct Direct3DDevice7SetRenderStateMethodValue
{
    D3DRENDERSTATETYPE RenderStateType;
    DWORD RenderState;
} DIRECT3DDEVICE7SETRENDERSTATEMETHODVALUE, * LPDIRECT3DDEVICE7SETRENDERSTATEMETHODVALUE;

typedef struct Direct3DDevice7GetRenderStateMethodValue
{
    D3DRENDERSTATETYPE RenderStateType;
    LPDWORD RenderState;
} DIRECT3DDEVICE7GETRENDERSTATEMETHODVALUE, * LPDIRECT3DDEVICE7GETRENDERSTATEMETHODVALUE;

typedef struct Direct3DDevice7BeginStateBlockMethodValue
{

} DIRECT3DDEVICE7BEGINSTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE7BEGINSTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice7EndStateBlockMethodValue
{
    LPDWORD Handle;
} DIRECT3DDEVICE7ENDSTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE7ENDSTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice7PreLoadMethodValue
{
    LPDIRECTDRAWSURFACE7 Texture;
} DIRECT3DDEVICE7PRELOADMETHODVALUE, * LPDIRECT3DDEVICE7PRELOADMETHODVALUE;

typedef struct Direct3DDevice7DrawPrimitiveMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    DWORD VertexType;
    LPVOID Vertices;
    DWORD VertexCount;
    DWORD Options;
} DIRECT3DDEVICE7DRAWPRIMITIVEMETHODVALUE, * LPDIRECT3DDEVICE7DRAWPRIMITIVEMETHODVALUE;

typedef struct Direct3DDevice7DrawIndexedPrimitiveMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    DWORD VertexType;
    LPVOID Vertices;
    DWORD VertexCount;
    LPWORD Indices;
    DWORD IndexCount;
    DWORD Options;
} DIRECT3DDEVICE7DRAWINDEXEDPRIMITIVEMETHODVALUE, * LPDIRECT3DDEVICE7DRAWINDEXEDPRIMITIVEMETHODVALUE;

typedef struct Direct3DDevice7SetClipStatusMethodValue
{
    LPD3DCLIPSTATUS Status;
} DIRECT3DDEVICE7SETCLIPSTATUSMETHODVALUE, * LPDIRECT3DDEVICE7SETCLIPSTATUSMETHODVALUE;

typedef struct Direct3DDevice7GetClipStatusMethodValue
{
    LPD3DCLIPSTATUS Status;
} DIRECT3DDEVICE7GETCLIPSTATUSMETHODVALUE, * LPDIRECT3DDEVICE7GETCLIPSTATUSMETHODVALUE;

typedef struct Direct3DDevice7DrawPrimitiveStridedMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    DWORD VertexType;
    LPD3DDRAWPRIMITIVESTRIDEDDATA VertexArray;
    DWORD VertexCount;
    DWORD Options;
} DIRECT3DDEVICE7DRAWPRIMITIVESTRIDEDMETHODVALUE, * LPDIRECT3DDEVICE7DRAWPRIMITIVESTRIDEDMETHODVALUE;

typedef struct Direct3DDevice7DrawIndexedPrimitiveStridedMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    DWORD VertexType;
    LPD3DDRAWPRIMITIVESTRIDEDDATA VertexArray;
    DWORD VertexCount;
    LPWORD Indices;
    DWORD IndexCount;
    DWORD Options;
} DIRECT3DDEVICE7DRAWINDEXEDPRIMITIVESTRIDEDMETHODVALUE, * LPDIRECT3DDEVICE7DRAWINDEXEDPRIMITIVESTRIDEDMETHODVALUE;

typedef struct Direct3DDevice7DrawPrimitiveVBMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    LPDIRECT3DVERTEXBUFFER7 Buffer;
    DWORD StartVertex;
    DWORD VertexCount;
    DWORD Options;
} DIRECT3DDEVICE7DRAWPRIMITIVEVBMETHODVALUE, * LPDIRECT3DDEVICE7DRAWPRIMITIVEVBMETHODVALUE;

typedef struct Direct3DDevice7DrawIndexedPrimitiveVBMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    LPDIRECT3DVERTEXBUFFER7 Buffer;
    DWORD StartVertex;
    DWORD VertexCount;
    LPWORD Indices;
    DWORD IndexCount;
    DWORD Options;
} DIRECT3DDEVICE7DRAWINDEXEDPRIMITIVEVBMETHODVALUE, * LPDIRECT3DDEVICE7DRAWINDEXEDPRIMITIVEVBMETHODVALUE;

typedef struct Direct3DDevice7ComputeSphereVisibilityMethodValue
{
    LPD3DVECTOR Centers;
    LPD3DVALUE Radii;
    DWORD Count;
    DWORD Options;
    LPDWORD ReturnValues;
} DIRECT3DDEVICE7COMPUTESPHEREVISIBILITYMETHODVALUE, * LPDIRECT3DDEVICE7COMPUTESPHEREVISIBILITYMETHODVALUE;

typedef struct Direct3DDevice7GetTextureMethodValue
{
    DWORD Stage;
    LPDIRECTDRAWSURFACE7* Texture;
} DIRECT3DDEVICE7GETTEXTUREMETHODVALUE, * LPDIRECT3DDEVICE7GETTEXTUREMETHODVALUE;

typedef struct Direct3DDevice7SetTextureMethodValue
{
    DWORD Stage;
    LPDIRECTDRAWSURFACE7 Texture;
} DIRECT3DDEVICE7SETTEXTUREMETHODVALUE, * LPDIRECT3DDEVICE7SETTEXTUREMETHODVALUE;

typedef struct Direct3DDevice7GetTextureStageStateMethodValue
{
    DWORD Stage;
    D3DTEXTURESTAGESTATETYPE State;
    LPDWORD Value;
} DIRECT3DDEVICE7GETTEXTURESTAGESTATEMETHODVALUE, * LPDIRECT3DDEVICE7GETTEXTURESTAGESTATEMETHODVALUE;

typedef struct Direct3DDevice7SetTextureStageStateMethodValue
{
    DWORD Stage;
    D3DTEXTURESTAGESTATETYPE State;
    DWORD Value;
} DIRECT3DDEVICE7SETTEXTURESTAGESTATEMETHODVALUE, * LPDIRECT3DDEVICE7SETTEXTURESTAGESTATEMETHODVALUE;

typedef struct Direct3DDevice7ValidateDeviceMethodValue
{
    LPDWORD Passes;
} DIRECT3DDEVICE7VALIDATEDEVICEMETHODVALUE, * LPDIRECT3DDEVICE7VALIDATEDEVICEMETHODVALUE;

typedef struct Direct3DDevice7ApplyStateBlockMethodValue
{
    DWORD Handle;
} DIRECT3DDEVICE7APPLYSTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE7APPLYSTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice7CaptureStateBlockMethodValue
{
    DWORD Handle;
} DIRECT3DDEVICE7CAPTURESTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE7CAPTURESTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice7DeleteStateBlockMethodValue
{
    DWORD Handle;
} DIRECT3DDEVICE7DELETESTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE7DELETESTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice7CreateStateBlockMethodValue
{
    D3DSTATEBLOCKTYPE Type;
    LPDWORD Handle;
} DIRECT3DDEVICE7CREATESTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE7CREATESTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice7LoadMethodValue
{
    LPDIRECTDRAWSURFACE7 Destination;
    LPPOINT Point;
    LPDIRECTDRAWSURFACE7 Source;
    LPRECT Rect;
    DWORD Options;
} DIRECT3DDEVICE7LOADMETHODVALUE, * LPDIRECT3DDEVICE7LOADMETHODVALUE;

typedef struct Direct3DDevice7LightEnableMethodValue
{
    DWORD Index;
    BOOL Enable;
} DIRECT3DDEVICE7LIGHTENABLEMETHODVALUE, * LPDIRECT3DDEVICE7LIGHTENABLEMETHODVALUE;

typedef struct Direct3DDevice7GetLightEnableMethodValue
{
    DWORD Index;
    LPBOOL Enable;
} DIRECT3DDEVICE7GETLIGHTENABLEMETHODVALUE, * LPDIRECT3DDEVICE7GETLIGHTENABLEMETHODVALUE;

typedef struct Direct3DDevice7SetClipPlaneMethodValue
{
    DWORD Index;
    D3DVALUE* Plane;
} DIRECT3DDEVICE7SETCLIPPLANEMETHODVALUE, * LPDIRECT3DDEVICE7SETCLIPPLANEMETHODVALUE;

typedef struct Direct3DDevice7GetClipPlaneMethodValue
{
    DWORD Index;
    D3DVALUE* Plane;
} DIRECT3DDEVICE7GETCLIPPLANEMETHODVALUE, * LPDIRECT3DDEVICE7GETCLIPPLANEMETHODVALUE;

typedef struct Direct3DDevice7GetInfoMethodValue
{
    DWORD ID;
    LPVOID Value;
    DWORD Size;
} DIRECT3DDEVICE7GETINFOMETHODVALUE, * LPDIRECT3DDEVICE7GETINFOMETHODVALUE;

typedef struct Direct3DDevice7EnumTextureFormatsMethodCallbackValue
{
    LPVOID Object;
    LPDDPIXELFORMAT Format;
} DIRECT3DDEVICE7ENUMTEXTUREFORMATSMETHODCALLBACKVALUE, * LPDIRECT3DDEVICE7ENUMTEXTUREFORMATSMETHODCALLBACKVALUE;
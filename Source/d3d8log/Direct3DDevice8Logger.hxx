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

typedef struct Direct3DDevice8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DDEVICE8QUERYINTERFACEMETHODVALUE, * LPDIRECT3DDEVICE8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DDevice8AddRefMethodValue
{

} DIRECT3DDEVICE8ADDREFMETHODVALUE, * LPDIRECT3DDEVICE8ADDREFMETHODVALUE;

typedef struct Direct3DDevice8ReleaseMethodValue
{

} DIRECT3DDEVICE8RELEASEMETHODVALUE, * LPDIRECT3DDEVICE8RELEASEMETHODVALUE;

typedef struct Direct3DDevice8TestCooperativeLevelMethodValue
{

} DIRECT3DDEVICE8TESTCOOPERATIVELEVELMETHODVALUE, * LPDIRECT3DDEVICE8TESTCOOPERATIVELEVELMETHODVALUE;

typedef struct Direct3DDevice8GetAvailableTextureMemMethodValue
{

} DIRECT3DDEVICE8GETAVAILABLETEXTUREMEMMETHODVALUE, * LPDIRECT3DDEVICE8GETAVAILABLETEXTUREMEMMETHODVALUE;

typedef struct Direct3DDevice8ResourceManagerDiscardBytesMethodValue
{
    DWORD Bytes;
} DIRECT3DDEVICE8RESOURCEMANAGERDISCARDBYTESMETHODVALUE, * LPDIRECT3DDEVICE8RESOURCEMANAGERDISCARDBYTESMETHODVALUE;

typedef struct Direct3DDevice8GetDirect3DMethodValue
{
    LPDIRECT3D8* D3D8;
} DIRECT3DDEVICE8GETDIRECT3DMETHODVALUE, * LPDIRECT3DDEVICE8GETDIRECT3DMETHODVALUE;

typedef struct Direct3DDevice8GetDeviceCapsMethodValue
{
    D3DCAPS8* Caps;
} DIRECT3DDEVICE8GETDEVICECAPSMETHODVALUE, * LPDIRECT3DDEVICE8GETDEVICECAPSMETHODVALUE;

typedef struct Direct3DDevice8GetDisplayModeMethodValue
{
    D3DDISPLAYMODE* Mode;
} DIRECT3DDEVICE8GETDISPLAYMODEMETHODVALUE, * LPDIRECT3DDEVICE8GETDISPLAYMODEMETHODVALUE;

typedef struct Direct3DDevice8GetCreationParametersMethodValue
{
    D3DDEVICE_CREATION_PARAMETERS* Params;
} DIRECT3DDEVICE8GETCREATIONPARAMETERSMETHODVALUE, * LPDIRECT3DDEVICE8GETCREATIONPARAMETERSMETHODVALUE;

typedef struct Direct3DDevice8SetCursorPropertiesMethodValue
{
    UINT X;
    UINT Y;
    LPDIRECT3DSURFACE8 Cursor;
} DIRECT3DDEVICE8SETCURSORPROPERTIESMETHODVALUE, * LPDIRECT3DDEVICE8SETCURSORPROPERTIESMETHODVALUE;

typedef struct Direct3DDevice8SetCursorPositionMethodValue
{
    UINT X;
    UINT Y;
    DWORD Options;
} DIRECT3DDEVICE8SETCURSORPOSITIONMETHODVALUE, * LPDIRECT3DDEVICE8SETCURSORPOSITIONMETHODVALUE;

typedef struct Direct3DDevice8ShowCursorMethodValue
{
    BOOL Show;
} DIRECT3DDEVICE8SHOWCURSORMETHODVALUE, * LPDIRECT3DDEVICE8SHOWCURSORMETHODVALUE;

typedef struct Direct3DDevice8CreateAdditionalSwapChainMethodValue
{
    D3DPRESENT_PARAMETERS* PresentationParameters;
    LPDIRECT3DSWAPCHAIN8* SwapChain;
} DIRECT3DDEVICE8CREATEADDITIONALSWAPCHAINMETHODVALUE, * LPDIRECT3DDEVICE8CREATEADDITIONALSWAPCHAINMETHODVALUE;

typedef struct Direct3DDevice8ResetMethodValue
{
    D3DPRESENT_PARAMETERS* PresentationParameters;
} DIRECT3DDEVICE8RESETMETHODVALUE, * LPDIRECT3DDEVICE8RESETMETHODVALUE;

typedef struct Direct3DDevice8PresentMethodValue
{
    CONST RECT* SourceRect;
    CONST RECT* DestRect;
    HWND Window;
    CONST RGNDATA* Region;
} DIRECT3DDEVICE8PRESENTMETHODVALUE, * LPDIRECT3DDEVICE8PRESENTMETHODVALUE;

typedef struct Direct3DDevice8GetBackBufferMethodValue
{
    UINT Index;
    D3DBACKBUFFER_TYPE Type;
    LPDIRECT3DSURFACE8* BackBuffer;
} DIRECT3DDEVICE8GETBACKBUFFERMETHODVALUE, * LPDIRECT3DDEVICE8GETBACKBUFFERMETHODVALUE;

typedef struct Direct3DDevice8GetRasterStatusMethodValue
{
    D3DRASTER_STATUS* RasterStatus;
} DIRECT3DDEVICE8GETRASTERSTATUSMETHODVALUE, * LPDIRECT3DDEVICE8GETRASTERSTATUSMETHODVALUE;

typedef struct Direct3DDevice8SetGammaRampMethodValue
{
    DWORD Options;
    CONST D3DGAMMARAMP* Ramp;
} DIRECT3DDEVICE8SETGAMMARAMPMETHODVALUE, * LPDIRECT3DDEVICE8SETGAMMARAMPMETHODVALUE;

typedef struct Direct3DDevice8GetGammaRampMethodValue
{
    D3DGAMMARAMP* Ramp;
} DIRECT3DDEVICE8GETGAMMARAMPMETHODVALUE, * LPDIRECT3DDEVICE8GETGAMMARAMPMETHODVALUE;

typedef struct Direct3DDevice8CreateTextureMethodValue
{
    UINT Width;
    UINT Height;
    UINT Levels;
    DWORD Usage;
    D3DFORMAT Format;
    D3DPOOL Pool;
    LPDIRECT3DTEXTURE8* Texture;
} DIRECT3DDEVICE8CREATETEXTUREMETHODVALUE, * LPDIRECT3DDEVICE8CREATETEXTUREMETHODVALUE;

typedef struct Direct3DDevice8CreateVolumeTextureMethodValue
{
    UINT Width;
    UINT Height;
    UINT Depth;
    UINT Levels;
    DWORD Usage;
    D3DFORMAT Format;
    D3DPOOL Pool;
    LPDIRECT3DVOLUMETEXTURE8* Texture;
} DIRECT3DDEVICE8CREATEVOLUMETEXTUREMETHODVALUE, * LPDIRECT3DDEVICE8CREATEVOLUMETEXTUREMETHODVALUE;

typedef struct Direct3DDevice8CreateCubeTextureMethodValue
{
    UINT EdgeLength;
    UINT Levels;
    DWORD Usage;
    D3DFORMAT Format;
    D3DPOOL Pool;
    LPDIRECT3DCUBETEXTURE8* Texture;
} DIRECT3DDEVICE8CREATECUBETEXTUREMETHODVALUE, * LPDIRECT3DDEVICE8CREATECUBETEXTUREMETHODVALUE;

typedef struct Direct3DDevice8CreateVertexBufferMethodValue
{
    UINT Length;
    DWORD Usage;
    DWORD FVF;
    D3DPOOL Pool;
    LPDIRECT3DVERTEXBUFFER8* Buffer;
} DIRECT3DDEVICE8CREATEVERTEXBUFFERMETHODVALUE, * LPDIRECT3DDEVICE8CREATEVERTEXBUFFERMETHODVALUE;

typedef struct Direct3DDevice8CreateIndexBufferMethodValue
{
    UINT Length;
    DWORD Usage;
    D3DFORMAT Format;
    D3DPOOL Pool;
    LPDIRECT3DINDEXBUFFER8* Buffer;
} DIRECT3DDEVICE8CREATEINDEXBUFFERMETHODVALUE, * LPDIRECT3DDEVICE8CREATEINDEXBUFFERMETHODVALUE;

typedef struct Direct3DDevice8CreateRenderTargetMethodValue
{
    UINT Width;
    UINT Height;
    D3DFORMAT Format;
    D3DMULTISAMPLE_TYPE MultiSample;
    BOOL Lockable;
    LPDIRECT3DSURFACE8* Surface;
} DIRECT3DDEVICE8CREATERENDERTARGETMETHODVALUE, * LPDIRECT3DDEVICE8CREATERENDERTARGETMETHODVALUE;

typedef struct Direct3DDevice8CreateDepthStencilSurfaceMethodValue
{
    UINT Width;
    UINT Height;
    D3DFORMAT Format;
    D3DMULTISAMPLE_TYPE MultiSample;
    LPDIRECT3DSURFACE8* Surface;
} DIRECT3DDEVICE8CREATEDEPTHSTENCILSURFACEMETHODVALUE, * LPDIRECT3DDEVICE8CREATEDEPTHSTENCILSURFACEMETHODVALUE;

typedef struct Direct3DDevice8CreateImageSurfaceMethodValue
{
    UINT Width;
    UINT Height;
    D3DFORMAT Format;
    LPDIRECT3DSURFACE8* Surface;
} DIRECT3DDEVICE8CREATEIMAGESURFACEMETHODVALUE, * LPDIRECT3DDEVICE8CREATEIMAGESURFACEMETHODVALUE;

typedef struct Direct3DDevice8CopyRectsMethodValue
{
    LPDIRECT3DSURFACE8 SourceSurface;
    CONST RECT* SourceRectsArray;
    UINT Rects;
    LPDIRECT3DSURFACE8 DestinationSurface;
    CONST POINT* DestPointsArray;
} DIRECT3DDEVICE8COPYRECTSMETHODVALUE, * LPDIRECT3DDEVICE8COPYRECTSMETHODVALUE;

typedef struct Direct3DDevice8UpdateTextureMethodValue
{
    LPDIRECT3DBASETEXTURE8 SourceTexture;
    LPDIRECT3DBASETEXTURE8 DestinationTexture;
} DIRECT3DDEVICE8UPDATETEXTUREMETHODVALUE, * LPDIRECT3DDEVICE8UPDATETEXTUREMETHODVALUE;

typedef struct Direct3DDevice8GetFrontBufferMethodValue
{
    LPDIRECT3DSURFACE8 DestSurface;
} DIRECT3DDEVICE8GETFRONTBUFFERMETHODVALUE, * LPDIRECT3DDEVICE8GETFRONTBUFFERMETHODVALUE;

typedef struct Direct3DDevice8SetRenderTargetMethodValue
{
    LPDIRECT3DSURFACE8 RenderTarget;
    LPDIRECT3DSURFACE8 NewZStencil;
} DIRECT3DDEVICE8SETRENDERTARGETMETHODVALUE, * LPDIRECT3DDEVICE8SETRENDERTARGETMETHODVALUE;

typedef struct Direct3DDevice8GetRenderTargetMethodValue
{
    LPDIRECT3DSURFACE8* RenderTarget;
} DIRECT3DDEVICE8GETRENDERTARGETMETHODVALUE, * LPDIRECT3DDEVICE8GETRENDERTARGETMETHODVALUE;

typedef struct Direct3DDevice8GetDepthStencilSurfaceMethodValue
{
    LPDIRECT3DSURFACE8* ZStencilSurface;
} DIRECT3DDEVICE8GETDEPTHSTENCILSURFACEMETHODVALUE, * LPDIRECT3DDEVICE8GETDEPTHSTENCILSURFACEMETHODVALUE;

typedef struct Direct3DDevice8BeginSceneMethodValue
{

} DIRECT3DDEVICE8BEGINSCENEMETHODVALUE, * LPDIRECT3DDEVICE8BEGINSCENEMETHODVALUE;

typedef struct Direct3DDevice8EndSceneMethodValue
{

} DIRECT3DDEVICE8ENDSCENEMETHODVALUE, * LPDIRECT3DDEVICE8ENDSCENEMETHODVALUE;

typedef struct Direct3DDevice8ClearMethodValue
{
    DWORD Count;
    CONST D3DRECT* Rects;
    DWORD Options;
    D3DCOLOR Color;
    FLOAT Z;
    DWORD Stencil;
} DIRECT3DDEVICE8CLEARMETHODVALUE, * LPDIRECT3DDEVICE8CLEARMETHODVALUE;

typedef struct Direct3DDevice8SetTransformMethodValue
{
    D3DTRANSFORMSTATETYPE State;
    CONST D3DMATRIX* Matrix;
} DIRECT3DDEVICE8SETTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE8SETTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice8GetTransformMethodValue
{
    D3DTRANSFORMSTATETYPE State;
    D3DMATRIX* Matrix;
} DIRECT3DDEVICE8GETTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE8GETTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice8MultiplyTransformMethodValue
{
    D3DTRANSFORMSTATETYPE State;
    CONST D3DMATRIX* Matrix;
} DIRECT3DDEVICE8MULTIPLYTRANSFORMMETHODVALUE, * LPDIRECT3DDEVICE8MULTIPLYTRANSFORMMETHODVALUE;

typedef struct Direct3DDevice8SetViewportMethodValue
{
    CONST D3DVIEWPORT8* Viewport;
} DIRECT3DDEVICE8SETVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE8SETVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice8GetViewportMethodValue
{
    D3DVIEWPORT8* Viewport;
} DIRECT3DDEVICE8GETVIEWPORTMETHODVALUE, * LPDIRECT3DDEVICE8GETVIEWPORTMETHODVALUE;

typedef struct Direct3DDevice8SetMaterialMethodValue
{
    CONST D3DMATERIAL8* Material;
} DIRECT3DDEVICE8SETMATERIALMETHODVALUE, * LPDIRECT3DDEVICE8SETMATERIALMETHODVALUE;

typedef struct Direct3DDevice8GetMaterialMethodValue
{
    D3DMATERIAL8* Material;
} DIRECT3DDEVICE8GETMATERIALMETHODVALUE, * LPDIRECT3DDEVICE8GETMATERIALMETHODVALUE;

typedef struct Direct3DDevice8SetLightMethodValue
{
    DWORD Index;
    CONST D3DLIGHT8* Light;
} DIRECT3DDEVICE8SETLIGHTMETHODVALUE, * LPDIRECT3DDEVICE8SETLIGHTMETHODVALUE;

typedef struct Direct3DDevice8GetLightMethodValue
{
    DWORD Index;
    D3DLIGHT8* Light;
} DIRECT3DDEVICE8GETLIGHTMETHODVALUE, * LPDIRECT3DDEVICE8GETLIGHTMETHODVALUE;

typedef struct Direct3DDevice8LightEnableMethodValue
{
    DWORD Index;
    BOOL Enable;
} DIRECT3DDEVICE8LIGHTENABLEMETHODVALUE, * LPDIRECT3DDEVICE8LIGHTENABLEMETHODVALUE;

typedef struct Direct3DDevice8GetLightEnableMethodValue
{
    DWORD Index;
    BOOL* Enable;
} DIRECT3DDEVICE8GETLIGHTENABLEMETHODVALUE, * LPDIRECT3DDEVICE8GETLIGHTENABLEMETHODVALUE;

typedef struct Direct3DDevice8SetClipPlaneMethodValue
{
    DWORD Index;
    CONST FLOAT* Plane;
} DIRECT3DDEVICE8SETCLIPPLANEMETHODVALUE, * LPDIRECT3DDEVICE8SETCLIPPLANEMETHODVALUE;

typedef struct Direct3DDevice8GetClipPlaneMethodValue
{
    DWORD Index;
    CONST FLOAT* Plane;
} DIRECT3DDEVICE8GETCLIPPLANEMETHODVALUE, * LPDIRECT3DDEVICE8GETCLIPPLANEMETHODVALUE;

typedef struct Direct3DDevice8SetRenderStateMethodValue
{
    D3DRENDERSTATETYPE State;
    DWORD Value;
} DIRECT3DDEVICE8SETRENDERSTATEMETHODVALUE, * LPDIRECT3DDEVICE8SETRENDERSTATEMETHODVALUE;

typedef struct Direct3DDevice8GetRenderStateMethodValue
{
    D3DRENDERSTATETYPE State;
    DWORD* Value;
} DIRECT3DDEVICE8GETRENDERSTATEMETHODVALUE, * LPDIRECT3DDEVICE8GETRENDERSTATEMETHODVALUE;

typedef struct Direct3DDevice8BeginStateBlockMethodValue
{

} DIRECT3DDEVICE8BEGINSTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE8BEGINSTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice8EndStateBlockMethodValue
{
    DWORD* Token;
} DIRECT3DDEVICE8ENDSTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE8ENDSTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice8ApplyStateBlockMethodValue
{
    DWORD Token;
} DIRECT3DDEVICE8APPLYSTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE8APPLYSTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice8CaptureStateBlockMethodValue
{
    DWORD Token;
} DIRECT3DDEVICE8CAPTURESTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE8CAPTURESTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice8DeleteStateBlockMethodValue
{
    DWORD Token;
} DIRECT3DDEVICE8DELETESTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE8DELETESTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice8CreateStateBlockMethodValue
{
    D3DSTATEBLOCKTYPE Type;
    DWORD* Token;
} DIRECT3DDEVICE8CREATESTATEBLOCKMETHODVALUE, * LPDIRECT3DDEVICE8CREATESTATEBLOCKMETHODVALUE;

typedef struct Direct3DDevice8SetClipStatusMethodValue
{
    CONST D3DCLIPSTATUS8* ClipStatus;
} DIRECT3DDEVICE8SETCLIPSTATUSMETHODVALUE, * LPDIRECT3DDEVICE8SETCLIPSTATUSMETHODVALUE;

typedef struct Direct3DDevice8GetClipStatusMethodValue
{
    D3DCLIPSTATUS8* ClipStatus;
} DIRECT3DDEVICE8GETCLIPSTATUSMETHODVALUE, * LPDIRECT3DDEVICE8GETCLIPSTATUSMETHODVALUE;

typedef struct Direct3DDevice8GetTextureMethodValue
{
    DWORD Stage;
    LPDIRECT3DBASETEXTURE8* Texture;
} DIRECT3DDEVICE8GETTEXTUREMETHODVALUE, * LPDIRECT3DDEVICE8GETTEXTUREMETHODVALUE;

typedef struct Direct3DDevice8SetTextureMethodValue
{
    DWORD Stage;
    LPDIRECT3DBASETEXTURE8 Texture;
} DIRECT3DDEVICE8SETTEXTUREMETHODVALUE, * LPDIRECT3DDEVICE8SETTEXTUREMETHODVALUE;

typedef struct Direct3DDevice8GetTextureStageStateMethodValue
{
    DWORD Stage;
    D3DTEXTURESTAGESTATETYPE Type;
    DWORD* Value;
} DIRECT3DDEVICE8GETTEXTURESTAGESTATEMETHODVALUE, * LPDIRECT3DDEVICE8GETTEXTURESTAGESTATEMETHODVALUE;

typedef struct Direct3DDevice8SetTextureStageStateMethodValue
{
    DWORD Stage;
    D3DTEXTURESTAGESTATETYPE Type;
    DWORD Value;
} DIRECT3DDEVICE8SETTEXTURESTAGESTATEMETHODVALUE, * LPDIRECT3DDEVICE8SETTEXTURESTAGESTATEMETHODVALUE;

typedef struct Direct3DDevice8ValidateDeviceMethodValue
{
    DWORD* NumPasses;
} DIRECT3DDEVICE8VALIDATEDEVICEMETHODVALUE, * LPDIRECT3DDEVICE8VALIDATEDEVICEMETHODVALUE;

typedef struct Direct3DDevice8GetInfoMethodValue
{
    DWORD DevInfoID;
    LPVOID DevInfoStruct;
    DWORD DevInfoStructSize;
} DIRECT3DDEVICE8GETINFOMETHODVALUE, * LPDIRECT3DDEVICE8GETINFOMETHODVALUE;

typedef struct Direct3DDevice8SetPaletteEntriesMethodValue
{
    UINT PaletteNumber;
    CONST PALETTEENTRY* Entries;
} DIRECT3DDEVICE8SETPALETTEENTRIESMETHODVALUE, * LPDIRECT3DDEVICE8SETPALETTEENTRIESMETHODVALUE;

typedef struct Direct3DDevice8GetPaletteEntriesMethodValue
{
    UINT PaletteNumber;
    PALETTEENTRY* Entries;
} DIRECT3DDEVICE8GETPALETTEENTRIESMETHODVALUE, * LPDIRECT3DDEVICE8GETPALETTEENTRIESMETHODVALUE;

typedef struct Direct3DDevice8SetCurrentTexturePaletteMethodValue
{
    UINT PaletteNumber;
} DIRECT3DDEVICE8SETCURRENTTEXTUREPALETTEMETHODVALUE, * LPDIRECT3DDEVICE8SETCURRENTTEXTUREPALETTEMETHODVALUE;

typedef struct Direct3DDevice8GetCurrentTexturePaletteMethodValue
{
    UINT* PaletteNumber;
} DIRECT3DDEVICE8GETCURRENTTEXTUREPALETTEMETHODVALUE, * LPDIRECT3DDEVICE8GETCURRENTTEXTUREPALETTEMETHODVALUE;

typedef struct Direct3DDevice8DrawPrimitiveMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    UINT StartVertex;
    UINT PrimitiveCount;
} DIRECT3DDEVICE8DRAWPRIMITIVEMETHODVALUE, * LPDIRECT3DDEVICE8DRAWPRIMITIVEMETHODVALUE;

typedef struct Direct3DDevice8DrawIndexedPrimitiveMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    UINT MinIndex;
    UINT NumVertices;
    UINT StartIndex;
    UINT PrimitiveCount;
} DIRECT3DDEVICE8DRAWINDEXEDPRIMITIVEMETHODVALUE, * LPDIRECT3DDEVICE8DRAWINDEXEDPRIMITIVEMETHODVALUE;

typedef struct Direct3DDevice8DrawPrimitiveUPMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    UINT PrimitiveCount;
    LPCVOID VertexStreamZeroData;
    UINT VertexStreamZeroStride;
} DIRECT3DDEVICE8DRAWPRIMITIVEUPMETHODVALUE, * LPDIRECT3DDEVICE8DRAWPRIMITIVEUPMETHODVALUE;

typedef struct Direct3DDevice8DrawIndexedPrimitiveUPMethodValue
{
    D3DPRIMITIVETYPE PrimitiveType;
    UINT MinVertexIndex;
    UINT NumVertexIndices;
    UINT PrimitiveCount;
    LPCVOID IndexData;
    D3DFORMAT IndexDataFormat;
    LPCVOID VertexStreamZeroData;
    UINT VertexStreamZeroStride;
} DIRECT3DDEVICE8DRAWINDEXEDPRIMITIVEUPMETHODVALUE, * LPDIRECT3DDEVICE8DRAWINDEXEDPRIMITIVEUPMETHODVALUE;

typedef struct Direct3DDevice8ProcessVerticesMethodValue
{
    UINT SrcStartIndex;
    UINT DestIndex;
    UINT VertexCount;
    LPDIRECT3DVERTEXBUFFER8 DestBuffer;
    DWORD Options;
} DIRECT3DDEVICE8PROCESSVERTICESMETHODVALUE, * LPDIRECT3DDEVICE8PROCESSVERTICESMETHODVALUE;

typedef struct Direct3DDevice8CreateVertexShaderMethodValue
{
    CONST DWORD* Declaration;
    CONST DWORD* Function;
    DWORD* Handle;
    DWORD Usage;
} DIRECT3DDEVICE8CREATEVERTEXSHADERMETHODVALUE, * LPDIRECT3DDEVICE8CREATEVERTEXSHADERMETHODVALUE;

typedef struct Direct3DDevice8SetVertexShaderMethodValue
{
    DWORD Handle;
} DIRECT3DDEVICE8SETVERTEXSHADERMETHODVALUE, * LPDIRECT3DDEVICE8SETVERTEXSHADERMETHODVALUE;

typedef struct Direct3DDevice8GetVertexShaderMethodValue
{
    DWORD* Handle;
} DIRECT3DDEVICE8GETVERTEXSHADERMETHODVALUE, * LPDIRECT3DDEVICE8GETVERTEXSHADERMETHODVALUE;

typedef struct Direct3DDevice8DeleteVertexShaderMethodValue
{
    DWORD Handle;
} DIRECT3DDEVICE8DELETEVERTEXSHADERMETHODVALUE, * LPDIRECT3DDEVICE8DELETEVERTEXSHADERMETHODVALUE;

typedef struct Direct3DDevice8SetVertexShaderConstantMethodValue
{
    DWORD Register;
    LPCVOID ConstantData;
    DWORD ConstantCount;
} DIRECT3DDEVICE8SETVERTEXSHADERCONSTANTMETHODVALUE, * LPDIRECT3DDEVICE8SETVERTEXSHADERCONSTANTMETHODVALUE;

typedef struct Direct3DDevice8GetVertexShaderConstantMethodValue
{
    DWORD Register;
    LPVOID ConstantData;
    DWORD ConstantCount;
} DIRECT3DDEVICE8GETVERTEXSHADERCONSTANTMETHODVALUE, * LPDIRECT3DDEVICE8GETVERTEXSHADERCONSTANTMETHODVALUE;

typedef struct Direct3DDevice8GetVertexShaderDeclarationMethodValue
{
    DWORD Handle;
    LPVOID Data;
    DWORD* SizeOfData;
} DIRECT3DDEVICE8GETVERTEXSHADERDECLARATIONMETHODVALUE, * LPDIRECT3DDEVICE8GETVERTEXSHADERDECLARATIONMETHODVALUE;

typedef struct Direct3DDevice8GetVertexShaderFunctionMethodValue
{
    DWORD Handle;
    LPVOID Data;
    DWORD* SizeOfData;
} DIRECT3DDEVICE8GETVERTEXSHADERFUNCTIONMETHODVALUE, * LPDIRECT3DDEVICE8GETVERTEXSHADERFUNCTIONMETHODVALUE;

typedef struct Direct3DDevice8SetStreamSourceMethodValue
{
    UINT StreamNumber;
    LPDIRECT3DVERTEXBUFFER8 StreamData;
    UINT Stride;
} DIRECT3DDEVICE8SETSTREAMSOURCEMETHODVALUE, * LPDIRECT3DDEVICE8SETSTREAMSOURCEMETHODVALUE;

typedef struct Direct3DDevice8GetStreamSourceMethodValue
{
    UINT StreamNumber;
    LPDIRECT3DVERTEXBUFFER8* StreamData;
    UINT* Stride;
} DIRECT3DDEVICE8GETSTREAMSOURCEMETHODVALUE, * LPDIRECT3DDEVICE8GETSTREAMSOURCEMETHODVALUE;

typedef struct Direct3DDevice8SetIndicesMethodValue
{
    LPDIRECT3DINDEXBUFFER8 IndexData;
    UINT BaseVertexIndex;
} DIRECT3DDEVICE8SETINDICESMETHODVALUE, * LPDIRECT3DDEVICE8SETINDICESMETHODVALUE;

typedef struct Direct3DDevice8GetIndicesMethodValue
{
    LPDIRECT3DINDEXBUFFER8* IndexData;
    UINT* BaseVertexIndex;
} DIRECT3DDEVICE8GETINDICESMETHODVALUE, * LPDIRECT3DDEVICE8GETINDICESMETHODVALUE;

typedef struct Direct3DDevice8CreatePixelShaderMethodValue
{
    CONST DWORD* Function;
    DWORD* Handle;
} DIRECT3DDEVICE8CREATEPIXELSHADERMETHODVALUE, * LPDIRECT3DDEVICE8CREATEPIXELSHADERMETHODVALUE;

typedef struct Direct3DDevice8SetPixelShaderMethodValue
{
    DWORD Handle;
} DIRECT3DDEVICE8SETPIXELSHADERMETHODVALUE, * LPDIRECT3DDEVICE8SETPIXELSHADERMETHODVALUE;

typedef struct Direct3DDevice8GetPixelShaderMethodValue
{
    DWORD* Handle;
} DIRECT3DDEVICE8GETPIXELSHADERMETHODVALUE, * LPDIRECT3DDEVICE8GETPIXELSHADERMETHODVALUE;

typedef struct Direct3DDevice8DeletePixelShaderMethodValue
{
    DWORD Handle;
} DIRECT3DDEVICE8DELETEPIXELSHADERMETHODVALUE, * LPDIRECT3DDEVICE8DELETEPIXELSHADERMETHODVALUE;

typedef struct Direct3DDevice8SetPixelShaderConstantMethodValue
{
    DWORD Register;
    LPCVOID ConstantData;
    DWORD ConstantCount;
} DIRECT3DDEVICE8SETPIXELSHADERCONSTANTMETHODVALUE, * LPDIRECT3DDEVICE8SETPIXELSHADERCONSTANTMETHODVALUE;

typedef struct Direct3DDevice8GetPixelShaderConstantMethodValue
{
    DWORD Register;
    LPVOID ConstantData;
    DWORD ConstantCount;
} DIRECT3DDEVICE8GETPIXELSHADERCONSTANTMETHODVALUE, * LPDIRECT3DDEVICE8GETPIXELSHADERCONSTANTMETHODVALUE;

typedef struct Direct3DDevice8GetPixelShaderFunctionMethodValue
{
    DWORD Handle;
    LPVOID Data;
    DWORD* SizeOfData;
} DIRECT3DDEVICE8GETPIXELSHADERFUNCTIONMETHODVALUE, * LPDIRECT3DDEVICE8GETPIXELSHADERFUNCTIONMETHODVALUE;

typedef struct Direct3DDevice8DrawRectPatchMethodValue
{
    UINT Handle;
    CONST FLOAT* NumSegs;
    CONST D3DRECTPATCH_INFO* RectPatchInfo;
} DIRECT3DDEVICE8DRAWRECTPATCHMETHODVALUE, * LPDIRECT3DDEVICE8DRAWRECTPATCHMETHODVALUE;

typedef struct Direct3DDevice8DrawTriPatchMethodValue
{
    UINT Handle;
    CONST FLOAT* NumSegs;
    CONST D3DTRIPATCH_INFO* TriPatchInfo;
} DIRECT3DDEVICE8DRAWTRIPATCHMETHODVALUE, * LPDIRECT3DDEVICE8DRAWTRIPATCHMETHODVALUE;

typedef struct Direct3DDevice8DeletePatchMethodValue
{
    UINT Handle;
} DIRECT3DDEVICE8DELETEPATCHMETHODVALUE, * LPDIRECT3DDEVICE8DELETEPATCHMETHODVALUE;
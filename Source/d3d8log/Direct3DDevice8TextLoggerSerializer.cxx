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

#include "AgentLogger.hxx"
#include "Direct3DDevice8Logger.hxx"
#include "Direct3DDevice8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(Direct3DDevice8, QueryInterface);                 \
        A(Direct3DDevice8, AddRef);                         \
        A(Direct3DDevice8, Release);                        \
        A(Direct3DDevice8, TestCooperativeLevel);           \
        A(Direct3DDevice8, GetAvailableTextureMem);         \
        A(Direct3DDevice8, ResourceManagerDiscardBytes);    \
        A(Direct3DDevice8, GetDirect3D);                    \
        A(Direct3DDevice8, GetDeviceCaps);                  \
        A(Direct3DDevice8, GetDisplayMode);                 \
        A(Direct3DDevice8, GetCreationParameters);          \
        A(Direct3DDevice8, SetCursorProperties);            \
        A(Direct3DDevice8, SetCursorPosition);              \
        A(Direct3DDevice8, ShowCursor);                     \
        A(Direct3DDevice8, CreateAdditionalSwapChain);      \
        A(Direct3DDevice8, Reset);                          \
        A(Direct3DDevice8, Present);                        \
        A(Direct3DDevice8, GetBackBuffer);                  \
        A(Direct3DDevice8, GetRasterStatus);                \
        A(Direct3DDevice8, SetGammaRamp);                   \
        A(Direct3DDevice8, GetGammaRamp);                   \
        A(Direct3DDevice8, CreateTexture);                  \
        A(Direct3DDevice8, CreateVolumeTexture);            \
        A(Direct3DDevice8, CreateCubeTexture);              \
        A(Direct3DDevice8, CreateVertexBuffer);             \
        A(Direct3DDevice8, CreateIndexBuffer);              \
        A(Direct3DDevice8, CreateRenderTarget);             \
        A(Direct3DDevice8, CreateDepthStencilSurface);      \
        A(Direct3DDevice8, CreateImageSurface);             \
        A(Direct3DDevice8, CopyRects);                      \
        A(Direct3DDevice8, UpdateTexture);                  \
        A(Direct3DDevice8, GetFrontBuffer);                 \
        A(Direct3DDevice8, SetRenderTarget);                \
        A(Direct3DDevice8, GetRenderTarget);                \
        A(Direct3DDevice8, GetDepthStencilSurface);         \
        A(Direct3DDevice8, BeginScene);                     \
        A(Direct3DDevice8, EndScene);                       \
        A(Direct3DDevice8, Clear);                          \
        A(Direct3DDevice8, SetTransform);                   \
        A(Direct3DDevice8, GetTransform);                   \
        A(Direct3DDevice8, MultiplyTransform);              \
        A(Direct3DDevice8, SetViewport);                    \
        A(Direct3DDevice8, GetViewport);                    \
        A(Direct3DDevice8, SetMaterial);                    \
        A(Direct3DDevice8, GetMaterial);                    \
        A(Direct3DDevice8, SetLight);                       \
        A(Direct3DDevice8, GetLight);                       \
        A(Direct3DDevice8, LightEnable);                    \
        A(Direct3DDevice8, GetLightEnable);                 \
        A(Direct3DDevice8, SetClipPlane);                   \
        A(Direct3DDevice8, GetClipPlane);                   \
        A(Direct3DDevice8, SetRenderState);                 \
        A(Direct3DDevice8, GetRenderState);                 \
        A(Direct3DDevice8, BeginStateBlock);                \
        A(Direct3DDevice8, EndStateBlock);                  \
        A(Direct3DDevice8, ApplyStateBlock);                \
        A(Direct3DDevice8, CaptureStateBlock);              \
        A(Direct3DDevice8, DeleteStateBlock);               \
        A(Direct3DDevice8, CreateStateBlock);               \
        A(Direct3DDevice8, SetClipStatus);                  \
        A(Direct3DDevice8, GetClipStatus);                  \
        A(Direct3DDevice8, GetTexture);                     \
        A(Direct3DDevice8, SetTexture);                     \
        A(Direct3DDevice8, GetTextureStageState);           \
        A(Direct3DDevice8, SetTextureStageState);           \
        A(Direct3DDevice8, ValidateDevice);                 \
        A(Direct3DDevice8, GetInfo);                        \
        A(Direct3DDevice8, SetPaletteEntries);              \
        A(Direct3DDevice8, GetPaletteEntries);              \
        A(Direct3DDevice8, SetCurrentTexturePalette);       \
        A(Direct3DDevice8, GetCurrentTexturePalette);       \
        A(Direct3DDevice8, DrawPrimitive);                  \
        A(Direct3DDevice8, DrawIndexedPrimitive);           \
        A(Direct3DDevice8, DrawPrimitiveUP);                \
        A(Direct3DDevice8, DrawIndexedPrimitiveUP);         \
        A(Direct3DDevice8, ProcessVertices);                \
        A(Direct3DDevice8, CreateVertexShader);             \
        A(Direct3DDevice8, SetVertexShader);                \
        A(Direct3DDevice8, GetVertexShader);                \
        A(Direct3DDevice8, DeleteVertexShader);             \
        A(Direct3DDevice8, SetVertexShaderConstant);        \
        A(Direct3DDevice8, GetVertexShaderConstant);        \
        A(Direct3DDevice8, GetVertexShaderDeclaration);     \
        A(Direct3DDevice8, GetVertexShaderFunction);        \
        A(Direct3DDevice8, SetStreamSource);                \
        A(Direct3DDevice8, GetStreamSource);                \
        A(Direct3DDevice8, SetIndices);                     \
        A(Direct3DDevice8, GetIndices);                     \
        A(Direct3DDevice8, CreatePixelShader);              \
        A(Direct3DDevice8, SetPixelShader);                 \
        A(Direct3DDevice8, GetPixelShader);                 \
        A(Direct3DDevice8, DeletePixelShader);              \
        A(Direct3DDevice8, SetPixelShaderConstant);         \
        A(Direct3DDevice8, GetPixelShaderConstant);         \
        A(Direct3DDevice8, GetPixelShaderFunction);         \
        A(Direct3DDevice8, DrawRectPatch);                  \
        A(Direct3DDevice8, DrawTriPatch);                   \
        A(Direct3DDevice8, DeletePatch);                    \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDevice8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDevice8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice8TestCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8TESTCOOPERATIVELEVELMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice8GetAvailableTextureMemValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETAVAILABLETEXTUREMEMMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice8ResourceManagerDiscardBytesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8RESOURCEMANAGERDISCARDBYTESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Bytes); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetDirect3DValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETDIRECT3DMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->D3D8); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetDeviceCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETDEVICECAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Mode /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetCreationParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETCREATIONPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Params /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetCursorPropertiesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETCURSORPROPERTIESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatObject, value->Cursor); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetCursorPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETCURSORPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8ShowCursorValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SHOWCURSORMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Show); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateAdditionalSwapChainValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATEADDITIONALSWAPCHAINMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->PresentationParameters /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->SwapChain); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8ResetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8RESETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->PresentationParameters /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8PresentValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8PRESENTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->SourceRect);
    FORMATVALUE(builder, TextFormatObject, value->DestRect);
    FORMATVALUE(builder, TextFormatWindow, value->Window); 
    FORMATVALUE(builder, TextFormatObject, value->Region); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetBackBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETBACKBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->BackBuffer); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetRasterStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETRASTERSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->RasterStatus /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetGammaRampValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETGAMMARAMPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatObject, value->Ramp /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetGammaRampValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETGAMMARAMPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Ramp /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATETEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Levels);
    FORMATVALUE(builder, TextFormatValue, value->Usage);
    FORMATVALUE(builder, TextFormatValue, value->Format);
    FORMATVALUE(builder, TextFormatValue, value->Pool);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateVolumeTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATEVOLUMETEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Depth);
    FORMATVALUE(builder, TextFormatValue, value->Levels);
    FORMATVALUE(builder, TextFormatValue, value->Usage /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Pool /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateCubeTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATECUBETEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->EdgeLength);
    FORMATVALUE(builder, TextFormatValue, value->Levels);
    FORMATVALUE(builder, TextFormatValue, value->Usage);
    FORMATVALUE(builder, TextFormatValue, value->Format);
    FORMATVALUE(builder, TextFormatValue, value->Pool);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateVertexBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATEVERTEXBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Length);
    FORMATVALUE(builder, TextFormatValue, value->Usage);
    FORMATVALUE(builder, TextFormatValue, value->FVF /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Pool /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Buffer); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateIndexBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATEINDEXBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Length);
    FORMATVALUE(builder, TextFormatValue, value->Usage /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Pool /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Buffer); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATERENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->MultiSample /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Lockable);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateDepthStencilSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATEDEPTHSTENCILSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->MultiSample /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateImageSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATEIMAGESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CopyRectsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8COPYRECTSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->SourceSurface);
    FORMATVALUE(builder, TextFormatObject, value->SourceRectsArray /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Rects);
    FORMATVALUE(builder, TextFormatObject, value->DestinationSurface);
    FORMATVALUE(builder, TextFormatObject, value->DestPointsArray /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8UpdateTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8UPDATETEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->SourceTexture);
    FORMATVALUE(builder, TextFormatObject, value->DestinationTexture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetFrontBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETFRONTBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DestSurface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETRENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->RenderTarget);
    FORMATVALUE(builder, TextFormatObject, value->NewZStencil); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETRENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->RenderTarget); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetDepthStencilSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETDEPTHSTENCILSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ZStencilSurface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8BeginSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8BEGINSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice8EndSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8ENDSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice8ClearValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CLEARMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Rects /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Color);
    FORMATVALUE(builder, TextFormatValue, value->Z); 
    FORMATVALUE(builder, TextFormatValue, value->Stencil /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->State /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->State /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8MultiplyTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8MULTIPLYTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->State /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Viewport /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Viewport /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatObject, value->Light /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatObject, value->Light /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8LightEnableValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8LIGHTENABLEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatValue, value->Enable); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetLightEnableValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETLIGHTENABLEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatValue, value->Enable); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetClipPlaneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETCLIPPLANEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatObject, value->Plane /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetClipPlaneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETCLIPPLANEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatObject, value->Plane /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetRenderStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETRENDERSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->State /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetRenderStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETRENDERSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->State /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8BeginStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8BEGINSTATEBLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice8EndStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8ENDSTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Token); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8ApplyStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8APPLYSTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Token); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CaptureStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CAPTURESTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Token); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DeleteStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DELETESTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Token); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATESTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Token); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetClipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETCLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ClipStatus /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetClipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETCLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ClipStatus /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETTEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETTEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetTextureStageStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETTEXTURESTAGESTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetTextureStageStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETTEXTURESTAGESTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8ValidateDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8VALIDATEDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->NumPasses); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetInfoValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETINFOMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->DevInfoID);
    FORMATVALUE(builder, TextFormatObject, value->DevInfoStruct /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->DevInfoStructSize); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetPaletteEntriesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETPALETTEENTRIESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PaletteNumber);
    FORMATVALUE(builder, TextFormatObject, value->Entries /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetPaletteEntriesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETPALETTEENTRIESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PaletteNumber);
    FORMATVALUE(builder, TextFormatObject, value->Entries /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetCurrentTexturePaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETCURRENTTEXTUREPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PaletteNumber); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetCurrentTexturePaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETCURRENTTEXTUREPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PaletteNumber); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DrawPrimitiveValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DRAWPRIMITIVEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->StartVertex);
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveCount); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DrawIndexedPrimitiveValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DRAWINDEXEDPRIMITIVEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->MinIndex);
    FORMATVALUE(builder, TextFormatValue, value->NumVertices);
    FORMATVALUE(builder, TextFormatValue, value->StartIndex);
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveCount); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DrawPrimitiveUPValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DRAWPRIMITIVEUPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveCount);
    FORMATVALUE(builder, TextFormatObject, value->VertexStreamZeroData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexStreamZeroStride); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DrawIndexedPrimitiveUPValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DRAWINDEXEDPRIMITIVEUPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->MinVertexIndex);
    FORMATVALUE(builder, TextFormatValue, value->NumVertexIndices);
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveCount);
    FORMATVALUE(builder, TextFormatObject, value->IndexData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->IndexDataFormat /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->VertexStreamZeroData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexStreamZeroStride); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8ProcessVerticesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8PROCESSVERTICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->SrcStartIndex);
    FORMATVALUE(builder, TextFormatValue, value->DestIndex);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatObject, value->DestBuffer /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreateVertexShaderValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATEVERTEXSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Declaration /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Function /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatValue, value->Usage /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetVertexShaderValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETVERTEXSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetVertexShaderValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETVERTEXSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DeleteVertexShaderValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DELETEVERTEXSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetVertexShaderConstantValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETVERTEXSHADERCONSTANTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Register);
    FORMATVALUE(builder, TextFormatObject, value->ConstantData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->ConstantCount); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetVertexShaderConstantValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETVERTEXSHADERCONSTANTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Register);
    FORMATVALUE(builder, TextFormatObject, value->ConstantData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->ConstantCount); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetVertexShaderDeclarationValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETVERTEXSHADERDECLARATIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatObject, value->SizeOfData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SizeOfData); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetVertexShaderFunctionValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETVERTEXSHADERFUNCTIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatObject, value->SizeOfData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SizeOfData); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetStreamSourceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETSTREAMSOURCEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->StreamNumber);
    FORMATVALUE(builder, TextFormatObject, value->StreamData);
    FORMATVALUE(builder, TextFormatValue, value->Stride); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetStreamSourceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETSTREAMSOURCEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->StreamNumber);
    FORMATVALUE(builder, TextFormatObject, value->StreamData);
    FORMATVALUE(builder, TextFormatValue, value->Stride); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetIndicesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETINDICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->IndexData);
    FORMATVALUE(builder, TextFormatValue, value->BaseVertexIndex); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetIndicesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETINDICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->IndexData);
    FORMATVALUE(builder, TextFormatValue, value->BaseVertexIndex); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8CreatePixelShaderValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8CREATEPIXELSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Function /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetPixelShaderValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETPIXELSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetPixelShaderValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETPIXELSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DeletePixelShaderValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DELETEPIXELSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8SetPixelShaderConstantValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8SETPIXELSHADERCONSTANTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Register); 
    FORMATVALUE(builder, TextFormatObject, value->ConstantData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->ConstantCount); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetPixelShaderConstantValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETPIXELSHADERCONSTANTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Register);
    FORMATVALUE(builder, TextFormatObject, value->ConstantData /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->ConstantCount); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8GetPixelShaderFunctionValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8GETPIXELSHADERFUNCTIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SizeOfData); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DrawRectPatchValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DRAWRECTPATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatObject, value->NumSegs /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->RectPatchInfo /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DrawTriPatchValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DRAWTRIPATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatObject, value->NumSegs /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->TriPatchInfo /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice8DeletePatchValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE8DELETEPATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DDevice8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DDevice8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DDevice8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
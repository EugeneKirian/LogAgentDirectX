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
#include "Direct3DDevice7Logger.hxx"
#include "Direct3DDevice7TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(Direct3DDevice7, QueryInterface);                 \
        A(Direct3DDevice7, AddRef);                         \
        A(Direct3DDevice7, Release);                        \
        A(Direct3DDevice7, GetCaps);                        \
        A(Direct3DDevice7, EnumTextureFormats);             \
        A(Direct3DDevice7, BeginScene);                     \
        A(Direct3DDevice7, EndScene);                       \
        A(Direct3DDevice7, GetDirect3D);                    \
        A(Direct3DDevice7, SetRenderTarget);                \
        A(Direct3DDevice7, GetRenderTarget);                \
        A(Direct3DDevice7, Clear);                          \
        A(Direct3DDevice7, SetTransform);                   \
        A(Direct3DDevice7, GetTransform);                   \
        A(Direct3DDevice7, SetViewport);                    \
        A(Direct3DDevice7, MultiplyTransform);              \
        A(Direct3DDevice7, GetViewport);                    \
        A(Direct3DDevice7, SetMaterial);                    \
        A(Direct3DDevice7, GetMaterial);                    \
        A(Direct3DDevice7, SetLight);                       \
        A(Direct3DDevice7, GetLight);                       \
        A(Direct3DDevice7, SetRenderState);                 \
        A(Direct3DDevice7, GetRenderState);                 \
        A(Direct3DDevice7, BeginStateBlock);                \
        A(Direct3DDevice7, EndStateBlock);                  \
        A(Direct3DDevice7, PreLoad);                        \
        A(Direct3DDevice7, DrawPrimitive);                  \
        A(Direct3DDevice7, DrawIndexedPrimitive);           \
        A(Direct3DDevice7, SetClipStatus);                  \
        A(Direct3DDevice7, GetClipStatus);                  \
        A(Direct3DDevice7, DrawPrimitiveStrided);           \
        A(Direct3DDevice7, DrawIndexedPrimitiveStrided);    \
        A(Direct3DDevice7, DrawPrimitiveVB);                \
        A(Direct3DDevice7, DrawIndexedPrimitiveVB);         \
        A(Direct3DDevice7, ComputeSphereVisibility);        \
        A(Direct3DDevice7, GetTexture);                     \
        A(Direct3DDevice7, SetTexture);                     \
        A(Direct3DDevice7, GetTextureStageState);           \
        A(Direct3DDevice7, SetTextureStageState);           \
        A(Direct3DDevice7, ValidateDevice);                 \
        A(Direct3DDevice7, ApplyStateBlock);                \
        A(Direct3DDevice7, CaptureStateBlock);              \
        A(Direct3DDevice7, DeleteStateBlock);               \
        A(Direct3DDevice7, CreateStateBlock);               \
        A(Direct3DDevice7, Load);                           \
        A(Direct3DDevice7, LightEnable);                    \
        A(Direct3DDevice7, GetLightEnable);                 \
        A(Direct3DDevice7, SetClipPlane);                   \
        A(Direct3DDevice7, GetClipPlane);                   \
        A(Direct3DDevice7, GetInfo);                        \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDevice7MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDevice7QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice7ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice7GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7EnumTextureFormatsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7ENUMTEXTUREFORMATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7BeginSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7BEGINSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice7EndSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7ENDSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice7GetDirect3DValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETDIRECT3DMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETRENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETRENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7ClearValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7CLEARMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Rects /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Color);
    FORMATVALUE(builder, TextFormatValue, value->Z);
    FORMATVALUE(builder, TextFormatValue, value->Stencil); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7MultiplyTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7MULTIPLYTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatObject, value->Light /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatObject, value->Light /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetRenderStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETRENDERSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->RenderStateType);
    FORMATVALUE(builder, TextFormatValue, value->RenderState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetRenderStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETRENDERSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->RenderStateType);
    FORMATVALUE(builder, TextFormatValue, value->RenderState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7BeginStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7BEGINSTATEBLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice7EndStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7ENDSTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7PreLoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7PRELOADMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7DrawPrimitiveValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7DRAWPRIMITIVEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->Vertices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7DrawIndexedPrimitiveValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7DRAWINDEXEDPRIMITIVEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->Vertices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatObject, value->Indices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->IndexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetClipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETCLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Status /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetClipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETCLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Status /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7DrawPrimitiveStridedValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7DRAWPRIMITIVESTRIDEDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->VertexArray /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7DrawIndexedPrimitiveStridedValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7DRAWINDEXEDPRIMITIVESTRIDEDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->VertexArray /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatObject, value->Indices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->IndexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7DrawPrimitiveVBValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7DRAWPRIMITIVEVBMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatObject, value->Buffer /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->StartVertex);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7DrawIndexedPrimitiveVBValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7DRAWINDEXEDPRIMITIVEVBMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatObject, value->Buffer /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Indices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->IndexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7ComputeSphereVisibilityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7COMPUTESPHEREVISIBILITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Centers /* TODO*/);
    FORMATVALUE(builder, TextFormatObject, value->Radii /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ReturnValues /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETTEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETTEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetTextureStageStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETTEXTURESTAGESTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatValue, value->State);
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetTextureStageStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETTEXTURESTAGESTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatValue, value->State);
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7ValidateDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7VALIDATEDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Passes /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7ApplyStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7APPLYSTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7CaptureStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7CAPTURESTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7DeleteStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7DELETESTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7CreateStateBlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7CREATESTATEBLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Type);
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7LoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7LOADMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Destination);
    FORMATVALUE(builder, TextFormatObject, value->Point /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Source);
    FORMATVALUE(builder, TextFormatObject, value->Rect /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7LightEnableValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7LIGHTENABLEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatValue, value->Enable); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetLightEnableValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETLIGHTENABLEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatValue, value->Enable); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7SetClipPlaneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7SETCLIPPLANEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatObject, value->Plane /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetClipPlaneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETCLIPPLANEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatObject, value->Plane /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice7GetInfoValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7GETINFOMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DDevice7MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                              \
    switch (ID)                                 \
    {                                           \
        A(Direct3DDevice7, EnumTextureFormats); \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDevice7MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDevice7EnumTextureFormatsCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE7ENUMTEXTUREFORMATSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirect3DDevice7MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}
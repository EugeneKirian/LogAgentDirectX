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
#include "Direct3DDevice3Logger.hxx"
#include "Direct3DDevice3TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(Direct3DDevice3, QueryInterface);                 \
        A(Direct3DDevice3, AddRef);                         \
        A(Direct3DDevice3, Release);                        \
        A(Direct3DDevice3, GetCaps);                        \
        A(Direct3DDevice3, GetStats);                       \
        A(Direct3DDevice3, AddViewport);                    \
        A(Direct3DDevice3, DeleteViewport);                 \
        A(Direct3DDevice3, NextViewport);                   \
        A(Direct3DDevice3, EnumTextureFormats);             \
        A(Direct3DDevice3, BeginScene);                     \
        A(Direct3DDevice3, EndScene);                       \
        A(Direct3DDevice3, GetDirect3D);                    \
        A(Direct3DDevice3, SetCurrentViewport);             \
        A(Direct3DDevice3, GetCurrentViewport);             \
        A(Direct3DDevice3, SetRenderTarget);                \
        A(Direct3DDevice3, GetRenderTarget);                \
        A(Direct3DDevice3, Begin);                          \
        A(Direct3DDevice3, BeginIndexed);                   \
        A(Direct3DDevice3, Vertex);                         \
        A(Direct3DDevice3, Index);                          \
        A(Direct3DDevice3, End);                            \
        A(Direct3DDevice3, GetRenderState);                 \
        A(Direct3DDevice3, SetRenderState);                 \
        A(Direct3DDevice3, GetLightState);                  \
        A(Direct3DDevice3, SetLightState);                  \
        A(Direct3DDevice3, SetTransform);                   \
        A(Direct3DDevice3, GetTransform);                   \
        A(Direct3DDevice3, MultiplyTransform);              \
        A(Direct3DDevice3, DrawPrimitive);                  \
        A(Direct3DDevice3, DrawIndexedPrimitive);           \
        A(Direct3DDevice3, SetClipStatus);                  \
        A(Direct3DDevice3, GetClipStatus);                  \
        A(Direct3DDevice3, DrawPrimitiveStrided);           \
        A(Direct3DDevice3, DrawIndexedPrimitiveStrided);    \
        A(Direct3DDevice3, DrawPrimitiveVB);                \
        A(Direct3DDevice3, DrawIndexedPrimitiveVB);         \
        A(Direct3DDevice3, ComputeSphereVisibility);        \
        A(Direct3DDevice3, GetTexture);                     \
        A(Direct3DDevice3, SetTexture);                     \
        A(Direct3DDevice3, GetTextureStageState);           \
        A(Direct3DDevice3, SetTextureStageState);           \
        A(Direct3DDevice3, ValidateDevice)                  \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDevice3MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDevice3QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice3ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice3GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->HardwareDescriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDescriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetStatsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETSTATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Statistics /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3AddViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3ADDVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3DeleteViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3DELETEVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3NextViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3NEXTVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort);
    FORMATVALUE(builder, TextFormatObject, value->NextViewPort);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3EnumTextureFormatsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3ENUMTEXTUREFORMATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3BeginSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3BEGINSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice3EndSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3ENDSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice3GetDirect3DValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETDIRECT3DMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3SetCurrentViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3SETCURRENTVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetCurrentViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETCURRENTVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3SetRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3SETRENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETRENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3BeginValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3BEGINMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3BeginIndexedValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3BEGININDEXEDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->Vertices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3VertexValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3VERTEXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Vertex /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3IndexValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3INDEXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3EndValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3ENDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetRenderStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETRENDERSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->RenderStateType);
    FORMATVALUE(builder, TextFormatValue, value->RenderState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3SetRenderStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3SETRENDERSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->RenderStateType);
    FORMATVALUE(builder, TextFormatValue, value->RenderState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetLightStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETLIGHTSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->LightStateType);
    FORMATVALUE(builder, TextFormatValue, value->LightState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3SetLightStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3SETLIGHTSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->LightStateType);
    FORMATVALUE(builder, TextFormatValue, value->LightState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3SetTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3SETTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3MultiplyTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3MULTIPLYTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3DrawPrimitiveValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3DRAWPRIMITIVEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->Vertices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3DrawIndexedPrimitiveValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3DRAWINDEXEDPRIMITIVEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->Vertices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatObject, value->Indices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->IndexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3SetClipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3SETCLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Status /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetClipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETCLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Status /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3DrawPrimitiveStridedValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3DRAWPRIMITIVESTRIDEDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->VertexArray /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3DrawIndexedPrimitiveStridedValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3DRAWINDEXEDPRIMITIVESTRIDEDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->VertexArray /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatObject, value->Indices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->IndexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3DrawPrimitiveVBValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3DRAWPRIMITIVEVBMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatObject, value->Buffer /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->StartVertex);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3DrawIndexedPrimitiveVBValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3DRAWINDEXEDPRIMITIVEVBMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatObject, value->Buffer /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Indices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->IndexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3ComputeSphereVisibilityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3COMPUTESPHEREVISIBILITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Centers /* TODO*/);
    FORMATVALUE(builder, TextFormatObject, value->Radii /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ReturnValues /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETTEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3SetTextureValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3SETTEXTUREMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3GetTextureStageStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3GETTEXTURESTAGESTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatValue, value->State);
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3SetTextureStageStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3SETTEXTURESTAGESTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Stage);
    FORMATVALUE(builder, TextFormatValue, value->State);
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice3ValidateDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3VALIDATEDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Passes /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DDevice3MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                              \
    switch (ID)                                 \
    {                                           \
        A(Direct3DDevice3, EnumTextureFormats); \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDevice3MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDevice3EnumTextureFormatsCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE3ENUMTEXTUREFORMATSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirect3DDevice3MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}
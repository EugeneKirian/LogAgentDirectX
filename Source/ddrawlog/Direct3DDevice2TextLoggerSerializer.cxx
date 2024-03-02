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
#include "Direct3DDevice2Logger.hxx"
#include "Direct3DDevice2TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DDevice2, QueryInterface);         \
        A(Direct3DDevice2, AddRef);                 \
        A(Direct3DDevice2, Release);                \
        A(Direct3DDevice2, GetCaps);                \
        A(Direct3DDevice2, SwapTextureHandles);     \
        A(Direct3DDevice2, GetStats);               \
        A(Direct3DDevice2, AddViewport);            \
        A(Direct3DDevice2, DeleteViewport);         \
        A(Direct3DDevice2, NextViewport);           \
        A(Direct3DDevice2, EnumTextureFormats);     \
        A(Direct3DDevice2, BeginScene);             \
        A(Direct3DDevice2, EndScene);               \
        A(Direct3DDevice2, GetDirect3D);            \
        A(Direct3DDevice2, SetCurrentViewport);     \
        A(Direct3DDevice2, GetCurrentViewport);     \
        A(Direct3DDevice2, SetRenderTarget);        \
        A(Direct3DDevice2, GetRenderTarget);        \
        A(Direct3DDevice2, Begin);                  \
        A(Direct3DDevice2, BeginIndexed);           \
        A(Direct3DDevice2, Vertex);                 \
        A(Direct3DDevice2, Index);                  \
        A(Direct3DDevice2, End);                    \
        A(Direct3DDevice2, GetRenderState);         \
        A(Direct3DDevice2, SetRenderState);         \
        A(Direct3DDevice2, GetLightState);          \
        A(Direct3DDevice2, SetLightState);          \
        A(Direct3DDevice2, SetTransform);           \
        A(Direct3DDevice2, GetTransform);           \
        A(Direct3DDevice2, MultiplyTransform);      \
        A(Direct3DDevice2, DrawPrimitive);          \
        A(Direct3DDevice2, DrawIndexedPrimitive);   \
        A(Direct3DDevice2, SetClipStatus);          \
        A(Direct3DDevice2, GetClipStatus);          \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDevice2MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDevice2QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice2ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice2GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->HardwareDescriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDescriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2SwapTextureHandlesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2SWAPTEXTUREHANDLESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Texture1);
    FORMATVALUE(builder, TextFormatObject, value->Texture2); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2GetStatsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETSTATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Statistics /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2AddViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2ADDVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2DeleteViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2DELETEVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2NextViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2NEXTVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort);
    FORMATVALUE(builder, TextFormatObject, value->NextViewPort);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2EnumTextureFormatsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2ENUMTEXTUREFORMATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2BeginSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2BEGINSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice2EndSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2ENDSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDevice2GetDirect3DValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETDIRECT3DMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2SetCurrentViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2SETCURRENTVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2GetCurrentViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETCURRENTVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2SetRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2SETRENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2GetRenderTargetValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETRENDERTARGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2BeginValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2BEGINMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2BeginIndexedValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2BEGININDEXEDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->Vertices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2VertexValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2VERTEXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Vertex /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2IndexValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2INDEXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2EndValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2ENDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2GetRenderStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETRENDERSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->RenderStateType);
    FORMATVALUE(builder, TextFormatValue, value->RenderState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2SetRenderStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2SETRENDERSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->RenderStateType);
    FORMATVALUE(builder, TextFormatValue, value->RenderState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2GetLightStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETLIGHTSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->LightStateType);
    FORMATVALUE(builder, TextFormatValue, value->LightState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2SetLightStateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2SETLIGHTSTATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->LightStateType);
    FORMATVALUE(builder, TextFormatValue, value->LightState); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2SetTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2SETTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2GetTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2MultiplyTransformValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2MULTIPLYTRANSFORMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->TransformStateType);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2DrawPrimitiveValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2DRAWPRIMITIVEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->Vertices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2DrawIndexedPrimitiveValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2DRAWINDEXEDPRIMITIVEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PrimitiveType);
    FORMATVALUE(builder, TextFormatValue, value->VertexType);
    FORMATVALUE(builder, TextFormatObject, value->Vertices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->VertexCount);
    FORMATVALUE(builder, TextFormatObject, value->Indices /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->IndexCount);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2SetClipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2SETCLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Status /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevice2GetClipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2GETCLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Status /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DDevice2MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                              \
    switch (ID)                                 \
    {                                           \
        A(Direct3DDevice2, EnumTextureFormats); \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDevice2MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDevice2EnumTextureFormatsCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICE2ENUMTEXTUREFORMATSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirect3DDevice2MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}
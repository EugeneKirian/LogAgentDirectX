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
#include "Direct3DViewportLogger.hxx"
#include "Direct3DViewportTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DViewport, QueryInterface);        \
        A(Direct3DViewport, AddRef);                \
        A(Direct3DViewport, Release);               \
        A(Direct3DViewport, Initialize);            \
        A(Direct3DViewport, GetViewport);           \
        A(Direct3DViewport, SetViewport);           \
        A(Direct3DViewport, TransformVertices);     \
        A(Direct3DViewport, LightElements);         \
        A(Direct3DViewport, SetBackground);         \
        A(Direct3DViewport, GetBackground);         \
        A(Direct3DViewport, SetBackgroundDepth);    \
        A(Direct3DViewport, GetBackgroundDepth);    \
        A(Direct3DViewport, Clear);                 \
        A(Direct3DViewport, AddLight);              \
        A(Direct3DViewport, DeleteLight);           \
        A(Direct3DViewport, NextLight);             \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DViewportMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DViewportQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DViewportReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DViewportInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportGetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTGETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportSetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTSETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportTransformVerticesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTTRANSFORMVERTICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Transform /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatValue, value->Offscreen) return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportLightElementsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTLIGHTELEMENTSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportSetBackgroundValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTSETBACKGROUNDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportGetBackgroundValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTGETBACKGROUNDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatValue, value->Valid); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportSetBackgroundDepthValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTSETBACKGROUNDDEPTHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportGetBackgroundDepthValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTGETBACKGROUNDDEPTHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Valid); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportClearValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTCLEARMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Rects /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportAddLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTADDLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportDeleteLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTDELETELIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewportNextLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORTNEXTLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light);
    FORMATVALUE(builder, TextFormatObject, value->NextLight);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DViewportMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DViewportMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DViewportMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
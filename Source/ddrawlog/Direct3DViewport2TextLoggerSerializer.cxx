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
#include "Direct3DViewport2Logger.hxx"
#include "Direct3DViewport2TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DViewport2, QueryInterface);       \
        A(Direct3DViewport2, AddRef);               \
        A(Direct3DViewport2, Release);              \
        A(Direct3DViewport2, Initialize);           \
        A(Direct3DViewport2, GetViewport);          \
        A(Direct3DViewport2, SetViewport);          \
        A(Direct3DViewport2, TransformVertices);    \
        A(Direct3DViewport2, LightElements);        \
        A(Direct3DViewport2, SetBackground);        \
        A(Direct3DViewport2, GetBackground);        \
        A(Direct3DViewport2, SetBackgroundDepth);   \
        A(Direct3DViewport2, GetBackgroundDepth);   \
        A(Direct3DViewport2, Clear);                \
        A(Direct3DViewport2, AddLight);             \
        A(Direct3DViewport2, DeleteLight);          \
        A(Direct3DViewport2, NextLight);            \
        A(Direct3DViewport2, GetViewport2);         \
        A(Direct3DViewport2, SetViewport2);         \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DViewport2MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DViewport2QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DViewport2ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DViewport2InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2GetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2GETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2SetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2SETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2TransformVerticesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2TRANSFORMVERTICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Transform /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatValue, value->Offscreen) return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2LightElementsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2LIGHTELEMENTSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2SetBackgroundValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2SETBACKGROUNDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2GetBackgroundValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2GETBACKGROUNDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatValue, value->Valid); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2SetBackgroundDepthValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2SETBACKGROUNDDEPTHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2GetBackgroundDepthValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2GETBACKGROUNDDEPTHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Valid); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2ClearValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2CLEARMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Rects /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2AddLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2ADDLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2DeleteLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2DELETELIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2NextLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2NEXTLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light);
    FORMATVALUE(builder, TextFormatObject, value->NextLight);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2GetViewport2Value(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2GETVIEWPORT2METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport2SetViewport2Value(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT2SETVIEWPORT2METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DViewport2MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DViewport2MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DViewport2MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
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
#include "Direct3DViewport3Logger.hxx"
#include "Direct3DViewport3TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DViewport3, QueryInterface);       \
        A(Direct3DViewport3, AddRef);               \
        A(Direct3DViewport3, Release);              \
        A(Direct3DViewport3, Initialize);           \
        A(Direct3DViewport3, GetViewport);          \
        A(Direct3DViewport3, SetViewport);          \
        A(Direct3DViewport3, TransformVertices);    \
        A(Direct3DViewport3, LightElements);        \
        A(Direct3DViewport3, SetBackground);        \
        A(Direct3DViewport3, GetBackground);        \
        A(Direct3DViewport3, SetBackgroundDepth);   \
        A(Direct3DViewport3, GetBackgroundDepth);   \
        A(Direct3DViewport3, Clear);                \
        A(Direct3DViewport3, AddLight);             \
        A(Direct3DViewport3, DeleteLight);          \
        A(Direct3DViewport3, NextLight);            \
        A(Direct3DViewport3, GetViewport2);         \
        A(Direct3DViewport3, SetViewport2);         \
        A(Direct3DViewport3, SetBackgroundDepth2);  \
        A(Direct3DViewport3, GetBackgroundDepth2);  \
        A(Direct3DViewport3, Clear2);               \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DViewport3MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DViewport3QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DViewport3ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DViewport3InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3GetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3GETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3SetViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3SETVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3TransformVerticesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3TRANSFORMVERTICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Transform /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatValue, value->Offscreen) return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3LightElementsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3LIGHTELEMENTSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3SetBackgroundValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3SETBACKGROUNDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3GetBackgroundValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3GETBACKGROUNDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatValue, value->Valid); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3SetBackgroundDepthValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3SETBACKGROUNDDEPTHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3GetBackgroundDepthValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3GETBACKGROUNDDEPTHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Valid); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3ClearValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3CLEARMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Rects /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3AddLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3ADDLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3DeleteLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3DELETELIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3NextLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3NEXTLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light);
    FORMATVALUE(builder, TextFormatObject, value->NextLight);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3GetViewport2Value(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3GETVIEWPORT2METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3SetViewport2Value(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3SETVIEWPORT2METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3SetBackgroundDepth2Value(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3SETBACKGROUNDDEPTH2METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3GetBackgroundDepth2Value(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3GETBACKGROUNDDEPTH2METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DViewport3Clear2Value(LPSTRINGBUILDER builder, CONST LPDIRECT3DVIEWPORT3CLEAR2METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Rects /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatValue, value->Color);
    FORMATVALUE(builder, TextFormatValue, value->Z);
    FORMATVALUE(builder, TextFormatValue, value->Stencil); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DViewport3MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DViewport3MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DViewport3MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
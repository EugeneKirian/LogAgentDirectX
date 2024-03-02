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
#include "Direct3DVertexBuffer7Logger.hxx"
#include "Direct3DVertexBuffer7TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(Direct3DVertexBuffer7, QueryInterface);           \
        A(Direct3DVertexBuffer7, AddRef);                   \
        A(Direct3DVertexBuffer7, Release);                  \
        A(Direct3DVertexBuffer7, Lock);                     \
        A(Direct3DVertexBuffer7, Unlock);                   \
        A(Direct3DVertexBuffer7, ProcessVertices);          \
        A(Direct3DVertexBuffer7, GetVertexBufferDesc);      \
        A(Direct3DVertexBuffer7, Optimize);                 \
        A(Direct3DVertexBuffer7, ProcessVerticesStrided);   \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DVertexBuffer7MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7LockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatObject, value->Value);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7UNLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7ProcessVerticesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7PROCESSVERTICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Operation);
    FORMATVALUE(builder, TextFormatValue, value->DestinationIndex);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Buffer);
    FORMATVALUE(builder, TextFormatValue, value->SourceIndex);
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7GetVertexBufferDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7GETVERTEXBUFFERDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7OptimizeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7OPTIMIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer7ProcessVerticesStridedValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER7PROCESSVERTICESSTRIDEDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Operation);
    FORMATVALUE(builder, TextFormatValue, value->DestinationIndex);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Value);
    FORMATVALUE(builder, TextFormatValue, value->SourceIndex);
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DVertexBuffer7MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DVertexBuffer7MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DVertexBuffer7MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
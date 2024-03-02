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
#include "Direct3DVertexBufferLogger.hxx"
#include "Direct3DVertexBufferTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(Direct3DVertexBuffer, QueryInterface);        \
        A(Direct3DVertexBuffer, AddRef);                \
        A(Direct3DVertexBuffer, Release);               \
        A(Direct3DVertexBuffer, Lock);                  \
        A(Direct3DVertexBuffer, Unlock);                \
        A(Direct3DVertexBuffer, ProcessVertices);       \
        A(Direct3DVertexBuffer, GetVertexBufferDesc);   \
        A(Direct3DVertexBuffer, Optimize);              \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DVertexBufferMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DVertexBufferQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFERQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBufferAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFERADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBufferReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFERRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBufferLockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFERLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatObject, value->Value);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBufferUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFERUNLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBufferProcessVerticesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFERPROCESSVERTICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Operation);
    FORMATVALUE(builder, TextFormatValue, value->DestinationIndex);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Buffer);
    FORMATVALUE(builder, TextFormatValue, value->SourceIndex);
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBufferGetVertexBufferDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFERGETVERTEXBUFFERDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBufferOptimizeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFEROPTIMIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DVertexBufferMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DVertexBufferMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DVertexBufferMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
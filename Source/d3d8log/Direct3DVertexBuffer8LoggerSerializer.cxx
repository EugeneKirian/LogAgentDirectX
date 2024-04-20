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
#include "Direct3DVertexBuffer8Logger.hxx"
#include "Direct3DVertexBuffer8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(Direct3DVertexBuffer8, QueryInterface);           \
        A(Direct3DVertexBuffer8, AddRef);                   \
        A(Direct3DVertexBuffer8, Release);                  \
        A(Direct3DVertexBuffer8, GetDevice);                \
        A(Direct3DVertexBuffer8, SetPrivateData);           \
        A(Direct3DVertexBuffer8, GetPrivateData);           \
        A(Direct3DVertexBuffer8, FreePrivateData);          \
        A(Direct3DVertexBuffer8, SetPriority);              \
        A(Direct3DVertexBuffer8, GetPriority);              \
        A(Direct3DVertexBuffer8, PreLoad);                  \
        A(Direct3DVertexBuffer8, GetType);                  \
        A(Direct3DVertexBuffer8, Lock);                     \
        A(Direct3DVertexBuffer8, Unlock);                   \
        A(Direct3DVertexBuffer8, GetDesc);                  \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DVertexBuffer8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8GetDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8GETDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8SetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8SETPRIORITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Priority); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8GetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8GETPRIORITYMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8PreLoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8PRELOADMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8GetTypeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8GETTYPEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8LockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Offset);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8UNLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVertexBuffer8GetDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVERTEXBUFFER8GETDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Desc /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DVertexBuffer8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DVertexBuffer8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DVertexBuffer8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
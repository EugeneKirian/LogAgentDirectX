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
#include "Direct3DIndexBuffer8Logger.hxx"
#include "Direct3DIndexBuffer8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(Direct3DIndexBuffer8, QueryInterface);        \
        A(Direct3DIndexBuffer8, AddRef);                \
        A(Direct3DIndexBuffer8, Release);               \
        A(Direct3DIndexBuffer8, GetDevice);             \
        A(Direct3DIndexBuffer8, SetPrivateData);        \
        A(Direct3DIndexBuffer8, GetPrivateData);        \
        A(Direct3DIndexBuffer8, FreePrivateData);       \
        A(Direct3DIndexBuffer8, SetPriority);           \
        A(Direct3DIndexBuffer8, GetPriority);           \
        A(Direct3DIndexBuffer8, PreLoad);               \
        A(Direct3DIndexBuffer8, GetType);               \
        A(Direct3DIndexBuffer8, Lock);                  \
        A(Direct3DIndexBuffer8, Unlock);                \
        A(Direct3DIndexBuffer8, GetDesc);               \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DIndexBuffer8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8GetDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8GETDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8SetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8SETPRIORITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Priority); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8GetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8GETPRIORITYMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8PreLoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8PRELOADMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8GetTypeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8GETTYPEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8LockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Offset);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8UNLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DIndexBuffer8GetDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINDEXBUFFER8GETDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Desc /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DIndexBuffer8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DIndexBuffer8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DIndexBuffer8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
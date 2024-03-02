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
#include "Direct3DExecuteBufferLogger.hxx"
#include "Direct3DExecuteBufferTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(Direct3DExecuteBuffer, QueryInterface);       \
        A(Direct3DExecuteBuffer, AddRef);               \
        A(Direct3DExecuteBuffer, Release);              \
        A(Direct3DExecuteBuffer, Initialize);           \
        A(Direct3DExecuteBuffer, Lock);                 \
        A(Direct3DExecuteBuffer, Unlock);               \
        A(Direct3DExecuteBuffer, SetExecuteData);       \
        A(Direct3DExecuteBuffer, GetExecuteData);       \
        A(Direct3DExecuteBuffer, Validate);             \
        A(Direct3DExecuteBuffer, Optimize);             \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DExecuteBufferMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DExecuteBufferQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DExecuteBufferAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DExecuteBufferReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DExecuteBufferInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DExecuteBufferLockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DExecuteBufferUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERUNLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DExecuteBufferSetExecuteDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERSETEXECUTEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DExecuteBufferGetExecuteDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERGETEXECUTEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DExecuteBufferValidateValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERVALIDATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Offset);
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatValue, value->Reserved); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DExecuteBufferOptimizeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFEROPTIMIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DExecuteBufferMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(Direct3DExecuteBuffer, Validate);             \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DExecuteBufferMethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DExecuteBufferValidateCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DEXECUTEBUFFERVALIDATEMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatValue, value->Offset); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirect3DExecuteBufferMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}
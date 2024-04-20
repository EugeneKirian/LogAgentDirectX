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
#include "Direct3DVolume8Logger.hxx"
#include "Direct3DVolume8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DVolume8, QueryInterface);         \
        A(Direct3DVolume8, AddRef);                 \
        A(Direct3DVolume8, Release);                \
        A(Direct3DVolume8, GetDevice);              \
        A(Direct3DVolume8, SetPrivateData);         \
        A(Direct3DVolume8, GetPrivateData);         \
        A(Direct3DVolume8, FreePrivateData);        \
        A(Direct3DVolume8, GetContainer);           \
        A(Direct3DVolume8, GetDesc);                \
        A(Direct3DVolume8, LockBox);                \
        A(Direct3DVolume8, UnlockBox);              \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DVolume8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DVolume8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolume8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolume8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolume8GetDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8GETDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolume8SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolume8GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolume8FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolume8GetContainerValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8GETCONTAINERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Container); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolume8GetDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8GETDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Desc /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolume8LockBoxValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8LOCKBOXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, &value->Volume);
    FORMATVALUE(builder, TextFormatObject, value->Box /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolume8UnlockBoxValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUME8UNLOCKBOXMETHODVALUE value) { return TRUE; }

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DVolume8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DVolume8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DVolume8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
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
#include "Direct3DSurface8Logger.hxx"
#include "Direct3DSurface8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(Direct3DSurface8, QueryInterface);            \
        A(Direct3DSurface8, AddRef);                    \
        A(Direct3DSurface8, Release);                   \
        A(Direct3DSurface8, GetDevice);                 \
        A(Direct3DSurface8, SetPrivateData);            \
        A(Direct3DSurface8, GetPrivateData);            \
        A(Direct3DSurface8, FreePrivateData);           \
        A(Direct3DSurface8, GetContainer);              \
        A(Direct3DSurface8, GetDesc);                   \
        A(Direct3DSurface8, LockRect);                  \
        A(Direct3DSurface8, UnlockRect);                \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DSurface8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DSurface8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSurface8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DSurface8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DSurface8GetDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8GETDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSurface8SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSurface8GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSurface8FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSurface8GetContainerValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8GETCONTAINERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Container); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSurface8GetDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8GETDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Desc /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSurface8LockRectValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8LOCKRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->LockedRect);
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSurface8UnlockRectValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSURFACE8UNLOCKRECTMETHODVALUE value) { return TRUE; }

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DSurface8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DSurface8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DSurface8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
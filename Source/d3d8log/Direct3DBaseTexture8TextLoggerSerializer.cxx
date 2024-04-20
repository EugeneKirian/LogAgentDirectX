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
#include "Direct3DBaseTexture8Logger.hxx"
#include "Direct3DBaseTexture8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DBaseTexture8, QueryInterface);    \
        A(Direct3DBaseTexture8, AddRef);            \
        A(Direct3DBaseTexture8, Release);           \
        A(Direct3DBaseTexture8, GetDevice);         \
        A(Direct3DBaseTexture8, SetPrivateData);    \
        A(Direct3DBaseTexture8, GetPrivateData);    \
        A(Direct3DBaseTexture8, FreePrivateData);   \
        A(Direct3DBaseTexture8, SetPriority);       \
        A(Direct3DBaseTexture8, GetPriority);       \
        A(Direct3DBaseTexture8, PreLoad);           \
        A(Direct3DBaseTexture8, GetType);           \
        A(Direct3DBaseTexture8, SetLOD);            \
        A(Direct3DBaseTexture8, GetLOD);            \
        A(Direct3DBaseTexture8, GetLevelCount);     \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DBaseTexture8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DBaseTexture8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DBaseTexture8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DBaseTexture8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DBaseTexture8GetDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8GETDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DBaseTexture8SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DBaseTexture8GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DBaseTexture8FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DBaseTexture8SetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8SETPRIORITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Priority); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DBaseTexture8GetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8GETPRIORITYMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DBaseTexture8PreLoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8PRELOADMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DBaseTexture8GetTypeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8GETTYPEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DBaseTexture8SetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8SETLODMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->LOD); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DBaseTexture8GetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8GETLODMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DBaseTexture8GetLevelCountValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DBASETEXTURE8GETLEVELCOUNTMETHODVALUE value) { return TRUE; }

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DBaseTexture8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DBaseTexture8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DBaseTexture8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
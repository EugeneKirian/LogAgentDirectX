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
#include "Direct3DTexture8Logger.hxx"
#include "Direct3DTexture8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DTexture8, QueryInterface);        \
        A(Direct3DTexture8, AddRef);                \
        A(Direct3DTexture8, Release);               \
        A(Direct3DTexture8, GetDevice);             \
        A(Direct3DTexture8, SetPrivateData);        \
        A(Direct3DTexture8, GetPrivateData);        \
        A(Direct3DTexture8, FreePrivateData);       \
        A(Direct3DTexture8, SetPriority);           \
        A(Direct3DTexture8, GetPriority);           \
        A(Direct3DTexture8, PreLoad);               \
        A(Direct3DTexture8, GetType);               \
        A(Direct3DTexture8, SetLOD);                \
        A(Direct3DTexture8, GetLOD);                \
        A(Direct3DTexture8, GetLevelCount);         \
        A(Direct3DTexture8, GetLevelDesc);          \
        A(Direct3DTexture8, GetSurfaceLevel);       \
        A(Direct3DTexture8, LockRect);              \
        A(Direct3DTexture8, UnlockRect);            \
        A(Direct3DTexture8, AddDirtyRect);          \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DTexture8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DTexture8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTexture8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTexture8GetDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8GETDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8SetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8SETPRIORITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Priority); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8GetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8GETPRIORITYMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTexture8PreLoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8PRELOADMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTexture8GetTypeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8GETTYPEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTexture8SetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8SETLODMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->LOD); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8GetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8GETLODMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTexture8GetLevelCountValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8GETLEVELCOUNTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTexture8GetLevelDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8GETLEVELDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->Desc /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8GetSurfaceLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8GETSURFACELEVELMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->SurfaceLevel /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8LockRectValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8LOCKRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->LockedRect);
    FORMATVALUE(builder, TextFormatObject, value->Rect /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8UnlockRectValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8UNLOCKRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexture8AddDirtyRectValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURE8ADDDIRTYRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DTexture8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DTexture8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DTexture8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
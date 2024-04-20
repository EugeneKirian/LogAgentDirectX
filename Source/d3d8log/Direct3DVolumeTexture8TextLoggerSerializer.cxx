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
#include "Direct3DVolumeTexture8Logger.hxx"
#include "Direct3DVolumeTexture8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(Direct3DVolumeTexture8, QueryInterface);          \
        A(Direct3DVolumeTexture8, AddRef);                  \
        A(Direct3DVolumeTexture8, Release);                 \
        A(Direct3DVolumeTexture8, GetDevice);               \
        A(Direct3DVolumeTexture8, SetPrivateData);          \
        A(Direct3DVolumeTexture8, GetPrivateData);          \
        A(Direct3DVolumeTexture8, FreePrivateData);         \
        A(Direct3DVolumeTexture8, SetPriority);             \
        A(Direct3DVolumeTexture8, GetPriority);             \
        A(Direct3DVolumeTexture8, PreLoad);                 \
        A(Direct3DVolumeTexture8, GetType);                 \
        A(Direct3DVolumeTexture8, SetLOD);                  \
        A(Direct3DVolumeTexture8, GetLOD);                  \
        A(Direct3DVolumeTexture8, GetLevelCount);           \
        A(Direct3DVolumeTexture8, GetLevelDesc);            \
        A(Direct3DVolumeTexture8, GetVolumeLevel);          \
        A(Direct3DVolumeTexture8, LockBox);                 \
        A(Direct3DVolumeTexture8, UnlockBox);               \
        A(Direct3DVolumeTexture8, AddDirtyBox);             \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DVolumeTexture8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8GetDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8GETDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8SetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8SETPRIORITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Priority); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8GetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8GETPRIORITYMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8PreLoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8PRELOADMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8GetTypeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8GETTYPEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8SetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8SETLODMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->LOD); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8GetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8GETLODMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8GetLevelCountValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8GETLEVELCOUNTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8GetLevelDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8GETLEVELDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->Desc /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8GetVolumeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8GETVOLUMELEVELMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->Volume /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8LockBoxValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8LOCKBOXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->Volume);
    FORMATVALUE(builder, TextFormatObject, value->Box /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8UnlockBoxValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8UNLOCKBOXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DVolumeTexture8AddDirtyBoxValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DVOLUMETEXTURE8ADDDIRTYBOXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Box /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DVolumeTexture8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DVolumeTexture8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DVolumeTexture8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
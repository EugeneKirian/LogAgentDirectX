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
#include "Direct3DCubeTexture8Logger.hxx"
#include "Direct3DCubeTexture8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DCubeTexture8, QueryInterface);    \
        A(Direct3DCubeTexture8, AddRef);            \
        A(Direct3DCubeTexture8, Release);           \
        A(Direct3DCubeTexture8, GetDevice);         \
        A(Direct3DCubeTexture8, SetPrivateData);    \
        A(Direct3DCubeTexture8, GetPrivateData);    \
        A(Direct3DCubeTexture8, FreePrivateData);   \
        A(Direct3DCubeTexture8, SetPriority);       \
        A(Direct3DCubeTexture8, GetPriority);       \
        A(Direct3DCubeTexture8, PreLoad);           \
        A(Direct3DCubeTexture8, GetType);           \
        A(Direct3DCubeTexture8, SetLOD);            \
        A(Direct3DCubeTexture8, GetLOD);            \
        A(Direct3DCubeTexture8, GetLevelCount);     \
        A(Direct3DCubeTexture8, GetLevelDesc);      \
        A(Direct3DCubeTexture8, GetCubeMapSurface); \
        A(Direct3DCubeTexture8, LockRect);          \
        A(Direct3DCubeTexture8, UnlockRect);        \
        A(Direct3DCubeTexture8, AddDirtyRect);      \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DCubeTexture8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DCubeTexture8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DCubeTexture8GetDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8GETDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Data /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8SetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8SETPRIORITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Priority); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8GetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8GETPRIORITYMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DCubeTexture8PreLoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8PRELOADMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DCubeTexture8GetTypeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8GETTYPEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DCubeTexture8SetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8SETLODMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->LOD); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8GetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8GETLODMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DCubeTexture8GetLevelCountValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8GETLEVELCOUNTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DCubeTexture8GetLevelDescValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8GETLEVELDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->Desc /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8GetCubeMapSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8GETCUBEMAPSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->Surface /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8LockRectValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8LOCKRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->LockedRect);
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8UnlockRectValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8UNLOCKRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Level); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCubeTexture8AddDirtyRectValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCUBETEXTURE8ADDDIRTYRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Rect); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DCubeTexture8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DCubeTexture8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DCubeTexture8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
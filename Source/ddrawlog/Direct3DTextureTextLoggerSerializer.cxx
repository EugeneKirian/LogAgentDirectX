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
#include "Direct3DTextureLogger.hxx"
#include "Direct3DTextureTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                               \
    switch (ID)                                 \
    {                                           \
        A(Direct3DTexture, QueryInterface);     \
        A(Direct3DTexture, AddRef);             \
        A(Direct3DTexture, Release);            \
        A(Direct3DTexture, Initialize);         \
        A(Direct3DTexture, GetHandle);          \
        A(Direct3DTexture, PaletteChanged);     \
        A(Direct3DTexture, Load);               \
        A(Direct3DTexture, Unload);             \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DTextureMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DTextureQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTUREQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTextureAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTUREADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTextureReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURERELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DTextureInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTUREINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTextureGetHandleValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTUREGETHANDLEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTexturePaletteChangedValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTUREPALETTECHANGEDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Start);
    FORMATVALUE(builder, TextFormatValue, value->Count); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTextureLoadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTURELOADMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Texture); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DTextureUnloadValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DTEXTUREUNLOADMETHODVALUE value) { return TRUE; }

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DTextureMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DTextureMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DTextureMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
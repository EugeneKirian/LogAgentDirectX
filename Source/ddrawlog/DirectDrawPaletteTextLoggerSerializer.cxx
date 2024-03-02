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
#include "DirectDrawPaletteLogger.hxx"
#include "DirectDrawPaletteTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                               \
    switch (ID)                                 \
    {                                           \
        A(DirectDrawPalette, QueryInterface);   \
        A(DirectDrawPalette, AddRef);           \
        A(DirectDrawPalette, Release);          \
        A(DirectDrawPalette, GetCaps);          \
        A(DirectDrawPalette, GetEntries);       \
        A(DirectDrawPalette, Initialize);       \
        A(DirectDrawPalette, SetEntries);       \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawPaletteMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawPaletteQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWPALETTEQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawPaletteAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWPALETTEADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawPaletteReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWPALETTERELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawPaletteGetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWPALETTEGETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawPaletteGetEntriesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWPALETTEGETENTRIESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Entries /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawPaletteInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWPALETTEINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Entries /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawPaletteSetEntriesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWPALETTESETENTRIESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Entries /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawPaletteMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectDrawPaletteMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectDrawPaletteMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
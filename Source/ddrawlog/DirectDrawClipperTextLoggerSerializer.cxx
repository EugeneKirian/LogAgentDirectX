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
#include "DirectDrawClipperLogger.hxx"
#include "DirectDrawClipperTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(DirectDrawClipper, QueryInterface);       \
        A(DirectDrawClipper, AddRef);               \
        A(DirectDrawClipper, Release);              \
        A(DirectDrawClipper, GetClipList);          \
        A(DirectDrawClipper, GetHWnd);              \
        A(DirectDrawClipper, Initialize);           \
        A(DirectDrawClipper, IsClipListChanged);    \
        A(DirectDrawClipper, SetClipList);          \
        A(DirectDrawClipper, SetHWnd);              \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawClipperMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawClipperQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawClipperAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawClipperReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawClipperGetClipListValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERGETCLIPLISTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ClipList /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawClipperGetHWndValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERGETHWNDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatWindow, value->Window); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawClipperInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawClipperIsClipListChangedValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERISCLIPLISTCHANGEDMETHODVALUE value)
{

    FORMATVALUE(builder, TextFormatValue, value->Changed /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawClipperSetClipListValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERSETCLIPLISTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ClipList /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawClipperSetHWndValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCLIPPERSETHWNDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatWindow, value->Window); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawClipperMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectDrawClipperMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectDrawClipperMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
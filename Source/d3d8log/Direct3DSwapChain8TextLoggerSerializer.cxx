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
#include "Direct3DSwapChain8Logger.hxx"
#include "Direct3DSwapChain8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(Direct3DSwapChain8, QueryInterface);          \
        A(Direct3DSwapChain8, AddRef);                  \
        A(Direct3DSwapChain8, Release);                 \
        A(Direct3DSwapChain8, Present);                 \
        A(Direct3DSwapChain8, GetBackBuffer);           \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DSwapChain8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DSwapChain8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSWAPCHAIN8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSwapChain8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSWAPCHAIN8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DSwapChain8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSWAPCHAIN8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DSwapChain8PresentValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSWAPCHAIN8PRESENTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->SourceRect);
    FORMATVALUE(builder, TextFormatObject, value->DestRect);
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatObject, value->Region /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DSwapChain8GetBackBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DSWAPCHAIN8GETBACKBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatValue, value->Type /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->BackBuffer /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DSwapChain8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DSwapChain8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DSwapChain8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
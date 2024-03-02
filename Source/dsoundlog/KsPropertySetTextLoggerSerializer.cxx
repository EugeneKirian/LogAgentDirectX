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
#include "KsPropertySetLogger.hxx"
#include "KsPropertySetTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                               \
    switch (ID)                                 \
    {                                           \
        A(KsPropertySet, QueryInterface);       \
        A(KsPropertySet, AddRef);               \
        A(KsPropertySet, Release);              \
        A(KsPropertySet, Get);                  \
        A(KsPropertySet, Set);                  \
        A(KsPropertySet, QuerySupport);         \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerKsPropertySetMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerKsPropertySetQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPKSPROPERTYSETQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerKsPropertySetAddRefValue(LPSTRINGBUILDER builder, CONST LPKSPROPERTYSETADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerKsPropertySetReleaseValue(LPSTRINGBUILDER builder, CONST LPKSPROPERTYSETRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerKsPropertySetGetValue(LPSTRINGBUILDER builder, CONST LPKSPROPERTYSETGETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->Set);
    FORMATVALUE(builder, TextFormatValue, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->InstanceValue /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->InstanceLenght);
    FORMATVALUE(builder, TextFormatObject, value->DataValue /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->DataLength);
    FORMATVALUE(builder, TextFormatValue, value->BytesReturned); return TRUE;
}

static CONST BOOL AcquireLoggerKsPropertySetSetValue(LPSTRINGBUILDER builder, CONST LPKSPROPERTYSETSETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->Set);
    FORMATVALUE(builder, TextFormatValue, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->InstanceValue /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->InstanceLenght);
    FORMATVALUE(builder, TextFormatObject, value->DataValue /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->DataLength); return TRUE;
}

static CONST BOOL AcquireLoggerKsPropertySetQuerySupportValue(LPSTRINGBUILDER builder, CONST LPKSPROPERTYSETQUERYSUPPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->Set);
    FORMATVALUE(builder, TextFormatValue, value->ID);
    FORMATVALUE(builder, TextFormatValue, value->TypeSupport); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerKsPropertySetMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerKsPropertySetMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerKsPropertySetMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
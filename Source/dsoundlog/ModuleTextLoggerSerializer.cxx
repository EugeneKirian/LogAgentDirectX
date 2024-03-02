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

#include "ModuleLogger.hxx"
#include "ModuleTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Module, DirectSoundCaptureCreate);        \
        A(Module, DirectSoundCaptureCreate8);       \
        A(Module, DirectSoundCaptureEnumerateA);    \
        A(Module, DirectSoundCaptureEnumerateW);    \
        A(Module, DirectSoundCreate);               \
        A(Module, DirectSoundCreate8);              \
        A(Module, DirectSoundEnumerateA);           \
        A(Module, DirectSoundEnumerateW);           \
        A(Module, DirectSoundFullDuplexCreate);     \
        A(Module, DllCanUnloadNow);                 \
        A(Module, DllGetClassObject);               \
        A(Module, GetDeviceID);                     \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerModuleMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerModuleDirectSoundCaptureCreateValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDCAPTURECREATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundCaptureCreate8Value(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDCAPTURECREATE8METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundCaptureEnumerateAValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDCAPTUREENUMERATEAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundCaptureEnumerateWValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDCAPTUREENUMERATEWMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundCreateValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDCREATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundCreate8Value(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDCREATE8METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundEnumerateAValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDENUMERATEAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundEnumerateWValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDENUMERATEWMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundFullDuplexCreateValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDFULLDUPLEXCREATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->CaptureDevice);
    FORMATVALUE(builder, TextFormatID, value->RenderDevice);
    FORMATVALUE(builder, TextFormatObject, value->CaptureDescriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->RenderDescriptor /* TODO */);
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatValue, value->Level);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->CaptureBuffer);
    FORMATVALUE(builder, TextFormatObject, value->RenderBuffer);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDllCanUnloadNowValue(LPSTRINGBUILDER builder, CONST LPMODULEDLLCANUNLOADNOWMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerModuleDllGetClassObjectValue(LPSTRINGBUILDER builder, CONST LPMODULEDLLGETCLASSOBJECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatID, value->IID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerModuleGetDeviceIDValue(LPSTRINGBUILDER builder, CONST LPMODULEGETDEVICEIDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->Source);
    FORMATVALUE(builder, TextFormatID, value->Destination); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerModuleMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                  \
    switch (ID)                                     \
    {                                               \
        A(Module, DirectSoundEnumerateA);           \
        A(Module, DirectSoundEnumerateW);           \
        A(Module, DirectSoundCaptureEnumerateA);    \
        A(Module, DirectSoundCaptureEnumerateW);    \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerModuleMethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerModuleDirectSoundEnumerateACallbackValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDENUMERATEAMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Module); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundEnumerateWCallbackValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDENUMERATEWMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Module); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundCaptureEnumerateACallbackValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDCAPTUREENUMERATEAMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Module); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectSoundCaptureEnumerateWCallbackValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTSOUNDCAPTUREENUMERATEWMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Module); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerModuleMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}
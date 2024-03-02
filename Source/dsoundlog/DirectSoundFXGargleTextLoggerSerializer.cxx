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
#include "DirectSoundFXGargleLogger.hxx"
#include "DirectSoundFXGargleTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(DirectSoundFXGargle, QueryInterface);     \
        A(DirectSoundFXGargle, AddRef);             \
        A(DirectSoundFXGargle, Release);            \
        A(DirectSoundFXGargle, SetAllParameters);   \
        A(DirectSoundFXGargle, GetAllParameters);   \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSoundFXGargleMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSoundFXGargleQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXGARGLEQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundFXGargleAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXGARGLEADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundFXGargleReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXGARGLERELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundFXGargleSetAllParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXGARGLESETALLPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundFXGargleGetAllParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXGARGLEGETALLPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSoundFXGargleMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSoundFXGargleMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSoundFXGargleMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
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
#include "DirectSoundFXI3DL2ReverbLogger.hxx"
#include "DirectSoundFXI3DL2ReverbTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectSoundFXI3DL2Reverb, QueryInterface);    \
        A(DirectSoundFXI3DL2Reverb, AddRef);            \
        A(DirectSoundFXI3DL2Reverb, Release);           \
        A(DirectSoundFXI3DL2Reverb, SetAllParameters);  \
        A(DirectSoundFXI3DL2Reverb, GetAllParameters);  \
        A(DirectSoundFXI3DL2Reverb, SetPreset);         \
        A(DirectSoundFXI3DL2Reverb, GetPreset);         \
        A(DirectSoundFXI3DL2Reverb, SetQuality);        \
        A(DirectSoundFXI3DL2Reverb, GetQuality);        \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSoundFXI3DL2ReverbMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbSetAllParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBSETALLPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbGetAllParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBGETALLPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbSetPresetValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBSETPRESETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Preset /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbGetPresetValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBGETPRESETMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Preset /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbSetQualityValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBSETQUALITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Quality); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbGetQualityValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDFXI3DL2REVERBGETQUALITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Quality); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSoundFXI3DL2ReverbMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSoundFXI3DL2ReverbMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
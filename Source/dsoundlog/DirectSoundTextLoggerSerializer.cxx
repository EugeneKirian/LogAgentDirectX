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
#include "DirectSoundLogger.hxx"
#include "DirectSoundTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                               \
    switch (ID)                                 \
    {                                           \
        A(DirectSound, QueryInterface);         \
        A(DirectSound, AddRef);                 \
        A(DirectSound, Release);                \
        A(DirectSound, CreateSoundBuffer);      \
        A(DirectSound, GetCaps);                \
        A(DirectSound, DuplicateSoundBuffer);   \
        A(DirectSound, SetCooperativeLevel);    \
        A(DirectSound, Compact);                \
        A(DirectSound, GetSpeakerConfig);       \
        A(DirectSound, SetSpeakerConfig);       \
        A(DirectSound, Initialize);             \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSoundMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSoundQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundCreateSoundBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCREATESOUNDBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Buffer);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundGetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDGETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundDuplicateSoundBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDDUPLICATESOUNDBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Original);
    FORMATVALUE(builder, TextFormatObject, value->Duplicate); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundSetCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDSETCOOPERATIVELEVELMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCompactValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCOMPACTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundGetSpeakerConfigValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDGETSPEAKERCONFIGMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Configuration /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundSetSpeakerConfigValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDSETSPEAKERCONFIGMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Configuration /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSoundMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSoundMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSoundMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
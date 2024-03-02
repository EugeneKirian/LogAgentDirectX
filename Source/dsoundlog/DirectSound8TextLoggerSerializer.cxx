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
#include "DirectSound8Logger.hxx"
#include "DirectSound8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                               \
    switch (ID)                                 \
    {                                           \
        A(DirectSound8, QueryInterface);        \
        A(DirectSound8, AddRef);                \
        A(DirectSound8, Release);               \
        A(DirectSound8, CreateSoundBuffer);     \
        A(DirectSound8, GetCaps);               \
        A(DirectSound8, DuplicateSoundBuffer);  \
        A(DirectSound8, SetCooperativeLevel);   \
        A(DirectSound8, Compact);               \
        A(DirectSound8, GetSpeakerConfig);      \
        A(DirectSound8, SetSpeakerConfig);      \
        A(DirectSound8, Initialize);            \
        A(DirectSound8, VerifyCertification);   \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSound8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSound8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSound8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSound8CreateSoundBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8CREATESOUNDBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Buffer);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound8GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound8DuplicateSoundBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8DUPLICATESOUNDBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Original);
    FORMATVALUE(builder, TextFormatObject, value->Duplicate); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound8SetCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8SETCOOPERATIVELEVELMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound8CompactValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8COMPACTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSound8GetSpeakerConfigValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8GETSPEAKERCONFIGMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Configuration /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound8SetSpeakerConfigValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8SETSPEAKERCONFIGMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Configuration /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound8InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound8VerifyCertificationValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND8VERIFYCERTIFICATIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSound8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSound8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSound8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
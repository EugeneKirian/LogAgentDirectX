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
#include "DirectSoundBuffer8Logger.hxx"
#include "DirectSoundBuffer8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(DirectSoundBuffer8, QueryInterface);      \
        A(DirectSoundBuffer8, AddRef);              \
        A(DirectSoundBuffer8, Release);             \
        A(DirectSoundBuffer8, GetCaps);             \
        A(DirectSoundBuffer8, GetCurrentPosition);  \
        A(DirectSoundBuffer8, GetFormat);           \
        A(DirectSoundBuffer8, GetVolume);           \
        A(DirectSoundBuffer8, GetPan);              \
        A(DirectSoundBuffer8, GetFrequency);        \
        A(DirectSoundBuffer8, GetStatus);           \
        A(DirectSoundBuffer8, Initialize);          \
        A(DirectSoundBuffer8, Lock);                \
        A(DirectSoundBuffer8, Play);                \
        A(DirectSoundBuffer8, SetCurrentPosition);  \
        A(DirectSoundBuffer8, SetFormat);           \
        A(DirectSoundBuffer8, SetVolume);           \
        A(DirectSoundBuffer8, SetPan);              \
        A(DirectSoundBuffer8, SetFrequency);        \
        A(DirectSoundBuffer8, Stop);                \
        A(DirectSoundBuffer8, Unlock);              \
        A(DirectSoundBuffer8, Restore);             \
        A(DirectSoundBuffer8, SetFX);               \
        A(DirectSoundBuffer8, AcquireResources);    \
        A(DirectSoundBuffer8, GetObjectInPath);     \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSoundBuffer8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundBuffer8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundBuffer8GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8GetCurrentPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8GETCURRENTPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PlayPosition);
    FORMATVALUE(builder, TextFormatValue, value->WritePosition); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8GetFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8GETFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SizeAllocated);
    FORMATVALUE(builder, TextFormatValue, value->SizeWritten); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8GetVolumeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8GETVOLUMEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Volume); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8GetPanValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8GETPANMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Pan); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8GetFrequencyValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8GETFREQUENCYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Frequency); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8GetStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8GETSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Status); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8LockValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Offset);
    FORMATVALUE(builder, TextFormatValue, value->Bytes);
    FORMATVALUE(builder, TextFormatObject, value->Audio1 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes1);
    FORMATVALUE(builder, TextFormatObject, value->Audio2 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes2);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8PlayValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8PLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Reserved);
    FORMATVALUE(builder, TextFormatValue, value->Priority);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8SetCurrentPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8SETCURRENTPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Position); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8SetFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8SETFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8SetVolumeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8SETVOLUMEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Volume); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8SetPanValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8SETPANMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Pan); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8SetFrequencyValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8SETFREQUENCYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Frequency); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8StopValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8STOPMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundBuffer8UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8UNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Audio1 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes1);
    FORMATVALUE(builder, TextFormatObject, value->Audio2 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes2); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8RestoreValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8RESTOREMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundBuffer8SetFXValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8SETFXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Descriptors /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ResultCodes /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8AcquireResourcesValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8ACQUIRERESOURCESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->ResultCodes /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBuffer8GetObjectInPathValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFER8GETOBJECTINPATHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatID, value->IID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSoundBuffer8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSoundBuffer8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSoundBuffer8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
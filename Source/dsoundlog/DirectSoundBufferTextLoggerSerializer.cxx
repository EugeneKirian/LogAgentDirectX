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
#include "DirectSoundBufferLogger.hxx"
#include "DirectSoundBufferTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(DirectSoundBuffer, QueryInterface);       \
        A(DirectSoundBuffer, AddRef);               \
        A(DirectSoundBuffer, Release);              \
        A(DirectSoundBuffer, GetCaps);              \
        A(DirectSoundBuffer, GetCurrentPosition);   \
        A(DirectSoundBuffer, GetFormat);            \
        A(DirectSoundBuffer, GetVolume);            \
        A(DirectSoundBuffer, GetPan);               \
        A(DirectSoundBuffer, GetFrequency);         \
        A(DirectSoundBuffer, GetStatus);            \
        A(DirectSoundBuffer, Initialize);           \
        A(DirectSoundBuffer, Lock);                 \
        A(DirectSoundBuffer, Play);                 \
        A(DirectSoundBuffer, SetCurrentPosition);   \
        A(DirectSoundBuffer, SetFormat);            \
        A(DirectSoundBuffer, SetVolume);            \
        A(DirectSoundBuffer, SetPan);               \
        A(DirectSoundBuffer, SetFrequency);         \
        A(DirectSoundBuffer, Stop);                 \
        A(DirectSoundBuffer, Unlock);               \
        A(DirectSoundBuffer, Restore);              \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSoundBufferMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSoundBufferQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundBufferReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundBufferGetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERGETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferGetCurrentPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERGETCURRENTPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->PlayPosition);
    FORMATVALUE(builder, TextFormatValue, value->WritePosition); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferGetFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERGETFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SizeAllocated);
    FORMATVALUE(builder, TextFormatValue, value->SizeWritten); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferGetVolumeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERGETVOLUMEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Volume); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferGetPanValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERGETPANMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Pan); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferGetFrequencyValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERGETFREQUENCYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Frequency); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferGetStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERGETSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Status); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferLockValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Offset);
    FORMATVALUE(builder, TextFormatValue, value->Bytes);
    FORMATVALUE(builder, TextFormatObject, value->Audio1 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes1);
    FORMATVALUE(builder, TextFormatObject, value->Audio2 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes2);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferPlayValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERPLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Reserved);
    FORMATVALUE(builder, TextFormatValue, value->Priority);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferSetCurrentPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERSETCURRENTPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Position); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferSetFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERSETFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferSetVolumeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERSETVOLUMEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Volume); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferSetPanValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERSETPANMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Pan); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferSetFrequencyValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERSETFREQUENCYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Frequency); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferStopValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERSTOPMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundBufferUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERUNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Audio1 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes1);
    FORMATVALUE(builder, TextFormatObject, value->Audio2 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes2); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundBufferRestoreValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDBUFFERRESTOREMETHODVALUE value) { return TRUE; }

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSoundBufferMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSoundBufferMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSoundBufferMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
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
#include "DirectSoundCaptureBufferLogger.hxx"
#include "DirectSoundCaptureBufferTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(DirectSoundCaptureBuffer, QueryInterface);        \
        A(DirectSoundCaptureBuffer, AddRef);                \
        A(DirectSoundCaptureBuffer, Release);               \
        A(DirectSoundCaptureBuffer, GetCaps);               \
        A(DirectSoundCaptureBuffer, GetCurrentPosition);    \
        A(DirectSoundCaptureBuffer, GetFormat);             \
        A(DirectSoundCaptureBuffer, GetStatus);             \
        A(DirectSoundCaptureBuffer, Initialize);            \
        A(DirectSoundCaptureBuffer, Lock);                  \
        A(DirectSoundCaptureBuffer, Start);                 \
        A(DirectSoundCaptureBuffer, Stop);                  \
        A(DirectSoundCaptureBuffer, Unlock);                \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSoundCaptureBufferMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferGetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERGETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferGetCurrentPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERGETCURRENTPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->CapturePosition);
    FORMATVALUE(builder, TextFormatValue, value->ReadPosition); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferGetFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERGETFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SizeAllocated);
    FORMATVALUE(builder, TextFormatValue, value->SizeWritten); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferGetStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERGETSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Status /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferLockValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Offset);
    FORMATVALUE(builder, TextFormatValue, value->Bytes);
    FORMATVALUE(builder, TextFormatObject, value->Audio1 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes1);
    FORMATVALUE(builder, TextFormatObject, value->Audio2);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes2 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferStartValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERSTARTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferStopValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERSTOPMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundCaptureBufferUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFERUNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Audio1 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes1);
    FORMATVALUE(builder, TextFormatObject, value->Audio2);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes2 /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSoundCaptureBufferMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSoundCaptureBufferMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSoundCaptureBufferMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
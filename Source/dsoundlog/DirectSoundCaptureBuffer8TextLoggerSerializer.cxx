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
#include "DirectSoundCaptureBuffer8Logger.hxx"
#include "DirectSoundCaptureBuffer8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(DirectSoundCaptureBuffer8, QueryInterface);       \
        A(DirectSoundCaptureBuffer8, AddRef);               \
        A(DirectSoundCaptureBuffer8, Release);              \
        A(DirectSoundCaptureBuffer8, GetCaps);              \
        A(DirectSoundCaptureBuffer8, GetCurrentPosition);   \
        A(DirectSoundCaptureBuffer8, GetFormat);            \
        A(DirectSoundCaptureBuffer8, GetStatus);            \
        A(DirectSoundCaptureBuffer8, Initialize);           \
        A(DirectSoundCaptureBuffer8, Lock);                 \
        A(DirectSoundCaptureBuffer8, Start);                \
        A(DirectSoundCaptureBuffer8, Stop);                 \
        A(DirectSoundCaptureBuffer8, Unlock);               \
        A(DirectSoundCaptureBuffer8, GetObjectInPath);      \
        A(DirectSoundCaptureBuffer8, GetFXStatus);          \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSoundCaptureBuffer8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8GetCurrentPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8GETCURRENTPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->CapturePosition);
    FORMATVALUE(builder, TextFormatValue, value->ReadPosition); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8GetFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8GETFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SizeAllocated);
    FORMATVALUE(builder, TextFormatValue, value->SizeWritten); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8GetStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8GETSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Status /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8LockValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Offset);
    FORMATVALUE(builder, TextFormatValue, value->Bytes);
    FORMATVALUE(builder, TextFormatObject, value->Audio1 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes1);
    FORMATVALUE(builder, TextFormatObject, value->Audio2);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes2 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8StartValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8STARTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8StopValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8STOPMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8UNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Audio1 /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes1);
    FORMATVALUE(builder, TextFormatObject, value->Audio2);
    FORMATVALUE(builder, TextFormatValue, value->AudioBytes2 /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8GetObjectInPathValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8GETOBJECTINPATHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatValue, value->Index);
    FORMATVALUE(builder, TextFormatID, value->IID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8GetFXStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUNDCAPTUREBUFFER8GETFXSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Status /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSoundCaptureBuffer8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSoundCaptureBuffer8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
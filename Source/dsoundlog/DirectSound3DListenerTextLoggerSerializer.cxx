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
#include "DirectSound3DListenerLogger.hxx"
#include "DirectSound3DListenerTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(DirectSound3DListener, QueryInterface);           \
        A(DirectSound3DListener, AddRef);                   \
        A(DirectSound3DListener, Release);                  \
        A(DirectSound3DListener, GetAllParameters);         \
        A(DirectSound3DListener, GetDistanceFactor);        \
        A(DirectSound3DListener, GetDopplerFactor);         \
        A(DirectSound3DListener, GetOrientation);           \
        A(DirectSound3DListener, GetPosition);              \
        A(DirectSound3DListener, GetRolloffFactor);         \
        A(DirectSound3DListener, GetVelocity);              \
        A(DirectSound3DListener, SetAllParameters);         \
        A(DirectSound3DListener, SetDistanceFactor);        \
        A(DirectSound3DListener, SetDopplerFactor);         \
        A(DirectSound3DListener, SetOrientation);           \
        A(DirectSound3DListener, SetPosition);              \
        A(DirectSound3DListener, SetRolloffFactor);         \
        A(DirectSound3DListener, SetVelocity);              \
        A(DirectSound3DListener, CommitDeferredSettings);   \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSound3DListenerMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSound3DListenerQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSound3DListenerReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSound3DListenerGetAllParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERGETALLPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerGetDistanceFactorValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERGETDISTANCEFACTORMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Factor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerGetDopplerFactorValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERGETDOPPLERFACTORMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Factor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerGetOrientationValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERGETORIENTATIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Front /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Top /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerGetPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERGETPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Position /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerGetRolloffFactorValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERGETROLLOFFFACTORMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Factor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerGetVelocityValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERGETVELOCITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Velocity /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerSetAllParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERSETALLPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO*/);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerSetDistanceFactorValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERSETDISTANCEFACTORMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Factor);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerSetDopplerFactorValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERSETDOPPLERFACTORMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Factor);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerSetOrientationValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERSETORIENTATIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->FrontX);
    FORMATVALUE(builder, TextFormatValue, value->FrontY);
    FORMATVALUE(builder, TextFormatValue, value->FrontZ);
    FORMATVALUE(builder, TextFormatValue, value->TopX);
    FORMATVALUE(builder, TextFormatValue, value->TopY);
    FORMATVALUE(builder, TextFormatValue, value->TopZ);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerSetPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERSETPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatValue, value->Z);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerSetRolloffFactorValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERSETROLLOFFFACTORMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Factor);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerSetVelocityValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERSETVELOCITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatValue, value->Z);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO*/); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DListenerCommitDeferredSettingsValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DLISTENERCOMMITDEFERREDSETTINGSMETHODVALUE value) { return TRUE; }

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSound3DListenerMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSound3DListenerMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSound3DListenerMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
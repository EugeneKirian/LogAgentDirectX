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
#include "DirectSound3DBufferLogger.hxx"
#include "DirectSound3DBufferTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectSound3DBuffer, QueryInterface);         \
        A(DirectSound3DBuffer, AddRef);                 \
        A(DirectSound3DBuffer, Release);                \
        A(DirectSound3DBuffer, GetAllParameters);       \
        A(DirectSound3DBuffer, GetConeAngles);          \
        A(DirectSound3DBuffer, GetConeOrientation);     \
        A(DirectSound3DBuffer, GetConeOutsideVolume);   \
        A(DirectSound3DBuffer, GetMaxDistance);         \
        A(DirectSound3DBuffer, GetMinDistance);         \
        A(DirectSound3DBuffer, GetMode);                \
        A(DirectSound3DBuffer, GetPosition);            \
        A(DirectSound3DBuffer, GetVelocity);            \
        A(DirectSound3DBuffer, SetAllParameters);       \
        A(DirectSound3DBuffer, SetConeAngles);          \
        A(DirectSound3DBuffer, SetConeOrientation);     \
        A(DirectSound3DBuffer, SetConeOutsideVolume);   \
        A(DirectSound3DBuffer, SetMaxDistance);         \
        A(DirectSound3DBuffer, SetMinDistance);         \
        A(DirectSound3DBuffer, SetMode);                \
        A(DirectSound3DBuffer, SetPosition);            \
        A(DirectSound3DBuffer, SetVelocity);            \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectSound3DBufferMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectSound3DBufferQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSound3DBufferReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectSound3DBufferGetAllParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETALLPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferGetConeAnglesValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETCONEANGLESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->InsideConeAngle);
    FORMATVALUE(builder, TextFormatValue, value->OutsideConeAngle); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferGetConeOrientationValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETCONEORIENTATIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Orientation /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferGetConeOutsideVolumeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETCONEOUTSIDEVOLUMEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Volume /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferGetMaxDistanceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETMAXDISTANCEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Distance /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferGetMinDistanceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETMINDISTANCEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Distance /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferGetModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Mode /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferGetPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Position /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferGetVelocityValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERGETVELOCITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Velocity /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetAllParametersValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETALLPARAMETERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetConeAnglesValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETCONEANGLESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->InsideConeAngle);
    FORMATVALUE(builder, TextFormatValue, value->OutsideConeAngle);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetConeOrientationValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETCONEORIENTATIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatValue, value->Z);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetConeOutsideVolumeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETCONEOUTSIDEVOLUMEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Volume);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetMaxDistanceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETMAXDISTANCEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Distance);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetMinDistanceValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETMINDISTANCEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Distance);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Mode /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatValue, value->Z);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectSound3DBufferSetVelocityValue(LPSTRINGBUILDER builder, CONST LPDIRECTSOUND3DBUFFERSETVELOCITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatValue, value->Z);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectSound3DBufferMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectSound3DBufferMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectSound3DBufferMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
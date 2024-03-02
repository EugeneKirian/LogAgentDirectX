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

#pragma once

#include "Base.hxx"

typedef struct DirectSound8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECTSOUND8QUERYINTERFACEMETHODVALUE, * LPDIRECTSOUND8QUERYINTERFACEMETHODVALUE;

typedef struct DirectSound8AddRefMethodValue
{

} DIRECTSOUND8ADDREFMETHODVALUE, * LPDIRECTSOUND8ADDREFMETHODVALUE;

typedef struct DirectSound8ReleaseMethodValue
{

} DIRECTSOUND8RELEASEMETHODVALUE, * LPDIRECTSOUND8RELEASEMETHODVALUE;

typedef struct DirectSound8CreateSoundBufferMethodValue
{
    LPCDSBUFFERDESC Descriptor;
    LPDIRECTSOUNDBUFFER* Buffer;
    LPUNKNOWN Unknown;
} DIRECTSOUND8CREATESOUNDBUFFERMETHODVALUE, * LPDIRECTSOUND8CREATESOUNDBUFFERMETHODVALUE;

typedef struct DirectSound8GetCapsMethodValue
{
    LPDSCAPS Caps;
} DIRECTSOUND8GETCAPSMETHODVALUE, * LPDIRECTSOUND8GETCAPSMETHODVALUE;

typedef struct DirectSound8DuplicateSoundBufferMethodValue
{
    LPDIRECTSOUNDBUFFER Original;
    LPDIRECTSOUNDBUFFER* Duplicate;
} DIRECTSOUND8DUPLICATESOUNDBUFFERMETHODVALUE, * LPDIRECTSOUND8DUPLICATESOUNDBUFFERMETHODVALUE;

typedef struct DirectSound8SetCooperativeLevelMethodValue
{
    HWND Window;
    DWORD Options;
} DIRECTSOUND8SETCOOPERATIVELEVELMETHODVALUE, * LPDIRECTSOUND8SETCOOPERATIVELEVELMETHODVALUE;

typedef struct DirectSound8CompactMethodValue
{

} DIRECTSOUND8COMPACTMETHODVALUE, * LPDIRECTSOUND8COMPACTMETHODVALUE;

typedef struct DirectSound8GetSpeakerConfigMethodValue
{
    LPDWORD Configuration;
} DIRECTSOUND8GETSPEAKERCONFIGMETHODVALUE, * LPDIRECTSOUND8GETSPEAKERCONFIGMETHODVALUE;

typedef struct DirectSound8SetSpeakerConfigMethodValue
{
    DWORD Configuration;
} DIRECTSOUND8SETSPEAKERCONFIGMETHODVALUE, * LPDIRECTSOUND8SETSPEAKERCONFIGMETHODVALUE;

typedef struct DirectSound8InitializeMethodValue
{
    LPCGUID ID;
} DIRECTSOUND8INITIALIZEMETHODVALUE, * LPDIRECTSOUND8INITIALIZEMETHODVALUE;

typedef struct DirectSound8VerifyCertificationMethodValue
{
    LPDWORD Value;
} DIRECTSOUND8VERIFYCERTIFICATIONMETHODVALUE, * LPDIRECTSOUND8VERIFYCERTIFICATIONMETHODVALUE;
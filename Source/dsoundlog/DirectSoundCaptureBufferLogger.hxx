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

typedef struct DirectSoundCaptureBufferQueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECTSOUNDCAPTUREBUFFERQUERYINTERFACEMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERQUERYINTERFACEMETHODVALUE;

typedef struct DirectSoundCaptureBufferAddRefMethodValue
{

} DIRECTSOUNDCAPTUREBUFFERADDREFMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERADDREFMETHODVALUE;

typedef struct DirectSoundCaptureBufferReleaseMethodValue
{

} DIRECTSOUNDCAPTUREBUFFERRELEASEMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERRELEASEMETHODVALUE;

typedef struct DirectSoundCaptureBufferGetCapsMethodValue
{
    LPDSCBCAPS Caps;
} DIRECTSOUNDCAPTUREBUFFERGETCAPSMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERGETCAPSMETHODVALUE;

typedef struct DirectSoundCaptureBufferGetCurrentPositionMethodValue
{
    LPDWORD CapturePosition;
    LPDWORD ReadPosition;
} DIRECTSOUNDCAPTUREBUFFERGETCURRENTPOSITIONMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERGETCURRENTPOSITIONMETHODVALUE;

typedef struct DirectSoundCaptureBufferGetFormatMethodValue
{
    LPWAVEFORMATEX Format;
    DWORD SizeAllocated;
    LPDWORD SizeWritten;
} DIRECTSOUNDCAPTUREBUFFERGETFORMATMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERGETFORMATMETHODVALUE;

typedef struct DirectSoundCaptureBufferGetStatusMethodValue
{
    LPDWORD Status;
} DIRECTSOUNDCAPTUREBUFFERGETSTATUSMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERGETSTATUSMETHODVALUE;

typedef struct DirectSoundCaptureBufferInitializeMethodValue
{
    LPDIRECTSOUNDCAPTURE Object;
    LPCDSCBUFFERDESC Descriptor;
} DIRECTSOUNDCAPTUREBUFFERINITIALIZEMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERINITIALIZEMETHODVALUE;

typedef struct DirectSoundCaptureBufferLockMethodValue
{
    DWORD Offset;
    DWORD Bytes;
    LPVOID* Audio1;
    LPDWORD AudioBytes1;
    LPVOID* Audio2;
    LPDWORD AudioBytes2;
    DWORD Options;
} DIRECTSOUNDCAPTUREBUFFERLOCKMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERLOCKMETHODVALUE;

typedef struct DirectSoundCaptureBufferStartMethodValue
{
    DWORD Options;
} DIRECTSOUNDCAPTUREBUFFERSTARTMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERSTARTMETHODVALUE;

typedef struct DirectSoundCaptureBufferStopMethodValue
{

} DIRECTSOUNDCAPTUREBUFFERSTOPMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERSTOPMETHODVALUE;

typedef struct DirectSoundCaptureBufferUnlockMethodValue
{
    LPVOID Audio1;
    DWORD AudioBytes1;
    LPVOID Audio2;
    DWORD AudioBytes2;
} DIRECTSOUNDCAPTUREBUFFERUNLOCKMETHODVALUE, * LPDIRECTSOUNDCAPTUREBUFFERUNLOCKMETHODVALUE;
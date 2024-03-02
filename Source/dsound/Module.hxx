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

#include "Export.hxx"

#define DIRECT_SOUND_LIBRARY_NAME "DSOUND.DLL"

#define DIRECT_SOUND_LIBRARY_PATH_LENGTH (MAX_PATH)
#define DIRECT_SOUND_LIBRARY_FILE_PATH_LENGTH (MAX_PATH + 100)

struct ModuleState
{
    BOOL Initialized;

    HMODULE Module;

    LPASSEMBLER Assembler;
    LPLOGGER Logger;

    LPDIRECTSOUNDCAPTURECREATE DirectSoundCaptureCreate;
    LPDIRECTSOUNDCAPTURECREATE8 DirectSoundCaptureCreate8;
    LPDIRECTSOUNDCAPTUREENUMERATEA DirectSoundCaptureEnumerateA;
    LPDIRECTSOUNDCAPTUREENUMERATEW DirectSoundCaptureEnumerateW;
    LPDIRECTSOUNDCREATE DirectSoundCreate;
    LPDIRECTSOUNDCREATE8 DirectSoundCreate8;
    LPDIRECTSOUNDENUMERATEA DirectSoundEnumerateA;
    LPDIRECTSOUNDENUMERATEW DirectSoundEnumerateW;
    LPDIRECTSOUNDFULLDUPLEXCREATE DirectSoundFullDuplexCreate;
    LPDLLCANUNLOADNOW DllCanUnloadNow;
    LPDLLGETCLASSOBJECT DllGetClassObject;
    LPGETDEVICEID GetDeviceID;
};

extern ModuleState Module;

#define INITIALIZE_MODULE_OK 0
#define INITIALIZE_MODULE_LOAD_ERROR 1
#define INITIALIZE_MODULE_LOGGER_ERROR 2

UINT InitializeModule(VOID);
BOOL ReleaseModule(VOID);
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

#include "Module.hxx"
#include "ModuleLogger.hxx"

#include <shlwapi.h>

ModuleState Module;

static BOOL InitializeModuleFilePath(LPSTR path)
{
    CHAR dir[DIRECT_SOUND_LIBRARY_PATH_LENGTH];
    ZeroMemory(dir, DIRECT_SOUND_LIBRARY_PATH_LENGTH);

    if (GetSystemDirectoryA(dir, DIRECT_SOUND_LIBRARY_PATH_LENGTH) == 0) { return FALSE; }

    if (PathCombineA(path, dir, DIRECT_SOUND_LIBRARY_NAME) == NULL) { return FALSE; }

    return TRUE;
}

UINT InitializeModule()
{
    CHAR path[DIRECT_SOUND_LIBRARY_FILE_PATH_LENGTH];
    ZeroMemory(path, DIRECT_SOUND_LIBRARY_FILE_PATH_LENGTH);

    if (!InitializeModuleFilePath(path)) { return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.Module = LoadLibraryA(path);

    if (Module.Module == NULL) { return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DirectSoundCaptureCreate = (LPDIRECTSOUNDCAPTURECREATE)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_CAPTURE_CREATE_NAME);
    if (Module.DirectSoundCaptureCreate == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DirectSoundCaptureCreate8 = (LPDIRECTSOUNDCAPTURECREATE8)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_CAPTURE_CREATE_8_NAME);

    Module.DirectSoundCaptureEnumerateA = (LPDIRECTSOUNDCAPTUREENUMERATEA)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_CAPTURE_ENUMERATE_A_NAME);
    if (Module.DirectSoundCaptureEnumerateA == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DirectSoundCaptureEnumerateW = (LPDIRECTSOUNDCAPTUREENUMERATEW)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_CAPTURE_ENUMERATE_W_NAME);
    if (Module.DirectSoundCaptureEnumerateW == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DirectSoundCreate = (LPDIRECTSOUNDCREATE)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_CREATE_NAME);
    if (Module.DirectSoundCreate == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DirectSoundCreate8 = (LPDIRECTSOUNDCREATE8)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_CREATE_8_NAME);

    Module.DirectSoundEnumerateA = (LPDIRECTSOUNDENUMERATEA)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_ENUMERATE_A_NAME);
    if (Module.DirectSoundEnumerateA == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DirectSoundEnumerateW = (LPDIRECTSOUNDENUMERATEW)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_ENUMERATE_W_NAME);
    if (Module.DirectSoundEnumerateW == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DirectSoundFullDuplexCreate = (LPDIRECTSOUNDFULLDUPLEXCREATE)GetProcAddress(Module.Module, DIRECT_SOUND_DIRECT_SOUND_FULL_DUPLEX_CREATE_NAME);

    Module.DllCanUnloadNow = (LPDLLCANUNLOADNOW)GetProcAddress(Module.Module, DIRECT_SOUND_DLL_CAN_UNLOAD_NOW_NAME);
    if (Module.DllCanUnloadNow == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DllGetClassObject = (LPDLLGETCLASSOBJECT)GetProcAddress(Module.Module, DIRECT_SOUND_DLL_GET_CLASS_OBJECT_NAME);
    if (Module.DllGetClassObject == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.GetDeviceID = (LPGETDEVICEID)GetProcAddress(Module.Module, DIRECT_SOUND_GET_DEVICE_ID_NAME);
    if (Module.GetDeviceID == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    if (!InitializeModuleLogger()) { return INITIALIZE_MODULE_LOGGER_ERROR; }

    Module.Assembler = new Assembler();

    Module.Initialized = TRUE;

    return INITIALIZE_MODULE_OK;
}

BOOL ReleaseModule()
{
    if (Module.Assembler != NULL) { delete Module.Assembler; }

    if (Module.Logger != NULL) { delete Module.Logger; }

    CONST BOOL result = Module.Module != NULL ? FreeLibrary(Module.Module) : FALSE;

    ZeroMemory(&Module, sizeof(ModuleState));

    return result;
}
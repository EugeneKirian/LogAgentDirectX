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

LPMODULE InitializeModule(LPCSTR path)
{
    LPMODULE result = new MODULE();

    result->Module = LoadLibraryA(path);

    if (result->Module == NULL) { return FALSE; }

    result->DirectSoundCaptureCreate = (LPDIRECTSOUNDCAPTURECREATE)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_CAPTURE_CREATE_NAME);
    if (result->DirectSoundCaptureCreate == NULL) { ReleaseModule(result); return NULL; }

    result->DirectSoundCaptureCreate8 = (LPDIRECTSOUNDCAPTURECREATE8)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_CAPTURE_CREATE_8_NAME);

    result->DirectSoundCaptureEnumerateA = (LPDIRECTSOUNDCAPTUREENUMERATEA)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_CAPTURE_ENUMERATE_A_NAME);
    if (result->DirectSoundCaptureEnumerateA == NULL) { ReleaseModule(result); return NULL; }

    result->DirectSoundCaptureEnumerateW = (LPDIRECTSOUNDCAPTUREENUMERATEW)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_CAPTURE_ENUMERATE_W_NAME);
    if (result->DirectSoundCaptureEnumerateW == NULL) { ReleaseModule(result); return NULL; }

    result->DirectSoundCreate = (LPDIRECTSOUNDCREATE)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_CREATE_NAME);
    if (result->DirectSoundCreate == NULL) { ReleaseModule(result); return NULL; }

    result->DirectSoundCreate8 = (LPDIRECTSOUNDCREATE8)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_CREATE_8_NAME);

    result->DirectSoundEnumerateA = (LPDIRECTSOUNDENUMERATEA)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_ENUMERATE_A_NAME);
    if (result->DirectSoundEnumerateA == NULL) { ReleaseModule(result); return NULL; }

    result->DirectSoundEnumerateW = (LPDIRECTSOUNDENUMERATEW)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_ENUMERATE_W_NAME);
    if (result->DirectSoundEnumerateW == NULL) { ReleaseModule(result); return NULL; }

    result->DirectSoundFullDuplexCreate = (LPDIRECTSOUNDFULLDUPLEXCREATE)GetProcAddress(result->Module, DIRECT_SOUND_DIRECT_SOUND_FULL_DUPLEX_CREATE_NAME);

    result->DllCanUnloadNow = (LPDLLCANUNLOADNOW)GetProcAddress(result->Module, DIRECT_SOUND_DLL_CAN_UNLOAD_NOW_NAME);
    if (result->DllCanUnloadNow == NULL) { ReleaseModule(result); return NULL; }

    result->DllGetClassObject = (LPDLLGETCLASSOBJECT)GetProcAddress(result->Module, DIRECT_SOUND_DLL_GET_CLASS_OBJECT_NAME);
    if (result->DllGetClassObject == NULL) { ReleaseModule(result); return NULL; }

    result->GetDeviceID = (LPGETDEVICEID)GetProcAddress(result->Module, DIRECT_SOUND_GET_DEVICE_ID_NAME);
    if (result->GetDeviceID == NULL) { ReleaseModule(result); return NULL; }

    return result;
}

BOOL ReleaseModule(LPMODULE module)
{
    if (module == NULL || module->Module == NULL) { return FALSE; }

    FreeLibrary(module->Module);

    delete module;

    return TRUE;
}
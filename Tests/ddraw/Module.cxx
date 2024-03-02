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

    result->AcquireInternalLock = (LPACQUIREDIRECTDRAWTHREADLOCK)GetProcAddress(result->Module, DIRECT_DRAW_ACQUIRE_DIRECT_DRAW_THREAD_LOCK_NAME);
    if (result->AcquireInternalLock == NULL) { ReleaseModule(result); return NULL; }

    result->CompleteCreateSysmemSurface = (LPCOMPLETECREATESYSTEMMEMORYSURFACE)GetProcAddress(result->Module, DIRECT_DRAW_COMPLETE_CREATE_SYSTEM_MEMORY_SURFACE_NAME);
    if (result->CompleteCreateSysmemSurface == NULL) { ReleaseModule(result); return NULL; }

    result->ParseUnknownCommand = (LPDIRECT3DPARSEUNKNOWNCOMMAND)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_3D_PARSE_UNKNOWN_COMMAND_NAME);
    if (result->ParseUnknownCommand == NULL) { ReleaseModule(result); return NULL; }

    result->GetAttachedSurfaceLocal = (LPDIRECTDRAWGETATTACHEDSURFACELOCAL)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_GET_ATTACHED_SURFACE_LOCAL_NAME);
    if (result->GetAttachedSurfaceLocal == NULL) { ReleaseModule(result); return NULL; }

    result->InternalLock = (LPDIRECTDRAWINTERNALLOCK)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_INTERNAL_LOCK_NAME);
    if (result->InternalLock == NULL) { ReleaseModule(result); return NULL; }

    result->InternalUnlock = (LPDIRECTDRAWINTERNALUNLOCK)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_INTERAL_UNLOCK_NAME);
    if (result->InternalUnlock == NULL) { ReleaseModule(result); return NULL; }

    result->DirectSoundHelp = (LPDIRECTSOUNDHELP)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_SOUND_HELP_NAME);
    if (result->DirectSoundHelp == NULL) { ReleaseModule(result); return NULL; }

    result->DirectDrawCreate = (LPDIRECTDRAWCREATE)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_CREATE_NAME);
    if (result->DirectDrawCreate == NULL) { ReleaseModule(result); return NULL; }

    result->DirectDrawCreateClipper = (LPDIRECTDRAWCREATECLIPPER)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_CREATE_CLIPPER_NAME);
    if (result->DirectDrawCreateClipper == NULL) { ReleaseModule(result); return NULL; }

    result->DirectDrawCreateEx = (LPDIRECTDRAWCREATEEX)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_CREATE_EX_NAME);
    if (result->DirectDrawCreateEx == NULL) { ReleaseModule(result); return NULL; }

    result->DirectDrawEnumerateA = (LPDIRECTDRAWENUMA)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_ENUMERATE_A_NAME);
    if (result->DirectDrawEnumerateA == NULL) { ReleaseModule(result); return NULL; }

    result->DirectDrawEnumerateExA = (LPDIRECTDRAWENUMERATEEXA)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_ENUMERATE_EX_A_NAME);
    if (result->DirectDrawEnumerateExA == NULL) { ReleaseModule(result); return NULL; }

    result->DirectDrawEnumerateExW = (LPDIRECTDRAWENUMERATEEXW)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_ENUMERATE_EX_W_NAME);
    if (result->DirectDrawEnumerateExW == NULL) { ReleaseModule(result); return NULL; }

    result->DirectDrawEnumerateW = (LPDIRECTDRAWENUMW)GetProcAddress(result->Module, DIRECT_DRAW_DIRECT_DRAW_ENUMERATE_W_NAME);
    if (result->DirectDrawEnumerateW == NULL) { ReleaseModule(result); return NULL; }

    result->DllCanUnloadNow = (LPDLLCANUNLOADNOW)GetProcAddress(result->Module, DIRECT_DRAW_CAN_UNLOAD_NOW_NAME);
    if (result->DllCanUnloadNow == NULL) { ReleaseModule(result); return NULL; }

    result->DllGetClassObject = (LPDLLGETCLASSOBJECT)GetProcAddress(result->Module, DIRECT_DRAW_GET_CLASS_OBJECT_NAME);
    if (result->DllGetClassObject == NULL) { ReleaseModule(result); return NULL; }

    result->GetDirectDrawSurfaceLocal = (LPGETDIRECTDRAWSURFACELOCAL)GetProcAddress(result->Module, DIRECT_DRAW_GET_DIRECT_DRAW_SURFACE_LOCAL_NAME);
    if (result->GetDirectDrawSurfaceLocal == NULL) { ReleaseModule(result); return NULL; }

    result->GetOLEThunkData = (LPGETOLETHUNKDATA)GetProcAddress(result->Module, DIRECT_DRAW_GET_OLE_THUNK_DATA_NAME);
    if (result->GetOLEThunkData == NULL) { ReleaseModule(result); return NULL; }

    result->GetSurfaceFromDeviceContext = (LPGETSURFACEFROMDEVICECONTEXT)GetProcAddress(result->Module, DIRECT_DRAW_GET_SURFACE_FROM_DEVICE_CONTEXT_NAME);
    if (result->GetSurfaceFromDeviceContext == NULL) { ReleaseModule(result); return NULL; }

    result->RegisterSpecialCase = (LPREGISTERSPECIALCASE)GetProcAddress(result->Module, DIRECT_DRAW_REGISTER_SPECIAL_CASE_NAME);
    if (result->RegisterSpecialCase == NULL) { ReleaseModule(result); return NULL; }

    result->ReleaseThreadLock = (LPRELEASEDIRECTDRAWTHREADLOCK)GetProcAddress(result->Module, DIRECT_DRAW_RELEASE_DIRECT_DRAW_THREAD_LOCK_NAME);
    if (result->ReleaseThreadLock == NULL) { ReleaseModule(result); return NULL; }

    result->SetApplicationCompatibilityData = (LPSETAPPLICATIONCOMPATIBILITYDATA)GetProcAddress(result->Module, DIRECT_DRAW_SET_APPLICATION_COMPATIBILITY_DATA_NAME);

    return result;
}

BOOL ReleaseModule(LPMODULE module)
{
    if (module == NULL || module->Module == NULL) { return FALSE; }

    FreeLibrary(module->Module);

    delete module;

    return TRUE;
}
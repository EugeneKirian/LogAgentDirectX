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

MODULESTATE Module;

static BOOL InitializeModuleFilePath(LPSTR path)
{
    CHAR dir[DIRECT3D_LIBRARY_PATH_LENGTH];
    ZeroMemory(dir, DIRECT3D_LIBRARY_PATH_LENGTH);

    if (GetSystemDirectoryA(dir, DIRECT3D_LIBRARY_PATH_LENGTH) == 0) { return FALSE; }

    if (PathCombineA(path, dir, DIRECT3D_LIBRARY_NAME) == NULL) { return FALSE; }

    return TRUE;
}

UINT InitializeModule()
{
    CHAR path[DIRECT3D_LIBRARY_FILE_PATH_LENGTH];
    ZeroMemory(path, DIRECT3D_LIBRARY_FILE_PATH_LENGTH);

    if (!InitializeModuleFilePath(path)) { return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.Module = LoadLibraryA(path);

    if (Module.Module == NULL) { return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.EnableMaximizedWindowedMode = (LPENABLEMAXIMIZEDWINDOWEDMODE)GetProcAddress(Module.Module, DIRECT3D_CHECK_FULL_SCREEN_NAME);

    Module.ValidatePixelShader = (LPVALIDATEPIXELSHADER)GetProcAddress(Module.Module, DIRECT3D_VALIDATE_PIXEL_SHADER_NAME);
    if (Module.ValidatePixelShader == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.ValidateVertexShader = (LPVALIDATEVERTEXSHADER)GetProcAddress(Module.Module, DIRECT3D_VALIDATE_VERTEX_SHADER_NAME);
    if (Module.ValidateVertexShader == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.DebugSetMute = (LPDEBUGSETMUTE)GetProcAddress(Module.Module, DIRECT3D_DEBUG_SET_MUTE_NAME);
    if (Module.DebugSetMute == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

    Module.Direct3DCreate8 = (LPDIRECT3DCREATE8)GetProcAddress(Module.Module, DIRECT3D_DIRECT3DCREATE8_NAME);
    if (Module.Direct3DCreate8 == NULL) { ReleaseModule(); return INITIALIZE_MODULE_LOAD_ERROR; }

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

    ZeroMemory(&Module, sizeof(MODULESTATE));

    return result;
}
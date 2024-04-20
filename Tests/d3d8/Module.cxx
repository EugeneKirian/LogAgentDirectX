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

    result->Direct3DCreate8 = (LPDIRECT3DCREATE8)GetProcAddress(result->Module, DIRECT3D_DIRECT3DCREATE8_NAME);
    if (result->Direct3DCreate8 == NULL) { ReleaseModule(result); return NULL; }

    result->DebugSetMute = (LPDEBUGSETMUTE)GetProcAddress(result->Module, DIRECT3D_DEBUG_SET_MUTE_NAME);
    if (result->DebugSetMute == NULL) { ReleaseModule(result); return NULL; }

    result->ValidateVertexShader = (LPVALIDATEVERTEXSHADER)GetProcAddress(result->Module, DIRECT3D_VALIDATE_VERTEX_SHADER_NAME);
    if (result->ValidateVertexShader == NULL) { ReleaseModule(result); return NULL; }

    result->ValidatePixelShader = (LPVALIDATEPIXELSHADER)GetProcAddress(result->Module, DIRECT3D_VALIDATE_PIXEL_SHADER_NAME);
    if (result->ValidatePixelShader == NULL) { ReleaseModule(result); return NULL; }

    result->EnableMaximizedWindowedMode = (LPENABLEMAXIMIZEDWINDOWEDMODE)GetProcAddress(result->Module, DIRECT3D_CHECK_FULL_SCREEN_NAME);

    return result;
}

BOOL ReleaseModule(LPMODULE module)
{
    if (module == NULL || module->Module == NULL) { return FALSE; }

    FreeLibrary(module->Module);

    delete module;

    return TRUE;
}
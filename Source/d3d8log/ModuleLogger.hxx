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

typedef struct ModuleEnableMaximizedWindowedModeMethodValue
{
    BOOL Enable;
} MODULEENABLEMAXIMIZEDWINDOWEDMODEMETHODVALUE, * LPMODULEENABLEMAXIMIZEDWINDOWEDMODEMETHODVALUE;

typedef struct ModuleValidatePixelShaderMethodValue
{
    DWORD* Shader;
    D3DCAPS8* Caps;
    BOOL ReturnErrors;
    CHAR** Errors;
} MODULEVALIDATEPIXELSHADERMETHODVALUE, * LPMODULEVALIDATEPIXELSHADERMETHODVALUE;

typedef struct ModuleValidateVertexShaderMethodValue
{
    DWORD* Shader;
    DWORD* Declaration;
    D3DCAPS8* Caps;
    BOOL ReturnErrors;
    CHAR** Errors;
} MODULEVALIDATEVERTEXSHADERMETHODVALUE, * LPMODULEVALIDATEVERTEXSHADERMETHODVALUE;

typedef struct ModuleDebugSetMuteMethodValue
{

} MODULEDEBUGSETMUTEMETHODVALUE, * LPMODULEDEBUGSETMUTEMETHODVALUE;

typedef struct ModuleDirect3DCreate8MethodValue
{
    UINT Version;
} MODULEDIRECT3DCREATE8METHODVALUE, * LPMODULEDIRECT3DCREATE8METHODVALUE;
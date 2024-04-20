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

#include "Agent.hxx"
#include "Base.hxx"
#include "Direct3D8.hxx"
#include "Export.hxx"
#include "Module.hxx"

#include <ModuleLogger.hxx>

#define ModuleLogMethod(LEVEL, M) LogMethodMacro(Module.Logger, LEVEL, Module, M, NULL)

#define ModuleLogMethodValue(LEVEL, M, C, PARAMS) LogMethodValueMacro(Module.Logger, LEVEL, Module, M, NULL, C, PARAMS)

#define ModuleLogMethodVoidResult(LEVEL, M)                                                                                             \
    if (Module.Logger->IsAcceptable(LOGGER_LEVEL_##LEVEL))                                                                              \
    {                                                                                                                                   \
        LogMethodResult(Module.Logger, LOGGER_LEVEL_##LEVEL, OBJECT_ID_Module, NULL, METHOD_ID_Module_##M, (DWORD)NULL, NULL);          \
    }

#define ModuleLogMethodResult(LEVEL, M, ERR, RT, R) LogMethodResultMacro(Module.Logger, LEVEL, Module, M, NULL, ERR, RT, R)

#define ModuleLogMethodResultValue(LEVEL, M, ERR, RT, R, C, PARAMS) LogMethodResultValueMacro(Module.Logger, LEVEL, Module, M, NULL, ERR, RT, R, C, PARAMS)

#define ModuleLogMethodCallbackValue(LEVEL, M, C, PARAMS) LogMethodCallbackValueMacro(Module.Logger, LEVEL, Module, M, M, NULL, C, PARAMS)

#define ModuleLogMethodCallbackResultValue(LEVEL, M, RT, R, C, PARAMS) LogMethodCallbackResultValueMacro(Module.Logger, LEVEL, Module, M, M, NULL, RT, R, C, PARAMS)

// NOTE: The method is called CheckFullscreen in Windows XP.
extern "C" HRESULT WINAPI Direct3D8EnableMaximizedWindowedModeShim(BOOL Enable)
{
    ModuleLogMethodValue(TRACE, EnableMaximizedWindowedMode, 1, (Enable));

    if (Module.EnableMaximizedWindowedMode == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, EnableMaximizedWindowedMode, TRUE, HRESULT, E_NOTIMPL, 1, (Enable)); }

    CONST HRESULT result = Module.EnableMaximizedWindowedMode(Enable);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, EnableMaximizedWindowedMode, FAILED(result), HRESULT, result, 1, (Enable));
}

extern "C" HRESULT WINAPI ValidatePixelShader(DWORD * Shader, D3DCAPS8 * Caps, BOOL ReturnErrors, CHAR * *Errors)
{
    ModuleLogMethodValue(TRACE, ValidatePixelShader, 4, (Shader, Caps, ReturnErrors, Errors));

    CONST HRESULT result = Module.ValidatePixelShader(Shader, Caps, ReturnErrors, Errors);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, ValidatePixelShader, FAILED(result), HRESULT, result, 4, (Shader, Caps, ReturnErrors, Errors));
}

extern "C" HRESULT WINAPI ValidateVertexShader(DWORD * Shader, DWORD * Declaration, D3DCAPS8 * Caps, BOOL ReturnErrors, CHAR * *Errors)
{
    ModuleLogMethodValue(TRACE, ValidateVertexShader, 5, (Shader, Declaration, Caps, ReturnErrors, Errors));

    CONST HRESULT result = Module.ValidateVertexShader(Shader, Declaration, Caps, ReturnErrors, Errors);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, ValidateVertexShader, FAILED(result), HRESULT, result, 5, (Shader, Declaration, Caps, ReturnErrors, Errors));
}

extern "C" VOID WINAPI DebugSetMute(VOID)
{
    ModuleLogMethod(TRACE, DebugSetMute);

    Module.DebugSetMute();

    ModuleLogMethodVoidResult(TRACEDEBUG, DebugSetMute);
}

// Creates an instance of a Direct3D8 object.
extern "C" LPDIRECT3D8 WINAPI Direct3DCreate8(UINT Version)
{
    ModuleLogMethodValue(TRACE, Direct3DCreate8, 1, (Version));

    LPDIRECT3D8 result = Module.Direct3DCreate8(Version);

    if (result != NULL) { result = AssembleAgent(Direct3D8, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, result); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, Direct3DCreate8, result == NULL, LPDIRECT3D8, result, 1, (Version));
}
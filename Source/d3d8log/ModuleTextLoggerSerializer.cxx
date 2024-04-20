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

#include "ModuleLogger.hxx"
#include "ModuleTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Module, EnableMaximizedWindowedMode);     \
        A(Module, ValidatePixelShader);             \
        A(Module, ValidateVertexShader);            \
        A(Module, DebugSetMute);                    \
        A(Module, Direct3DCreate8);                 \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerModuleMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerModuleEnableMaximizedWindowedModeValue(LPSTRINGBUILDER builder, CONST LPMODULEENABLEMAXIMIZEDWINDOWEDMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Enable); return TRUE;
}

static CONST BOOL AcquireLoggerModuleValidatePixelShaderValue(LPSTRINGBUILDER builder, CONST LPMODULEVALIDATEPIXELSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Shader /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->ReturnErrors);
    FORMATVALUE(builder, TextFormatObject, value->Errors /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerModuleValidateVertexShaderValue(LPSTRINGBUILDER builder, CONST LPMODULEVALIDATEVERTEXSHADERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Shader /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Declaration /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->ReturnErrors);
    FORMATVALUE(builder, TextFormatObject, value->Errors /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDebugSetMuteValue(LPSTRINGBUILDER builder, CONST LPMODULEDEBUGSETMUTEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerModuleDirect3DCreate8Value(LPSTRINGBUILDER builder, CONST LPMODULEDIRECT3DCREATE8METHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Version); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerModuleMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerModuleMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerModuleMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }
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

#include "Array.hxx"
#include "Direct3D8TextLoggerSerializer.hxx"
#include "Direct3DBaseTexture8TextLoggerSerializer.hxx"
#include "Direct3DCubeTexture8TextLoggerSerializer.hxx"
#include "Direct3DDevice8TextLoggerSerializer.hxx"
#include "Direct3DIndexBuffer8TextLoggerSerializer.hxx"
#include "Direct3DResource8TextLoggerSerializer.hxx"
#include "Direct3DSurface8TextLoggerSerializer.hxx"
#include "Direct3DSwapChain8TextLoggerSerializer.hxx"
#include "Direct3DTexture8TextLoggerSerializer.hxx"
#include "Direct3DVertexBuffer8TextLoggerSerializer.hxx"
#include "Direct3DVolume8TextLoggerSerializer.hxx"
#include "Direct3DVolumeTexture8TextLoggerSerializer.hxx"
#include "ModuleTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"
#include "UnknownTextLoggerSerializer.hxx"

static BOOL AcquireLoggerLevelValue(LPSTRINGBUILDER builder, CONST LOGGERLEVEL level)
{
    Array<LOGGERLEVEL> array;

    if (level & LOGGER_LEVEL_TRACE) { if (!array.Contains(LOGGER_LEVEL_TRACE)) { array.Add(LOGGER_LEVEL_TRACE); } }
    if (level & LOGGER_LEVEL_DEBUG) { if (!array.Contains(LOGGER_LEVEL_DEBUG)) { array.Add(LOGGER_LEVEL_DEBUG); } }
    if (level & LOGGER_LEVEL_INFO) { if (!array.Contains(LOGGER_LEVEL_INFO)) { array.Add(LOGGER_LEVEL_INFO); } }
    if (level & LOGGER_LEVEL_ERROR) { if (!array.Contains(LOGGER_LEVEL_ERROR)) { array.Add(LOGGER_LEVEL_ERROR); } }

    if (array.Count() == 0) { FORMAT(builder, Append("NONE")); }

    for (INT x = 0; x < array.Count(); x++)
    {
        if (x != 0) { FORMAT(builder, Append("|")); }

        switch (array[x])
        {
        case LOGGER_LEVEL_ERROR: { FORMAT(builder, Append("ERROR")); break; }
        case LOGGER_LEVEL_INFO: { FORMAT(builder, Append("INFO")); break; }
        case LOGGER_LEVEL_DEBUG: { FORMAT(builder, Append("DEBUG")); break; }
        case LOGGER_LEVEL_TRACE: { FORMAT(builder, Append("TRACE")); break; }
        }
    }

    return TRUE;
}

static CONST LPCSTR AcquireLoggerActionValue(CONST LOGGERACTIONID id)
{
    switch (id)
    {
    case LOGGER_ACTION_ID_INITIALIZE: { return "INITIALIZE"; }
    case LOGGER_ACTION_ID_MESSAGE: { return "MESSAGE"; }
    case LOGGER_ACTION_ID_ATTACHPROCESS: { return "ATTACHPROCESS"; }
    case LOGGER_ACTION_ID_DETACHPROCESS: { return "DETACHPROCESS"; }
    case LOGGER_ACTION_ID_ATTACHTHREAD: { return "ATTACHTHREAD"; }
    case LOGGER_ACTION_ID_DETACHTHREAD: { return "DETACHTHREAD"; }
    case LOGGER_ACTION_ID_CONSTRUCTOR: { return "CONSTRUCTOR"; }
    case LOGGER_ACTION_ID_DESTRUCTOR: { return "DESTRUCTOR"; }
    case LOGGER_ACTION_ID_METHOD: { return "METHOD"; }
    case LOGGER_ACTION_ID_METHODCALLBACK: { return "CALLBACK"; }
    case LOGGER_ACTION_ID_METHODRESULT: { return "METHODRESULT"; }
    case LOGGER_ACTION_ID_METHODCALLBACKRESULT: { return "CALLBACKRESULT"; }
    }

    return "<UNKNOWN>";
}

static CONST BOOL FormatLoggerActionInitialize(LPSTRINGBUILDER builder, CONST LOGGERLEVEL, CONST LPLOGGERACTIONINITIALIZE action)
{
    return builder->Format("[DXAGNT][DDRAW][%d][%d][%d][%d][%d]",
        ACQUIRE_LOGGER_VERSION_MAJOR(action->Version), ACQUIRE_LOGGER_VERSION_MINOR(action->Version),
        ACQUIRE_LOGGER_VERSION_PATCH(action->Version), ACQUIRE_LOGGER_VERSION_BUILD(action->Version), action->Platform);
}

static CONST BOOL FormatLoggerActionMessage(LPSTRINGBUILDER builder, CONST LOGGERLEVEL, CONST LPLOGGERACTIONMESSAGE action)
{
    return action->Arguments == NULL
        ? builder->Format("[%s]", action->Message)
        : builder->Arguments(action->Message, action->Arguments);
}

static CONST BOOL FormatLoggerActionAttachProcess(LPSTRINGBUILDER builder, CONST LOGGERLEVEL, CONST LPLOGGERACTIONATTACHPROCESS action)
{
    return builder->Format("[%s]", action->Name);
}

static CONST BOOL FormatLoggerActionDetachProcess(LPSTRINGBUILDER builder, CONST LOGGERLEVEL, CONST LPLOGGERACTIONDETACHPROCESS action) { return TRUE; }

static CONST BOOL FormatLoggerActionAttachThread(LPSTRINGBUILDER builder, CONST LOGGERLEVEL, CONST LPLOGGERACTIONATTACHTHREAD action) { return TRUE; }

static CONST BOOL FormatLoggerActionDetachThread(LPSTRINGBUILDER builder, CONST LOGGERLEVEL, CONST LPLOGGERACTIONDETACHTHREAD action) { return TRUE; }

#define X(ID, A)                            \
    switch (ID)                             \
    {                                       \
        A(Module);                          \
        A(Direct3D8);                       \
        A(Direct3DBaseTexture8);            \
        A(Direct3DCubeTexture8);            \
        A(Direct3DDevice8);                 \
        A(Direct3DIndexBuffer8);            \
        A(Direct3DResource8);               \
        A(Direct3DSurface8);                \
        A(Direct3DSwapChain8);              \
        A(Direct3DTexture8);                \
        A(Direct3DVertexBuffer8);           \
        A(Direct3DVolume8);                 \
        A(Direct3DVolumeTexture8);          \
        A(Unknown);                         \
    }


#define ACQUIREOBJECTNAME(ID) case OBJECT_ID_##ID: { return #ID; }

static LPCSTR AcquireLoggerObjectName(CONST AGENTOBJECTID id)
{
    X(id, ACQUIREOBJECTNAME); return "<UNKNOWN>";
}

#define ACQUIREMETHODNAME(ID) case OBJECT_ID_##ID: { return AcquireLogger##ID##MethodName(method); }

static LPCSTR AcquireLoggerObjectMethodName(CONST AGENTOBJECTID id, CONST AGENTMETHODID method)
{
    X(id, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

#define ACQUIREMETHODCALLBACKNAME(ID) case OBJECT_ID_##ID: { return AcquireLogger##ID##MethodCallbackName(callback); }

static LPCSTR AcquireLoggerObjectMethodCallbackName(CONST AGENTOBJECTID id, CONST AGENTMETHODCALLBACKID callback)
{
    X(id, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

#define ACQUIREMETHODVALUE(ID) case OBJECT_ID_##ID: { return AcquireLogger##ID##MethodValue(builder, method, value); }

static BOOL AcquireLoggerObjectMethodValue(LPSTRINGBUILDER builder, CONST AGENTOBJECTID id, CONST AGENTMETHODID method, CONST LPVOID value)
{
    X(id, ACQUIREMETHODVALUE); return FALSE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID) case OBJECT_ID_##ID: { return AcquireLogger##ID##MethodCallbackValue(builder, callback, value); }

static BOOL AcquireLoggerObjectMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTOBJECTID id, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    X(id, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}

static CONST BOOL FormatLoggerActionConstructor(LPSTRINGBUILDER builder, CONST LOGGERLEVEL, CONST LPLOGGERACTIONCONSTRUCTOR action)
{
    FORMAT(builder, Format("[%s][0x%x]", AcquireLoggerObjectName(action->ID), (ADDR)action->Object)); return TRUE;
}

static CONST BOOL FormatLoggerActionDestructor(LPSTRINGBUILDER builder, CONST LOGGERLEVEL, CONST LPLOGGERACTIONDESTRUCTOR action)
{
    FORMAT(builder, Format("[%s][0x%x]", AcquireLoggerObjectName(action->ID), (ADDR)action->Object)); return TRUE;
}

static CONST BOOL FormatLoggerActionMethod(LPSTRINGBUILDER builder, CONST LOGGERLEVEL level, CONST LPLOGGERACTIONMETHOD action)
{
    FORMAT(builder, Format("[%s][0x%x][%s]",
        AcquireLoggerObjectName(action->ID), (ADDR)action->Object,
        AcquireLoggerObjectMethodName(action->ID, action->Method)));

    if (level & (LOGGER_LEVEL_DEBUG | LOGGER_LEVEL_TRACE)) { FORMATACTION(builder, AcquireLoggerObjectMethodValue(builder, action->ID, action->Method, action->Value)); }

    return TRUE;
}

static CONST BOOL FormatLoggerActionMethodResult(LPSTRINGBUILDER builder, CONST LOGGERLEVEL level, CONST LPLOGGERACTIONMETHODRESULT action)
{
    FORMAT(builder, Format("[%s][0x%x][%s][0x%x]",
        AcquireLoggerObjectName(action->ID), (ADDR)action->Object,
        AcquireLoggerObjectMethodName(action->ID, action->Method), action->Result));

    if (level & (LOGGER_LEVEL_DEBUG | LOGGER_LEVEL_TRACE)) { FORMATACTION(builder, AcquireLoggerObjectMethodValue(builder, action->ID, action->Method, action->Value)); }

    return TRUE;
}

static CONST BOOL FormatLoggerActionMethodCallback(LPSTRINGBUILDER builder, CONST LOGGERLEVEL level, CONST LPLOGGERACTIONMETHODCALLBACK action)
{
    FORMAT(builder, Format("[%s][0x%x][%s][%s]",
        AcquireLoggerObjectName(action->ID), (ADDR)action->Object,
        AcquireLoggerObjectMethodName(action->ID, action->Method),
        AcquireLoggerObjectMethodCallbackName(action->ID, action->Callback)));

    if (level & (LOGGER_LEVEL_DEBUG | LOGGER_LEVEL_TRACE)) { FORMATACTION(builder, AcquireLoggerObjectMethodCallbackValue(builder, action->ID, action->Callback, action->Value)); }

    return TRUE;
}

static CONST BOOL FormatLoggerActionMethodCallbackResult(LPSTRINGBUILDER builder, CONST LOGGERLEVEL level, CONST LPLOGGERACTIONMETHODCALLBACKRESULT action)
{
    FORMAT(builder, Format("[%s][0x%x][%s][%s][0x%x]",
        AcquireLoggerObjectName(action->ID), (ADDR)action->Object,
        AcquireLoggerObjectMethodName(action->ID, action->Method),
        AcquireLoggerObjectMethodCallbackName(action->ID, action->Callback), action->Result));

    if (level & (LOGGER_LEVEL_DEBUG | LOGGER_LEVEL_TRACE)) { FORMATACTION(builder, AcquireLoggerObjectMethodCallbackValue(builder, action->ID, action->Callback, action->Value)); }

    return TRUE;
}

TextLoggerSerializer::TextLoggerSerializer(LPLOGGERSETTINGS settings, LPLOGGERWRITER writer) : LoggerSerializer(settings, writer)
{
    this->Builder = new StringBuilder();
}

TextLoggerSerializer::~TextLoggerSerializer()
{
    if (this->State.Writer != NULL) { delete this->State.Writer; this->State.Writer = NULL; }

    delete this->Builder;

    DeleteCriticalSection(&this->State.Mutex);
}

#define FORMATLOGGERACTION(ID, M, LABEL) case LOGGER_ACTION_ID_##ID: { FORMATACTIONGOTO(this->Builder, M(this->Builder, (LOGGERLEVEL)(level & action->Level), (LPLOGGERACTION##ID)action->Value), LABEL); break; }

CONST BOOL TextLoggerSerializer::Serialize(CONST LOGGERLEVEL level, CONST LPLOGGERACTION action)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State.Mutex);

    FORMATGOTO(this->Builder, Format("[%04d-%02d-%02d %02d:%02d:%02d:%03d][%d][%d][",
        action->Time.wYear, action->Time.wMonth, action->Time.wDay, action->Time.wHour, action->Time.wMinute, action->Time.wSecond, action->Time.wMilliseconds,
        action->Process, action->Thread), DONE);

    FORMATACTIONGOTO(this->Builder, AcquireLoggerLevelValue(this->Builder, (LOGGERLEVEL)(level & action->Level)), DONE);
    FORMATGOTO(this->Builder, Format("][%s]", AcquireLoggerActionValue(action->Action)), DONE);

    switch (action->Action)
    {
        FORMATLOGGERACTION(INITIALIZE, FormatLoggerActionInitialize, DONE);
        FORMATLOGGERACTION(MESSAGE, FormatLoggerActionMessage, DONE);
        FORMATLOGGERACTION(ATTACHPROCESS, FormatLoggerActionAttachProcess, DONE);
        FORMATLOGGERACTION(DETACHPROCESS, FormatLoggerActionDetachProcess, DONE);
        FORMATLOGGERACTION(ATTACHTHREAD, FormatLoggerActionAttachThread, DONE);
        FORMATLOGGERACTION(DETACHTHREAD, FormatLoggerActionDetachThread, DONE);
        FORMATLOGGERACTION(CONSTRUCTOR, FormatLoggerActionConstructor, DONE);
        FORMATLOGGERACTION(DESTRUCTOR, FormatLoggerActionDestructor, DONE);
        FORMATLOGGERACTION(METHOD, FormatLoggerActionMethod, DONE);
        FORMATLOGGERACTION(METHODCALLBACK, FormatLoggerActionMethodCallback, DONE);
        FORMATLOGGERACTION(METHODRESULT, FormatLoggerActionMethodResult, DONE);
        FORMATLOGGERACTION(METHODCALLBACKRESULT, FormatLoggerActionMethodCallbackResult, DONE);
    }

    FORMATGOTO(this->Builder, Append("\r\n"), DONE);

DONE:

    CONST INT count = this->Builder->Count();

    if (count > 0) { result = this->State.Writer->Write(this->Builder->String(), count); }

    this->Builder->Clear();

    LeaveCriticalSection(&this->State.Mutex);

    return result;
}

#define TEXT_LOGGER_FLOAT_VALUE_FORMAT "[%.12f]"

#define TEXT_LOGGER_GUID_FORMAT "[%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x]"

#define TEXT_LOGGER_INT_VALUE_FORMAT "[0x%x]"
#define TEXT_LOGGER_UINT_VALUE_FORMAT "[0x%x]"

#define TEXT_LOGGER_LONG_VALUE_FORMAT "[0x%llx]"

#define TEXT_LOGGER_STRING_FORMAT "[%s]"

#define TEXT_LOGGER_WINDOW_DEFAULT_NAME "-----"
#define TEXT_LOGGER_WINDOW_FORMAT "[0x%x [%s]]"

#if _WIN64
#define TEXT_LOGGER_ADDRESS_FORMAT "[0x%llx]"
#define TEXT_LOGGER_ADDRESS_ADDRESS_FORMAT "[0x%llx" TEXT_LOGGER_ADDRESS_FORMAT "]"
#define TEXT_LOGGER_GUID_ADDRESS_FORMAT "[0x%llx " TEXT_LOGGER_GUID_FORMAT "]"
#define TEXT_LOGGER_INT_VALUE_ADDRESS_FORMAT "[0x%llx " TEXT_LOGGER_INT_VALUE_FORMAT "]"
#define TEXT_LOGGER_UINT_VALUE_ADDRESS_FORMAT "[0x%x " TEXT_LOGGER_UINT_VALUE_FORMAT "]"
#define TEXT_LOGGER_WINDOW_ADDRESS_FORMAT "[0x%llx " TEXT_LOGGER_WINDOW_FORMAT "]"

#define TEXT_LOGGER_LOCKED_BOX_FORMAT "[0x%x][0x%x][0x%llx]"
#define TEXT_LOGGER_LOCKED_RECT_FORMAT "[0x%x][0x%llx]"
#else
#define TEXT_LOGGER_ADDRESS_FORMAT "[0x%x]"
#define TEXT_LOGGER_ADDRESS_ADDRESS_FORMAT "[0x%x" TEXT_LOGGER_ADDRESS_FORMAT "]"
#define TEXT_LOGGER_GUID_ADDRESS_FORMAT "[0x%x " TEXT_LOGGER_GUID_FORMAT "]"
#define TEXT_LOGGER_INT_VALUE_ADDRESS_FORMAT "[0x%x " TEXT_LOGGER_INT_VALUE_FORMAT "]"
#define TEXT_LOGGER_UINT_VALUE_ADDRESS_FORMAT "[0x%x " TEXT_LOGGER_UINT_VALUE_FORMAT "]"
#define TEXT_LOGGER_WINDOW_ADDRESS_FORMAT "[0x%x " TEXT_LOGGER_WINDOW_FORMAT "]"

#define TEXT_LOGGER_LOCKED_BOX_FORMAT "[0x%x][0x%x][0x%x]"
#define TEXT_LOGGER_LOCKED_RECT_FORMAT "[0x%x][0x%x]"
#endif

#define TEXT_LOGGER_LONG_VALUE_ADDRESS_FORMAT "[0x%llx " TEXT_LOGGER_LONG_VALUE_FORMAT "]"

CONST BOOL TextFormatID(LPSTRINGBUILDER builder, CONST GUID value)
{
    return builder->Format(TEXT_LOGGER_GUID_FORMAT,
        value.Data1, value.Data2, value.Data3,
        value.Data4[0], value.Data4[1], value.Data4[2], value.Data4[3], value.Data4[4], value.Data4[5], value.Data4[6], value.Data4[7]);
}

CONST BOOL TextFormatID(LPSTRINGBUILDER builder, CONST LPGUID value)
{
    CONST GUID id = value == NULL ? GUID_NULL : *value;

    return builder->Format(TEXT_LOGGER_GUID_ADDRESS_FORMAT,
        value, id.Data1, id.Data2, id.Data3, id.Data4[0], id.Data4[1], id.Data4[2], id.Data4[3], id.Data4[4], id.Data4[5], id.Data4[6], id.Data4[7]);
}

CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST LPVOID* value)
{
    return builder->Format(TEXT_LOGGER_ADDRESS_ADDRESS_FORMAT, value, value == NULL ? NULL : (*value));
}

CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST LPCVOID value)
{
    return builder->Format(TEXT_LOGGER_ADDRESS_FORMAT, value);
}

CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST LPVOID value)
{
    return builder->Format(TEXT_LOGGER_ADDRESS_FORMAT, value);
}

CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST BYTE* value)
{
    return builder->Format(TEXT_LOGGER_ADDRESS_FORMAT, value);
}

CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST BYTE** value)
{
    return builder->Format(TEXT_LOGGER_ADDRESS_ADDRESS_FORMAT, value, value == NULL ? NULL : (*value));
}

// TODO: Support an array.
CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST D3DLOCKED_BOX* value)
{
    return builder->Format(TEXT_LOGGER_LOCKED_BOX_FORMAT, value->RowPitch, value->SlicePitch, value->pBits);
}

// TODO: Support an array.
CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST D3DLOCKED_RECT* value)
{
    return builder->Format(TEXT_LOGGER_LOCKED_RECT_FORMAT, value->Pitch, value->pBits);
}

CONST BOOL TextFormatString(LPSTRINGBUILDER builder, CONST LPCSTR value)
{
    return builder->Format(TEXT_LOGGER_STRING_FORMAT, value);
}

CONST BOOL TextFormatString(LPSTRINGBUILDER builder, CONST LPCWSTR value)
{
    CONST INT length = WideCharToMultiByte(CP_ACP, 0, value, -1, NULL, 0, NULL, NULL);

    if (length <= 0) { return FALSE; }

    LPSTR str = (LPSTR)malloc(length);

    if (str == NULL) { return FALSE; }

    ZeroMemory(str, length);

    BOOL result = FALSE;

    if (WideCharToMultiByte(CP_ACP, 0, value, -1, str, length, NULL, NULL) != 0) { result = builder->Format(TEXT_LOGGER_STRING_FORMAT, str); }

    if (str != NULL) { free(str); }

    return result;
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST BOOL value)
{
    return builder->Format(TEXT_LOGGER_INT_VALUE_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST FLOAT value)
{
    return builder->Format(TEXT_LOGGER_FLOAT_VALUE_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST DWORD value)
{
    return builder->Format(TEXT_LOGGER_INT_VALUE_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LONG value)
{
    return builder->Format(TEXT_LOGGER_INT_VALUE_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPBOOL value)
{
    return builder->Format(TEXT_LOGGER_INT_VALUE_ADDRESS_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPDWORD value)
{
    return builder->Format(TEXT_LOGGER_INT_VALUE_ADDRESS_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPLONG value)
{
    return builder->Format(TEXT_LOGGER_INT_VALUE_ADDRESS_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPQWORD value)
{
    return builder->Format(TEXT_LOGGER_LONG_VALUE_ADDRESS_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPUINT value)
{
    return builder->Format(TEXT_LOGGER_UINT_VALUE_ADDRESS_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST QWORD value)
{
    return builder->Format(TEXT_LOGGER_LONG_VALUE_FORMAT, value);
}

CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST UINT value)
{
    return builder->Format(TEXT_LOGGER_UINT_VALUE_FORMAT, value);
}

CONST BOOL TextFormatWindow(LPSTRINGBUILDER builder, CONST HWND* value)
{
    if (value == NULL) { return builder->Format(TEXT_LOGGER_WINDOW_ADDRESS_FORMAT, NULL, NULL, TEXT_LOGGER_WINDOW_DEFAULT_NAME); }

    HWND window = *value;

    CONST INT length = GetWindowTextLengthA(window);

    LPSTR title = (LPSTR)VirtualAlloc((LPVOID)NULL, (DWORD)(length + 1), MEM_COMMIT, PAGE_READWRITE);

    if (title != NULL) { GetWindowTextA(window, title, length + 1); }

    CONST BOOL result = builder->Format(TEXT_LOGGER_WINDOW_FORMAT, value, title == NULL ? TEXT_LOGGER_WINDOW_DEFAULT_NAME : title);

    if (title != NULL) { VirtualFree(title, 0, MEM_RELEASE); }

    return result;
}

CONST BOOL TextFormatWindow(LPSTRINGBUILDER builder, CONST HWND value)
{
    CONST INT length = GetWindowTextLengthA(value);

    if (length <= 0) { return FALSE; }

    LPSTR title = (LPSTR)VirtualAlloc((LPVOID)NULL, (DWORD)(length + 1), MEM_COMMIT, PAGE_READWRITE);

    if (title != NULL) { GetWindowTextA(value, title, length + 1); }

    CONST BOOL result = builder->Format(TEXT_LOGGER_WINDOW_FORMAT, value, title == NULL ? TEXT_LOGGER_WINDOW_DEFAULT_NAME : title);

    if (title != NULL) { VirtualFree(title, 0, MEM_RELEASE); }

    return result;
}
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

#include "Base.hxx"
#include "Logger.hxx"

Logger::Logger()
{
    this->State.Level = LOGGER_LEVEL_NONE;

    this->State.Settings = NULL;
    this->State.Serializer = NULL;

    ZeroMemory(&this->State.Mutex, sizeof(CRITICAL_SECTION));
    InitializeCriticalSection(&this->State.Mutex);
}

Logger::Logger(LPLOGGERSETTINGS settings, LPLOGGERSERIALIZER serializer)
{
    this->State.Level = LOGGER_LEVEL_NONE;

    this->State.Settings = settings;
    this->State.Serializer = serializer;

    this->State.Settings->ReadInteger(LOGGER_SETTINGS_LEVEL_PROPERTY_NAME, (INT*)&this->State.Level);

    ZeroMemory(&this->State.Mutex, sizeof(CRITICAL_SECTION));
    InitializeCriticalSection(&this->State.Mutex);

    this->Initialize();
}

Logger::~Logger()
{
    if (this->State.Settings != NULL) { delete this->State.Settings; this->State.Settings = NULL; }
    if (this->State.Serializer != NULL) { delete this->State.Serializer; this->State.Serializer = NULL; }

    DeleteCriticalSection(&this->State.Mutex);
}

CONST BOOL Logger::IsAcceptable(const LOGGERLEVEL level)
{
    return (this->State.Level & level) != LOGGER_LEVEL_NONE;
}

VOID Logger::Initialize()
{
    LOGGERACTION action;
    ZeroMemory(&action, sizeof(LOGGERACTION));

    action.Action = LOGGER_ACTION_ID_INITIALIZE;
    action.Level = this->State.Level;
    action.Process = GetCurrentProcessId();
    action.Thread = GetCurrentThreadId();

    GetLocalTime(&action.Time);

    LOGGERACTIONINITIALIZE initialize;
    ZeroMemory(&initialize, sizeof(LOGGERACTIONINITIALIZE));

    initialize.Version = LOGGER_COMPLETE_VERSION;
    initialize.Platform = LOGGER_PLATFORM;

    action.Value = &initialize;

    this->State.Serializer->Serialize(this->State.Level, &action);
}

VOID Logger::Log(CONST LPLOGGERACTION action)
{
    if (!IsAcceptable(action->Level)) { return; }

    this->State.Serializer->Serialize(this->State.Level, action);
}

VOID LogStructure(LPLOGGER logger, CONST LOGGERLEVEL level, CONST LOGGERACTIONID id, CONST LPVOID value)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTION action;
    ZeroMemory(&action, sizeof(LOGGERACTION));

    action.Action = id;
    action.Level = level;
    action.Process = GetCurrentProcessId();
    action.Thread = GetCurrentThreadId();

    GetLocalTime(&action.Time);

    action.Value = value;

    logger->Log(&action);
}

VOID LogMessage(LPLOGGER logger, CONST LOGGERLEVEL level, LPCSTR message)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONMESSAGE action;
    ZeroMemory(&action, sizeof(LOGGERACTIONMESSAGE));

    action.Message = message;
    action.Arguments = NULL;

    LogStructure(logger, level, LOGGER_ACTION_ID_MESSAGE, &action);
}

VOID LogMessage(LPLOGGER logger, CONST LOGGERLEVEL level, LPCSTR message, ...)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONMESSAGE action;
    ZeroMemory(&action, sizeof(LOGGERACTIONMESSAGE));

    action.Message = message;

    va_start(action.Arguments, message);

    LogStructure(logger, level, LOGGER_ACTION_ID_MESSAGE, &action);

    va_end(action.Arguments);
}

VOID LogAttachProcess(LPLOGGER logger, CONST LOGGERLEVEL level)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONATTACHPROCESS action;
    ZeroMemory(&action, sizeof(LOGGERACTIONATTACHPROCESS));

    GetModuleFileNameA(NULL, action.Name, MAX_PATH);

    LogStructure(logger, level, LOGGER_ACTION_ID_ATTACHPROCESS, &action);
}

VOID LogDetachProcess(LPLOGGER logger, CONST LOGGERLEVEL level)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONDETACHPROCESS action;
    ZeroMemory(&action, sizeof(LOGGERACTIONDETACHPROCESS));

    LogStructure(logger, level, LOGGER_ACTION_ID_DETACHPROCESS, &action);
}

VOID LogAttachThread(LPLOGGER logger, CONST LOGGERLEVEL level)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONATTACHTHREAD action;
    ZeroMemory(&action, sizeof(LOGGERACTIONATTACHTHREAD));

    LogStructure(logger, level, LOGGER_ACTION_ID_ATTACHTHREAD, &action);
}

VOID LogDetachThread(LPLOGGER logger, CONST LOGGERLEVEL level)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONDETACHTHREAD action;
    ZeroMemory(&action, sizeof(LOGGERACTIONDETACHTHREAD));

    LogStructure(logger, level, LOGGER_ACTION_ID_DETACHTHREAD, &action);
}

VOID LogConstructor(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONCONSTRUCTOR action;
    ZeroMemory(&action, sizeof(LOGGERACTIONCONSTRUCTOR));

    action.ID = id;
    action.Object = object;

    LogStructure(logger, level, LOGGER_ACTION_ID_CONSTRUCTOR, &action);
}

VOID LogDestructor(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONDESTRUCTOR action;
    ZeroMemory(&action, sizeof(LOGGERACTIONDESTRUCTOR));

    action.ID = id;
    action.Object = object;

    LogStructure(logger, level, LOGGER_ACTION_ID_DESTRUCTOR, &action);
}

VOID LogMethod(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object, CONST AGENTMETHODID method, CONST LPVOID value)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONMETHOD action;
    ZeroMemory(&action, sizeof(LOGGERACTIONMETHOD));

    action.ID = id;
    action.Object = object;
    action.Method = method;
    action.Value = value;

    LogStructure(logger, level, LOGGER_ACTION_ID_METHOD, &action);
}

VOID LogMethodResult(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object, CONST AGENTMETHODID method, CONST ADDR result, CONST LPVOID value)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONMETHODRESULT action;
    ZeroMemory(&action, sizeof(LOGGERACTIONMETHODRESULT));

    action.ID = id;
    action.Object = object;
    action.Method = method;
    action.Result = result;
    action.Value = value;

    LogStructure(logger, level, LOGGER_ACTION_ID_METHODRESULT, &action);
}

VOID LogMethodCallback(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object, CONST AGENTMETHODID method, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONMETHODCALLBACK action;
    ZeroMemory(&action, sizeof(LOGGERACTIONMETHODCALLBACK));

    action.ID = id;
    action.Object = object;
    action.Method = method;
    action.Callback = callback;
    action.Value = value;

    LogStructure(logger, level, LOGGER_ACTION_ID_METHODCALLBACK, &action);
}

VOID LogMethodCallbackResult(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object, CONST AGENTMETHODID method, CONST AGENTMETHODCALLBACKID callback, CONST ADDR result, CONST LPVOID value)
{
    if (!logger->IsAcceptable(level)) { return; }

    LOGGERACTIONMETHODCALLBACKRESULT action;
    ZeroMemory(&action, sizeof(LOGGERACTIONMETHODCALLBACKRESULT));

    action.ID = id;
    action.Object = object;
    action.Method = method;
    action.Callback = callback;
    action.Result = result;
    action.Value = value;

    LogStructure(logger, level, LOGGER_ACTION_ID_METHODCALLBACKRESULT, &action);
}
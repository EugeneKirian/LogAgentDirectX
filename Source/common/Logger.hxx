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

#include "Array.hxx"

#define LOGGER_VERSION_MAJOR 1
#define LOGGER_VERSION_MINOR 0
#define LOGGER_VERSION_PATCH 0
#define LOGGER_VERSION_BUILD 0

#define LOGGER_COMPLETE_VERSION ((LOGGER_VERSION_MAJOR << 24) | (LOGGER_VERSION_MINOR << 16) | (LOGGER_VERSION_PATCH << 8) | (LOGGER_VERSION_BUILD < 0))

#define ACQUIRE_LOGGER_VERSION_MAJOR(x) ((x >> 24) & 0xFF)
#define ACQUIRE_LOGGER_VERSION_MINOR(x) ((x >> 16) & 0xFF)
#define ACQUIRE_LOGGER_VERSION_PATCH(x) ((x >> 8) & 0xFF)
#define ACQUIRE_LOGGER_VERSION_BUILD(x) ((x >> 0) & 0xFF)

#if _WIN64
#define LOGGER_PLATFORM 64
#else
#define LOGGER_PLATFORM 32
#endif

typedef enum LoggerLevel
{
    LOGGER_LEVEL_NONE   =   0x00000000,
    LOGGER_LEVEL_TRACE  =   0x00000001,
    LOGGER_LEVEL_DEBUG  =   0x00000002,
    LOGGER_LEVEL_INFO   =   0x00000004,
    LOGGER_LEVEL_ERROR  =   0x00000008,

    LOGGER_LEVEL_FORCE_DWORD = 0x7fffffff, /* force 32-bit size enum */
} LOGGERLEVEL, * LPLOGGERLEVEL;

#define LOGGER_LEVEL_DEBUGERROR (LOGGERLEVEL)(LOGGER_LEVEL_ERROR | LOGGER_LEVEL_DEBUG)
#define LOGGER_LEVEL_DEBUGINFO (LOGGERLEVEL)(LOGGER_LEVEL_INFO | LOGGER_LEVEL_DEBUG)
#define LOGGER_LEVEL_TRACEDEBUG (LOGGERLEVEL)(LOGGER_LEVEL_DEBUG | LOGGER_LEVEL_TRACE)
#define LOGGER_LEVEL_TRACEDEBUGERROR (LOGGERLEVEL)(LOGGER_LEVEL_ERROR | LOGGER_LEVEL_DEBUG | LOGGER_LEVEL_TRACE)
#define LOGGER_LEVEL_TRACEDEBUGINFO (LOGGERLEVEL)(LOGGER_LEVEL_INFO | LOGGER_LEVEL_DEBUG | LOGGER_LEVEL_TRACE)
#define LOGGER_LEVEL_TRACEERROR (LOGGERLEVEL)(LOGGER_LEVEL_ERROR | LOGGER_LEVEL_TRACE)
#define LOGGER_LEVEL_TRACEINFO (LOGGERLEVEL)(LOGGER_LEVEL_INFO | LOGGER_LEVEL_TRACE)

typedef DWORD AGENTOBJECTID;
typedef DWORD AGENTMETHODID;
typedef DWORD AGENTMETHODCALLBACKID;

#define LOGGER_ACTION_ID_BASE                        0
#define LOGGER_ACTION_ID_INITIALIZE                  (LOGGER_ACTION_ID_BASE + 0)

#define LOGGER_ACTION_ID_MESSAGE                     (LOGGER_ACTION_ID_BASE + 1)

#define LOGGER_ACTION_ID_ATTACHPROCESS               (LOGGER_ACTION_ID_BASE + 10)
#define LOGGER_ACTION_ID_DETACHPROCESS               (LOGGER_ACTION_ID_BASE + 11)
#define LOGGER_ACTION_ID_ATTACHTHREAD                (LOGGER_ACTION_ID_BASE + 12)
#define LOGGER_ACTION_ID_DETACHTHREAD                (LOGGER_ACTION_ID_BASE + 13)

#define LOGGER_ACTION_ID_CONSTRUCTOR                 (LOGGER_ACTION_ID_BASE + 100)
#define LOGGER_ACTION_ID_DESTRUCTOR                  (LOGGER_ACTION_ID_BASE + 101)
#define LOGGER_ACTION_ID_METHOD                      (LOGGER_ACTION_ID_BASE + 102)
#define LOGGER_ACTION_ID_METHODCALLBACK              (LOGGER_ACTION_ID_BASE + 103)
#define LOGGER_ACTION_ID_METHODRESULT                (LOGGER_ACTION_ID_BASE + 104)
#define LOGGER_ACTION_ID_METHODCALLBACKRESULT        (LOGGER_ACTION_ID_BASE + 105)

// LOGGER_ACTION_ID_INITIALIZE
typedef struct LoggerActionInitialize
{
    DWORD Version;
    DWORD Platform;
} LOGGERACTIONINITIALIZE, * LPLOGGERACTIONINITIALIZE;

// LOGGER_ACTION_ID_MESSAGE
typedef struct LoggerActionMessage
{
    LPCSTR Message;
    va_list Arguments;
} LOGGERACTIONMESSAGE, * LPLOGGERACTIONMESSAGE;

// LOGGER_ACTION_ID_ATTACHPROCESS
typedef struct LoggerActionAttachProcess
{
    CHAR Name[MAX_PATH];
} LOGGERACTIONATTACHPROCESS, * LPLOGGERACTIONATTACHPROCESS;

// LOGGER_ACTION_ID_DETACHPROCESS
typedef struct LoggerActionDetachProcess
{
} LOGGERACTIONDETACHPROCESS, * LPLOGGERACTIONDETACHPROCESS;

// LOGGER_ACTION_ID_ATTACHTHREAD
typedef struct LoggerActionAttachThread
{
} LOGGERACTIONATTACHTHREAD, * LPLOGGERACTIONATTACHTHREAD;

// LOGGER_ACTION_ID_DETACHTHREAD
typedef struct LoggerActionDetachThread
{
} LOGGERACTIONDETACHTHREAD, * LPLOGGERACTIONDETACHTHREAD;

// LOGGER_ACTION_ID_CONSTRUCTOR
typedef struct LoggerActionConstructor
{
    AGENTOBJECTID ID;
    LPVOID Object;
} LOGGERACTIONCONSTRUCTOR, * LPLOGGERACTIONCONSTRUCTOR;

// LOGGER_ACTION_ID_DESTRUCTOR
typedef struct LoggerActionDestructor
{
    AGENTOBJECTID ID;
    LPVOID Object;
} LOGGERACTIONDESTRUCTOR, * LPLOGGERACTIONDESTRUCTOR;

// LOGGER_ACTION_ID_METHOD
typedef struct LoggerActionMethod
{
    AGENTOBJECTID ID;
    LPVOID Object;
    AGENTMETHODID Method;
    LPVOID Value;
} LOGGERACTIONMETHOD, * LPLOGGERACTIONMETHOD;

// LOGGER_ACTION_ID_METHODCALLBACK
typedef struct LoggerActionMethodCallBack
{
    AGENTOBJECTID ID;
    LPVOID Object;
    AGENTMETHODID Method;
    AGENTMETHODCALLBACKID Callback;
    LPVOID Value;
} LOGGERACTIONMETHODCALLBACK, * LPLOGGERACTIONMETHODCALLBACK;

// LOGGER_ACTION_ID_METHODRESULT
typedef struct LoggerActionMethodResult
{
    AGENTOBJECTID ID;
    LPVOID Object;
    AGENTMETHODID Method;
    ADDR Result;
    LPVOID Value;
} LOGGERACTIONMETHODRESULT, * LPLOGGERACTIONMETHODRESULT;

// LOGGER_ACTION_ID_METHODCALLBACKRESULT
typedef struct LoggerActionMethodCallBackResult
{
    AGENTOBJECTID ID;
    LPVOID Object;
    AGENTMETHODID Method;
    AGENTMETHODCALLBACKID Callback;
    ADDR Result;
    LPVOID Value;
} LOGGERACTIONMETHODCALLBACKRESULT, * LPLOGGERACTIONMETHODCALLBACKRESULT;

#define LOGGER_SETTINGS_LEVEL_PROPERTY_NAME "Level"
#define LOGGER_SETTINGS_SERIALIZER_PROPERTY_NAME "Serializer"
#define LOGGER_SETTINGS_WRITER_PROPERTY_NAME "Writer"

class LoggerSettings
{
public:
    virtual ~LoggerSettings();

    virtual CONST BOOL ReadBool(LPCSTR name, BOOL* value) PURE;
    virtual CONST BOOL ReadInteger(LPCSTR name, INT* value) PURE;
    virtual CONST BOOL ReadString(LPCSTR name, LPSTR value, CONST DWORD size) PURE;

protected:
    LoggerSettings();
};

typedef LoggerSettings* LPLOGGERSETTINGS;

#define LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH (MAX_PATH)
#define LOGGER_SETTINGS_MAX_SECTION_LENGTH 100

class FileLoggerSettings : public LoggerSettings
{
public:
    FileLoggerSettings(LPCSTR file, LPCSTR name);
    virtual ~FileLoggerSettings();

    virtual CONST BOOL ReadBool(LPCSTR name, BOOL* value) override;
    virtual CONST BOOL ReadInteger(LPCSTR name, INT* value) override;
    virtual CONST BOOL ReadString(LPCSTR name, LPSTR value, CONST DWORD size) override;

protected:
    struct
    {
        CHAR Name[LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH];
        CHAR Section[LOGGER_SETTINGS_MAX_SECTION_LENGTH];
    } State;
};

typedef FileLoggerSettings* LPFILELOGGERSETTINGS;

class LoggerWriter
{
public:
    virtual ~LoggerWriter();

    virtual CONST BOOL Write(CONST LPCVOID value, CONST DWORD size) PURE;

protected:
    LoggerWriter(LPLOGGERSETTINGS settings);

    struct
    {
        LPLOGGERSETTINGS Settings;
    } State;
};

typedef LoggerWriter* LPLOGGERWRITER;

class ConsoleLoggerWriter : public LoggerWriter
{
public:
    ConsoleLoggerWriter(LPLOGGERSETTINGS settings);
    virtual ~ConsoleLoggerWriter();

    virtual CONST BOOL Write(CONST LPCVOID value, CONST DWORD size) override;

protected:
    struct
    {
        HANDLE Handle;
        CRITICAL_SECTION Mutex;
    } State;
};

typedef ConsoleLoggerWriter* LPCONSOLELOGGERWRITER;

class DebugLoggerWriter : public LoggerWriter
{
public:
    DebugLoggerWriter(LPLOGGERSETTINGS settings);
    virtual ~DebugLoggerWriter();

    virtual CONST BOOL Write(CONST LPCVOID value, CONST DWORD size) override;

protected:
    struct
    {
        CRITICAL_SECTION Mutex;
    } State;
};

typedef ConsoleLoggerWriter* LPCONSOLELOGGERWRITER;

class FileLoggerWriter : public LoggerWriter
{
public:
    FileLoggerWriter(LPLOGGERSETTINGS settings);
    virtual ~FileLoggerWriter();

    virtual CONST BOOL Write(CONST LPCVOID value, CONST DWORD size) override;

protected:
    struct
    {
        HANDLE Handle;
        CRITICAL_SECTION Mutex;
    } State;
};

typedef FileLoggerWriter* LPFILELOGGERWRITER;

typedef DWORD LOGGERACTIONID;

typedef struct LoggerAction
{
    LOGGERLEVEL Level;
    LOGGERACTIONID Action;
    DWORD Process;
    DWORD Thread;
    SYSTEMTIME Time;
    LPVOID Value;
} LOGGERACTION, * LPLOGGERACTION;

class LoggerSerializer
{
public:
    virtual ~LoggerSerializer();

    virtual CONST BOOL Serialize(CONST LOGGERLEVEL level, CONST LPLOGGERACTION action) PURE;

protected:
    LoggerSerializer(LPLOGGERSETTINGS settings, LPLOGGERWRITER writer);

    struct
    {
        LPLOGGERSETTINGS Settings;
        LPLOGGERWRITER Writer;
        CRITICAL_SECTION Mutex;
    } State;
};

typedef LoggerSerializer* LPLOGGERSERIALIZER;

class Logger
{
public:
    Logger(LPLOGGERSETTINGS settings, LPLOGGERSERIALIZER serializer);
    virtual ~Logger();

    virtual VOID Log(CONST LPLOGGERACTION action);
    virtual CONST BOOL IsAcceptable(CONST LOGGERLEVEL level);

protected:
    Logger();
    VOID Initialize();

    struct
    {
        LOGGERLEVEL Level;
        LPLOGGERSETTINGS Settings;
        LPLOGGERSERIALIZER Serializer;
        CRITICAL_SECTION Mutex;
    } State;
};

typedef Logger* LPLOGGER;

class MultiLogger : public Logger
{
public:
    MultiLogger();
    virtual ~MultiLogger();

    virtual VOID Log(CONST LPLOGGERACTION action) override;
    virtual CONST BOOL IsAcceptable(CONST LOGGERLEVEL level) override;

    virtual CONST BOOL Attach(LPLOGGER logger);

protected:
    Array<LPLOGGER> Items;
};

#define LogConstructorMacro(LOG, LEVEL, O, V) \
    if (LOG->IsAcceptable(LOGGER_LEVEL_##LEVEL)) { LogConstructor(LOG, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, V); }

#define LogDestructorMacro(LOG, LEVEL, O, V) \
    if (LOG->IsAcceptable(LOGGER_LEVEL_##LEVEL)) { LogDestructor(LOG, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, V); }

#define LogMethodMacro(LOG, LEVEL, O, M, V) \
    if (LOG->IsAcceptable(LOGGER_LEVEL_##LEVEL)) { LogMethod(LOG, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, V, METHOD_ID_##O##_##M, NULL); }

#define LogStructureArgument1Macro(A1) A1
#define LogStructureArgument2Macro(A1, A2) A1, A2
#define LogStructureArgument3Macro(A1, A2, A3) A1, A2, A3
#define LogStructureArgument4Macro(A1, A2, A3, A4) A1, A2, A3, A4
#define LogStructureArgument5Macro(A1, A2, A3, A4, A5) A1, A2, A3, A4, A5
#define LogStructureArgument6Macro(A1, A2, A3, A4, A5, A6) A1, A2, A3, A4, A5, A6
#define LogStructureArgument7Macro(A1, A2, A3, A4, A5, A6, A7) A1, A2, A3, A4, A5, A6, A7
#define LogStructureArgument8Macro(A1, A2, A3, A4, A5, A6, A7, A8) A1, A2, A3, A4, A5, A6, A7, A8
#define LogStructureArgument9Macro(A1, A2, A3, A4, A5, A6, A7, A8, A9) A1, A2, A3, A4, A5, A6, A7, A8, A9
#define LogStructureArgument10Macro(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) A1, A2, A3, A4, A5, A6, A7, A8, A9, A10

#define LogMethodStructureMacro(O, M, N, C, PARAMS) O##M##MethodValue N = { LogStructureArgument##C##Macro PARAMS };

#define LogMethodValueMacro(LOG, LEVEL, O, M, V, C, PARAMS)                                             \
    if (LOG->IsAcceptable(LOGGER_LEVEL_##LEVEL))                                                        \
    {                                                                                                   \
        LogMethodStructureMacro(O, M, __value__, C, PARAMS)                                             \
        LogMethod(LOG, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, V, METHOD_ID_##O##_##M, &__value__);        \
    }

#define LogMethodResultMacro(LOG, LEVEL, O, M, V, ERR, RT, R)                                                               \
    CONST RT __result__ = R;                                                                                                \
    if (LOG->IsAcceptable((ERR) ? (LOGGERLEVEL)(LOGGER_LEVEL_ERROR | LOGGER_LEVEL_##LEVEL) : (LOGGER_LEVEL_##LEVEL)))       \
    {                                                                                                                       \
        LogMethodResult(LOG, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, V, METHOD_ID_##O##_##M, (RT)__result__, NULL);            \
    }                                                                                                                       \
    return __result__;

#define LogMethodResultValueMacro(LOG, LEVEL, O, M, V, ERR, RT, R, C, PARAMS)                                               \
    CONST RT __result__ = R;                                                                                                \
    if (LOG->IsAcceptable((ERR) ? (LOGGERLEVEL)(LOGGER_LEVEL_ERROR | LOGGER_LEVEL_##LEVEL) : (LOGGER_LEVEL_##LEVEL)))       \
    {                                                                                                                       \
        LogMethodStructureMacro(O, M, __value__, C, PARAMS)                                                                 \
        LogMethodResult(LOG, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, V, METHOD_ID_##O##_##M, (ADDR)__result__, &__value__);    \
    }                                                                                                                       \
    return __result__;

#define LogMethodCallbackStructureMacro(O, M, MC, N, C, PARAMS) O##MC##MethodCallbackValue N = { LogStructureArgument##C##Macro PARAMS };

#define LogMethodCallbackValueMacro(LOG, LEVEL, O, M, MC, V, C, PARAMS)                                                                 \
    if (LOG->IsAcceptable(LOGGER_LEVEL_##LEVEL))                                                                                        \
    {                                                                                                                                   \
        LogMethodCallbackStructureMacro(O, M, MC, __value__, C, PARAMS)                                                                 \
        LogMethodCallback(LOG, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, V, METHOD_ID_##O##_##M, METHODCALLBACK_ID_##O##_##MC, &__value__);  \
    }

#define LogMethodCallbackResultValueMacro(LOG, LEVEL, O, M, MC, V, RT, R, C, PARAMS)                                                                            \
    CONST RT __result__ = R;                                                                                                                                    \
    if (LOG->IsAcceptable(LOGGER_LEVEL_##LEVEL))                                                                                                                \
    {                                                                                                                                                           \
        LogMethodCallbackStructureMacro(O, M, MC, __value__, C, PARAMS)                                                                                         \
        LogMethodCallbackResult(LOG, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, V, METHOD_ID_##O##_##M, METHODCALLBACK_ID_##O##_##MC, (ADDR)__result__, &__value__);  \
    }                                                                                                                                                           \
    return __result__;

VOID LogMessage(LPLOGGER logger, CONST LOGGERLEVEL level, LPCSTR message);
VOID LogMessage(LPLOGGER logger, CONST LOGGERLEVEL level, LPCSTR message, ...);
VOID LogStructure(LPLOGGER logger, CONST LOGGERLEVEL level, CONST LOGGERACTIONID id, CONST LPVOID value);
VOID LogAttachProcess(LPLOGGER logger, CONST LOGGERLEVEL level);
VOID LogDetachProcess(LPLOGGER logger, CONST LOGGERLEVEL level);
VOID LogAttachThread(LPLOGGER logger, CONST LOGGERLEVEL level);
VOID LogDetachThread(LPLOGGER logger, CONST LOGGERLEVEL level);
VOID LogConstructor(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object);
VOID LogDestructor(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object);
VOID LogMethod(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object, CONST AGENTMETHODID method, CONST LPVOID value);
VOID LogMethodResult(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object, CONST AGENTMETHODID method, CONST ADDR result, CONST LPVOID value);
VOID LogMethodCallback(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object, CONST AGENTMETHODID method, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value);
VOID LogMethodCallbackResult(LPLOGGER logger, CONST LOGGERLEVEL level, CONST AGENTOBJECTID id, CONST LPVOID object, CONST AGENTMETHODID method, CONST AGENTMETHODCALLBACKID callback, CONST ADDR result, CONST LPVOID value);
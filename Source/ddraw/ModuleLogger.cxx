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

#include "AgentLogger.hxx"
#include "ModuleLogger.hxx"

#include <shlwapi.h>

#define LOGGER_SETTINGS_INI_FILE "DDRAW.INI"
#define LOGGER_SETTINGS_SECTION_NAME "Logger"
#define LOGGER_SETTINGS_NAME_VALUE_NAME "Name"

#define LOGGER_SETTINGS_DEFAULT_VALUE ""

#define LOGGER_SETTINGS_MAX_STRING_LENGTH 256

#define LOGGER_SETTINGS_BINARY_FORMATTER_NAME "Binary"
#define LOGGER_SETTINGS_TEXT_FORMATTER_NAME "Text"

#define LOGGER_SETTINGS_CONSOLE_WRITER_NAME "Console"
#define LOGGER_SETTINGS_DEBUG_WRITER_NAME "Debug"
#define LOGGER_SETTINGS_FILE_WRITER_NAME "File"

static BOOL AcquireLoggerName(LPCSTR input, CONST SIZE_T position, LPSTR name)
{
    if (input == NULL || name == NULL) { return FALSE; }

    if (strlen(input) < position || input[position] == NULL) { return FALSE; }

    SIZE_T current = position;

    while (input[current] != NULL)
    {
        CONST CHAR c = input[current];

        if (c == ' ' || c == ',' || c == ';') { break; }

        name[current - position] = c;

        current++;
    }

    name[current - position] = NULL;

    return TRUE;
}

static BOOL InitializeLoggerFilePath(LPSTR path)
{
    CHAR dir[LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH];
    ZeroMemory(dir, LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH);

    if (GetCurrentDirectoryA(LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH, dir) == 0) { return FALSE; }

    if (PathCombineA(path, dir, LOGGER_SETTINGS_INI_FILE) == NULL) { return FALSE; }

    return TRUE;
}

static BOOL IsLoggerFormatterNameValid(LPCSTR name)
{
    if (strcmpi(name, LOGGER_SETTINGS_BINARY_FORMATTER_NAME) == 0) { return TRUE; }
    else if (strcmpi(name, LOGGER_SETTINGS_TEXT_FORMATTER_NAME) == 0) { return TRUE; }

    return FALSE;
}
static BOOL IsLoggerWriterNameValid(LPCSTR name)
{
    if (strcmpi(name, LOGGER_SETTINGS_CONSOLE_WRITER_NAME) == 0) { return TRUE; }
    else if (strcmpi(name, LOGGER_SETTINGS_DEBUG_WRITER_NAME) == 0) { return TRUE; }
    else if (strcmpi(name, LOGGER_SETTINGS_FILE_WRITER_NAME) == 0) { return TRUE; }

    return FALSE;
}

static LPLOGGERSERIALIZER AcquireLoggerSerializer(LPCSTR name, LPLOGGERSETTINGS settings, LPLOGGERWRITER writer)
{
    if (strcmpi(name, LOGGER_SETTINGS_BINARY_FORMATTER_NAME) == 0) { return new BinaryLoggerSerializer(settings, writer); }
    else if (strcmpi(name, LOGGER_SETTINGS_TEXT_FORMATTER_NAME) == 0) { return new TextLoggerSerializer(settings, writer); }

    return NULL;
}

static LPLOGGERWRITER AcquireLoggerWriter(LPCSTR name, LPLOGGERSETTINGS settings)
{
    if (strcmpi(name, LOGGER_SETTINGS_CONSOLE_WRITER_NAME) == 0) { return new ConsoleLoggerWriter(settings); }
    else if (strcmpi(name, LOGGER_SETTINGS_DEBUG_WRITER_NAME) == 0) { return new DebugLoggerWriter(settings); }
    else if (strcmpi(name, LOGGER_SETTINGS_FILE_WRITER_NAME) == 0) { return new FileLoggerWriter(settings); }

    return NULL;
}

static LPLOGGER InitializeLoggerInstance(LPCSTR file, LPCSTR section)
{
    CHAR formatter[LOGGER_SETTINGS_MAX_STRING_LENGTH];
    ZeroMemory(formatter, LOGGER_SETTINGS_MAX_STRING_LENGTH);

    GetPrivateProfileStringA(section, LOGGER_SETTINGS_SERIALIZER_PROPERTY_NAME,
        LOGGER_SETTINGS_DEFAULT_VALUE, formatter, LOGGER_SETTINGS_MAX_STRING_LENGTH, file);

    CHAR writer[LOGGER_SETTINGS_MAX_STRING_LENGTH];
    ZeroMemory(writer, LOGGER_SETTINGS_MAX_STRING_LENGTH);

    GetPrivateProfileStringA(section, LOGGER_SETTINGS_WRITER_PROPERTY_NAME,
        LOGGER_SETTINGS_DEFAULT_VALUE, writer, LOGGER_SETTINGS_MAX_STRING_LENGTH, file);

    if (!IsLoggerFormatterNameValid(formatter) || !IsLoggerWriterNameValid(writer)) { return NULL; }

    LPLOGGERSETTINGS settings = new FileLoggerSettings(file, section);

    return new Logger(settings, AcquireLoggerSerializer(formatter, settings, AcquireLoggerWriter(writer, settings)));
}

BOOL InitializeModuleLogger(VOID)
{
    CHAR file[LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH];
    ZeroMemory(file, LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH);

    if (!InitializeLoggerFilePath(file)) { return FALSE; }

    MultiLogger* multi = new MultiLogger();

    {
        CHAR configuration[LOGGER_SETTINGS_MAX_STRING_LENGTH];
        ZeroMemory(configuration, LOGGER_SETTINGS_MAX_STRING_LENGTH);

        GetPrivateProfileStringA(LOGGER_SETTINGS_SECTION_NAME, LOGGER_SETTINGS_NAME_VALUE_NAME,
            LOGGER_SETTINGS_DEFAULT_VALUE, configuration, LOGGER_SETTINGS_MAX_STRING_LENGTH, file);

        SIZE_T indx = 0;

        CHAR name[LOGGER_SETTINGS_MAX_STRING_LENGTH];
        ZeroMemory(name, LOGGER_SETTINGS_MAX_STRING_LENGTH);

        while (AcquireLoggerName(configuration, indx, name))
        {
            indx += strlen(name) + 1;

            if (strlen(name) != 0)
            {
                LPLOGGER logger = InitializeLoggerInstance(file, name);

                if (logger != NULL) { multi->Attach(logger); }
            }
        }
    }

    Module.Logger = multi;

    return TRUE;
}

BOOL ReleaseModuleLogger(VOID)
{
    if (Module.Logger != NULL)
    {
        delete Module.Logger;

        Module.Logger = NULL;
    }

    return TRUE;
}
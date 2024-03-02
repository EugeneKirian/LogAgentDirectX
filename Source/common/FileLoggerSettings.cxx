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

#include "Logger.hxx"

#include <shlwapi.h>
#include <stdio.h>

#define LOGGER_SETTINGS_EMPTY_STRING_VALUE ""
#define LOGGER_SETTINGS_FALSE_STRING_VALUE "FALSE"
#define LOGGER_SETTINGS_TRUE_STRING_VALUE "TRUE"
#define LOGGER_SETTINGS_ZERO_STRING_VALUE "0"

#define LOGGER_SETTINGS_DEFAULT_STRING_VALUE ""
#define LOGGER_SETTINGS_MAX_STRING_SIZE 100

static BOOL InitializeLoggerFilePath(LPCSTR file, LPSTR path)
{
    CHAR dir[LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH];
    ZeroMemory(dir, LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH);

    if (GetCurrentDirectoryA(LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH, dir) == 0) { return FALSE; }

    if (PathCombineA(path, dir, file) == NULL) { return FALSE; }

    return TRUE;
}

FileLoggerSettings::FileLoggerSettings(LPCSTR file, LPCSTR section)
{
    ZeroMemory(this->State.Name, LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH);
    strcpy_s(this->State.Section, LOGGER_SETTINGS_MAX_SECTION_LENGTH, section);

    if (!InitializeLoggerFilePath(file, this->State.Name)) { sprintf_s(this->State.Name, LOGGER_SETTINGS_MAX_FILE_PATH_LENGTH, ".\\%s", file); }
}

FileLoggerSettings::~FileLoggerSettings() { }

CONST BOOL FileLoggerSettings::ReadBool(LPCSTR name, BOOL* value)
{
    if (value == NULL) { return FALSE; }

    CHAR str[LOGGER_SETTINGS_MAX_STRING_SIZE];
    ZeroMemory(str, LOGGER_SETTINGS_MAX_STRING_SIZE);

    if (!this->ReadString(name, str, LOGGER_SETTINGS_MAX_STRING_SIZE)) { return TRUE; }

    if (strcmpi(str, LOGGER_SETTINGS_EMPTY_STRING_VALUE) == 0) { *value = FALSE; }
    else if (strcmpi(str, LOGGER_SETTINGS_FALSE_STRING_VALUE) == 0) { *value = FALSE; }
    else if (strcmpi(str, LOGGER_SETTINGS_ZERO_STRING_VALUE) == 0) { *value = FALSE; }
    else { *value = TRUE; }

    return TRUE;
}

CONST BOOL FileLoggerSettings::ReadInteger(LPCSTR name, INT* value)
{
    if (value == NULL) { return FALSE; }

    CHAR str[LOGGER_SETTINGS_MAX_STRING_SIZE];
    ZeroMemory(str, LOGGER_SETTINGS_MAX_STRING_SIZE);

    if (!this->ReadString(name, str, LOGGER_SETTINGS_MAX_STRING_SIZE)) { return FALSE; }

    return sscanf_s(str, "%d", value) == 1;
}

CONST BOOL FileLoggerSettings::ReadString(LPCSTR name, LPSTR value, CONST DWORD size)
{
    if (value == NULL) { return FALSE; }

    return GetPrivateProfileStringA(this->State.Section, name, LOGGER_SETTINGS_DEFAULT_STRING_VALUE, value, size, this->State.Name) != 0;
}
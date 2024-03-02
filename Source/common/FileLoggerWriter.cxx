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

#include <stdio.h>

#define LOGGER_SETTINGS_WRITER_FILE_PROPERTY_NAME "File"
#define LOGGER_SETTINGS_WRITER_APPEND_PROPERTY_NAME "Append"

// TODO: Templates in the file names.
// TODO: Create directories.

FileLoggerWriter::FileLoggerWriter(LPLOGGERSETTINGS settings) : LoggerWriter(settings)
{
    this->State.Handle = INVALID_HANDLE_VALUE;

    ZeroMemory(&this->State.Mutex, sizeof(CRITICAL_SECTION));

    InitializeCriticalSection(&this->State.Mutex);

    CHAR file[MAX_PATH];
    ZeroMemory(file, MAX_PATH);

    if (settings->ReadString(LOGGER_SETTINGS_WRITER_FILE_PROPERTY_NAME, file, MAX_PATH))
    {
        BOOL append = FALSE;
        settings->ReadBool(LOGGER_SETTINGS_WRITER_APPEND_PROPERTY_NAME, &append);

        this->State.Handle = CreateFileA(file, GENERIC_READ | GENERIC_WRITE | FILE_APPEND_DATA,
            FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
            append ? OPEN_ALWAYS : CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

        if (this->State.Handle != INVALID_HANDLE_VALUE)
        {
            if (append) { SetFilePointer(this->State.Handle, 0, NULL, FILE_END); }
        }
    }
}

FileLoggerWriter::~FileLoggerWriter()
{
    if (this->State.Handle != NULL) { CloseHandle(this->State.Handle); }

    DeleteCriticalSection(&this->State.Mutex);
}

CONST BOOL FileLoggerWriter::Write(CONST LPCVOID value, CONST DWORD size)
{
    if (value == NULL || size == 0) { return FALSE; }
    if (this->State.Handle == INVALID_HANDLE_VALUE) { return FALSE; }

    EnterCriticalSection(&this->State.Mutex);

    DWORD written = 0;
    CONST BOOL result = WriteFile(this->State.Handle, value, size, &written, NULL);

    LeaveCriticalSection(&this->State.Mutex);

    return result && written == size;
}
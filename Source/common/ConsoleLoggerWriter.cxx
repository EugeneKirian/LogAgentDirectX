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

#define AGENT_CONSOLE_TITLE "AgentDirectX Console Logger"

ConsoleLoggerWriter::ConsoleLoggerWriter(LPLOGGERSETTINGS settings) : LoggerWriter(settings)
{
    this->State.Handle = INVALID_HANDLE_VALUE;

    ZeroMemory(&this->State.Mutex, sizeof(CRITICAL_SECTION));

    InitializeCriticalSection(&this->State.Mutex);

    if (AttachConsole(ATTACH_PARENT_PROCESS) == ERROR_INVALID_HANDLE)
    {
        if (!AllocConsole()) { return; }

        this->State.Handle = CreateFileA("CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if (this->State.Handle != INVALID_HANDLE_VALUE) { SetStdHandle(STD_OUTPUT_HANDLE, this->State.Handle); }
    }
    else
    {
        this->State.Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    SetConsoleTitleA(AGENT_CONSOLE_TITLE);
}

ConsoleLoggerWriter::~ConsoleLoggerWriter()
{
    if (this->State.Handle != NULL) { CloseHandle(this->State.Handle); }

    FreeConsole();

    DeleteCriticalSection(&this->State.Mutex);
}

CONST BOOL ConsoleLoggerWriter::Write(CONST LPCVOID value, CONST DWORD size)
{
    if (value == NULL || size == 0) { return FALSE; }
    if (this->State.Handle == INVALID_HANDLE_VALUE) { return FALSE; }

    EnterCriticalSection(&this->State.Mutex);

    DWORD written = 0;
    CONST BOOL result = WriteFile(this->State.Handle, value, size, &written, NULL);

    LeaveCriticalSection(&this->State.Mutex);

    return result && written == size;
}
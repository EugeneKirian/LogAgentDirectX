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

MultiLogger::MultiLogger() : Logger() { }

MultiLogger::~MultiLogger()
{
    if (this->State.Settings != NULL) { delete this->State.Settings; this->State.Settings = NULL; }
    if (this->State.Serializer != NULL) { delete this->State.Serializer; this->State.Serializer = NULL; }

    DeleteCriticalSection(&this->State.Mutex);

    CONST INT count = this->Items.Count();

    for (INT x = count - 1; x >= 0; x--)
    {
        delete this->Items[x];

        this->Items.Remove(x);
    }
}

CONST BOOL MultiLogger::Attach(LPLOGGER logger)
{
    if (logger == NULL) { return FALSE; }

    EnterCriticalSection(&this->State.Mutex);

    CONST BOOL result = this->Items.Add(logger);

    LeaveCriticalSection(&this->State.Mutex);

    return result;
}

CONST BOOL MultiLogger::IsAcceptable(CONST LOGGERLEVEL level)
{
    CONST INT count = this->Items.Count();

    if (count == 0) { return FALSE; }

    BOOL result = FALSE;

    for (INT x = 0; x < count; x++)
    {
        if (this->Items[x]->IsAcceptable(level)) { return TRUE; }
    }

    return FALSE;
}

VOID MultiLogger::Log(CONST LPLOGGERACTION action)
{
    if (action == NULL) { return; }

    CONST INT count = this->Items.Count();

    if (count == 0) { return; }

    EnterCriticalSection(&this->State.Mutex);

    for (INT x = 0; x < count; x++) { this->Items[x]->Log(action); }

    LeaveCriticalSection(&this->State.Mutex);
}
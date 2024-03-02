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

#include "StringBuilder.hxx"

#include <stdio.h>

#define STRING_BUILDER_DEFAULT_CAPACITY_VALUE   (4 * 1024) /* 4 KB */
#define STRING_BUILDER_RESIZE_MULTIPLIER_VALUE  2

StringBuilder::StringBuilder() : StringBuilder(STRING_BUILDER_DEFAULT_CAPACITY_VALUE) { }

StringBuilder::StringBuilder(CONST INT capacity)
{
    this->State.Count = 0;
    this->State.Capacity = capacity <= 0 ? STRING_BUILDER_DEFAULT_CAPACITY_VALUE : capacity;

    CONST UINT size = capacity * sizeof(CHAR);

    this->State.Value = (LPSTR)malloc(size);

    if (this->State.Value == NULL) { this->State.Capacity = 0; }
    else { ZeroMemory(this->State.Value, size); }

    ZeroMemory(&this->State.Mutex, sizeof(CRITICAL_SECTION));
    InitializeCriticalSection(&this->State.Mutex);
}

StringBuilder::~StringBuilder()
{
    this->State.Count = 0;
    this->State.Capacity = 0;

    if (this->State.Value != NULL) { free(this->State.Value); this->State.Value = NULL; }

    DeleteCriticalSection(&this->State.Mutex);
}

CONST BOOL StringBuilder::Append(LPCSTR value)
{
    if (value == NULL || this->State.Value == NULL) { return FALSE; }

    EnterCriticalSection(&this->State.Mutex);

    CONST INT size = (INT)strlen(value);

    if (this->State.Capacity <= (this->State.Count + size + 1))
    {
        CONST INT capacity = MAX(this->State.Capacity * STRING_BUILDER_RESIZE_MULTIPLIER_VALUE, this->State.Capacity + size + 1);

        LPSTR ptr = (CHAR*)realloc(this->State.Value, capacity * sizeof(CHAR));

        if (ptr == NULL) { LeaveCriticalSection(&this->State.Mutex); return FALSE; }

        this->State.Value = ptr;
        this->State.Capacity = capacity;

        ZeroMemory(&this->State.Value[this->State.Count], (this->State.Capacity - this->State.Count) * sizeof(CHAR));
    }

    strcat_s(&this->State.Value[this->State.Count], this->State.Capacity - this->State.Count, value);

    this->State.Count += size;

    LeaveCriticalSection(&this->State.Mutex);

    return TRUE;
}

VOID StringBuilder::Clear(VOID)
{
    if (this->State.Value == NULL || this->State.Count == 0) { return; }

    EnterCriticalSection(&this->State.Mutex);

    ZeroMemory(this->State.Value, this->State.Count * sizeof(CHAR));

    this->State.Count = 0;

    LeaveCriticalSection(&this->State.Mutex);
}

CONST INT StringBuilder::Count(VOID)
{
    return this->State.Count;
}

CONST BOOL StringBuilder::Format(LPCSTR format, ...)
{
    if (format == NULL || this->State.Value == NULL) { return FALSE; }

    va_list args;
    va_start(args, format);
    CONST BOOL result = this->Arguments(format, args);
    va_end(args);

    return result;
}

CONST BOOL StringBuilder::Arguments(LPCSTR format, CONST va_list args)
{
    if (format == NULL || this->State.Value == NULL) { return FALSE; }

    CONST INT size = (INT)_vscprintf(format, args);

    if (size < 0) { return FALSE; }
    else if (size == 0) { return TRUE; }

    EnterCriticalSection(&this->State.Mutex);

    if (this->State.Capacity <= (this->State.Count + size + 1))
    {
        CONST INT capacity = MAX(this->State.Capacity * STRING_BUILDER_RESIZE_MULTIPLIER_VALUE, this->State.Capacity + size + 1);

        LPSTR ptr = (CHAR*)realloc(this->State.Value, capacity * sizeof(CHAR));

        if (ptr == NULL) { LeaveCriticalSection(&this->State.Mutex); return FALSE; }

        this->State.Value = ptr;
        this->State.Capacity = capacity;

        ZeroMemory(&this->State.Value[this->State.Count], (this->State.Capacity - this->State.Count) * sizeof(CHAR));
    }

    vsprintf_s(&this->State.Value[this->State.Count], this->State.Capacity - this->State.Count, format, args);

    this->State.Count += size;

    LeaveCriticalSection(&this->State.Mutex);

    return TRUE;
}

LPCSTR StringBuilder::String(VOID)
{
    return this->State.Value;
}
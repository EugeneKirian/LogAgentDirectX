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

#include "Base.hxx"

#define ARRAY_DEFAULT_CAPACITY_VALUE 16
#define ARRAY_DEFAULT_CAPACITY_MULTIPLIER_VALUE 2

template<typename T>
class Array
{
public:
    Array();
    Array(CONST INT capacity);
    virtual ~Array();

    CONST BOOL Add(CONST T& item);
    T& At(CONST INT index);
    VOID Clear(VOID);
    CONST BOOL Contains(CONST T& item);
    CONST INT Count(VOID);
    CONST BOOL Remove(CONST INT index);

    T& operator[](CONST INT index);

protected:
    struct
    {
        INT Count;
        INT Capacity;
        T* Items;
        CRITICAL_SECTION Mutex;
    } State;
};

template<typename T>
inline Array<T>::Array() : Array(ARRAY_DEFAULT_CAPACITY_VALUE) { }

template<typename T>
inline Array<T>::Array(CONST INT capacity)
{
    this->State.Count = 0;
    this->State.Capacity = capacity <= 0 ? ARRAY_DEFAULT_CAPACITY_MULTIPLIER_VALUE : capacity;

    CONST INT size = capacity * sizeof(T);

    this->State.Items = (T*)malloc(size);

    if (this->State.Items == NULL) { this->State.Capacity = 0; }
    else { ZeroMemory(this->State.Items, size); }

    ZeroMemory(&this->State.Mutex, sizeof(CRITICAL_SECTION));
    InitializeCriticalSection(&this->State.Mutex);
}

template<typename T>
inline Array<T>::~Array()
{
    this->State.Count = 0;
    this->State.Capacity = 0;

    if (this->State.Items != NULL) { free(this->State.Items); this->State.Items = NULL; }

    DeleteCriticalSection(&this->State.Mutex);
}

template<typename T>
CONST BOOL Array<T>::Add(CONST T& item)
{
    if (this->State.Items == NULL) { return FALSE; }

    EnterCriticalSection(&this->State.Mutex);

    if (this->State.Capacity <= (this->State.Count + 1))
    {
        CONST INT capacity = this->State.Capacity * ARRAY_DEFAULT_CAPACITY_MULTIPLIER_VALUE;

        T* ptr = (T*)realloc(this->State.Items, capacity * sizeof(T));

        if (ptr == NULL) { LeaveCriticalSection(&this->State.Mutex); return FALSE; }

        this->State.Items = ptr;
        this->State.Capacity = capacity;

        ZeroMemory(&this->State.Items[this->State.Count], (this->State.Capacity - this->State.Count) * sizeof(T));
    }

    this->State.Items[this->State.Count++] = item;

    LeaveCriticalSection(&this->State.Mutex);

    return TRUE;
}

template<typename T>
inline T& Array<T>::At(CONST INT index)
{
    return this->State.Items[index];
}

template<typename T>
VOID Array<T>::Clear(VOID)
{
    if (this->State.Items == NULL || this->State.Count == 0) { return; }

    EnterCriticalSection(&this->State.Mutex);

    ZeroMemory(this->State.Items, this->State.Count * sizeof(T));

    this->State.Count = 0;

    LeaveCriticalSection(&this->State.Mutex);
}

template<typename T>
CONST BOOL Array<T>::Contains(CONST T& item)
{
    if (this->State.Items == NULL || this->State.Count == 0) { return FALSE; }

    BOOL result = FALSE;

    EnterCriticalSection(&this->State.Mutex);

    for (INT x = 0; x < (this->State.Count - 1); x++)
    {
        if (this->State.Items[x] == item) { result = TRUE; break; }
    }

    LeaveCriticalSection(&this->State.Mutex);

    return result;
}

template<typename T>
inline CONST INT Array<T>::Count(VOID)
{
    return this->State.Count;
}

template<typename T>
CONST BOOL Array<T>::Remove(CONST INT index)
{
    if (this->State.Items == NULL || this->State.Count == 0) { return FALSE; }
    if (index < 0 || this->State.Count < index) { return FALSE; }

    EnterCriticalSection(&this->State.Mutex);

    for (INT x = index; x < (this->State.Count - 1); x++)
    {
        this->State.Items[x] = this->State.Items[x + 1];
    }

    this->State.Count--;

    ZeroMemory(&this->State.Items[this->State.Count], sizeof(T));

    LeaveCriticalSection(&this->State.Mutex);

    return TRUE;
}

template<typename T>
inline T& Array<T>::operator[](CONST INT index)
{
    return this->State.Items[index];
}
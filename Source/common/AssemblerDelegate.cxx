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

#include "Assembler.hxx"

AssemblerDelegateState::AssemblerDelegateState(LPASSEMBLER assembler)
{
    this->Assembler = assembler;

    ZeroMemory(&this->Mutex, sizeof(CRITICAL_SECTION));
    InitializeCriticalSection(&this->Mutex);
}

AssemblerDelegateState::~AssemblerDelegateState()
{
    DeleteCriticalSection(&this->Mutex);
}

AssemblerDelegate::AssemblerDelegate(LPASSEMBLER assembler)
{
	this->State = new AssemblerDelegateState(assembler);
}

AssemblerDelegate::~AssemblerDelegate()
{
	this->State->Assembler->RemoveDelegate(this);

	delete this->State;
}

BOOL AssemblerDelegate::Agent(LPVOID value, REFIID riid, LPVOID* agent)
{
    BOOL result = FALSE;

    if (agent == NULL) { return result; }

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerDelegateItem item = this->State->Items[x];

        if (item.Value == value)
        {
            *agent = item.Agent;

            if (item.IID != riid) { item.IID = riid; }

            result = TRUE;

            break;
        }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

LPVOID AssemblerDelegate::Agent(LPVOID value, REFIID riid)
{
    LPVOID result = NULL;

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerDelegateItem item = this->State->Items[x];

        if (item.Value == value)
        {
            result = item.Agent;

            if (item.IID != riid) { item.IID = riid; }

            break;
        }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL AssemblerDelegate::Initialize(LPVOID value, REFIID riid, LPVOID agent)
{
    EnterCriticalSection(&this->State->Mutex);

    AssemblerDelegateItem item;

    item.Agent = agent;
    item.IID = riid;
    item.Value = value;

    BOOL result = this->State->Items.Add(item);

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL AssemblerDelegate::IsAgent(LPVOID agent, REFIID riid)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerDelegateItem item = this->State->Items[x];

        if (item.Agent == agent && item.IID == riid) { result = TRUE; break; }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL AssemblerDelegate::IsValue(LPVOID value, REFIID riid)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerDelegateItem item = this->State->Items[x];

        if (item.Value == value && item.IID == riid) { result = TRUE; break; }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL AssemblerDelegate::Remove(LPVOID agent, REFIID /*riid*/, LPVOID value)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    {
        for (INT x = 0; x < this->State->Items.Count(); x++)
        {
            AssemblerDelegateItem item = this->State->Items[x];

            if (item.Agent == agent) { result = this->State->Items.Remove(x); x--; }
        }
    }

    {
        for (INT x = 0; x < this->State->Items.Count(); x++)
        {
            AssemblerDelegateItem item = this->State->Items[x];

            if (item.Value == value) { result = this->State->Items.Remove(x); x--; }
        }
    }

    BOOL empty = this->State->Items.Count() == 0;

    LeaveCriticalSection(&this->State->Mutex);

    if (empty) { delete this; }

    return result;
}

BOOL AssemblerDelegate::RemoveAgent(LPVOID agent, REFIID /*riid*/)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    for (INT x = 0; x < this->State->Items.Count(); x++)
    {
        AssemblerDelegateItem item = this->State->Items[x];

        if (item.Agent == agent) { result = this->State->Items.Remove(x); x--; }
    }

    BOOL empty = this->State->Items.Count() == 0;

    LeaveCriticalSection(&this->State->Mutex);

    if (empty) { delete this; }

    return result;
}

BOOL AssemblerDelegate::RemoveValue(LPVOID value, REFIID /*riid*/)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    for (INT x = 0; x < this->State->Items.Count(); x++)
    {
        AssemblerDelegateItem item = this->State->Items[x];

        if (item.Value == value) { result = this->State->Items.Remove(x); x--; }
    }

    BOOL empty = this->State->Items.Count() == 0;

    LeaveCriticalSection(&this->State->Mutex);

    if (empty) { delete this; }

    return result;
}

BOOL AssemblerDelegate::Value(LPVOID agent, REFIID riid, LPVOID* value)
{
    BOOL result = FALSE;

    if (value == NULL) { return result; }

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerDelegateItem item = this->State->Items[x];

        if (item.Agent == agent && item.IID == riid) { *value = item.Value; result = TRUE; break; }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

LPVOID AssemblerDelegate::Value(LPVOID agent, REFIID riid)
{
    EnterCriticalSection(&this->State->Mutex);

    LPVOID result = NULL;

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerDelegateItem item = this->State->Items[x];

        if (item.Agent == agent && item.IID == riid) { result = item.Value; break; }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}
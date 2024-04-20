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

AssemblerState::AssemblerState()
{
    ZeroMemory(&this->Mutex, sizeof(CRITICAL_SECTION));

    InitializeCriticalSection(&this->Mutex);
}

AssemblerState::~AssemblerState()
{
    DeleteCriticalSection(&this->Mutex);
}

Assembler::Assembler()
{
    this->State = new AssemblerState();
}

Assembler::~Assembler()
{
    delete this->State;
}

BOOL Assembler::Agent(LPVOID value, REFIID riid, LPVOID* agent)
{
    BOOL result = FALSE;

    if (agent == NULL) { return result; }

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Value == value)
        {
            if (item.Delegate->Agent(value, riid, agent)) { result = TRUE; break; }
        }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

LPVOID Assembler::Agent(LPVOID value, REFIID riid)
{
    LPVOID result = NULL;

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Value == value)
        {
            if (item.Delegate->Agent(value, riid, &result)) { break; }
        }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL Assembler::Initialize(LPVOID agent, LPASSEMBLERDELEGATE delegate, LPVOID value)
{
    EnterCriticalSection(&this->State->Mutex);

    AssemblerItem item;

    item.Agent = agent;
    item.Delegate = delegate;
    item.Value = value;

    BOOL result = this->State->Items.Add(item);

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL Assembler::IsAgent(LPVOID agent, REFIID riid, CONST BOOL base)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Agent == agent)
        {
            if (item.Delegate->IsAgent(agent, riid, base)) { result = TRUE; break; }
        }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL Assembler::IsValue(LPVOID value, REFIID riid, CONST BOOL base)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Value == value)
        {
            if (item.Delegate->IsValue(value, riid, base)) { result = TRUE; break; }
        }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL Assembler::RemoveAgent(LPVOID agent, REFIID /*riid*/)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    for (INT x = 0; x < this->State->Items.Count(); x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Agent == agent) { result = this->State->Items.Remove(x); x--; }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL Assembler::RemoveDelegate(LPASSEMBLERDELEGATE delegate)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    for (INT x = 0; x < this->State->Items.Count(); x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Delegate == delegate) { result = this->State->Items.Remove(x); x--; }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL Assembler::RemoveValue(LPVOID value, REFIID /*riid*/)
{
    BOOL result = FALSE;

    EnterCriticalSection(&this->State->Mutex);

    for (INT x = 0; x < this->State->Items.Count(); x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Value == value) { result = this->State->Items.Remove(x); x--; }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

BOOL Assembler::Value(LPVOID agent, REFIID riid, CONST BOOL base, LPVOID* value)
{
    BOOL result = FALSE;

    if (value == NULL) { return result; }

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Agent == agent)
        {
            if (item.Delegate->Value(agent, riid, base, value)) { result = TRUE; break; }
        }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}

LPVOID Assembler::Value(LPVOID agent, REFIID riid, CONST BOOL base)
{
    LPVOID result = NULL;

    EnterCriticalSection(&this->State->Mutex);

    CONST INT count = this->State->Items.Count();

    for (INT x = 0; x < count; x++)
    {
        AssemblerItem item = this->State->Items[x];

        if (item.Agent == agent)
        {
            if (item.Delegate->Value(agent, riid, base, &result)) { break; }
        }
    }

    LeaveCriticalSection(&this->State->Mutex);

    return result;
}
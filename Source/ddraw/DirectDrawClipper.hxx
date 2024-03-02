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

class DirectDrawClipper : public IDirectDrawClipper
{
public:
    DirectDrawClipper(AgentConstructorParameters(DirectDrawClipper));
    virtual ~DirectDrawClipper();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectDrawClipper ***/

    STDMETHOD(GetClipList)(THIS_ LPRECT, LPRGNDATA, LPDWORD);
    STDMETHOD(GetHWnd)(THIS_ HWND FAR*);
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD);
    STDMETHOD(IsClipListChanged)(THIS_ BOOL FAR*);
    STDMETHOD(SetClipList)(THIS_ LPRGNDATA, DWORD);
    STDMETHOD(SetHWnd)(THIS_ DWORD, HWND);

protected:
    AgentStateStruct(DirectDrawClipper);
};
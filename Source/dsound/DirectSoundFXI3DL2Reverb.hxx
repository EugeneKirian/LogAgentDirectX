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

class DirectSoundFXI3DL2Reverb : public IDirectSoundFXI3DL2Reverb
{
public:
    DirectSoundFXI3DL2Reverb(AgentConstructorParameters(DirectSoundFXI3DL2Reverb));
    virtual ~DirectSoundFXI3DL2Reverb();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectSoundFXI3DL2Reverb ***/

    STDMETHOD(SetAllParameters)(THIS_ LPCDSFXI3DL2Reverb pcDsFxI3DL2Reverb);
    STDMETHOD(GetAllParameters)(THIS_ LPDSFXI3DL2Reverb pDsFxI3DL2Reverb);
    STDMETHOD(SetPreset)(THIS_ DWORD dwPreset);
    STDMETHOD(GetPreset)(THIS_ LPDWORD pdwPreset);
    STDMETHOD(SetQuality)(THIS_ LONG lQuality);
    STDMETHOD(GetQuality)(THIS_ LPLONG plQuality);

protected:
    AgentStateStruct(DirectSoundFXI3DL2Reverb);
};
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

class DirectSoundCaptureBuffer8 : public IDirectSoundCaptureBuffer8
{
public:
    DirectSoundCaptureBuffer8(AgentConstructorParameters(DirectSoundCaptureBuffer8));
    virtual ~DirectSoundCaptureBuffer8();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectSoundCaptureBuffer ***/

    STDMETHOD(GetCaps)(THIS_ LPDSCBCAPS pDSCBCaps);
    STDMETHOD(GetCurrentPosition)(THIS_ LPDWORD pdwCapturePosition, LPDWORD pdwReadPosition);
    STDMETHOD(GetFormat)(THIS_ LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, LPDWORD pdwSizeWritten);
    STDMETHOD(GetStatus)(THIS_ LPDWORD pdwStatus);
    STDMETHOD(Initialize)(THIS_ LPDIRECTSOUNDCAPTURE pDirectSoundCapture, LPCDSCBUFFERDESC pcDSCBufferDesc);
    STDMETHOD(Lock)(THIS_ DWORD dwOffset, DWORD dwBytes, LPVOID* ppvAudioPtr1, LPDWORD pdwAudioBytes1, LPVOID* ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags);
    STDMETHOD(Start)(THIS_ DWORD dwFlags);
    STDMETHOD(Stop)(THIS);
    STDMETHOD(Unlock)(THIS_ LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2);

    /*** IDirectSoundCaptureBuffer8 ***/

    STDMETHOD(GetObjectInPath)(THIS_ REFGUID rguidObject, DWORD dwIndex, REFGUID rguidInterface, LPVOID* ppObject);
    STDMETHOD(GetFXStatus)(DWORD dwEffectsCount, LPDWORD pdwFXStatus);

protected:
    AgentStateStruct(DirectSoundCaptureBuffer8);
};
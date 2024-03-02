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

#include "DirectSound.hxx"
#include "DirectSoundBuffer.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundLogger.hxx>

#define DirectSoundLogMethod(L, M) AgentLogMethod(L, DirectSound, M)
#define DirectSoundLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSound, M, C, PARAMS)

#define DirectSoundLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSound, AddRef, R)
#define DirectSoundLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSound, Release, R)

#define DirectSoundLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSound, M, R)
#define DirectSoundLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSound, M, R, C, PARAMS)

DirectSound::DirectSound(AgentConstructorParameters(DirectSound))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectSound);
}

DirectSound::~DirectSound()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectSound);
}

HRESULT DirectSound::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSound, riid)) { *ppvObj = ActivateAgent(DirectSound, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSound::AddRef()
{
    DirectSoundLogMethod(DEBUG, AddRef);
    DirectSoundLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSound::Release()
{
    DirectSoundLogMethod(DEBUG, Release);
    DirectSoundLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Creates a DirectSoundBuffer object to hold a sequence of audio samples.
HRESULT DirectSound::CreateSoundBuffer(LPCDSBUFFERDESC pcDSBufferDesc, LPDIRECTSOUNDBUFFER* ppDSBuffer, LPUNKNOWN pUnkOuter)
{
    DirectSoundLogMethodValue(DEBUG, CreateSoundBuffer, 3, (pcDSBufferDesc, ppDSBuffer, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateSoundBuffer(pcDSBufferDesc, ppDSBuffer, pUnkOuter);

    if (SUCCEEDED(result)) { *ppDSBuffer = ActivateAgentDelegate(DirectSoundBuffer, *ppDSBuffer); }

    DirectSoundLogMethodResultValue(DEBUGINFO, CreateSoundBuffer, result, 3, (pcDSBufferDesc, ppDSBuffer, pUnkOuter));
}

// Retrieves the capabilities of the hardware device that is represented by the DirectSound object.
HRESULT DirectSound::GetCaps(LPDSCAPS pDSCaps)
{
    DirectSoundLogMethodValue(DEBUG, GetCaps, 1, (pDSCaps));

    CONST HRESULT result = this->State.Self->GetCaps(pDSCaps);

    DirectSoundLogMethodResultValue(DEBUGINFO, GetCaps, result, 1, (pDSCaps));
}

// Creates a new DirectSoundBuffer object that uses the same buffer memory as the original object.
HRESULT DirectSound::DuplicateSoundBuffer(LPDIRECTSOUNDBUFFER pDSBufferOriginal, LPDIRECTSOUNDBUFFER* ppDSBufferDuplicate)
{
    DirectSoundLogMethodValue(DEBUG, DuplicateSoundBuffer, 2, (pDSBufferOriginal, ppDSBufferDuplicate));

    AttemptAccessAgentValue(DirectSoundBuffer, pDSBufferOriginal);

    CONST HRESULT result = this->State.Self->DuplicateSoundBuffer(pDSBufferOriginal, ppDSBufferDuplicate);

    if (SUCCEEDED(result)) { *ppDSBufferDuplicate = ActivateAgentDelegate(DirectSoundBuffer, *ppDSBufferDuplicate); }

    DirectSoundLogMethodResultValue(DEBUGINFO, DuplicateSoundBuffer, result, 2, (ActivateAgent(DirectSoundBuffer, pDSBufferOriginal), ppDSBufferDuplicate));
}

// Sets the cooperative level of the application for this sound device.
HRESULT DirectSound::SetCooperativeLevel(HWND hwnd, DWORD dwLevel)
{
    DirectSoundLogMethodValue(DEBUG, SetCooperativeLevel, 2, (hwnd, dwLevel));

    CONST HRESULT result = this->State.Self->SetCooperativeLevel(hwnd, dwLevel);

    DirectSoundLogMethodResultValue(DEBUGINFO, SetCooperativeLevel, result, 2, (hwnd, dwLevel));
}

// Moves the unused portions of on-board sound memory, if any, to a contiguous block so that the largest portion of free memory will be available.
HRESULT DirectSound::Compact()
{
    DirectSoundLogMethod(DEBUG, Compact);

    CONST HRESULT result = this->State.Self->Compact();

    DirectSoundLogMethodResult(DEBUGINFO, Compact, result);
}

// Retrieves the speaker configuration.
HRESULT DirectSound::GetSpeakerConfig(LPDWORD pdwSpeakerConfig)
{
    DirectSoundLogMethodValue(DEBUG, GetSpeakerConfig, 1, (pdwSpeakerConfig));

    CONST HRESULT result = this->State.Self->GetSpeakerConfig(pdwSpeakerConfig);

    DirectSoundLogMethodResultValue(DEBUGINFO, GetSpeakerConfig, result, 1, (pdwSpeakerConfig));
}

// Specifies the speaker configuration of the DirectSound object.
HRESULT DirectSound::SetSpeakerConfig(DWORD dwSpeakerConfig)
{
    DirectSoundLogMethodValue(DEBUG, SetSpeakerConfig, 1, (dwSpeakerConfig));

    CONST HRESULT result = this->State.Self->SetSpeakerConfig(dwSpeakerConfig);

    DirectSoundLogMethodResultValue(DEBUGINFO, SetSpeakerConfig, result, 1, (dwSpeakerConfig));
}

// Initializes the DirectSound object that was created by using the CoCreateInstance function.
HRESULT DirectSound::Initialize(LPCGUID pcGuidDevice)
{
    DirectSoundLogMethodValue(DEBUG, Initialize, 1, (pcGuidDevice));

    CONST HRESULT result = this->State.Self->Initialize(pcGuidDevice);

    DirectSoundLogMethodResultValue(DEBUGINFO, Initialize, result, 1, (pcGuidDevice));
}
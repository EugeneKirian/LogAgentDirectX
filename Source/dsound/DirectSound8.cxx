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
#include "DirectSound8.hxx"
#include "DirectSoundBuffer.hxx"
#include "DirectSoundBuffer8.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSound8Logger.hxx>

#define DirectSound8LogMethod(L, M) AgentLogMethod(L, DirectSound8, M)
#define DirectSound8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSound8, M, C, PARAMS)

#define DirectSound8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSound8, AddRef, R)
#define DirectSound8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSound8, Release, R)

#define DirectSound8LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSound8, M, R)
#define DirectSound8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSound8, M, R, C, PARAMS)

DirectSound8::DirectSound8(AgentConstructorParameters(DirectSound8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSound8);
}

DirectSound8::~DirectSound8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSound8);
}

HRESULT DirectSound8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSound8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSound, riid) || IsEqualIID(IID_IDirectSound8, riid)) { *ppvObj = ActivateAgent(DirectSound8, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSound8::AddRef()
{
    DirectSound8LogMethod(DEBUG, AddRef);
    DirectSound8LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSound8::Release()
{
    DirectSound8LogMethod(DEBUG, Release);
    DirectSound8LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Creates a DirectSoundBuffer object to hold a sequence of audio samples.
HRESULT DirectSound8::CreateSoundBuffer(LPCDSBUFFERDESC pcDSBufferDesc, LPDIRECTSOUNDBUFFER* ppDSBuffer, LPUNKNOWN pUnkOuter)
{
    DirectSound8LogMethodValue(TRACE, CreateSoundBuffer, 3, (pcDSBufferDesc, ppDSBuffer, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateSoundBuffer(pcDSBufferDesc, ppDSBuffer, pUnkOuter);

    if (SUCCEEDED(result)) { *ppDSBuffer = ActivateAgentDelegate(DirectSoundBuffer8, *ppDSBuffer); }

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, CreateSoundBuffer, result, 3, (pcDSBufferDesc, ppDSBuffer, pUnkOuter));
}

// Retrieves the capabilities of the hardware device that is represented by the DirectSound object.
HRESULT DirectSound8::GetCaps(LPDSCAPS pDSCaps)
{
    DirectSound8LogMethodValue(TRACE, GetCaps, 1, (pDSCaps));

    CONST HRESULT result = this->State.Self->GetCaps(pDSCaps);

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 1, (pDSCaps));
}

// Creates a new DirectSoundBuffer object that uses the same buffer memory as the original object.
HRESULT DirectSound8::DuplicateSoundBuffer(LPDIRECTSOUNDBUFFER pDSBufferOriginal, LPDIRECTSOUNDBUFFER* ppDSBufferDuplicate)
{
    DirectSound8LogMethodValue(TRACE, DuplicateSoundBuffer, 2, (pDSBufferOriginal, ppDSBufferDuplicate));

    AttemptAccessAgentValue(DirectSoundBuffer, pDSBufferOriginal);

    CONST HRESULT result = this->State.Self->DuplicateSoundBuffer(pDSBufferOriginal, ppDSBufferDuplicate);

    if (SUCCEEDED(result)) { *ppDSBufferDuplicate = ActivateAgentDelegate(DirectSoundBuffer8, *ppDSBufferDuplicate); }

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, DuplicateSoundBuffer, result, 2, (ActivateAgent(DirectSoundBuffer, pDSBufferOriginal), ppDSBufferDuplicate));
}

// Sets the cooperative level of the application for this sound device.
HRESULT DirectSound8::SetCooperativeLevel(HWND hwnd, DWORD dwLevel)
{
    DirectSound8LogMethodValue(TRACE, SetCooperativeLevel, 2, (hwnd, dwLevel));

    CONST HRESULT result = this->State.Self->SetCooperativeLevel(hwnd, dwLevel);

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, SetCooperativeLevel, result, 2, (hwnd, dwLevel));
}

// Moves the unused portions of on-board sound memory, if any, to a contiguous block so that the largest portion of free memory will be available.
HRESULT DirectSound8::Compact()
{
    DirectSound8LogMethod(DEBUG, Compact);

    CONST HRESULT result = this->State.Self->Compact();

    DirectSound8LogMethodResult(DEBUGINFO, Compact, result);
}

// Retrieves the speaker configuration.
HRESULT DirectSound8::GetSpeakerConfig(LPDWORD pdwSpeakerConfig)
{
    DirectSound8LogMethodValue(TRACE, GetSpeakerConfig, 1, (pdwSpeakerConfig));

    CONST HRESULT result = this->State.Self->GetSpeakerConfig(pdwSpeakerConfig);

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, GetSpeakerConfig, result, 1, (pdwSpeakerConfig));
}

// Specifies the speaker configuration of the DirectSound object.
HRESULT DirectSound8::SetSpeakerConfig(DWORD dwSpeakerConfig)
{
    DirectSound8LogMethodValue(TRACE, SetSpeakerConfig, 1, (dwSpeakerConfig));

    CONST HRESULT result = this->State.Self->SetSpeakerConfig(dwSpeakerConfig);

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, SetSpeakerConfig, result, 1, (dwSpeakerConfig));
}

// Initializes the DirectSound object that was created by using the CoCreateInstance function.
HRESULT DirectSound8::Initialize(LPCGUID pcGuidDevice)
{
    DirectSound8LogMethodValue(TRACE, Initialize, 1, (pcGuidDevice));

    CONST HRESULT result = this->State.Self->Initialize(pcGuidDevice);

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (pcGuidDevice));
}

// Ascertains whether the DirectSound device is certified for DirectX.
HRESULT DirectSound8::VerifyCertification(LPDWORD pdwCertified)
{
    DirectSound8LogMethodValue(TRACE, VerifyCertification, 1, (pdwCertified));

    CONST HRESULT result = this->State.Self->VerifyCertification(pdwCertified);

    DirectSound8LogMethodResultValue(TRACEDEBUGINFO, VerifyCertification, result, 1, (pdwCertified));
}
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
#include "DirectSound3DBuffer.hxx"
#include "DirectSound3DListener.hxx"
#include "DirectSoundBuffer.hxx"
#include "DirectSoundBuffer8.hxx"
#include "DirectSoundNotify.hxx"
#include "KsPropertySet.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundBufferLogger.hxx>

#define DirectSoundBufferLogMethod(L, M) AgentLogMethod(L, DirectSoundBuffer, M)
#define DirectSoundBufferLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundBuffer, M, C, PARAMS)

#define DirectSoundBufferLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundBuffer, AddRef, R)
#define DirectSoundBufferLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundBuffer, Release, R)

#define DirectSoundBufferLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundBuffer, M, R)
#define DirectSoundBufferLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundBuffer, M, R, C, PARAMS)

DirectSoundBuffer::DirectSoundBuffer(AgentConstructorParameters(DirectSoundBuffer))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectSoundBuffer);
}

DirectSoundBuffer::~DirectSoundBuffer()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectSoundBuffer);
}

HRESULT DirectSoundBuffer::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundBufferLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSound3DBuffer, riid)) { *ppvObj = ActivateAgent(DirectSound3DBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSound3DListener, riid)) { *ppvObj = ActivateAgent(DirectSound3DListener, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundBuffer, riid)) { *ppvObj = ActivateAgent(DirectSoundBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundBuffer8, riid)) { *ppvObj = ActivateAgent(DirectSoundBuffer8, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundNotify, riid)) { *ppvObj = ActivateAgent(DirectSoundNotify, *ppvObj); }
            else if (IsEqualIID(IID_IKsPropertySet, riid)) { *ppvObj = ActivateAgent(KsPropertySet, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundBuffer::AddRef()
{
    DirectSoundBufferLogMethod(DEBUG, AddRef);
    DirectSoundBufferLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundBuffer::Release()
{
    DirectSoundBufferLogMethod(DEBUG, Release);
    DirectSoundBufferLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves the capabilities of the DirectSoundBuffer object.
HRESULT DirectSoundBuffer::GetCaps(LPDSBCAPS pDSBufferCaps)
{
    DirectSoundBufferLogMethodValue(DEBUG, GetCaps, 1, (pDSBufferCaps));

    CONST HRESULT result = this->State.Self->GetCaps(pDSBufferCaps);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, GetCaps, result, 1, (pDSBufferCaps));
}

// Retrieves the current position of the play and write cursors in the sound buffer.
HRESULT DirectSoundBuffer::GetCurrentPosition(LPDWORD pdwCurrentPlayCursor, LPDWORD pdwCurrentWriteCursor)
{
    DirectSoundBufferLogMethodValue(DEBUG, GetCurrentPosition, 2, (pdwCurrentPlayCursor, pdwCurrentWriteCursor));

    CONST HRESULT result = this->State.Self->GetCurrentPosition(pdwCurrentPlayCursor, pdwCurrentWriteCursor);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, GetCurrentPosition, result, 2, (pdwCurrentPlayCursor, pdwCurrentWriteCursor));
}

// Retrieves a description of the format of the sound data in the buffer, or the buffer size needed to retrieve the format description.
HRESULT DirectSoundBuffer::GetFormat(LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, LPDWORD pdwSizeWritten)
{
    DirectSoundBufferLogMethodValue(DEBUG, GetFormat, 3, (pwfxFormat, dwSizeAllocated, pdwSizeWritten));

    CONST HRESULT result = this->State.Self->GetFormat(pwfxFormat, dwSizeAllocated, pdwSizeWritten);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, GetFormat, result, 3, (pwfxFormat, dwSizeAllocated, pdwSizeWritten));
}

// Retrieves the current volume for this sound buffer.
HRESULT DirectSoundBuffer::GetVolume(LPLONG plVolume)
{
    DirectSoundBufferLogMethodValue(DEBUG, GetVolume, 1, (plVolume));

    CONST HRESULT result = this->State.Self->GetVolume(plVolume);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, GetVolume, result, 1, (plVolume));
}

// Retrieves a variable that represents the relative volume between the left and right audio channels.
HRESULT DirectSoundBuffer::GetPan(LPLONG plPan)
{
    DirectSoundBufferLogMethodValue(DEBUG, GetPan, 1, (plPan));

    CONST HRESULT result = this->State.Self->GetPan(plPan);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, GetPan, result, 1, (plPan));
}

// Retrieves the frequency, in samples per second, at which the buffer is playing.
HRESULT DirectSoundBuffer::GetFrequency(LPDWORD pdwFrequency)
{
    DirectSoundBufferLogMethodValue(DEBUG, GetFrequency, 1, (pdwFrequency));

    CONST HRESULT result = this->State.Self->GetFrequency(pdwFrequency);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, GetFrequency, result, 1, (pdwFrequency));
}

// Retrieves the current status of the sound buffer.
HRESULT DirectSoundBuffer::GetStatus(LPDWORD pdwStatus)
{
    DirectSoundBufferLogMethodValue(DEBUG, GetStatus, 1, (pdwStatus));

    CONST HRESULT result = this->State.Self->GetStatus(pdwStatus);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, GetStatus, result, 1, (pdwStatus));
}

// Initializes a DirectSoundBuffer object if it has not yet been initialized.
HRESULT DirectSoundBuffer::Initialize(LPDIRECTSOUND pDirectSound, LPCDSBUFFERDESC pcDSBufferDesc)
{
    DirectSoundBufferLogMethodValue(DEBUG, Initialize, 2, (pDirectSound, pcDSBufferDesc));

    AttemptAccessAgentValue(DirectSound, pDirectSound);

    CONST HRESULT result = this->State.Self->Initialize(pDirectSound, pcDSBufferDesc);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectSound, pDirectSound), pcDSBufferDesc));
}

// Obtains a valid write pointer to the sound buffer's audio data.
HRESULT DirectSoundBuffer::Lock(DWORD dwOffset, DWORD dwBytes, LPVOID* ppvAudioPtr1, LPDWORD pdwAudioBytes1, LPVOID* ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags)
{
    DirectSoundBufferLogMethodValue(DEBUG, Lock, 7, (dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags));

    CONST HRESULT result = this->State.Self->Lock(dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, Lock, result, 7, (dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags));
}

// Causes the sound buffer to play from the current position.
HRESULT DirectSoundBuffer::Play(DWORD dwReserved1, DWORD dwPriority, DWORD dwFlags)
{
    DirectSoundBufferLogMethodValue(DEBUG, Play, 3, (dwReserved1, dwPriority, dwFlags));

    CONST HRESULT result = this->State.Self->Play(dwReserved1, dwPriority, dwFlags);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, Play, result, 3, (dwReserved1, dwPriority, dwFlags));
}

// Moves the current play position for secondary sound buffers.
HRESULT DirectSoundBuffer::SetCurrentPosition(DWORD dwNewPosition)
{
    DirectSoundBufferLogMethodValue(DEBUG, SetCurrentPosition, 1, (dwNewPosition));

    CONST HRESULT result = this->State.Self->SetCurrentPosition(dwNewPosition);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, SetCurrentPosition, result, 1, (dwNewPosition));
}

// Sets the format of the primary sound buffer for the application.
// Whenever this application has the input focus, DirectSound will set the primary buffer to the specified format.
HRESULT DirectSoundBuffer::SetFormat(LPCWAVEFORMATEX pcfxFormat)
{
    DirectSoundBufferLogMethodValue(DEBUG, SetFormat, 1, (pcfxFormat));

    CONST HRESULT result = this->State.Self->SetFormat(pcfxFormat);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, SetFormat, result, 1, (pcfxFormat));
}

// Changes the volume of a sound buffer.
HRESULT DirectSoundBuffer::SetVolume(LONG lVolume)
{
    DirectSoundBufferLogMethodValue(DEBUG, SetVolume, 1, (lVolume));

    CONST HRESULT result = this->State.Self->SetVolume(lVolume);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, SetVolume, result, 1, (lVolume));
}

// Specifies the relative volume between the left and right channels.
HRESULT DirectSoundBuffer::SetPan(LONG lPan)
{
    DirectSoundBufferLogMethodValue(DEBUG, SetPan, 1, (lPan));

    CONST HRESULT result = this->State.Self->SetPan(lPan);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, SetPan, result, 1, (lPan));
}

// Sets the frequency at which the audio samples are played.
HRESULT DirectSoundBuffer::SetFrequency(DWORD dwFrequency)
{
    DirectSoundBufferLogMethodValue(DEBUG, SetFrequency, 1, (dwFrequency));

    CONST HRESULT result = this->State.Self->SetFrequency(dwFrequency);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, SetFrequency, result, 1, (dwFrequency));
}

// Causes the sound buffer to stop playing.
HRESULT DirectSoundBuffer::Stop()
{
    DirectSoundBufferLogMethod(DEBUG, Stop);

    CONST HRESULT result = this->State.Self->Stop();

    DirectSoundBufferLogMethodResult(DEBUGINFO, Stop, result);
}

// Releases a locked sound buffer.
HRESULT DirectSoundBuffer::Unlock(LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2)
{
    DirectSoundBufferLogMethodValue(DEBUG, Unlock, 4, (pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2));

    CONST HRESULT result = this->State.Self->Unlock(pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2);

    DirectSoundBufferLogMethodResultValue(DEBUGINFO, Unlock, result, 4, (pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2));
}

// Restores the memory allocation for a lost sound buffer for the specified DirectSoundBuffer object.
HRESULT DirectSoundBuffer::Restore()
{
    DirectSoundBufferLogMethod(DEBUG, Restore);

    CONST HRESULT result = this->State.Self->Restore();

    DirectSoundBufferLogMethodResult(DEBUGINFO, Restore, result);
}
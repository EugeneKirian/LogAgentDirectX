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
#include "DirectSoundFXChorus.hxx"
#include "DirectSoundFXCompressor.hxx"
#include "DirectSoundFXDistortion.hxx"
#include "DirectSoundFXEcho.hxx"
#include "DirectSoundFXFlanger.hxx"
#include "DirectSoundFXGargle.hxx"
#include "DirectSoundFXI3DL2Reverb.hxx"
#include "DirectSoundFXParamEq.hxx"
#include "DirectSoundFXWavesReverb.hxx"
#include "DirectSoundNotify.hxx"
#include "KsPropertySet.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundBuffer8Logger.hxx>

#define DirectSoundBuffer8LogMethod(L, M) AgentLogMethod(L, DirectSoundBuffer8, M)
#define DirectSoundBuffer8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundBuffer8, M, C, PARAMS)

#define DirectSoundBuffer8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundBuffer8, AddRef, R)
#define DirectSoundBuffer8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundBuffer8, Release, R)

#define DirectSoundBuffer8LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundBuffer8, M, R)
#define DirectSoundBuffer8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundBuffer8, M, R, C, PARAMS)


DirectSoundBuffer8::DirectSoundBuffer8(AgentConstructorParameters(DirectSoundBuffer8))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectSoundBuffer8);
}

DirectSoundBuffer8::~DirectSoundBuffer8()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectSoundBuffer8);
}

HRESULT DirectSoundBuffer8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

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

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundBuffer8::AddRef()
{
    DirectSoundBuffer8LogMethod(DEBUG, AddRef);
    DirectSoundBuffer8LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundBuffer8::Release()
{
    DirectSoundBuffer8LogMethod(DEBUG, Release);
    DirectSoundBuffer8LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves the capabilities of the DirectSoundBuffer8 object.
HRESULT DirectSoundBuffer8::GetCaps(LPDSBCAPS pDSBufferCaps)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, GetCaps, 1, (pDSBufferCaps));

    CONST HRESULT result = this->State.Self->GetCaps(pDSBufferCaps);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, GetCaps, result, 1, (pDSBufferCaps));
}

// Retrieves the current position of the play and write cursors in the sound buffer.
HRESULT DirectSoundBuffer8::GetCurrentPosition(LPDWORD pdwCurrentPlayCursor, LPDWORD pdwCurrentWriteCursor)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, GetCurrentPosition, 2, (pdwCurrentPlayCursor, pdwCurrentWriteCursor));

    CONST HRESULT result = this->State.Self->GetCurrentPosition(pdwCurrentPlayCursor, pdwCurrentWriteCursor);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, GetCurrentPosition, result, 2, (pdwCurrentPlayCursor, pdwCurrentWriteCursor));
}

// Retrieves a description of the format of the sound data in the buffer, or the buffer size needed to retrieve the format description.
HRESULT DirectSoundBuffer8::GetFormat(LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, LPDWORD pdwSizeWritten)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, GetFormat, 3, (pwfxFormat, dwSizeAllocated, pdwSizeWritten));

    CONST HRESULT result = this->State.Self->GetFormat(pwfxFormat, dwSizeAllocated, pdwSizeWritten);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, GetFormat, result, 3, (pwfxFormat, dwSizeAllocated, pdwSizeWritten));
}

// Retrieves the current volume for this sound buffer.
HRESULT DirectSoundBuffer8::GetVolume(LPLONG plVolume)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, GetVolume, 1, (plVolume));

    CONST HRESULT result = this->State.Self->GetVolume(plVolume);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, GetVolume, result, 1, (plVolume));
}

// Retrieves a variable that represents the relative volume between the left and right audio channels.
HRESULT DirectSoundBuffer8::GetPan(LPLONG plPan)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, GetPan, 1, (plPan));

    CONST HRESULT result = this->State.Self->GetPan(plPan);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, GetPan, result, 1, (plPan));
}

// Retrieves the frequency, in samples per second, at which the buffer is playing.
HRESULT DirectSoundBuffer8::GetFrequency(LPDWORD pdwFrequency)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, GetFrequency, 1, (pdwFrequency));

    CONST HRESULT result = this->State.Self->GetFrequency(pdwFrequency);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, GetFrequency, result, 1, (pdwFrequency));
}

// Retrieves the current status of the sound buffer.
HRESULT DirectSoundBuffer8::GetStatus(LPDWORD pdwStatus)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, GetStatus, 1, (pdwStatus));

    CONST HRESULT result = this->State.Self->GetStatus(pdwStatus);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, GetStatus, result, 1, (pdwStatus));
}

// Initializes a DirectSoundBuffer8 object if it has not yet been initialized.
HRESULT DirectSoundBuffer8::Initialize(LPDIRECTSOUND pDirectSound, LPCDSBUFFERDESC pcDSBufferDesc)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, Initialize, 2, (pDirectSound, pcDSBufferDesc));

    AttemptAccessAgentValue(DirectSound, pDirectSound);

    CONST HRESULT result = this->State.Self->Initialize(pDirectSound, pcDSBufferDesc);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectSound, pDirectSound), pcDSBufferDesc));
}

// Obtains a valid write pointer to the sound buffer's audio data.
HRESULT DirectSoundBuffer8::Lock(DWORD dwOffset, DWORD dwBytes, LPVOID* ppvAudioPtr1, LPDWORD pdwAudioBytes1, LPVOID* ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, Lock, 7, (dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags));

    CONST HRESULT result = this->State.Self->Lock(dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, Lock, result, 7, (dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags));
}

// Causes the sound buffer to play from the current position.
HRESULT DirectSoundBuffer8::Play(DWORD dwReserved1, DWORD dwPriority, DWORD dwFlags)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, Play, 3, (dwReserved1, dwPriority, dwFlags));

    CONST HRESULT result = this->State.Self->Play(dwReserved1, dwPriority, dwFlags);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, Play, result, 3, (dwReserved1, dwPriority, dwFlags));
}

// Moves the current play position for secondary sound buffers.
HRESULT DirectSoundBuffer8::SetCurrentPosition(DWORD dwNewPosition)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, SetCurrentPosition, 1, (dwNewPosition));

    CONST HRESULT result = this->State.Self->SetCurrentPosition(dwNewPosition);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, SetCurrentPosition, result, 1, (dwNewPosition));
}

// Sets the format of the primary sound buffer for the application.
// Whenever this application has the input focus, DirectSound will set the primary buffer to the specified format.
HRESULT DirectSoundBuffer8::SetFormat(LPCWAVEFORMATEX pcfxFormat)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, SetFormat, 1, (pcfxFormat));

    CONST HRESULT result = this->State.Self->SetFormat(pcfxFormat);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, SetFormat, result, 1, (pcfxFormat));
}

// Changes the volume of a sound buffer.
HRESULT DirectSoundBuffer8::SetVolume(LONG lVolume)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, SetVolume, 1, (lVolume));

    CONST HRESULT result = this->State.Self->SetVolume(lVolume);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, SetVolume, result, 1, (lVolume));
}

// Specifies the relative volume between the left and right channels.
HRESULT DirectSoundBuffer8::SetPan(LONG lPan)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, SetPan, 1, (lPan));

    CONST HRESULT result = this->State.Self->SetPan(lPan);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, SetPan, result, 1, (lPan));
}

// Sets the frequency at which the audio samples are played.
HRESULT DirectSoundBuffer8::SetFrequency(DWORD dwFrequency)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, SetFrequency, 1, (dwFrequency));

    CONST HRESULT result = this->State.Self->SetFrequency(dwFrequency);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, SetFrequency, result, 1, (dwFrequency));
}

// Causes the sound buffer to stop playing.
HRESULT DirectSoundBuffer8::Stop()
{
    DirectSoundBuffer8LogMethod(DEBUG, Stop);

    CONST HRESULT result = this->State.Self->Stop();

    DirectSoundBuffer8LogMethodResult(DEBUGINFO, Stop, result);
}

// Releases a locked sound buffer.
HRESULT DirectSoundBuffer8::Unlock(LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, Unlock, 4, (pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2));

    CONST HRESULT result = this->State.Self->Unlock(pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, Unlock, result, 4, (pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2));
}

// Restores the memory allocation for a lost sound buffer for the specified DirectSoundBuffer8 object.
HRESULT DirectSoundBuffer8::Restore()
{
    DirectSoundBuffer8LogMethod(DEBUG, Restore);

    CONST HRESULT result = this->State.Self->Restore();

    DirectSoundBuffer8LogMethodResult(DEBUGINFO, Restore, result);
}

// Enables effects on a buffer. The buffer must not be playing or locked.
HRESULT DirectSoundBuffer8::SetFX(DWORD dwEffectsCount, LPDSEFFECTDESC pDSFXDesc, LPDWORD pdwResultCodes)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, SetFX, 3, (dwEffectsCount, pDSFXDesc, pdwResultCodes));

    CONST HRESULT result = this->State.Self->SetFX(dwEffectsCount, pDSFXDesc, pdwResultCodes);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, SetFX, result, 3, (dwEffectsCount, pDSFXDesc, pdwResultCodes));
}

// Allocates resources for a buffer that was created with the DSBCAPS_LOCDEFER flag in the DSBUFFERDESC structure. 
HRESULT DirectSoundBuffer8::AcquireResources(DWORD dwFlags, DWORD dwEffectsCount, LPDWORD pdwResultCodes)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, AcquireResources, 3, (dwFlags, dwEffectsCount, pdwResultCodes));

    CONST HRESULT result = this->State.Self->AcquireResources(dwFlags, dwEffectsCount, pdwResultCodes);

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, AcquireResources, result, 3, (dwFlags, dwEffectsCount, pdwResultCodes));
}

// Retrieves an interface for an effect object associated with the buffer.
HRESULT DirectSoundBuffer8::GetObjectInPath(REFGUID rguidObject, DWORD dwIndex, REFGUID rguidInterface, LPVOID* ppObject)
{
    DirectSoundBuffer8LogMethodValue(DEBUG, GetObjectInPath, 4, (rguidObject, dwIndex, rguidInterface, ppObject));

    CONST HRESULT result = this->State.Self->GetObjectInPath(rguidObject, dwIndex, rguidInterface, ppObject);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(rguidInterface, ppObject))
        {
            if (IsEqualIID(IID_IDirectSoundFXChorus, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXChorus, *ppObject); }
            else if (IsEqualIID(IID_IDirectSoundFXCompressor, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXCompressor, *ppObject); }
            else if (IsEqualIID(IID_IDirectSoundFXDistortion, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXDistortion, *ppObject); }
            else if (IsEqualIID(IID_IDirectSoundFXEcho, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXEcho, *ppObject); }
            else if (IsEqualIID(IID_IDirectSoundFXFlanger, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXFlanger, *ppObject); }
            else if (IsEqualIID(IID_IDirectSoundFXGargle, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXGargle, *ppObject); }
            else if (IsEqualIID(IID_IDirectSoundFXI3DL2Reverb, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXI3DL2Reverb, *ppObject); }
            else if (IsEqualIID(IID_IDirectSoundFXParamEq, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXParamEq, *ppObject); }
            else if (IsEqualIID(IID_IDirectSoundFXWavesReverb, rguidInterface)) { *ppObject = ActivateAgentDelegate(DirectSoundFXWavesReverb, *ppObject); }
            //else if (IsEqualIID(IID_IMediaObject, rguidInterface)) { *ppObject = ActivateAgentDelegate(MediaObject, *ppObject); } // NOT IMPLEMENTED
            //else if (IsEqualIID(IID_IMediaObjectInPlace, rguidInterface)) { *ppObject = ActivateAgentDelegate(MediaObjectInPlace, *ppObject); } // NOT IMPLEMENTED
            //else if (IsEqualIID(IID_IMediaParams, rguidInterface)) { *ppObject = ActivateAgentDelegate(MediaParams, *ppObject); } // NOT IMPLEMENTED
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundBuffer8LogMethodResultValue(DEBUGINFO, GetObjectInPath, result, 4, (rguidObject, dwIndex, rguidInterface, ppObject));
}
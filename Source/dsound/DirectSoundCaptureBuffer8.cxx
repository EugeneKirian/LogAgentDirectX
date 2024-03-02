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

#include "DirectSoundCapture.hxx"
#include "DirectSoundCaptureBuffer.hxx"
#include "DirectSoundCaptureBuffer8.hxx"
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
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundCaptureBuffer8Logger.hxx>

#define DirectSoundCaptureBuffer8LogMethod(L, M) AgentLogMethod(L, DirectSoundCaptureBuffer8, M)
#define DirectSoundCaptureBuffer8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundCaptureBuffer8, M, C, PARAMS)

#define DirectSoundCaptureBuffer8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundCaptureBuffer8, AddRef, R)
#define DirectSoundCaptureBuffer8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundCaptureBuffer8, Release, R)

#define DirectSoundCaptureBuffer8LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundCaptureBuffer8, M, R)
#define DirectSoundCaptureBuffer8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundCaptureBuffer8, M, R, C, PARAMS)


DirectSoundCaptureBuffer8::DirectSoundCaptureBuffer8(AgentConstructorParameters(DirectSoundCaptureBuffer8))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectSoundCaptureBuffer8);
}

DirectSoundCaptureBuffer8::~DirectSoundCaptureBuffer8()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectSoundCaptureBuffer8);
}

HRESULT DirectSoundCaptureBuffer8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundCaptureBuffer, riid)) { *ppvObj = ActivateAgent(DirectSoundCaptureBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundCaptureBuffer8, riid)) { *ppvObj = ActivateAgent(DirectSoundCaptureBuffer8, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundNotify, riid)) { *ppvObj = ActivateAgent(DirectSoundNotify, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundCaptureBuffer8::AddRef()
{
    DirectSoundCaptureBuffer8LogMethod(DEBUG, AddRef);
    DirectSoundCaptureBuffer8LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundCaptureBuffer8::Release()
{
    DirectSoundCaptureBuffer8LogMethod(DEBUG, Release);
    DirectSoundCaptureBuffer8LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves the capabilities of the buffer.
HRESULT DirectSoundCaptureBuffer8::GetCaps(LPDSCBCAPS pDSCBCaps)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, GetCaps, 1, (pDSCBCaps));

    CONST HRESULT result = this->State.Self->GetCaps(pDSCBCaps);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, GetCaps, result, 1, (pDSCBCaps));
}

// Retrieves the capture and read cursors in the buffer.
// The capture cursor is ahead of the read cursor.
// The data after the read position up to and including the capture position is not necessarily valid data.
HRESULT DirectSoundCaptureBuffer8::GetCurrentPosition(LPDWORD pdwCapturePosition, LPDWORD pdwReadPosition)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, GetCurrentPosition, 2, (pdwCapturePosition, pdwReadPosition));

    CONST HRESULT result = this->State.Self->GetCurrentPosition(pdwCapturePosition, pdwReadPosition);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, GetCurrentPosition, result, 2, (pdwCapturePosition, pdwReadPosition));
}

// Retrieves the format of the capture buffer.
HRESULT DirectSoundCaptureBuffer8::GetFormat(LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, LPDWORD pdwSizeWritten)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, GetFormat, 3, (pwfxFormat, dwSizeAllocated, pdwSizeWritten));

    CONST HRESULT result = this->State.Self->GetFormat(pwfxFormat, dwSizeAllocated, pdwSizeWritten);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, GetFormat, result, 3, (pwfxFormat, dwSizeAllocated, pdwSizeWritten));
}

// Retrieves the status of the capture buffer.
HRESULT DirectSoundCaptureBuffer8::GetStatus(LPDWORD pdwStatus)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, GetStatus, 1, (pdwStatus));

    CONST HRESULT result = this->State.Self->GetStatus(pdwStatus);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, GetStatus, result, 1, (pdwStatus));
}

// Initializes a capture buffer object.
// Because the IDirectSoundCapture::CreateCaptureBuffer method and the DirectSoundFullDuplexCreate function call
// the IDirectSoundCaptureBuffer8::Initialize method internally, this method is not used by applications.
// It is provided for future extensibility.
HRESULT DirectSoundCaptureBuffer8::Initialize(LPDIRECTSOUNDCAPTURE pDirectSoundCapture, LPCDSCBUFFERDESC pcDSCBufferDesc)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, Initialize, 2, (pDirectSoundCapture, pcDSCBufferDesc));

    AttemptAccessAgentValue(DirectSoundCapture, pDirectSoundCapture);

    CONST HRESULT result = this->State.Self->Initialize(pDirectSoundCapture, pcDSCBufferDesc);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectSoundCapture, pDirectSoundCapture), pcDSCBufferDesc));
}

// Locks a portion of the buffer.
// Locking the buffer returns pointers into the buffer, allowing the application to read or write audio data into memory.
HRESULT DirectSoundCaptureBuffer8::Lock(DWORD dwOffset, DWORD dwBytes, LPVOID* ppvAudioPtr1, LPDWORD pdwAudioBytes1, LPVOID* ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, Lock, 7, (dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags));

    CONST HRESULT result = this->State.Self->Lock(dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, Lock, result, 7, (dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags));
}

// Begins capturing data into the buffer.
// If the buffer is already capturing, the method has no effect.
HRESULT DirectSoundCaptureBuffer8::Start(DWORD dwFlags)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, Start, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->Start(dwFlags);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, Start, result, 1, (dwFlags));
}

// Stops the buffer so that it is no longer capturing data.
// If the buffer is not capturing, the method has no effect.
HRESULT DirectSoundCaptureBuffer8::Stop()
{
    DirectSoundCaptureBuffer8LogMethod(DEBUG, Stop);

    CONST HRESULT result = this->State.Self->Stop();

    DirectSoundCaptureBuffer8LogMethodResult(DEBUGINFO, Stop, result);
}

// Unlocks the buffer.
HRESULT DirectSoundCaptureBuffer8::Unlock(LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, Unlock, 4, (pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2));

    CONST HRESULT result = this->State.Self->Unlock(pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, Unlock, result, 4, (pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2));
}

// Retrieves an interface to an effect object associated with the buffer.
HRESULT DirectSoundCaptureBuffer8::GetObjectInPath(REFGUID rguidObject, DWORD dwIndex, REFGUID rguidInterface, LPVOID* ppObject)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, GetObjectInPath, 4, (rguidObject, dwIndex, rguidInterface, ppObject));

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

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, GetObjectInPath, result, 4, (rguidObject, dwIndex, rguidInterface, ppObject));
}

// Retrieves the status of capture effects.
HRESULT DirectSoundCaptureBuffer8::GetFXStatus(DWORD dwEffectsCount, LPDWORD pdwFXStatus)
{
    DirectSoundCaptureBuffer8LogMethodValue(DEBUG, GetFXStatus, 2, (dwEffectsCount, pdwFXStatus));

    CONST HRESULT result = this->State.Self->GetFXStatus(dwEffectsCount, pdwFXStatus);

    DirectSoundCaptureBuffer8LogMethodResultValue(DEBUGINFO, GetFXStatus, result, 2, (dwEffectsCount, pdwFXStatus));
}
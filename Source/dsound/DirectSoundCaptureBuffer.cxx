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
#include "DirectSoundNotify.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundCaptureBufferLogger.hxx>

#define DirectSoundCaptureBufferLogMethod(L, M) AgentLogMethod(L, DirectSoundCaptureBuffer, M)
#define DirectSoundCaptureBufferLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundCaptureBuffer, M, C, PARAMS)

#define DirectSoundCaptureBufferLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundCaptureBuffer, AddRef, R)
#define DirectSoundCaptureBufferLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundCaptureBuffer, Release, R)

#define DirectSoundCaptureBufferLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundCaptureBuffer, M, R)
#define DirectSoundCaptureBufferLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundCaptureBuffer, M, R, C, PARAMS)

DirectSoundCaptureBuffer::DirectSoundCaptureBuffer(AgentConstructorParameters(DirectSoundCaptureBuffer))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundCaptureBuffer);
}

DirectSoundCaptureBuffer::~DirectSoundCaptureBuffer()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundCaptureBuffer);
}

HRESULT DirectSoundCaptureBuffer::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

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

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundCaptureBuffer::AddRef()
{
    DirectSoundCaptureBufferLogMethod(DEBUG, AddRef);
    DirectSoundCaptureBufferLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundCaptureBuffer::Release()
{
    DirectSoundCaptureBufferLogMethod(DEBUG, Release);
    DirectSoundCaptureBufferLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves the capabilities of the buffer.
HRESULT DirectSoundCaptureBuffer::GetCaps(LPDSCBCAPS pDSCBCaps)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, GetCaps, 1, (pDSCBCaps));

    CONST HRESULT result = this->State.Self->GetCaps(pDSCBCaps);

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 1, (pDSCBCaps));
}

// Retrieves the capture and read cursors in the buffer.
// The capture cursor is ahead of the read cursor.
// The data after the read position up to and including the capture position is not necessarily valid data.
HRESULT DirectSoundCaptureBuffer::GetCurrentPosition(LPDWORD pdwCapturePosition, LPDWORD pdwReadPosition)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, GetCurrentPosition, 2, (pdwCapturePosition, pdwReadPosition));

    CONST HRESULT result = this->State.Self->GetCurrentPosition(pdwCapturePosition, pdwReadPosition);

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, GetCurrentPosition, result, 2, (pdwCapturePosition, pdwReadPosition));
}

// Retrieves the format of the capture buffer.
HRESULT DirectSoundCaptureBuffer::GetFormat(LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, LPDWORD pdwSizeWritten)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, GetFormat, 3, (pwfxFormat, dwSizeAllocated, pdwSizeWritten));

    CONST HRESULT result = this->State.Self->GetFormat(pwfxFormat, dwSizeAllocated, pdwSizeWritten);

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, GetFormat, result, 3, (pwfxFormat, dwSizeAllocated, pdwSizeWritten));
}

// Retrieves the status of the capture buffer.
HRESULT DirectSoundCaptureBuffer::GetStatus(LPDWORD pdwStatus)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, GetStatus, 1, (pdwStatus));

    CONST HRESULT result = this->State.Self->GetStatus(pdwStatus);

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, GetStatus, result, 1, (pdwStatus));
}

// Initializes a capture buffer object.
// Because the IDirectSoundCapture::CreateCaptureBuffer method and the DirectSoundFullDuplexCreate function call
// the IDirectSoundCaptureBuffer::Initialize method internally, this method is not used by applications.
// It is provided for future extensibility.
HRESULT DirectSoundCaptureBuffer::Initialize(LPDIRECTSOUNDCAPTURE pDirectSoundCapture, LPCDSCBUFFERDESC pcDSCBufferDesc)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, Initialize, 2, (pDirectSoundCapture, pcDSCBufferDesc));

    AttemptAccessAgentValue(DirectSoundCapture, pDirectSoundCapture);

    CONST HRESULT result = this->State.Self->Initialize(pDirectSoundCapture, pcDSCBufferDesc);

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectSoundCapture, pDirectSoundCapture), pcDSCBufferDesc));
}

// Locks a portion of the buffer.
// Locking the buffer returns pointers into the buffer, allowing the application to read or write audio data into memory.
HRESULT DirectSoundCaptureBuffer::Lock(DWORD dwOffset, DWORD dwBytes, LPVOID* ppvAudioPtr1, LPDWORD pdwAudioBytes1, LPVOID* ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, Lock, 7, (dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags));

    CONST HRESULT result = this->State.Self->Lock(dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags);

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, Lock, result, 7, (dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags));
}

// Begins capturing data into the buffer.
// If the buffer is already capturing, the method has no effect.
HRESULT DirectSoundCaptureBuffer::Start(DWORD dwFlags)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, Start, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->Start(dwFlags);

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, Start, result, 1, (dwFlags));
}

// Stops the buffer so that it is no longer capturing data.
// If the buffer is not capturing, the method has no effect.
HRESULT DirectSoundCaptureBuffer::Stop()
{
    DirectSoundCaptureBufferLogMethod(DEBUG, Stop);

    CONST HRESULT result = this->State.Self->Stop();

    DirectSoundCaptureBufferLogMethodResult(DEBUGINFO, Stop, result);
}

// Unlocks the buffer.
HRESULT DirectSoundCaptureBuffer::Unlock(LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2)
{
    DirectSoundCaptureBufferLogMethodValue(TRACE, Unlock, 4, (pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2));

    CONST HRESULT result = this->State.Self->Unlock(pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2);

    DirectSoundCaptureBufferLogMethodResultValue(TRACEDEBUGINFO, Unlock, result, 4, (pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2));
}
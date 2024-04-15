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
#include "DirectSound8.hxx"
#include "DirectSoundBuffer.hxx"
#include "DirectSoundBuffer8.hxx"
#include "DirectSoundCapture.hxx"
#include "DirectSoundCaptureBuffer.hxx"
#include "DirectSoundCaptureBuffer8.hxx"
#include "DirectSoundCaptureFXAec.hxx"
#include "DirectSoundCaptureFXNoiseSuppress.hxx"
#include "DirectSoundFullDuplex.hxx"
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
#include <UnknownLogger.hxx>

#define UnknownLogMethod(L, M) AgentLogMethod(L, Unknown, M)
#define UnknownLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Unknown, M, C, PARAMS)

#define UnknownLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Unknown, AddRef, R)
#define UnknownLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Unknown, Release, R)

#define UnknownLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Unknown, M, R, C, PARAMS)

Unknown::Unknown(AgentConstructorParameters(Unknown))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Unknown);
}

Unknown::~Unknown()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Unknown);
}

HRESULT Unknown::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    UnknownLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSound, riid)) { *ppvObj = ActivateAgent(DirectSound, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSound3DBuffer, riid)) { *ppvObj = ActivateAgent(DirectSound3DBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSound3DListener, riid)) { *ppvObj = ActivateAgent(DirectSound3DListener, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSound8, riid)) { *ppvObj = ActivateAgent(DirectSound8, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundBuffer, riid)) { *ppvObj = ActivateAgent(DirectSoundBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundBuffer8, riid)) { *ppvObj = ActivateAgent(DirectSoundBuffer8, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundCapture, riid)) { *ppvObj = ActivateAgent(DirectSoundCapture, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundCaptureBuffer, riid)) { *ppvObj = ActivateAgent(DirectSoundCaptureBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundCaptureBuffer8, riid)) { *ppvObj = ActivateAgent(DirectSoundCaptureBuffer8, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundCaptureFXAec, riid)) { *ppvObj = ActivateAgent(DirectSoundCaptureFXAec, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundCaptureFXNoiseSuppress, riid)) { *ppvObj = ActivateAgent(DirectSoundCaptureFXNoiseSuppress, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXChorus, riid)) { *ppvObj = ActivateAgent(DirectSoundFXChorus, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXCompressor, riid)) { *ppvObj = ActivateAgent(DirectSoundFXCompressor, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXDistortion, riid)) { *ppvObj = ActivateAgent(DirectSoundFXDistortion, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXEcho, riid)) { *ppvObj = ActivateAgent(DirectSoundFXEcho, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXFlanger, riid)) { *ppvObj = ActivateAgent(DirectSoundFXFlanger, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXGargle, riid)) { *ppvObj = ActivateAgent(DirectSoundFXGargle, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXI3DL2Reverb, riid)) { *ppvObj = ActivateAgent(DirectSoundFXI3DL2Reverb, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXParamEq, riid)) { *ppvObj = ActivateAgent(DirectSoundFXParamEq, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFXWavesReverb, riid)) { *ppvObj = ActivateAgent(DirectSoundFXWavesReverb, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFullDuplex, riid)) { *ppvObj = ActivateAgent(DirectSoundFullDuplex, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundNotify, riid)) { *ppvObj = ActivateAgent(DirectSoundNotify, *ppvObj); }
            else if (IsEqualIID(IID_IKsPropertySet, riid)) { *ppvObj = ActivateAgent(KsPropertySet, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    UnknownLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Unknown::AddRef()
{
    UnknownLogMethod(TRACE, AddRef);
    UnknownLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Unknown::Release()
{
    UnknownLogMethod(TRACE, Release);
    UnknownLogReleaseMethodResult(TRACE, this->State.Self->Release());
}
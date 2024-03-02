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

#include "DirectSound3DListener.hxx"
#include "DirectSoundBuffer.hxx"
#include "KsPropertySet.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSound3DListenerLogger.hxx>

#define DirectSound3DListenerLogMethod(L, M) AgentLogMethod(L, DirectSound3DListener, M)
#define DirectSound3DListenerLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSound3DListener, M, C, PARAMS)

#define DirectSound3DListenerLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSound3DListener, AddRef, R)
#define DirectSound3DListenerLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSound3DListener, Release, R)

#define DirectSound3DListenerLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSound3DListener, M, R)
#define DirectSound3DListenerLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSound3DListener, M, R, C, PARAMS)

DirectSound3DListener::DirectSound3DListener(AgentConstructorParameters(DirectSound3DListener))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectSound3DListener);
}

DirectSound3DListener::~DirectSound3DListener()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectSound3DListener);
}

HRESULT DirectSound3DListener::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSound3DListenerLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSound3DListener, riid)) { *ppvObj = ActivateAgent(DirectSound3DListener, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundBuffer, riid)) { *ppvObj = ActivateAgent(DirectSoundBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IKsPropertySet, riid)) { *ppvObj = ActivateAgent(KsPropertySet, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSound3DListener::AddRef()
{
    DirectSound3DListenerLogMethod(DEBUG, AddRef);
    DirectSound3DListenerLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSound3DListener::Release()
{
    DirectSound3DListenerLogMethod(DEBUG, Release);
    DirectSound3DListenerLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves information that describes the current state of the 3-D world and listener.
HRESULT DirectSound3DListener::GetAllParameters(LPDS3DLISTENER pListener)
{
    DirectSound3DListenerLogMethodValue(DEBUG, GetAllParameters, 1, (pListener));

    CONST HRESULT result = this->State.Self->GetAllParameters(pListener);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, GetAllParameters, result, 1, (pListener));
}

// Retrieves the current distance factor.
HRESULT DirectSound3DListener::GetDistanceFactor(LPD3DVALUE pflDistanceFactor)
{
    DirectSound3DListenerLogMethodValue(DEBUG, GetDistanceFactor, 1, (pflDistanceFactor));

    CONST HRESULT result = this->State.Self->GetDistanceFactor(pflDistanceFactor);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, GetDistanceFactor, result, 1, (pflDistanceFactor));
}

// Retrieves the current Doppler effect factor.
HRESULT DirectSound3DListener::GetDopplerFactor(LPD3DVALUE pflDopplerFactor)
{
    DirectSound3DListenerLogMethodValue(DEBUG, GetDopplerFactor, 1, (pflDopplerFactor));

    CONST HRESULT result = this->State.Self->GetDopplerFactor(pflDopplerFactor);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, GetDopplerFactor, result, 1, (pflDopplerFactor));
}

// Retrieves the listener's current orientation in vectors: a front vector and a top vector.
HRESULT DirectSound3DListener::GetOrientation(LPD3DVECTOR pvOrientFront, LPD3DVECTOR pvOrientTop)
{
    DirectSound3DListenerLogMethodValue(DEBUG, GetOrientation, 2, (pvOrientFront, pvOrientTop));

    CONST HRESULT result = this->State.Self->GetOrientation(pvOrientFront, pvOrientTop);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, GetOrientation, result, 2, (pvOrientFront, pvOrientTop));
}

// Retrieves the listener's current position in distance units.
// By default, these units are meters, but this can be changed by calling the IDirectSound3DListener::SetDistanceFactor method.
HRESULT DirectSound3DListener::GetPosition(LPD3DVECTOR pvPosition)
{
    DirectSound3DListenerLogMethodValue(DEBUG, GetPosition, 1, (pvPosition));

    CONST HRESULT result = this->State.Self->GetPosition(pvPosition);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, GetPosition, result, 1, (pvPosition));
}

// Retrieves the current rolloff factor.
HRESULT DirectSound3DListener::GetRolloffFactor(LPD3DVALUE pflRolloffFactor)
{
    DirectSound3DListenerLogMethodValue(DEBUG, GetRolloffFactor, 1, (pflRolloffFactor));

    CONST HRESULT result = this->State.Self->GetRolloffFactor(pflRolloffFactor);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, GetRolloffFactor, result, 1, (pflRolloffFactor));
}

// Retrieves the listener's current velocity.
HRESULT DirectSound3DListener::GetVelocity(LPD3DVECTOR pvVelocity)
{
    DirectSound3DListenerLogMethodValue(DEBUG, GetVelocity, 1, (pvVelocity));

    CONST HRESULT result = this->State.Self->GetVelocity(pvVelocity);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, GetVelocity, result, 1, (pvVelocity));
}

// Sets all 3-D listener parameters from a given DS3DLISTENER structure that describes all aspects of the 3-D listener at a moment in time.
HRESULT DirectSound3DListener::SetAllParameters(LPCDS3DLISTENER pcListener, DWORD dwApply)
{
    DirectSound3DListenerLogMethodValue(DEBUG, SetAllParameters, 2, (pcListener, dwApply));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcListener, dwApply);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, SetAllParameters, result, 2, (pcListener, dwApply));
}

// Sets the current distance factor.
HRESULT DirectSound3DListener::SetDistanceFactor(D3DVALUE flDistanceFactor, DWORD dwApply)
{
    DirectSound3DListenerLogMethodValue(DEBUG, SetDistanceFactor, 2, (flDistanceFactor, dwApply));

    CONST HRESULT result = this->State.Self->SetDistanceFactor(flDistanceFactor, dwApply);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, SetDistanceFactor, result, 2, (flDistanceFactor, dwApply));
}

// Sets the current Doppler effect factor.
HRESULT DirectSound3DListener::SetDopplerFactor(D3DVALUE flDopplerFactor, DWORD dwApply)
{
    DirectSound3DListenerLogMethodValue(DEBUG, SetDopplerFactor, 2, (flDopplerFactor, dwApply));

    CONST HRESULT result = this->State.Self->SetDopplerFactor(flDopplerFactor, dwApply);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, SetDopplerFactor, result, 2, (flDopplerFactor, dwApply));
}

// Sets the listener's current orientation in terms of two vectors: a front vector and a top vector.
HRESULT DirectSound3DListener::SetOrientation(D3DVALUE xFront, D3DVALUE yFront, D3DVALUE zFront, D3DVALUE xTop, D3DVALUE yTop, D3DVALUE zTop, DWORD dwApply)
{
    DirectSound3DListenerLogMethodValue(DEBUG, SetOrientation, 7, (xFront, yFront, zFront, xTop, yTop, zTop, dwApply));

    CONST HRESULT result = this->State.Self->SetOrientation(xFront, yFront, zFront, xTop, yTop, zTop, dwApply);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, SetOrientation, result, 7, (xFront, yFront, zFront, xTop, yTop, zTop, dwApply));
}

// Sets the listener's current position, in distance units.
// By default, these units are meters, but this can be changed by calling the IDirectSound3DListener::SetDistanceFactor method.
HRESULT DirectSound3DListener::SetPosition(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
    DirectSound3DListenerLogMethodValue(DEBUG, SetPosition, 4, (x, y, z, dwApply));

    CONST HRESULT result = this->State.Self->SetPosition(x, y, z, dwApply);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, SetPosition, result, 4, (x, y, z, dwApply));
}

// Sets the rolloff factor.
HRESULT DirectSound3DListener::SetRolloffFactor(D3DVALUE flRolloffFactor, DWORD dwApply)
{
    DirectSound3DListenerLogMethodValue(DEBUG, SetRolloffFactor, 2, (flRolloffFactor, dwApply));

    CONST HRESULT result = this->State.Self->SetRolloffFactor(flRolloffFactor, dwApply);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, SetRolloffFactor, result, 2, (flRolloffFactor, dwApply));
}

// Sets the listener's velocity.
HRESULT DirectSound3DListener::SetVelocity(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
    DirectSound3DListenerLogMethodValue(DEBUG, SetVelocity, 4, (x, y, z, dwApply));

    CONST HRESULT result = this->State.Self->SetVelocity(x, y, z, dwApply);

    DirectSound3DListenerLogMethodResultValue(DEBUGINFO, SetVelocity, result, 4, (x, y, z, dwApply));
}

// Commits any deferred settings made since the last call to this method.
HRESULT DirectSound3DListener::CommitDeferredSettings()
{
    DirectSound3DListenerLogMethod(DEBUG, CommitDeferredSettings);

    CONST HRESULT result = this->State.Self->CommitDeferredSettings();

    DirectSound3DListenerLogMethodResult(DEBUGINFO, CommitDeferredSettings, result);
}
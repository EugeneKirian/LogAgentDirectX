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

#include "DirectSound3DBuffer.hxx"
#include "DirectSoundBuffer.hxx"
#include "KsPropertySet.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSound3DBufferLogger.hxx>

#define DirectSound3DBufferLogMethod(L, M) AgentLogMethod(L, DirectSound3DBuffer, M)
#define DirectSound3DBufferLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSound3DBuffer, M, C, PARAMS)

#define DirectSound3DBufferLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSound3DBuffer, AddRef, R)
#define DirectSound3DBufferLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSound3DBuffer, Release, R)

#define DirectSound3DBufferLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSound3DBuffer, M, R)
#define DirectSound3DBufferLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSound3DBuffer, M, R, C, PARAMS)

DirectSound3DBuffer::DirectSound3DBuffer(AgentConstructorParameters(DirectSound3DBuffer))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSound3DBuffer)
}

DirectSound3DBuffer::~DirectSound3DBuffer()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSound3DBuffer);
}

HRESULT DirectSound3DBuffer::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSound3DBufferLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSound3DBuffer, riid)) { *ppvObj = ActivateAgent(DirectSound3DBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundBuffer, riid)) { *ppvObj = ActivateAgent(DirectSoundBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IKsPropertySet, riid)) { *ppvObj = ActivateAgent(KsPropertySet, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSound3DBuffer::AddRef()
{
    DirectSound3DBufferLogMethod(TRACE, AddRef);
    DirectSound3DBufferLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectSound3DBuffer::Release()
{
    DirectSound3DBufferLogMethod(TRACE, Release);
    DirectSound3DBufferLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves information that describes the 3-D characteristics of a sound buffer at a given point in time.
HRESULT DirectSound3DBuffer::GetAllParameters(LPDS3DBUFFER pDs3dBuffer)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetAllParameters, 1, (pDs3dBuffer));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDs3dBuffer);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDs3dBuffer));
}

// Retrieves the inside and outside angles of the sound projection cone for this sound buffer.
HRESULT DirectSound3DBuffer::GetConeAngles(LPDWORD pdwInsideConeAngle, LPDWORD pdwOutsideConeAngle)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetConeAngles, 2, (pdwInsideConeAngle, pdwOutsideConeAngle));

    CONST HRESULT result = this->State.Self->GetConeAngles(pdwInsideConeAngle, pdwOutsideConeAngle);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetConeAngles, result, 2, (pdwInsideConeAngle, pdwOutsideConeAngle));
}

// Retrieves the orientation of the sound projection cone for this sound buffer.
HRESULT DirectSound3DBuffer::GetConeOrientation(LPD3DVECTOR pvOrientation)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetConeOrientation, 1, (pvOrientation));

    CONST HRESULT result = this->State.Self->GetConeOrientation(pvOrientation);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetConeOrientation, result, 1, (pvOrientation));
}

// Retrieves the current cone outside volume for this sound buffer.
HRESULT DirectSound3DBuffer::GetConeOutsideVolume(LPLONG plConeOutsideVolume)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetConeOutsideVolume, 1, (plConeOutsideVolume));

    CONST HRESULT result = this->State.Self->GetConeOutsideVolume(plConeOutsideVolume);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetConeOutsideVolume, result, 1, (plConeOutsideVolume));
}

// Retrieves the current maximum distance for this sound buffer.
HRESULT DirectSound3DBuffer::GetMaxDistance(LPD3DVALUE pflMaxDistance)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetMaxDistance, 1, (pflMaxDistance));

    CONST HRESULT result = this->State.Self->GetMaxDistance(pflMaxDistance);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetMaxDistance, result, 1, (pflMaxDistance));
}

// Retrieves the current minimum distance for this sound buffer.
HRESULT DirectSound3DBuffer::GetMinDistance(LPD3DVALUE pflMinDistance)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetMinDistance, 1, (pflMinDistance));

    CONST HRESULT result = this->State.Self->GetMinDistance(pflMinDistance);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetMinDistance, result, 1, (pflMinDistance));
}

// Retrieves the current operation mode for 3-D sound processing.
HRESULT DirectSound3DBuffer::GetMode(LPDWORD pdwMode)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetMode, 1, (pdwMode));

    CONST HRESULT result = this->State.Self->GetMode(pdwMode);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetMode, result, 1, (pdwMode));
}

// Retrieves the sound buffer's current position, in distance units.
// By default, distance units are meters, but the units can be changed by using the IDirectSound3DListener::SetDistanceFactor method.
HRESULT DirectSound3DBuffer::GetPosition(LPD3DVECTOR pvPosition)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetPosition, 1, (pvPosition));

    CONST HRESULT result = this->State.Self->GetPosition(pvPosition);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetPosition, result, 1, (pvPosition));
}

// Retrieves the current velocity for this sound buffer.
// Velocity is measured in units per second. The default unit is one meter, but this can be changed by using the IDirectSound3DListener::SetDistanceFactor method.
HRESULT DirectSound3DBuffer::GetVelocity(LPD3DVECTOR pvVelocity)
{
    DirectSound3DBufferLogMethodValue(TRACE, GetVelocity, 1, (pvVelocity));

    CONST HRESULT result = this->State.Self->GetVelocity(pvVelocity);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, GetVelocity, result, 1, (pvVelocity));
}

// Sets all 3-D sound buffer parameters from a given DS3DBUFFER structure that describes all aspects of the sound buffer at a moment in time.
HRESULT DirectSound3DBuffer::SetAllParameters(LPCDS3DBUFFER pcDs3dBuffer, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetAllParameters, 2, (pcDs3dBuffer, dwApply));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDs3dBuffer, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 2, (pcDs3dBuffer, dwApply));
}

// Sets the inside and outside angles of the sound projection cone for this sound buffer.
HRESULT DirectSound3DBuffer::SetConeAngles(DWORD dwInsideConeAngle, DWORD dwOutsideConeAngle, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetConeAngles, 3, (dwInsideConeAngle, dwOutsideConeAngle, dwApply));

    CONST HRESULT result = this->State.Self->SetConeAngles(dwInsideConeAngle, dwOutsideConeAngle, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetConeAngles, result, 3, (dwInsideConeAngle, dwOutsideConeAngle, dwApply));
}

// Sets the orientation of the sound projection cone for this sound buffer.
// This method has no effect unless the cone angle and cone volume factor have also been set.
HRESULT DirectSound3DBuffer::SetConeOrientation(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetConeOrientation, 4, (x, y, z, dwApply));

    CONST HRESULT result = this->State.Self->SetConeOrientation(x, y, z, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetConeOrientation, result, 4, (x, y, z, dwApply));
}

// Sets the current cone outside volume for this sound buffer.
HRESULT DirectSound3DBuffer::SetConeOutsideVolume(LONG lConeOutsideVolume, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetConeOutsideVolume, 2, (lConeOutsideVolume, dwApply));

    CONST HRESULT result = this->State.Self->SetConeOutsideVolume(lConeOutsideVolume, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetConeOutsideVolume, result, 2, (lConeOutsideVolume, dwApply));
}

// Sets the current maximum distance value.
HRESULT DirectSound3DBuffer::SetMaxDistance(D3DVALUE flMaxDistance, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetMaxDistance, 2, (flMaxDistance, dwApply));

    CONST HRESULT result = this->State.Self->SetMaxDistance(flMaxDistance, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetMaxDistance, result, 2, (flMaxDistance, dwApply));
}

// Sets the current minimum distance value.
HRESULT DirectSound3DBuffer::SetMinDistance(D3DVALUE flMinDistance, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetMinDistance, 2, (flMinDistance, dwApply));

    CONST HRESULT result = this->State.Self->SetMinDistance(flMinDistance, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetMinDistance, result, 2, (flMinDistance, dwApply));
}

// Sets the operation mode for 3-D sound processing.
HRESULT DirectSound3DBuffer::SetMode(DWORD dwMode, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetMode, 2, (dwMode, dwApply));

    CONST HRESULT result = this->State.Self->SetMode(dwMode, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetMode, result, 2, (dwMode, dwApply));
}

// Sets the sound buffer's current position, in distance units.
// By default, distance units are meters, but the units can be changed by using the IDirectSound3DListener::SetDistanceFactor method.
HRESULT DirectSound3DBuffer::SetPosition(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetPosition, 4, (x, y, z, dwApply));

    CONST HRESULT result = this->State.Self->SetPosition(x, y, z, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetPosition, result, 4, (x, y, z, dwApply));
}

// Sets the sound buffer's current velocity. 
HRESULT DirectSound3DBuffer::SetVelocity(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
    DirectSound3DBufferLogMethodValue(TRACE, SetVelocity, 4, (x, y, z, dwApply));

    CONST HRESULT result = this->State.Self->SetVelocity(x, y, z, dwApply);

    DirectSound3DBufferLogMethodResultValue(TRACEDEBUGINFO, SetVelocity, result, 4, (x, y, z, dwApply));
}
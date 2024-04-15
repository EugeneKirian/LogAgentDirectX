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
#include <KsPropertySetLogger.hxx>

#define KsPropertySetLogMethod(L, M) AgentLogMethod(L, KsPropertySet, M)
#define KsPropertySetLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, KsPropertySet, M, C, PARAMS)

#define KsPropertySetLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, KsPropertySet, AddRef, R)
#define KsPropertySetLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, KsPropertySet, Release, R)

#define KsPropertySetLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, KsPropertySet, M, R, C, PARAMS)

KsPropertySet::KsPropertySet(AgentConstructorParameters(KsPropertySet))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, KsPropertySet);
}

KsPropertySet::~KsPropertySet()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, KsPropertySet);
}

HRESULT KsPropertySet::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    KsPropertySetLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSound3DBuffer, riid)) { *ppvObj = ActivateAgent(KsPropertySet, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundBuffer, riid)) { *ppvObj = ActivateAgent(DirectSoundBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IKsPropertySet, riid)) { *ppvObj = ActivateAgent(KsPropertySet, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    KsPropertySetLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG KsPropertySet::AddRef()
{
    KsPropertySetLogMethod(TRACE, AddRef);
    KsPropertySetLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG KsPropertySet::Release()
{
    KsPropertySetLogMethod(TRACE, Release);
    KsPropertySetLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves data for an item in a property set.
HRESULT KsPropertySet::Get(REFGUID rguidPropSet, ULONG ulId, LPVOID pInstanceData, ULONG ulInstanceLength, LPVOID pPropertyData, ULONG ulDataLength, PULONG pulBytesReturned)
{
    KsPropertySetLogMethodValue(TRACE, Get, 7, (rguidPropSet, ulId, pInstanceData, ulInstanceLength, pPropertyData, ulDataLength, pulBytesReturned));

    CONST HRESULT result = this->State.Self->Get(rguidPropSet, ulId, pInstanceData, ulInstanceLength, pPropertyData, ulDataLength, pulBytesReturned);

    KsPropertySetLogMethodResultValue(TRACEDEBUGINFO, Get, result, 7, (rguidPropSet, ulId, pInstanceData, ulInstanceLength, pPropertyData, ulDataLength, pulBytesReturned));
}

// Sets the value of a property in a property set.
HRESULT KsPropertySet::Set(REFGUID rguidPropSet, ULONG ulId, LPVOID pInstanceData, ULONG ulInstanceLength, LPVOID pPropertyData, ULONG ulDataLength)
{
    KsPropertySetLogMethodValue(TRACE, Set, 6, (rguidPropSet, ulId, pInstanceData, ulInstanceLength, pPropertyData, ulDataLength));

    CONST HRESULT result = this->State.Self->Set(rguidPropSet, ulId, pInstanceData, ulInstanceLength, pPropertyData, ulDataLength);

    KsPropertySetLogMethodResultValue(TRACEDEBUGINFO, Set, result, 6, (rguidPropSet, ulId, pInstanceData, ulInstanceLength, pPropertyData, ulDataLength));
}

// Ascertains whether a property in a property set is supported on the port or device.
HRESULT KsPropertySet::QuerySupport(REFGUID rguidPropSet, ULONG ulId, PULONG pulTypeSupport)
{
    KsPropertySetLogMethodValue(TRACE, QuerySupport, 3, (rguidPropSet, ulId, pulTypeSupport));

    CONST HRESULT result = this->State.Self->QuerySupport(rguidPropSet, ulId, pulTypeSupport);

    KsPropertySetLogMethodResultValue(TRACEDEBUGINFO, QuerySupport, result, 3, (rguidPropSet, ulId, pulTypeSupport));
}
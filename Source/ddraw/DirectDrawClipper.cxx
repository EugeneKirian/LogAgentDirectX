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

#include "DirectDraw.hxx"
#include "DirectDrawClipper.hxx"

#include <AgentLogger.hxx>
#include <DirectDrawClipperLogger.hxx>

#define DirectDrawClipperLogMethod(L, M) AgentLogMethod(L, DirectDrawClipper, M)
#define DirectDrawClipperLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawClipper, M, C, PARAMS)

#define DirectDrawClipperLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawClipper, AddRef, R)
#define DirectDrawClipperLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawClipper, Release, R)

#define DirectDrawClipperLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawClipper, M, R, C, PARAMS)

DirectDrawClipper::DirectDrawClipper(AgentConstructorParameters(DirectDrawClipper))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectDrawClipper);
}

DirectDrawClipper::~DirectDrawClipper()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectDrawClipper);
}

HRESULT DirectDrawClipper::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawClipperLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectDrawClipper, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDrawClipper, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectDrawClipperLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawClipper::AddRef()
{
    DirectDrawClipperLogMethod(DEBUG, AddRef);
    DirectDrawClipperLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawClipper::Release()
{
    DirectDrawClipperLogMethod(DEBUG, Release);
    DirectDrawClipperLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves a copy of the clip list that is associated with a DirectDrawClipper object.
// To select a subset of the clip list, you can pass a rectangle that clips the clip list.
HRESULT DirectDrawClipper::GetClipList(LPRECT lpRect, LPRGNDATA lpClipList, LPDWORD lpdwSize)
{
    DirectDrawClipperLogMethodValue(DEBUG, GetClipList, 3, (lpRect, lpClipList, lpdwSize));

    CONST HRESULT result = this->State.Self->GetClipList(lpRect, lpClipList, lpdwSize);

    DirectDrawClipperLogMethodResultValue(DEBUGINFO, GetClipList, result, 3, (lpRect, lpClipList, lpdwSize));
}

// Retrieves the window handle that was previously associated with this DirectDrawClipper object by the IDirectDrawClipper::SetHWnd method.
HRESULT DirectDrawClipper::GetHWnd(HWND FAR* lphWnd)
{
    DirectDrawClipperLogMethodValue(DEBUG, GetHWnd, 1, (lphWnd));

    CONST HRESULT result = this->State.Self->GetHWnd(lphWnd);

    DirectDrawClipperLogMethodResultValue(DEBUGINFO, GetHWnd, result, 1, (lphWnd));
}

// Initializes a DirectDrawClipper object that was created by using the CoCreateInstance COM function.
HRESULT DirectDrawClipper::Initialize(LPDIRECTDRAW lpDD, DWORD dwFlags)
{
    DirectDrawClipperLogMethodValue(DEBUG, Initialize, 2, (lpDD, dwFlags));

    AttemptAccessAgentValue(DirectDraw, lpDD);

    CONST HRESULT result = this->State.Self->Initialize(lpDD, dwFlags);

    DirectDrawClipperLogMethodResultValue(DEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectDraw, lpDD), dwFlags));
}

// Retrieves the status of the clip list if a window handle is associated with a DirectDrawClipper object.
HRESULT DirectDrawClipper::IsClipListChanged(BOOL FAR* lpbChanged)
{
    DirectDrawClipperLogMethodValue(DEBUG, IsClipListChanged, 1, (lpbChanged));

    CONST HRESULT result = this->State.Self->IsClipListChanged(lpbChanged);

    DirectDrawClipperLogMethodResultValue(DEBUGINFO, IsClipListChanged, result, 1, (lpbChanged));
}

// Sets or deletes the clip list that is used by the IDirectDrawSurface7::Blt, IDirectDrawSurface7::BltBatch,
// and IDirectDrawSurface7::UpdateOverlay methods on surfaces to which the parent DirectDrawClipper object is attached.
HRESULT DirectDrawClipper::SetClipList(LPRGNDATA lpClipList, DWORD dwFlags)
{
    DirectDrawClipperLogMethodValue(DEBUG, SetClipList, 2, (lpClipList, dwFlags));

    CONST HRESULT result = this->State.Self->SetClipList(lpClipList, dwFlags);

    DirectDrawClipperLogMethodResultValue(DEBUGINFO, SetClipList, result, 2, (lpClipList, dwFlags));
}

// Sets the window handle that the clipper object uses to obtain clipping information.
HRESULT DirectDrawClipper::SetHWnd(DWORD dwFlags, HWND hWnd)
{
    DirectDrawClipperLogMethodValue(DEBUG, SetHWnd, 2, (dwFlags, hWnd));

    CONST HRESULT result = this->State.Self->SetHWnd(dwFlags, hWnd);

    DirectDrawClipperLogMethodResultValue(DEBUGINFO, SetHWnd, result, 2, (dwFlags, hWnd));
}
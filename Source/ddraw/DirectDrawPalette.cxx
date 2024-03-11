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
#include "DirectDrawPalette.hxx"

#include <AgentLogger.hxx>
#include <DirectDrawPaletteLogger.hxx>

#define DirectDrawPaletteLogMethod(L, M) AgentLogMethod(L, DirectDrawPalette, M)
#define DirectDrawPaletteLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawPalette, M, C, PARAMS)

#define DirectDrawPaletteLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawPalette, AddRef, R)
#define DirectDrawPaletteLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawPalette, Release, R)

#define DirectDrawPaletteLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDrawPalette, M, R)
#define DirectDrawPaletteLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawPalette, M, R, C, PARAMS)

DirectDrawPalette::DirectDrawPalette(AgentConstructorParameters(DirectDrawPalette))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectDrawPalette);
}

DirectDrawPalette::~DirectDrawPalette()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectDrawPalette);
}

HRESULT DirectDrawPalette::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawPaletteLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectDrawPalette, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDrawPalette, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectDrawPaletteLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawPalette::AddRef()
{
    DirectDrawPaletteLogMethod(DEBUG, AddRef);
    DirectDrawPaletteLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawPalette::Release()
{
    DirectDrawPaletteLogMethod(DEBUG, Release);
    DirectDrawPaletteLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves the capabilities of the palette object.
HRESULT DirectDrawPalette::GetCaps(LPDWORD lpdwCaps)
{
    DirectDrawPaletteLogMethodValue(TRACE, GetCaps, 1, (lpdwCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpdwCaps);

    DirectDrawPaletteLogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 1, (lpdwCaps));
}

// Retrieves palette values from a DirectDrawPalette object.
HRESULT DirectDrawPalette::GetEntries(DWORD dwFlags, DWORD dwBase, DWORD dwNumEntries, LPPALETTEENTRY lpEntries)
{
    DirectDrawPaletteLogMethodValue(TRACE, GetEntries, 4, (dwFlags, dwBase, dwNumEntries, lpEntries));

    CONST HRESULT result = this->State.Self->GetEntries(dwFlags, dwBase, dwNumEntries, lpEntries);

    DirectDrawPaletteLogMethodResultValue(TRACEDEBUGINFO, GetEntries, result, 4, (dwFlags, dwBase, dwNumEntries, lpEntries));
}

// Initializes the DirectDrawPalette object.
HRESULT DirectDrawPalette::Initialize(LPDIRECTDRAW lpDD, DWORD dwFlags, LPPALETTEENTRY lpDDColorTable)
{
    DirectDrawPaletteLogMethodValue(TRACE, Initialize, 3, (lpDD, dwFlags, lpDDColorTable));

    AttemptAccessAgentValue(DirectDraw, lpDD);

    CONST HRESULT result = this->State.Self->Initialize(lpDD, dwFlags, lpDDColorTable);

    DirectDrawPaletteLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 3, (ActivateAgent(DirectDraw, lpDD), dwFlags, lpDDColorTable));
}
// Changes entries in a DirectDrawPalette object immediately.
HRESULT DirectDrawPalette::SetEntries(DWORD dwFlags, DWORD dwStartingEntry, DWORD dwCount, LPPALETTEENTRY lpEntries)
{
    DirectDrawPaletteLogMethodValue(TRACE, SetEntries, 4, (dwFlags, dwStartingEntry, dwCount, lpEntries));

    CONST HRESULT result = this->State.Self->SetEntries(dwFlags, dwStartingEntry, dwCount, lpEntries);

    DirectDrawPaletteLogMethodResultValue(TRACEDEBUGINFO, SetEntries, result, 4, (dwFlags, dwStartingEntry, dwCount, lpEntries));
}
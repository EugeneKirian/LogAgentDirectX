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

#include "DirectDrawSurface.hxx"
#include "DirectDrawVideoPort.hxx"

#include <AgentLogger.hxx>
#include <DirectDrawVideoPortLogger.hxx>

#define DirectDrawVideoPortLogMethod(L, M) AgentLogMethod(L, DirectDrawVideoPort, M)
#define DirectDrawVideoPortLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawVideoPort, M, C, PARAMS)

#define DirectDrawVideoPortLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawVideoPort, AddRef, R)
#define DirectDrawVideoPortLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawVideoPort, Release, R)

#define DirectDrawVideoPortLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDrawVideoPort, M, R)
#define DirectDrawVideoPortLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawVideoPort, M, R, C, PARAMS)

DirectDrawVideoPort::DirectDrawVideoPort(AgentConstructorParameters(DirectDrawVideoPort))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectDrawVideoPort);
}

DirectDrawVideoPort::~DirectDrawVideoPort()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectDrawVideoPort);
}

HRESULT DirectDrawVideoPort::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectDrawVideoPort, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPort, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawVideoPort::AddRef()
{
    DirectDrawVideoPortLogMethod(DEBUG, AddRef);
    DirectDrawVideoPortLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawVideoPort::Release()
{
    DirectDrawVideoPortLogMethod(DEBUG, Release);
    DirectDrawVideoPortLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Instructs the DirectDrawVideoPort object to write the next frame of video to a new surface.
HRESULT DirectDrawVideoPort::Flip(LPDIRECTDRAWSURFACE lpDDSurface, DWORD dwFlags)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, Flip, 2, (lpDDSurface, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSurface);

    CONST HRESULT result = this->State.Self->Flip(lpDDSurface, dwFlags);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, Flip, result, 2, (ActivateAgent(DirectDrawSurface, lpDDSurface), dwFlags));
}

// Retrieves the minimum required overlay zoom factors and device limitations of a video port that uses the provided output pixel format.
HRESULT DirectDrawVideoPort::GetBandwidthInfo(LPDDPIXELFORMAT lpddpfFormat, DWORD dwWidth, DWORD dwHeight, DWORD dwFlags, LPDDVIDEOPORTBANDWIDTH lpBandwidth)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, GetBandwidthInfo, 5, (lpddpfFormat, dwWidth, dwHeight, dwFlags, lpBandwidth));

    CONST HRESULT result = this->State.Self->GetBandwidthInfo(lpddpfFormat, dwWidth, dwHeight, dwFlags, lpBandwidth);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, GetBandwidthInfo, result, 5, (lpddpfFormat, dwWidth, dwHeight, dwFlags, lpBandwidth));
}

// Returns the current color control settings associated with the video port.
HRESULT DirectDrawVideoPort::GetColorControls(LPDDCOLORCONTROL lpColorControl)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, GetColorControls, 1, (lpColorControl));

    CONST HRESULT result = this->State.Self->GetColorControls(lpColorControl);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, GetColorControls, result, 1, (lpColorControl));
}

// Retrieves the input formats supported by the DirectDrawVideoPort object.
HRESULT DirectDrawVideoPort::GetInputFormats(LPDWORD lpNumFormats, LPDDPIXELFORMAT lpFormats, DWORD dwFlags)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, GetInputFormats, 3, (lpNumFormats, lpFormats, dwFlags));

    CONST HRESULT result = this->State.Self->GetInputFormats(lpNumFormats, lpFormats, dwFlags);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, GetInputFormats, result, 3, (lpNumFormats, lpFormats, dwFlags));
}

// Retrieves a list of output formats that the DirectDrawVideoPort object supports for a specified input format.
HRESULT DirectDrawVideoPort::GetOutputFormats(LPDDPIXELFORMAT lpInputFormat, LPDWORD lpNumFormats, LPDDPIXELFORMAT lpFormats, DWORD dwFlags)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, GetOutputFormats, 4, (lpInputFormat, lpNumFormats, lpFormats, dwFlags));

    CONST HRESULT result = this->State.Self->GetOutputFormats(lpInputFormat, lpNumFormats, lpFormats, dwFlags);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, GetOutputFormats, result, 4, (lpInputFormat, lpNumFormats, lpFormats, dwFlags));
}

// Retrieves the polarity of a video field.
HRESULT DirectDrawVideoPort::GetFieldPolarity(LPBOOL lpbFieldPolarity)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, GetFieldPolarity, 1, (lpbFieldPolarity));

    CONST HRESULT result = this->State.Self->GetFieldPolarity(lpbFieldPolarity);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, GetFieldPolarity, result, 1, (lpbFieldPolarity));
}

// Retrieves the line of video currently being written to the frame buffer.
HRESULT DirectDrawVideoPort::GetVideoLine(LPDWORD lpdwLine)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, GetVideoLine, 1, (lpdwLine));

    CONST HRESULT result = this->State.Self->GetVideoLine(lpdwLine);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, GetVideoLine, result, 1, (lpdwLine));
}

// Retrieves the status of the video signal currently being presented to the video port.
HRESULT DirectDrawVideoPort::GetVideoSignalStatus(LPDWORD lpdwStatus)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, GetVideoSignalStatus, 1, (lpdwStatus));

    CONST HRESULT result = this->State.Self->GetVideoSignalStatus(lpdwStatus);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, GetVideoSignalStatus, result, 1, (lpdwStatus));
}

// Sets the color control settings associated with the video port.
HRESULT DirectDrawVideoPort::SetColorControls(LPDDCOLORCONTROL lpColorControl)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, SetColorControls, 1, (lpColorControl));

    CONST HRESULT result = this->State.Self->SetColorControls(lpColorControl);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, SetColorControls, result, 1, (lpColorControl));
}

// Sets the DirectDraw surface object to receive the stream of live video data and/or the vertical blank interval data.
HRESULT DirectDrawVideoPort::SetTargetSurface(LPDIRECTDRAWSURFACE lpDDSurface, DWORD dwFlags)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, SetTargetSurface, 2, (lpDDSurface, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSurface);

    CONST HRESULT result = this->State.Self->SetTargetSurface(lpDDSurface, dwFlags);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, SetTargetSurface, result, 2, (ActivateAgent(DirectDrawSurface, lpDDSurface), dwFlags));
}

// Enables the hardware video port and starts the flow of video data into the currently specified surface.
HRESULT DirectDrawVideoPort::StartVideo(LPDDVIDEOPORTINFO lpVideoInfo)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, StartVideo, 1, (lpVideoInfo));

    CONST HRESULT result = this->State.Self->StartVideo(lpVideoInfo);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, StartVideo, result, 1, (lpVideoInfo));
}

// Stops the flow of video-port data into the frame buffer.
HRESULT DirectDrawVideoPort::StopVideo()
{
    DirectDrawVideoPortLogMethod(DEBUG, StopVideo);

    CONST HRESULT result = this->State.Self->StopVideo();

    DirectDrawVideoPortLogMethodResult(DEBUGINFO, StopVideo, result);
}

// Updates parameters that govern the flow of video data from the video port to the DirectDrawSurface object.
HRESULT DirectDrawVideoPort::UpdateVideo(LPDDVIDEOPORTINFO lpVideoInfo)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, UpdateVideo, 1, (lpVideoInfo));

    CONST HRESULT result = this->State.Self->UpdateVideo(lpVideoInfo);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, UpdateVideo, result, 1, (lpVideoInfo));
}

// Waits for VSYNC or until a given scan line is being drawn.
HRESULT DirectDrawVideoPort::WaitForSync(DWORD dwFlags, DWORD dwLine, DWORD dwTimeout)
{
    DirectDrawVideoPortLogMethodValue(DEBUG, WaitForSync, 3, (dwFlags, dwLine, dwTimeout));

    CONST HRESULT result = this->State.Self->WaitForSync(dwFlags, dwLine, dwTimeout);

    DirectDrawVideoPortLogMethodResultValue(DEBUGINFO, WaitForSync, result, 3, (dwFlags, dwLine, dwTimeout));
}
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

#include "Window.hxx"

#include <stdio.h>

#define Invoke(X)                 \
    printf(#X ## "\r\n");         \
    X(module)

VOID ExecuteDirectSound(LPMODULE module)
{
    Invoke(DirectSoundCreate);
    Invoke(DirectSoundQueryInterfaceIUnknown);
    Invoke(DirectSoundQueryInterfaceAll);
}

VOID ExecuteDirectSound3DBuffer(LPMODULE module)
{
    Invoke(DirectSound3DBufferCreate);
    Invoke(DirectSound3DBufferQueryInterfaceIUnknown);
    Invoke(DirectSound3DBufferQueryInterfaceAll);
}

VOID ExecuteDirectSound3DListener(LPMODULE module)
{
    Invoke(DirectSound3DListenerCreate);
    Invoke(DirectSound3DListenerQueryInterfaceIUnknown);
    Invoke(DirectSound3DListenerQueryInterfaceAll);
}

VOID ExecuteDirectSound8(LPMODULE module)
{
    Invoke(DirectSound8Create);
    Invoke(DirectSound8QueryInterfaceIUnknown);
    Invoke(DirectSound8QueryInterfaceAll);
}

VOID ExecuteDirectSoundBuffer(LPMODULE module)
{
    Invoke(DirectSoundBufferCreate);
    Invoke(DirectSoundBufferQueryInterfaceIUnknown);
    Invoke(DirectSoundBufferQueryInterfaceAll);
}

VOID ExecuteDirectSoundBuffer8(LPMODULE module)
{
    Invoke(DirectSoundBuffer8Create);
    Invoke(DirectSoundBuffer8QueryInterfaceIUnknown);
    Invoke(DirectSoundBuffer8QueryInterfaceAll);
}

VOID ExecuteDirectSoundCapture(LPMODULE module)
{
    Invoke(DirectSoundCaptureCreate);
    Invoke(DirectSoundCaptureQueryInterfaceIUnknown);
    Invoke(DirectSoundCaptureQueryInterfaceAll);
}

VOID ExecuteDirectSoundCaptureBuffer(LPMODULE module)
{
    Invoke(DirectSoundCaptureBufferCreate);
    Invoke(DirectSoundCaptureBufferQueryInterfaceIUnknown);
    Invoke(DirectSoundCaptureBufferQueryInterfaceAll);
}

VOID ExecuteDirectSoundCaptureBuffer8(LPMODULE module)
{
    Invoke(DirectSoundCaptureBuffer8Create);
    Invoke(DirectSoundCaptureBuffer8QueryInterfaceIUnknown);
    Invoke(DirectSoundCaptureBuffer8QueryInterfaceAll);
}

VOID ExecuteDirectSoundCaptureFXAec(LPMODULE module)
{
    Invoke(DirectSoundCaptureFXAecCreate);
}

VOID ExecuteDirectSoundCaptureFXNoiseSuppress(LPMODULE module)
{
    Invoke(DirectSoundCaptureFXNoiseSuppressCreate);
}

VOID ExecuteDirectSoundFullDuplex(LPMODULE module)
{
    Invoke(DirectSoundFullDuplexCreate);
    Invoke(DirectSoundFullDuplexQueryInterfaceIUnknown);
    Invoke(DirectSoundFullDuplexQueryInterfaceAll);
}

VOID ExecuteDirectSoundFXChorus(LPMODULE module)
{
    Invoke(DirectSoundFXChorusCreate);
}

VOID ExecuteDirectSoundFXCompressor(LPMODULE module)
{
    Invoke(DirectSoundFXCompressorCreate);
}

VOID ExecuteDirectSoundFXDistortion(LPMODULE module)
{
    Invoke(DirectSoundFXDistortionCreate);
}

VOID ExecuteDirectSoundFXEcho(LPMODULE module)
{
    Invoke(DirectSoundFXEchoCreate);
}

VOID ExecuteDirectSoundFXFlanger(LPMODULE module)
{
    Invoke(DirectSoundFXEchoCreate);
}

VOID ExecuteDirectSoundFXGargle(LPMODULE module)
{
    Invoke(DirectSoundFXGargleCreate);
}

VOID ExecuteDirectSoundFXI3DL2Reverb(LPMODULE module)
{
    Invoke(DirectSoundFXI3DL2ReverbCreate);
}

VOID ExecuteDirectSoundFXParamEq(LPMODULE module)
{
    Invoke(DirectSoundFXParamEqCreate);
}

VOID ExecuteDirectSoundFXWavesReverb(LPMODULE module)
{
    Invoke(DirectSoundFXWavesReverbCreate);
}

VOID ExecuteDirectSoundNotify(LPMODULE module)
{
    Invoke(DirectSoundNotifyCreate);
    Invoke(DirectSoundNotify8Create);
    Invoke(DirectSoundNotifyQueryInterfaceIUnknown);
    Invoke(DirectSoundNotify8QueryInterfaceIUnknown);
    Invoke(DirectSoundNotifyQueryInterfaceAll);
    Invoke(DirectSoundNotify8QueryInterfaceAll);
}

VOID ExecuteKsPropertySet(LPMODULE module)
{
    Invoke(KsPropertySetCreate);
    Invoke(KsPropertySetQueryInterfaceIUnknown);
    Invoke(KsPropertySetQueryInterfaceAll);
}

VOID Execute(LPMODULE module)
{
    Invoke(ExecuteDirectSound);
    Invoke(ExecuteDirectSound3DBuffer);
    Invoke(ExecuteDirectSound3DListener);
    Invoke(ExecuteDirectSound8);
    Invoke(ExecuteDirectSoundBuffer);
    Invoke(ExecuteDirectSoundBuffer8);
    Invoke(ExecuteDirectSoundCapture);
    Invoke(ExecuteDirectSoundCaptureBuffer);
    Invoke(ExecuteDirectSoundCaptureBuffer8);
    Invoke(ExecuteDirectSoundCaptureFXAec);
    Invoke(ExecuteDirectSoundCaptureFXNoiseSuppress);
    Invoke(ExecuteDirectSoundFullDuplex);
    Invoke(ExecuteDirectSoundFXChorus);
    Invoke(ExecuteDirectSoundFXCompressor);
    Invoke(ExecuteDirectSoundFXDistortion);
    Invoke(ExecuteDirectSoundFXEcho);
    Invoke(ExecuteDirectSoundFXFlanger);
    Invoke(ExecuteDirectSoundFXGargle);
    Invoke(ExecuteDirectSoundFXI3DL2Reverb);
    Invoke(ExecuteDirectSoundFXParamEq);
    Invoke(ExecuteDirectSoundFXWavesReverb);
    Invoke(ExecuteDirectSoundNotify);
    Invoke(ExecuteKsPropertySet);
}

BOOL AcquirePath(LPSTR lpBuffer, LPCSTR lpPath, const UINT uSize)
{
    CHAR path[MAX_PATH];
    ZeroMemory(path, MAX_PATH);

    if (PathCombineA(path, lpPath, DIRECT_SOUND_LIBRARY_NAME) == NULL) { return FALSE; }

    return strncpy_s(lpBuffer, uSize, path, MAX_PATH) == 0;
}

BOOL AcquireOriginalPath(LPSTR lpBuffer, const UINT uSize)
{
    if (lpBuffer == NULL) { return FALSE; }

    CHAR path[MAX_PATH];
    ZeroMemory(path, MAX_PATH);

    if (GetSystemDirectoryA(path, MAX_PATH) == 0) { return FALSE; }

    return AcquirePath(lpBuffer, path, uSize);
}

BOOL AcquireAgentPath(LPSTR lpBuffer, const UINT uSize)
{
    if (lpBuffer == NULL) { return FALSE; }

    CHAR path[MAX_PATH];
    ZeroMemory(path, MAX_PATH);

    if (GetCurrentDirectoryA(MAX_PATH, path) == 0) { return FALSE; }

    return AcquirePath(lpBuffer, path, uSize);
}

int main()
{
    if (!RegisterWindowClass()) { printf("Unable to register window class.\r\n."); return EXIT_FAILURE; }

    // Original
    {
        CHAR path[MAX_PATH];
        ZeroMemory(path, MAX_PATH);

        if (AcquireOriginalPath(path, MAX_PATH))
        {
            LPMODULE module = InitializeModule(path);

            if (module == NULL) { printf("Unable to load the original module %s.\r\n", path); return EXIT_FAILURE; }

            printf("Executing tests on %s ...\r\n", path);

            Execute(module);
            ReleaseModule(module);
        }
        else { printf("Unable to load the original module %s.\r\n", path); return EXIT_FAILURE; }
    }

    // Agent
    {
        CHAR path[MAX_PATH];
        ZeroMemory(path, MAX_PATH);

        if (AcquireAgentPath(path, MAX_PATH))
        {
            LPMODULE module = InitializeModule(path);

            if (module == NULL) { printf("Unable to load the agent module %s.\r\n", path); return EXIT_FAILURE; }

            printf("Executing tests on %s ...\r\n", path);

            Execute(module);
            ReleaseModule(module);
        }
        else { printf("Unable to load the agent module %s.\r\n", path); return EXIT_FAILURE; }
    }

    ReleaseWindowClass();

    return EXIT_SUCCESS;
}
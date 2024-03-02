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

#include "DirectSoundCaptureFXNoiseSuppress.hxx"

VOID DirectSoundCaptureFXNoiseSuppressCreate(LPMODULE module)
{
    LPDIRECTSOUNDCAPTURE dsc = NULL;
    HRESULT result = module->DirectSoundCaptureCreate8(NULL, &dsc, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsc, NULL);

    dsc->AddRef();
    IsEqual(dsc->Release(), 1);

    WAVEFORMATEX format;
    ZeroMemory(&format, sizeof(WAVEFORMATEX));

    format.wFormatTag = WAVE_FORMAT_PCM;
    format.nSamplesPerSec = 22050;
    format.wBitsPerSample = 16;
    format.cbSize = 0;
    format.nChannels = 1;
    format.nBlockAlign = format.nChannels * format.wBitsPerSample / 8;
    format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;

    DSCBUFFERDESC desc;
    ZeroMemory(&desc, sizeof(DSCBUFFERDESC));
    desc.dwFlags = DSCBCAPS_CTRLFX;
    desc.dwSize = sizeof(DSCBUFFERDESC);
    desc.dwBufferBytes = 1024 << 2;
    desc.lpwfxFormat = &format;

    desc.dwFXCount = 1;

    DSCEFFECTDESC edesc;
    ZeroMemory(&edesc, sizeof(DSCEFFECTDESC));

    edesc.dwSize = sizeof(DSCEFFECTDESC);
    edesc.dwFlags = DSCFX_LOCSOFTWARE;
    edesc.guidDSCFXClass = GUID_DSCFX_CLASS_NS;
    edesc.guidDSCFXInstance = GUID_DSCFX_MS_NS;

    desc.lpDSCFXDesc = &edesc;

    LPDIRECTSOUNDCAPTUREBUFFER dscb = NULL;
    result = dsc->CreateCaptureBuffer(&desc, &dscb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dscb, NULL);

    {
        LPDIRECTSOUNDCAPTUREBUFFER8 dscb8 = NULL;
        result = dscb->QueryInterface(IID_IDirectSoundCaptureBuffer8, (LPVOID*)&dscb8);
        IsEqual(result, DS_OK);
        IsNotEqual(dscb, NULL);

        IsEqual((LPVOID)dscb, dscb8);

        LPDIRECTSOUNDCAPTUREFXNOISESUPPRESS ns = NULL;
        result = dscb8->GetObjectInPath(GUID_DSCFX_CLASS_NS, 0, IID_IDirectSoundCaptureFXNoiseSuppress, (LPVOID*)&ns);
        IsNotEqual(result, DS_OK);

        DIRECTRELEASE(dscb8);
    }

    DIRECTRELEASE(dscb);
    DIRECTRELEASE(dsc);
}
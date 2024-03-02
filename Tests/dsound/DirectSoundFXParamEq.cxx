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

#include "DirectSoundFXParamEq.hxx"

VOID DirectSoundFXParamEqCreate(LPMODULE module)
{
    LPDIRECTSOUND8 ds = NULL;
    HRESULT result = module->DirectSoundCreate8(NULL, &ds, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(ds, NULL);

    ds->AddRef();
    IsEqual(ds->Release(), 1);

    WAVEFORMATEX format;
    ZeroMemory(&format, sizeof(WAVEFORMATEX));

    format.wFormatTag = WAVE_FORMAT_PCM;
    format.nSamplesPerSec = 22050;
    format.wBitsPerSample = 16;
    format.cbSize = 0;
    format.nChannels = 1;
    format.nBlockAlign = format.nChannels * format.wBitsPerSample / 8;
    format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;

    DSBUFFERDESC desc;
    ZeroMemory(&desc, sizeof(DSBUFFERDESC));
    desc.dwSize = sizeof(DSBUFFERDESC);
    desc.dwBufferBytes = 1024 << 2;
    desc.lpwfxFormat = &format;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    {
        LPDIRECTSOUNDBUFFER8 dsb8 = NULL;
        result = dsb->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&dsb8);
        IsEqual(result, DS_OK);
        IsNotEqual(dsb, NULL);

        IsEqual((LPVOID)dsb, dsb8);

        DSEFFECTDESC edesc;
        ZeroMemory(&edesc, sizeof(DSEFFECTDESC));

        edesc.dwSize = sizeof(DSEFFECTDESC);
        edesc.guidDSFXClass = GUID_DSFX_STANDARD_PARAMEQ;

        DWORD res = DSFXR_PRESENT;
        result = dsb8->SetFX(1, &edesc, &res);
        IsNotEqual(result, DS_OK);
        IsNotEqual(res, DSFXR_FAILED);

        DIRECTRELEASE(dsb8);
    }

    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}
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

#include "DirectSoundNotify.hxx"

VOID DirectSoundNotifyCreate(LPMODULE module)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = module->DirectSoundCreate(NULL, &ds, NULL);
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
    desc.dwFlags = DSBCAPS_CTRLPOSITIONNOTIFY;
    desc.dwBufferBytes = 1024;
    desc.lpwfxFormat = &format;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    {
        LPDIRECTSOUNDNOTIFY dsn = NULL;
        result = dsb->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
        IsEqual(result, DS_OK);
        IsNotEqual(dsb, NULL);

        IsNotEqual((LPVOID)dsb, dsn);
        IsNotEqual((LPVOID)ds, dsn);

        DIRECTRELEASE(dsn);
    }

    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}

VOID DirectSoundNotify8Create(LPMODULE module)
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
    desc.dwFlags = DSBCAPS_CTRLPOSITIONNOTIFY;
    desc.dwBufferBytes = 1024;
    desc.lpwfxFormat = &format;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    LPDIRECTSOUNDBUFFER8 dsb8 = NULL;
    result = dsb->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&dsb8);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb8, NULL);

    {
        LPDIRECTSOUNDNOTIFY dsn = NULL;
        result = dsb8->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
        IsEqual(result, DS_OK);
        IsNotEqual(dsb, NULL);

        IsNotEqual((LPVOID)dsb8, dsn);
        IsNotEqual((LPVOID)dsb, dsn);
        IsNotEqual((LPVOID)ds, dsn);

        DIRECTRELEASE(dsn);
    }

    IsEqual(dsb8, dsb);

    DIRECTRELEASE(dsb8);
    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}

VOID DirectSoundNotifyQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = module->DirectSoundCreate(NULL, &ds, NULL);
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
    desc.dwFlags = DSBCAPS_CTRLPOSITIONNOTIFY;
    desc.dwBufferBytes = 1024;
    desc.lpwfxFormat = &format;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    {
        LPDIRECTSOUNDNOTIFY dsn = NULL;
        result = dsb->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
        IsEqual(result, DS_OK);
        IsNotEqual(dsb, NULL);

        IsNotEqual((LPVOID)dsb, dsn);
        IsNotEqual((LPVOID)ds, dsn);

        {
            LPUNKNOWN unk = NULL;
            result = dsn->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
            IsEqual(result, DS_OK);
            IsNotEqual(unk, NULL);

            IsNotEqual(ds, unk);
            IsNotEqual(dsb, unk);
            IsNotEqual(dsn, unk);

            DIRECTRELEASE(unk);
        }

        DIRECTRELEASE(dsn);
    }

    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}

VOID DirectSoundNotify8QueryInterfaceIUnknown(LPMODULE module)
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
    desc.dwFlags = DSBCAPS_CTRLPOSITIONNOTIFY;
    desc.dwBufferBytes = 1024;
    desc.lpwfxFormat = &format;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    LPDIRECTSOUNDBUFFER8 dsb8 = NULL;
    result = dsb->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&dsb8);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb8, NULL);

    {
        LPDIRECTSOUNDNOTIFY dsn = NULL;
        result = dsb8->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
        IsEqual(result, DS_OK);
        IsNotEqual(dsb, NULL);

        IsNotEqual((LPVOID)dsb8, dsn);
        IsNotEqual((LPVOID)dsb, dsn);
        IsNotEqual((LPVOID)ds, dsn);

        {
            LPUNKNOWN unk = NULL;
            result = dsn->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
            IsEqual(result, DS_OK);
            IsNotEqual(unk, NULL);

            IsNotEqual(ds, unk);
            IsNotEqual(dsb, unk);
            IsNotEqual(dsn, unk);
            IsNotEqual(dsb8, unk);

            DIRECTRELEASE(unk);
        }

        DIRECTRELEASE(dsn);
    }

    IsEqual(dsb8, dsb);

    DIRECTRELEASE(dsb8);
    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}

VOID DirectSoundNotifyQuery(LPDIRECTSOUNDNOTIFY notify, const BOOL eight)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = notify->QueryInterface(IID_IDirectSound, (LPVOID*)&ds);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds, NULL);

    LPDIRECTSOUND3DBUFFER ds3db = NULL;
    result = notify->QueryInterface(IID_IDirectSound3DBuffer, (LPVOID*)&ds3db);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds3db, NULL);

    LPDIRECTSOUND3DLISTENER ds3dl = NULL;
    result = notify->QueryInterface(IID_IDirectSound3DListener, (LPVOID*)&ds3dl);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds3dl, NULL);

    LPDIRECTSOUND8 ds8 = NULL;
    result = notify->QueryInterface(IID_IDirectSound8, (LPVOID*)&ds8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds8, NULL);

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = notify->QueryInterface(IID_IDirectSoundBuffer, (LPVOID*)&dsb);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)dsb, NULL);
    IsNotEqual((LPVOID)dsb, notify);
    DIRECTRELEASE(dsb);

    LPDIRECTSOUNDBUFFER dsb8 = NULL;
    result = notify->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&dsb8);

    if (eight)
    {
        IsEqual(result, DS_OK);
        IsNotEqual((LPVOID)dsb8, NULL);
        IsNotEqual((LPVOID)dsb8, notify);
        DIRECTRELEASE(dsb8);
    }
    else
    {
        IsNotEqual(result, DS_OK);
        IsEqual((LPVOID)dsb8, NULL);
    }

    LPDIRECTSOUNDCAPTURE dsc = NULL;
    result = notify->QueryInterface(IID_IDirectSoundCapture, (LPVOID*)&dsc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsc, NULL);

    LPDIRECTSOUNDCAPTUREBUFFER dscb = NULL;
    result = notify->QueryInterface(IID_IDirectSoundCaptureBuffer, (LPVOID*)&dscb);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscb, NULL);

    LPDIRECTSOUNDCAPTUREBUFFER8 dscb8 = NULL;
    result = notify->QueryInterface(IID_IDirectSoundCaptureBuffer8, (LPVOID*)&dscb8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscb8, NULL);

    LPDIRECTSOUNDCAPTUREFXAEC dscfxeac = NULL;
    result = notify->QueryInterface(IID_IDirectSoundCaptureFXAec, (LPVOID*)&dscfxeac);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscfxeac, NULL);

    LPDIRECTSOUNDCAPTUREFXNOISESUPPRESS dscfxns = NULL;
    result = notify->QueryInterface(IID_IDirectSoundCaptureFXNoiseSuppress, (LPVOID*)&dscfxns);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscfxns, NULL);

    LPDIRECTSOUNDFXCHORUS dsfxc = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXChorus, (LPVOID*)&dsfxc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxc, NULL);

    LPDIRECTSOUNDFXCOMPRESSOR dsfxcomp = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXCompressor, (LPVOID*)&dsfxcomp);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxcomp, NULL);

    LPDIRECTSOUNDFXDISTORTION dsfxdist = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXDistortion, (LPVOID*)&dsfxdist);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxdist, NULL);

    LPDIRECTSOUNDFXECHO dsfxecho = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXEcho, (LPVOID*)&dsfxecho);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxecho, NULL);

    LPDIRECTSOUNDFXFLANGER dsfxfl = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXFlanger, (LPVOID*)&dsfxfl);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxfl, NULL);

    LPDIRECTSOUNDFXGARGLE dsfxg = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXGargle, (LPVOID*)&dsfxg);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxg, NULL);

    LPDIRECTSOUNDFXI3DL2REVERB dsfx3dr = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXI3DL2Reverb, (LPVOID*)&dsfx3dr);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfx3dr, NULL);

    LPDIRECTSOUNDFXPARAMEQ dsfxpq = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXParamEq, (LPVOID*)&dsfxpq);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxpq, NULL);

    LPDIRECTSOUNDFXWAVESREVERB dsfxwr = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFXWavesReverb, (LPVOID*)&dsfxwr);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxwr, NULL);

    LPDIRECTSOUNDFULLDUPLEX dsfxfd = NULL;
    result = notify->QueryInterface(IID_IDirectSoundFullDuplex, (LPVOID*)&dsfxfd);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxfd, NULL);

    LPDIRECTSOUNDNOTIFY dsn = NULL;
    result = notify->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)dsn, NULL);
    IsEqual((LPVOID)dsn, notify);
    DIRECTRELEASE(dsn);

    LPKSPROPERTYSET ksp = NULL;
    result = notify->QueryInterface(IID_IKsPropertySet, (LPVOID*)&ksp);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)ksp, NULL);
    IsNotEqual((LPVOID)ksp, notify);
    DIRECTRELEASE(ksp);

    LPREFERENCECLOCK rc = NULL;
    result = notify->QueryInterface(IID_IReferenceClock, (LPVOID*)&rc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)rc, NULL);

    LPUNKNOWN unk = NULL;
    result = notify->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)unk, NULL);
    DIRECTRELEASE(unk);
}

VOID DirectSoundNotifyQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = module->DirectSoundCreate(NULL, &ds, NULL);
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
    desc.dwFlags = DSBCAPS_CTRLPOSITIONNOTIFY;
    desc.dwBufferBytes = 1024;
    desc.lpwfxFormat = &format;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    {
        LPDIRECTSOUNDNOTIFY dsn = NULL;
        result = dsb->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
        IsEqual(result, DS_OK);
        IsNotEqual(dsb, NULL);

        IsNotEqual((LPVOID)dsb, dsn);
        IsNotEqual((LPVOID)ds, dsn);

        DirectSoundNotifyQuery(dsn, FALSE);

        DIRECTRELEASE(dsn);
    }

    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}

VOID DirectSoundNotify8QueryInterfaceAll(LPMODULE module)
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
    desc.dwFlags = DSBCAPS_CTRLPOSITIONNOTIFY;
    desc.dwBufferBytes = 1024;
    desc.lpwfxFormat = &format;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    LPDIRECTSOUNDBUFFER8 dsb8 = NULL;
    result = dsb->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&dsb8);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb8, NULL);

    {
        LPDIRECTSOUNDNOTIFY dsn = NULL;
        result = dsb8->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
        IsEqual(result, DS_OK);
        IsNotEqual(dsb, NULL);

        IsNotEqual((LPVOID)dsb8, dsn);
        IsNotEqual((LPVOID)dsb, dsn);
        IsNotEqual((LPVOID)ds, dsn);

        DirectSoundNotifyQuery(dsn, TRUE);

        DIRECTRELEASE(dsn);
    }

    IsEqual(dsb8, dsb);

    DIRECTRELEASE(dsb8);
    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}
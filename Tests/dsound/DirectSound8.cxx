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

#include "DirectSound8.hxx"

VOID DirectSound8Create(LPMODULE module)
{
    LPDIRECTSOUND8 ds = NULL;
    HRESULT result = module->DirectSoundCreate8(NULL, &ds, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(ds, NULL);

    ds->AddRef();
    IsEqual(ds->Release(), 1);

    DIRECTRELEASE(ds);
}

VOID DirectSound8QueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTSOUND8 ds = NULL;
    HRESULT result = module->DirectSoundCreate8(NULL, &ds, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(ds, NULL);

    ds->AddRef();
    IsEqual(ds->Release(), 1);

    {
        LPUNKNOWN unk = NULL;
        result = ds->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
        IsEqual(result, DS_OK);
        IsNotEqual(ds, NULL);

        IsNotEqual(ds, unk);

        DIRECTRELEASE(unk);
    }

    DIRECTRELEASE(ds);
}

VOID DirectSound8Query(LPDIRECTSOUND8 sound)
{
    LPDIRECTSOUND8 ds = NULL;
    HRESULT result = sound->QueryInterface(IID_IDirectSound, (LPVOID*)&ds);
    IsEqual(result, DS_OK);
    IsEqual((LPVOID)ds, sound);
    DIRECTRELEASE(ds);

    LPDIRECTSOUND3DBUFFER ds3db = NULL;
    result = sound->QueryInterface(IID_IDirectSound3DBuffer, (LPVOID*)&ds3db);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds3db, NULL);

    LPDIRECTSOUND3DLISTENER ds3dl = NULL;
    result = sound->QueryInterface(IID_IDirectSound3DListener, (LPVOID*)&ds3dl);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds3dl, NULL);

    LPDIRECTSOUND8 ds8 = NULL;
    result = sound->QueryInterface(IID_IDirectSound8, (LPVOID*)&ds8);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)ds8, NULL);
    IsEqual((LPVOID)ds8, sound);
    DIRECTRELEASE(ds8);

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = sound->QueryInterface(IID_IDirectSoundBuffer, (LPVOID*)&dsb);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsb, NULL);

    LPDIRECTSOUNDBUFFER dsb8 = NULL;
    result = sound->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&dsb8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsb8, NULL);

    LPDIRECTSOUNDCAPTURE dsc = NULL;
    result = sound->QueryInterface(IID_IDirectSoundCapture, (LPVOID*)&dsc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsc, NULL);

    LPDIRECTSOUNDCAPTUREBUFFER dscb = NULL;
    result = sound->QueryInterface(IID_IDirectSoundCaptureBuffer, (LPVOID*)&dscb);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscb, NULL);

    LPDIRECTSOUNDCAPTUREBUFFER8 dscb8 = NULL;
    result = sound->QueryInterface(IID_IDirectSoundCaptureBuffer8, (LPVOID*)&dscb8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscb8, NULL);

    LPDIRECTSOUNDCAPTUREFXAEC dscfxeac = NULL;
    result = sound->QueryInterface(IID_IDirectSoundCaptureFXAec, (LPVOID*)&dscfxeac);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscfxeac, NULL);

    LPDIRECTSOUNDCAPTUREFXNOISESUPPRESS dscfxns = NULL;
    result = sound->QueryInterface(IID_IDirectSoundCaptureFXNoiseSuppress, (LPVOID*)&dscfxns);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscfxns, NULL);

    LPDIRECTSOUNDFXCHORUS dsfxc = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXChorus, (LPVOID*)&dsfxc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxc, NULL);

    LPDIRECTSOUNDFXCOMPRESSOR dsfxcomp = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXCompressor, (LPVOID*)&dsfxcomp);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxcomp, NULL);

    LPDIRECTSOUNDFXDISTORTION dsfxdist = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXDistortion, (LPVOID*)&dsfxdist);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxdist, NULL);

    LPDIRECTSOUNDFXECHO dsfxecho = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXEcho, (LPVOID*)&dsfxecho);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxecho, NULL);

    LPDIRECTSOUNDFXFLANGER dsfxfl = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXFlanger, (LPVOID*)&dsfxfl);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxfl, NULL);

    LPDIRECTSOUNDFXGARGLE dsfxg = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXGargle, (LPVOID*)&dsfxg);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxg, NULL);

    LPDIRECTSOUNDFXI3DL2REVERB dsfx3dr = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXI3DL2Reverb, (LPVOID*)&dsfx3dr);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfx3dr, NULL);

    LPDIRECTSOUNDFXPARAMEQ dsfxpq = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXParamEq, (LPVOID*)&dsfxpq);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxpq, NULL);

    LPDIRECTSOUNDFXWAVESREVERB dsfxwr = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFXWavesReverb, (LPVOID*)&dsfxwr);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxwr, NULL);

    LPDIRECTSOUNDFULLDUPLEX dsfxfd = NULL;
    result = sound->QueryInterface(IID_IDirectSoundFullDuplex, (LPVOID*)&dsfxfd);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxfd, NULL);

    LPDIRECTSOUNDNOTIFY dsn = NULL;
    result = sound->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsn, NULL);

    LPKSPROPERTYSET ksp = NULL;
    result = sound->QueryInterface(IID_IKsPropertySet, (LPVOID*)&ksp);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ksp, NULL);

    LPREFERENCECLOCK rc = NULL;
    result = sound->QueryInterface(IID_IReferenceClock, (LPVOID*)&rc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)rc, NULL);

    LPUNKNOWN unk = NULL;
    result = sound->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)unk, NULL);
    DIRECTRELEASE(unk);
}

VOID DirectSound8QueryInterfaceAll(LPMODULE module)
{
    LPDIRECTSOUND8 ds = NULL;
    HRESULT result = module->DirectSoundCreate8(NULL, &ds, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(ds, NULL);

    ds->AddRef();
    IsEqual(ds->Release(), 1);

    DirectSound8Query(ds);

    DIRECTRELEASE(ds);
}
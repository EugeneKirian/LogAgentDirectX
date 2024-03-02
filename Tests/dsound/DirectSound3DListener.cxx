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

#include "DirectSound3DListener.hxx"

VOID DirectSound3DListenerCreate(LPMODULE module)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = module->DirectSoundCreate(NULL, &ds, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(ds, NULL);

    ds->AddRef();
    IsEqual(ds->Release(), 1);

    DSBUFFERDESC desc;
    ZeroMemory(&desc, sizeof(DSBUFFERDESC));

    desc.dwSize = sizeof(DSBUFFERDESC);
    desc.dwFlags = DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    LPDIRECTSOUND3DLISTENER ds3dl = NULL;
    result = dsb->QueryInterface(IID_IDirectSound3DListener, (LPVOID*)&ds3dl);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    IsNotEqual((LPVOID)ds, dsb);
    IsNotEqual((LPVOID)dsb, ds3dl);

    DIRECTRELEASE(ds3dl);
    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}

VOID DirectSound3DListenerQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = module->DirectSoundCreate(NULL, &ds, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(ds, NULL);

    ds->AddRef();
    IsEqual(ds->Release(), 1);

    DSBUFFERDESC desc;
    ZeroMemory(&desc, sizeof(DSBUFFERDESC));

    desc.dwSize = sizeof(DSBUFFERDESC);
    desc.dwFlags = DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    LPDIRECTSOUND3DLISTENER ds3dl = NULL;
    result = dsb->QueryInterface(IID_IDirectSound3DListener, (LPVOID*)&ds3dl);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    IsNotEqual((LPVOID)ds, dsb);
    IsNotEqual((LPVOID)dsb, ds3dl);

    {
        LPUNKNOWN unk = NULL;
        result = ds3dl->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
        IsEqual(result, DS_OK);
        IsNotEqual(unk, NULL);

        IsNotEqual(ds, unk);
        IsNotEqual(dsb, unk);
        IsNotEqual(ds3dl, unk);

        DIRECTRELEASE(unk);
    }

    DIRECTRELEASE(ds3dl);
    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}

VOID DirectSound3DListenerQuery(LPDIRECTSOUND3DLISTENER listener)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = listener->QueryInterface(IID_IDirectSound, (LPVOID*)&ds);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds, NULL);

    LPDIRECTSOUND3DBUFFER ds3db = NULL;
    result = listener->QueryInterface(IID_IDirectSound3DBuffer, (LPVOID*)&ds3db);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds3db, NULL);

    LPDIRECTSOUND3DLISTENER ds3dl = NULL;
    result = listener->QueryInterface(IID_IDirectSound3DListener, (LPVOID*)&ds3dl);
    IsEqual(result, DS_OK);
    IsEqual((LPVOID)ds3dl, listener);
    DIRECTRELEASE(ds3dl);

    LPDIRECTSOUND8 ds8 = NULL;
    result = listener->QueryInterface(IID_IDirectSound8, (LPVOID*)&ds8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds8, NULL);

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = listener->QueryInterface(IID_IDirectSoundBuffer, (LPVOID*)&dsb);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)dsb, listener);
    DIRECTRELEASE(dsb);

    LPDIRECTSOUNDBUFFER dsb8 = NULL;
    result = listener->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&dsb8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsb8, NULL);

    LPDIRECTSOUNDCAPTURE dsc = NULL;
    result = listener->QueryInterface(IID_IDirectSoundCapture, (LPVOID*)&dsc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsc, NULL);

    LPDIRECTSOUNDCAPTUREBUFFER dscb = NULL;
    result = listener->QueryInterface(IID_IDirectSoundCaptureBuffer, (LPVOID*)&dscb);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscb, NULL);

    LPDIRECTSOUNDCAPTUREBUFFER8 dscb8 = NULL;
    result = listener->QueryInterface(IID_IDirectSoundCaptureBuffer8, (LPVOID*)&dscb8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscb8, NULL);

    LPDIRECTSOUNDCAPTUREFXAEC dscfxeac = NULL;
    result = listener->QueryInterface(IID_IDirectSoundCaptureFXAec, (LPVOID*)&dscfxeac);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscfxeac, NULL);

    LPDIRECTSOUNDCAPTUREFXNOISESUPPRESS dscfxns = NULL;
    result = listener->QueryInterface(IID_IDirectSoundCaptureFXNoiseSuppress, (LPVOID*)&dscfxns);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscfxns, NULL);

    LPDIRECTSOUNDFXCHORUS dsfxc = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXChorus, (LPVOID*)&dsfxc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxc, NULL);

    LPDIRECTSOUNDFXCOMPRESSOR dsfxcomp = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXCompressor, (LPVOID*)&dsfxcomp);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxcomp, NULL);

    LPDIRECTSOUNDFXDISTORTION dsfxdist = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXDistortion, (LPVOID*)&dsfxdist);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxdist, NULL);

    LPDIRECTSOUNDFXECHO dsfxecho = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXEcho, (LPVOID*)&dsfxecho);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxecho, NULL);

    LPDIRECTSOUNDFXFLANGER dsfxfl = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXFlanger, (LPVOID*)&dsfxfl);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxfl, NULL);

    LPDIRECTSOUNDFXGARGLE dsfxg = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXGargle, (LPVOID*)&dsfxg);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxg, NULL);

    LPDIRECTSOUNDFXI3DL2REVERB dsfx3dr = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXI3DL2Reverb, (LPVOID*)&dsfx3dr);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfx3dr, NULL);

    LPDIRECTSOUNDFXPARAMEQ dsfxpq = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXParamEq, (LPVOID*)&dsfxpq);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxpq, NULL);

    LPDIRECTSOUNDFXWAVESREVERB dsfxwr = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFXWavesReverb, (LPVOID*)&dsfxwr);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxwr, NULL);

    LPDIRECTSOUNDFULLDUPLEX dsfxfd = NULL;
    result = listener->QueryInterface(IID_IDirectSoundFullDuplex, (LPVOID*)&dsfxfd);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxfd, NULL);

    LPDIRECTSOUNDNOTIFY dsn = NULL;
    result = listener->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsn, NULL);

    LPKSPROPERTYSET ksp = NULL;
    result = listener->QueryInterface(IID_IKsPropertySet, (LPVOID*)&ksp);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)ksp, listener);
    DIRECTRELEASE(ksp);

    LPREFERENCECLOCK rc = NULL;
    result = listener->QueryInterface(IID_IReferenceClock, (LPVOID*)&rc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)rc, NULL);

    LPUNKNOWN unk = NULL;
    result = listener->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)unk, NULL);
    DIRECTRELEASE(unk);
}

VOID DirectSound3DListenerQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = module->DirectSoundCreate(NULL, &ds, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(ds, NULL);

    ds->AddRef();
    IsEqual(ds->Release(), 1);

    DSBUFFERDESC desc;
    ZeroMemory(&desc, sizeof(DSBUFFERDESC));

    desc.dwSize = sizeof(DSBUFFERDESC);
    desc.dwFlags = DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER;

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = ds->CreateSoundBuffer(&desc, &dsb, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    LPDIRECTSOUND3DLISTENER ds3dl = NULL;
    result = dsb->QueryInterface(IID_IDirectSound3DListener, (LPVOID*)&ds3dl);
    IsEqual(result, DS_OK);
    IsNotEqual(dsb, NULL);

    IsNotEqual((LPVOID)ds, dsb);
    IsNotEqual((LPVOID)dsb, ds3dl);

    DirectSound3DListenerQuery(ds3dl);

    DIRECTRELEASE(ds3dl);
    DIRECTRELEASE(dsb);
    DIRECTRELEASE(ds);
}
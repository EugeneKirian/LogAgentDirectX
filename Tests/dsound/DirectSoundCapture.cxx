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

#include "DirectSoundCapture.hxx"

VOID DirectSoundCaptureCreate(LPMODULE module)
{
    LPDIRECTSOUNDCAPTURE dsc = NULL;
    HRESULT result = module->DirectSoundCaptureCreate(NULL, &dsc, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsc, NULL);

    dsc->AddRef();
    IsEqual(dsc->Release(), 1);

    DIRECTRELEASE(dsc);
}

VOID DirectSoundCaptureQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTSOUNDCAPTURE dsc = NULL;
    HRESULT result = module->DirectSoundCaptureCreate(NULL, &dsc, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsc, NULL);

    dsc->AddRef();
    IsEqual(dsc->Release(), 1);

    {
        LPUNKNOWN unk = NULL;
        result = dsc->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
        IsEqual(result, DS_OK);
        IsNotEqual(dsc, NULL);

        IsNotEqual(dsc, unk);

        DIRECTRELEASE(unk);
    }

    DIRECTRELEASE(dsc);
}

VOID DirectSoundCaptureQuery(LPDIRECTSOUNDCAPTURE capture)
{
    LPDIRECTSOUND ds = NULL;
    HRESULT result = capture->QueryInterface(IID_IDirectSound, (LPVOID*)&ds);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds, NULL);

    LPDIRECTSOUND3DBUFFER ds3db = NULL;
    result = capture->QueryInterface(IID_IDirectSound3DBuffer, (LPVOID*)&ds3db);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds3db, NULL);

    LPDIRECTSOUND3DLISTENER ds3dl = NULL;
    result = capture->QueryInterface(IID_IDirectSound3DListener, (LPVOID*)&ds3dl);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds3dl, NULL);

    LPDIRECTSOUND8 ds8 = NULL;
    result = capture->QueryInterface(IID_IDirectSound8, (LPVOID*)&ds8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ds8, NULL);

    LPDIRECTSOUNDBUFFER dsb = NULL;
    result = capture->QueryInterface(IID_IDirectSoundBuffer, (LPVOID*)&dsb);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsb, NULL);

    LPDIRECTSOUNDBUFFER dsb8 = NULL;
    result = capture->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&dsb8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsb8, NULL);

    LPDIRECTSOUNDCAPTURE dsc = NULL;
    result = capture->QueryInterface(IID_IDirectSoundCapture, (LPVOID*)&dsc);
    IsEqual(result, DS_OK);
    IsEqual((LPVOID)dsc, capture);
    DIRECTRELEASE(dsc);

    LPDIRECTSOUNDCAPTUREBUFFER dscb = NULL;
    result = capture->QueryInterface(IID_IDirectSoundCaptureBuffer, (LPVOID*)&dscb);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscb, NULL);

    LPDIRECTSOUNDCAPTUREBUFFER8 dscb8 = NULL;
    result = capture->QueryInterface(IID_IDirectSoundCaptureBuffer8, (LPVOID*)&dscb8);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscb8, NULL);

    LPDIRECTSOUNDCAPTUREFXAEC dscfxeac = NULL;
    result = capture->QueryInterface(IID_IDirectSoundCaptureFXAec, (LPVOID*)&dscfxeac);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscfxeac, NULL);

    LPDIRECTSOUNDCAPTUREFXNOISESUPPRESS dscfxns = NULL;
    result = capture->QueryInterface(IID_IDirectSoundCaptureFXNoiseSuppress, (LPVOID*)&dscfxns);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dscfxns, NULL);

    LPDIRECTSOUNDFXCHORUS dsfxc = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXChorus, (LPVOID*)&dsfxc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxc, NULL);

    LPDIRECTSOUNDFXCOMPRESSOR dsfxcomp = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXCompressor, (LPVOID*)&dsfxcomp);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxcomp, NULL);

    LPDIRECTSOUNDFXDISTORTION dsfxdist = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXDistortion, (LPVOID*)&dsfxdist);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxdist, NULL);

    LPDIRECTSOUNDFXECHO dsfxecho = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXEcho, (LPVOID*)&dsfxecho);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxecho, NULL);

    LPDIRECTSOUNDFXFLANGER dsfxfl = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXFlanger, (LPVOID*)&dsfxfl);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxfl, NULL);

    LPDIRECTSOUNDFXGARGLE dsfxg = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXGargle, (LPVOID*)&dsfxg);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxg, NULL);

    LPDIRECTSOUNDFXI3DL2REVERB dsfx3dr = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXI3DL2Reverb, (LPVOID*)&dsfx3dr);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfx3dr, NULL);

    LPDIRECTSOUNDFXPARAMEQ dsfxpq = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXParamEq, (LPVOID*)&dsfxpq);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxpq, NULL);

    LPDIRECTSOUNDFXWAVESREVERB dsfxwr = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFXWavesReverb, (LPVOID*)&dsfxwr);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxwr, NULL);

    LPDIRECTSOUNDFULLDUPLEX dsfxfd = NULL;
    result = capture->QueryInterface(IID_IDirectSoundFullDuplex, (LPVOID*)&dsfxfd);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsfxfd, NULL);

    LPDIRECTSOUNDNOTIFY dsn = NULL;
    result = capture->QueryInterface(IID_IDirectSoundNotify, (LPVOID*)&dsn);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)dsn, NULL);

    LPKSPROPERTYSET ksp = NULL;
    result = capture->QueryInterface(IID_IKsPropertySet, (LPVOID*)&ksp);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)ksp, NULL);

    LPREFERENCECLOCK rc = NULL;
    result = capture->QueryInterface(IID_IReferenceClock, (LPVOID*)&rc);
    IsNotEqual(result, DS_OK);
    IsEqual((LPVOID)rc, NULL);

    LPUNKNOWN unk = NULL;
    result = capture->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DS_OK);
    IsNotEqual((LPVOID)unk, NULL);
    DIRECTRELEASE(unk);
}

VOID DirectSoundCaptureQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTSOUNDCAPTURE dsc = NULL;
    HRESULT result = module->DirectSoundCaptureCreate(NULL, &dsc, NULL);
    IsEqual(result, DS_OK);
    IsNotEqual(dsc, NULL);

    dsc->AddRef();
    IsEqual(dsc->Release(), 1);

    DirectSoundCaptureQuery(dsc);

    DIRECTRELEASE(dsc);
}
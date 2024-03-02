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

#pragma once

#define OBJECT_ID_Module                                                0

#define METHOD_ID_Module_DirectSoundCreate                              0
#define METHOD_ID_Module_DirectSoundEnumerateA                          1
#define METHOD_ID_Module_DirectSoundEnumerateW                          2
#define METHOD_ID_Module_DllCanUnloadNow                                3
#define METHOD_ID_Module_DllGetClassObject                              4
#define METHOD_ID_Module_DirectSoundCaptureCreate                       5
#define METHOD_ID_Module_DirectSoundCaptureEnumerateA                   6
#define METHOD_ID_Module_DirectSoundCaptureEnumerateW                   7
#define METHOD_ID_Module_GetDeviceID                                    8
#define METHOD_ID_Module_DirectSoundFullDuplexCreate                    9
#define METHOD_ID_Module_DirectSoundCreate8                             10
#define METHOD_ID_Module_DirectSoundCaptureCreate8                      11

#define METHODCALLBACK_ID_Module_DirectSoundEnumerateA                  0
#define METHODCALLBACK_ID_Module_DirectSoundEnumerateW                  1
#define METHODCALLBACK_ID_Module_DirectSoundCaptureEnumerateA           2
#define METHODCALLBACK_ID_Module_DirectSoundCaptureEnumerateW           3

#define OBJECT_ID_DirectSound                                           1

#define METHOD_ID_DirectSound_QueryInterface                            0
#define METHOD_ID_DirectSound_AddRef                                    1
#define METHOD_ID_DirectSound_Release                                   2
#define METHOD_ID_DirectSound_CreateSoundBuffer                         3
#define METHOD_ID_DirectSound_GetCaps                                   4
#define METHOD_ID_DirectSound_DuplicateSoundBuffer                      5
#define METHOD_ID_DirectSound_SetCooperativeLevel                       6
#define METHOD_ID_DirectSound_Compact                                   7
#define METHOD_ID_DirectSound_GetSpeakerConfig                          8
#define METHOD_ID_DirectSound_SetSpeakerConfig                          9
#define METHOD_ID_DirectSound_Initialize                                10

#define OBJECT_ID_DirectSound8                                          2

#define METHOD_ID_DirectSound8_QueryInterface                           0
#define METHOD_ID_DirectSound8_AddRef                                   1
#define METHOD_ID_DirectSound8_Release                                  2
#define METHOD_ID_DirectSound8_CreateSoundBuffer                        3
#define METHOD_ID_DirectSound8_GetCaps                                  4
#define METHOD_ID_DirectSound8_DuplicateSoundBuffer                     5
#define METHOD_ID_DirectSound8_SetCooperativeLevel                      6
#define METHOD_ID_DirectSound8_Compact                                  7
#define METHOD_ID_DirectSound8_GetSpeakerConfig                         8
#define METHOD_ID_DirectSound8_SetSpeakerConfig                         9
#define METHOD_ID_DirectSound8_Initialize                               10
#define METHOD_ID_DirectSound8_VerifyCertification                      11

#define OBJECT_ID_DirectSoundBuffer                                     3

#define METHOD_ID_DirectSoundBuffer_QueryInterface                      0
#define METHOD_ID_DirectSoundBuffer_AddRef                              1
#define METHOD_ID_DirectSoundBuffer_Release                             2
#define METHOD_ID_DirectSoundBuffer_GetCaps                             3
#define METHOD_ID_DirectSoundBuffer_GetCurrentPosition                  4
#define METHOD_ID_DirectSoundBuffer_GetFormat                           5
#define METHOD_ID_DirectSoundBuffer_GetVolume                           6
#define METHOD_ID_DirectSoundBuffer_GetPan                              7
#define METHOD_ID_DirectSoundBuffer_GetFrequency                        8
#define METHOD_ID_DirectSoundBuffer_GetStatus                           9
#define METHOD_ID_DirectSoundBuffer_Initialize                          10
#define METHOD_ID_DirectSoundBuffer_Lock                                11
#define METHOD_ID_DirectSoundBuffer_Play                                12
#define METHOD_ID_DirectSoundBuffer_SetCurrentPosition                  13
#define METHOD_ID_DirectSoundBuffer_SetFormat                           14
#define METHOD_ID_DirectSoundBuffer_SetVolume                           15
#define METHOD_ID_DirectSoundBuffer_SetPan                              16
#define METHOD_ID_DirectSoundBuffer_SetFrequency                        17
#define METHOD_ID_DirectSoundBuffer_Stop                                18
#define METHOD_ID_DirectSoundBuffer_Unlock                              19
#define METHOD_ID_DirectSoundBuffer_Restore                             20

#define OBJECT_ID_DirectSoundBuffer8                                    4

#define METHOD_ID_DirectSoundBuffer8_QueryInterface                     0
#define METHOD_ID_DirectSoundBuffer8_AddRef                             1
#define METHOD_ID_DirectSoundBuffer8_Release                            2
#define METHOD_ID_DirectSoundBuffer8_GetCaps                            3
#define METHOD_ID_DirectSoundBuffer8_GetCurrentPosition                 4
#define METHOD_ID_DirectSoundBuffer8_GetFormat                          5
#define METHOD_ID_DirectSoundBuffer8_GetVolume                          6
#define METHOD_ID_DirectSoundBuffer8_GetPan                             7
#define METHOD_ID_DirectSoundBuffer8_GetFrequency                       8
#define METHOD_ID_DirectSoundBuffer8_GetStatus                          9
#define METHOD_ID_DirectSoundBuffer8_Initialize                         10
#define METHOD_ID_DirectSoundBuffer8_Lock                               11
#define METHOD_ID_DirectSoundBuffer8_Play                               12
#define METHOD_ID_DirectSoundBuffer8_SetCurrentPosition                 13
#define METHOD_ID_DirectSoundBuffer8_SetFormat                          14
#define METHOD_ID_DirectSoundBuffer8_SetVolume                          15
#define METHOD_ID_DirectSoundBuffer8_SetPan                             16
#define METHOD_ID_DirectSoundBuffer8_SetFrequency                       17
#define METHOD_ID_DirectSoundBuffer8_Stop                               18
#define METHOD_ID_DirectSoundBuffer8_Unlock                             19
#define METHOD_ID_DirectSoundBuffer8_Restore                            20
#define METHOD_ID_DirectSoundBuffer8_SetFX                              21
#define METHOD_ID_DirectSoundBuffer8_AcquireResources                   22
#define METHOD_ID_DirectSoundBuffer8_GetObjectInPath                    23

#define OBJECT_ID_DirectSound3DBuffer                                   5

#define METHOD_ID_DirectSound3DBuffer_QueryInterface                    0
#define METHOD_ID_DirectSound3DBuffer_AddRef                            1
#define METHOD_ID_DirectSound3DBuffer_Release                           2
#define METHOD_ID_DirectSound3DBuffer_GetAllParameters                  3
#define METHOD_ID_DirectSound3DBuffer_GetConeAngles                     4
#define METHOD_ID_DirectSound3DBuffer_GetConeOrientation                5
#define METHOD_ID_DirectSound3DBuffer_GetConeOutsideVolume              6
#define METHOD_ID_DirectSound3DBuffer_GetMaxDistance                    7
#define METHOD_ID_DirectSound3DBuffer_GetMinDistance                    8
#define METHOD_ID_DirectSound3DBuffer_GetMode                           9
#define METHOD_ID_DirectSound3DBuffer_GetPosition                       10
#define METHOD_ID_DirectSound3DBuffer_GetVelocity                       11
#define METHOD_ID_DirectSound3DBuffer_SetAllParameters                  12
#define METHOD_ID_DirectSound3DBuffer_SetConeAngles                     13
#define METHOD_ID_DirectSound3DBuffer_SetConeOrientation                14
#define METHOD_ID_DirectSound3DBuffer_SetConeOutsideVolume              15
#define METHOD_ID_DirectSound3DBuffer_SetMaxDistance                    16
#define METHOD_ID_DirectSound3DBuffer_SetMinDistance                    17
#define METHOD_ID_DirectSound3DBuffer_SetMode                           18
#define METHOD_ID_DirectSound3DBuffer_SetPosition                       19
#define METHOD_ID_DirectSound3DBuffer_SetVelocity                       20

#define OBJECT_ID_DirectSound3DListener                                 6

#define METHOD_ID_DirectSound3DListener_QueryInterface                  0
#define METHOD_ID_DirectSound3DListener_AddRef                          1
#define METHOD_ID_DirectSound3DListener_Release                         2
#define METHOD_ID_DirectSound3DListener_GetAllParameters                3
#define METHOD_ID_DirectSound3DListener_GetDistanceFactor               4
#define METHOD_ID_DirectSound3DListener_GetDopplerFactor                5
#define METHOD_ID_DirectSound3DListener_GetOrientation                  6
#define METHOD_ID_DirectSound3DListener_GetPosition                     7
#define METHOD_ID_DirectSound3DListener_GetRolloffFactor                8
#define METHOD_ID_DirectSound3DListener_GetVelocity                     9    
#define METHOD_ID_DirectSound3DListener_SetAllParameters                10
#define METHOD_ID_DirectSound3DListener_SetDistanceFactor               11
#define METHOD_ID_DirectSound3DListener_SetDopplerFactor                12
#define METHOD_ID_DirectSound3DListener_SetOrientation                  13
#define METHOD_ID_DirectSound3DListener_SetPosition                     14
#define METHOD_ID_DirectSound3DListener_SetRolloffFactor                15
#define METHOD_ID_DirectSound3DListener_SetVelocity                     16
#define METHOD_ID_DirectSound3DListener_CommitDeferredSettings          17

#define OBJECT_ID_DirectSoundCapture                                    7

#define METHOD_ID_DirectSoundCapture_QueryInterface                     0
#define METHOD_ID_DirectSoundCapture_AddRef                             1
#define METHOD_ID_DirectSoundCapture_Release                            2
#define METHOD_ID_DirectSoundCapture_CreateCaptureBuffer                3
#define METHOD_ID_DirectSoundCapture_GetCaps                            4
#define METHOD_ID_DirectSoundCapture_Initialize                         5

#define OBJECT_ID_DirectSoundCaptureBuffer                              8

#define METHOD_ID_DirectSoundCaptureBuffer_QueryInterface               0
#define METHOD_ID_DirectSoundCaptureBuffer_AddRef                       1
#define METHOD_ID_DirectSoundCaptureBuffer_Release                      2
#define METHOD_ID_DirectSoundCaptureBuffer_GetCaps                      3
#define METHOD_ID_DirectSoundCaptureBuffer_GetCurrentPosition           4
#define METHOD_ID_DirectSoundCaptureBuffer_GetFormat                    5
#define METHOD_ID_DirectSoundCaptureBuffer_GetStatus                    6
#define METHOD_ID_DirectSoundCaptureBuffer_Initialize                   7
#define METHOD_ID_DirectSoundCaptureBuffer_Lock                         8
#define METHOD_ID_DirectSoundCaptureBuffer_Start                        9
#define METHOD_ID_DirectSoundCaptureBuffer_Stop                         11
#define METHOD_ID_DirectSoundCaptureBuffer_Unlock                       12

#define OBJECT_ID_DirectSoundCaptureBuffer8                             9

#define METHOD_ID_DirectSoundCaptureBuffer8_QueryInterface              0
#define METHOD_ID_DirectSoundCaptureBuffer8_AddRef                      1
#define METHOD_ID_DirectSoundCaptureBuffer8_Release                     2
#define METHOD_ID_DirectSoundCaptureBuffer8_GetCaps                     3
#define METHOD_ID_DirectSoundCaptureBuffer8_GetCurrentPosition          4
#define METHOD_ID_DirectSoundCaptureBuffer8_GetFormat                   5
#define METHOD_ID_DirectSoundCaptureBuffer8_GetStatus                   6
#define METHOD_ID_DirectSoundCaptureBuffer8_Initialize                  7
#define METHOD_ID_DirectSoundCaptureBuffer8_Lock                        8
#define METHOD_ID_DirectSoundCaptureBuffer8_Start                       9
#define METHOD_ID_DirectSoundCaptureBuffer8_Stop                        11
#define METHOD_ID_DirectSoundCaptureBuffer8_Unlock                      12
#define METHOD_ID_DirectSoundCaptureBuffer8_GetObjectInPath             13
#define METHOD_ID_DirectSoundCaptureBuffer8_GetFXStatus                 14

#define OBJECT_ID_DirectSoundCaptureFXAec                               10

#define METHOD_ID_DirectSoundCaptureFXAec_QueryInterface                0
#define METHOD_ID_DirectSoundCaptureFXAec_AddRef                        1
#define METHOD_ID_DirectSoundCaptureFXAec_Release                       2
#define METHOD_ID_DirectSoundCaptureFXAec_SetAllParameters              3
#define METHOD_ID_DirectSoundCaptureFXAec_GetAllParameters              4
#define METHOD_ID_DirectSoundCaptureFXAec_GetStatus                     5
#define METHOD_ID_DirectSoundCaptureFXAec_Reset                         6

#define OBJECT_ID_DirectSoundCaptureFXNoiseSuppress                     11

#define METHOD_ID_DirectSoundCaptureFXNoiseSuppress_QueryInterface      0
#define METHOD_ID_DirectSoundCaptureFXNoiseSuppress_AddRef              1
#define METHOD_ID_DirectSoundCaptureFXNoiseSuppress_Release             2
#define METHOD_ID_DirectSoundCaptureFXNoiseSuppress_SetAllParameters    3
#define METHOD_ID_DirectSoundCaptureFXNoiseSuppress_GetAllParameters    4
#define METHOD_ID_DirectSoundCaptureFXNoiseSuppress_Reset               5

#define OBJECT_ID_DirectSoundFullDuplex                                 12

#define METHOD_ID_DirectSoundFullDuplex_QueryInterface                  0
#define METHOD_ID_DirectSoundFullDuplex_AddRef                          1
#define METHOD_ID_DirectSoundFullDuplex_Release                         2
#define METHOD_ID_DirectSoundFullDuplex_Initialize                      3

#define OBJECT_ID_DirectSoundFXChorus                                   13

#define METHOD_ID_DirectSoundFXChorus_QueryInterface                    0
#define METHOD_ID_DirectSoundFXChorus_AddRef                            1
#define METHOD_ID_DirectSoundFXChorus_Release                           2
#define METHOD_ID_DirectSoundFXChorus_SetAllParameters                  3
#define METHOD_ID_DirectSoundFXChorus_GetAllParameters                  4

#define OBJECT_ID_DirectSoundFXCompressor                               14

#define METHOD_ID_DirectSoundFXCompressor_QueryInterface                0
#define METHOD_ID_DirectSoundFXCompressor_AddRef                        1
#define METHOD_ID_DirectSoundFXCompressor_Release                       2
#define METHOD_ID_DirectSoundFXCompressor_SetAllParameters              3
#define METHOD_ID_DirectSoundFXCompressor_GetAllParameters              4

#define OBJECT_ID_DirectSoundFXDistortion                               15

#define METHOD_ID_DirectSoundFXDistortion_QueryInterface                0
#define METHOD_ID_DirectSoundFXDistortion_AddRef                        1
#define METHOD_ID_DirectSoundFXDistortion_Release                       2
#define METHOD_ID_DirectSoundFXDistortion_SetAllParameters              3
#define METHOD_ID_DirectSoundFXDistortion_GetAllParameters              4

#define OBJECT_ID_DirectSoundFXEcho                                     16

#define METHOD_ID_DirectSoundFXEcho_QueryInterface                      0
#define METHOD_ID_DirectSoundFXEcho_AddRef                              1
#define METHOD_ID_DirectSoundFXEcho_Release                             2
#define METHOD_ID_DirectSoundFXEcho_SetAllParameters                    3
#define METHOD_ID_DirectSoundFXEcho_GetAllParameters                    4

#define OBJECT_ID_DirectSoundFXFlanger                                  17

#define METHOD_ID_DirectSoundFXFlanger_QueryInterface                   0
#define METHOD_ID_DirectSoundFXFlanger_AddRef                           1
#define METHOD_ID_DirectSoundFXFlanger_Release                          2
#define METHOD_ID_DirectSoundFXFlanger_SetAllParameters                 3
#define METHOD_ID_DirectSoundFXFlanger_GetAllParameters                 4

#define OBJECT_ID_DirectSoundFXGargle                                   18

#define METHOD_ID_DirectSoundFXGargle_QueryInterface                    0
#define METHOD_ID_DirectSoundFXGargle_AddRef                            1
#define METHOD_ID_DirectSoundFXGargle_Release                           2
#define METHOD_ID_DirectSoundFXGargle_SetAllParameters                  3
#define METHOD_ID_DirectSoundFXGargle_GetAllParameters                  4

#define OBJECT_ID_DirectSoundFXI3DL2Reverb                              19

#define METHOD_ID_DirectSoundFXI3DL2Reverb_QueryInterface               0
#define METHOD_ID_DirectSoundFXI3DL2Reverb_AddRef                       1
#define METHOD_ID_DirectSoundFXI3DL2Reverb_Release                      2
#define METHOD_ID_DirectSoundFXI3DL2Reverb_SetAllParameters             3
#define METHOD_ID_DirectSoundFXI3DL2Reverb_GetAllParameters             4
#define METHOD_ID_DirectSoundFXI3DL2Reverb_SetPreset                    5
#define METHOD_ID_DirectSoundFXI3DL2Reverb_GetPreset                    6
#define METHOD_ID_DirectSoundFXI3DL2Reverb_SetQuality                   7
#define METHOD_ID_DirectSoundFXI3DL2Reverb_GetQuality                   8

#define OBJECT_ID_DirectSoundFXParamEq                                  20

#define METHOD_ID_DirectSoundFXParamEq_QueryInterface                   0
#define METHOD_ID_DirectSoundFXParamEq_AddRef                           1
#define METHOD_ID_DirectSoundFXParamEq_Release                          2
#define METHOD_ID_DirectSoundFXParamEq_SetAllParameters                 3
#define METHOD_ID_DirectSoundFXParamEq_GetAllParameters                 4

#define OBJECT_ID_DirectSoundFXWavesReverb                              21

#define METHOD_ID_DirectSoundFXWavesReverb_QueryInterface               0
#define METHOD_ID_DirectSoundFXWavesReverb_AddRef                       1
#define METHOD_ID_DirectSoundFXWavesReverb_Release                      2
#define METHOD_ID_DirectSoundFXWavesReverb_SetAllParameters             3
#define METHOD_ID_DirectSoundFXWavesReverb_GetAllParameters             4

#define OBJECT_ID_DirectSoundNotify                                     22

#define METHOD_ID_DirectSoundNotify_QueryInterface                      0
#define METHOD_ID_DirectSoundNotify_AddRef                              1
#define METHOD_ID_DirectSoundNotify_Release                             2
#define METHOD_ID_DirectSoundNotify_SetNotificationPositions            3

#define OBJECT_ID_KsPropertySet                                         23

#define METHOD_ID_KsPropertySet_QueryInterface                          0
#define METHOD_ID_KsPropertySet_AddRef                                  1
#define METHOD_ID_KsPropertySet_Release                                 2
#define METHOD_ID_KsPropertySet_Get                                     3
#define METHOD_ID_KsPropertySet_Set                                     4
#define METHOD_ID_KsPropertySet_QuerySupport                            5

#define OBJECT_ID_Unknown                                               24

#define METHOD_ID_Unknown_QueryInterface                                0
#define METHOD_ID_Unknown_AddRef                                        1
#define METHOD_ID_Unknown_Release                                       2
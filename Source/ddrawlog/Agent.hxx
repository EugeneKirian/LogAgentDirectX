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

#define METHOD_ID_Module_AcquireDDThreadLock                            0
#define METHOD_ID_Module_CompleteCreateSysmemSurface                    1
#define METHOD_ID_Module_D3DParseUnknownCommand                         2
#define METHOD_ID_Module_DDGetAttachedSurfaceLcl                        3
#define METHOD_ID_Module_DDInternalLock                                 4
#define METHOD_ID_Module_DDInternalUnlock                               5
#define METHOD_ID_Module_DSoundHelp                                     6
#define METHOD_ID_Module_DirectDrawCreate                               7
#define METHOD_ID_Module_DirectDrawCreateClipper                        8
#define METHOD_ID_Module_DirectDrawCreateEx                             9
#define METHOD_ID_Module_DirectDrawEnumerateA                           10
#define METHOD_ID_Module_DirectDrawEnumerateExA                         11
#define METHOD_ID_Module_DirectDrawEnumerateExW                         12
#define METHOD_ID_Module_DirectDrawEnumerateW                           13
#define METHOD_ID_Module_DllCanUnloadNow                                14
#define METHOD_ID_Module_DllGetClassObject                              15
#define METHOD_ID_Module_GetDDSurfaceLocal                              16
#define METHOD_ID_Module_GetOLEThunkData                                17
#define METHOD_ID_Module_GetSurfaceFromDC                               18
#define METHOD_ID_Module_RegisterSpecialCase                            19
#define METHOD_ID_Module_ReleaseDDThreadLock                            20
#define METHOD_ID_Module_SetAppCompatData                               21

#define METHODCALLBACK_ID_Module_DirectDrawEnumerateA                   0
#define METHODCALLBACK_ID_Module_DirectDrawEnumerateExA                 1
#define METHODCALLBACK_ID_Module_DirectDrawEnumerateExW                 2
#define METHODCALLBACK_ID_Module_DirectDrawEnumerateW                   3

#define OBJECT_ID_DirectDraw                                            1

#define METHOD_ID_DirectDraw_QueryInterface                             0
#define METHOD_ID_DirectDraw_AddRef                                     1
#define METHOD_ID_DirectDraw_Release                                    2
#define METHOD_ID_DirectDraw_Compact                                    3
#define METHOD_ID_DirectDraw_CreateClipper                              4
#define METHOD_ID_DirectDraw_CreatePalette                              5
#define METHOD_ID_DirectDraw_CreateSurface                              6
#define METHOD_ID_DirectDraw_DuplicateSurface                           7
#define METHOD_ID_DirectDraw_EnumDisplayModes                           8
#define METHOD_ID_DirectDraw_EnumSurfaces                               9
#define METHOD_ID_DirectDraw_FlipToGDISurface                           10
#define METHOD_ID_DirectDraw_GetCaps                                    11
#define METHOD_ID_DirectDraw_GetDisplayMode                             12
#define METHOD_ID_DirectDraw_GetFourCCCodes                             13
#define METHOD_ID_DirectDraw_GetGDISurface                              14
#define METHOD_ID_DirectDraw_GetMonitorFrequency                        15
#define METHOD_ID_DirectDraw_GetScanLine                                16
#define METHOD_ID_DirectDraw_GetVerticalBlankStatus                     17
#define METHOD_ID_DirectDraw_Initialize                                 18
#define METHOD_ID_DirectDraw_RestoreDisplayMode                         19
#define METHOD_ID_DirectDraw_SetCooperativeLevel                        20
#define METHOD_ID_DirectDraw_SetDisplayMode                             21
#define METHOD_ID_DirectDraw_WaitForVerticalBlank                       22

#define METHODCALLBACK_ID_DirectDraw_EnumDisplayModes                   0
#define METHODCALLBACK_ID_DirectDraw_EnumSurfaces                       1

#define OBJECT_ID_DirectDraw2                                           2

#define METHOD_ID_DirectDraw2_QueryInterface                            0
#define METHOD_ID_DirectDraw2_AddRef                                    1
#define METHOD_ID_DirectDraw2_Release                                   2
#define METHOD_ID_DirectDraw2_Compact                                   3
#define METHOD_ID_DirectDraw2_CreateClipper                             4
#define METHOD_ID_DirectDraw2_CreatePalette                             5
#define METHOD_ID_DirectDraw2_CreateSurface                             6
#define METHOD_ID_DirectDraw2_DuplicateSurface                          7
#define METHOD_ID_DirectDraw2_EnumDisplayModes                          8
#define METHOD_ID_DirectDraw2_EnumSurfaces                              9
#define METHOD_ID_DirectDraw2_FlipToGDISurface                          10
#define METHOD_ID_DirectDraw2_GetCaps                                   11
#define METHOD_ID_DirectDraw2_GetDisplayMode                            12
#define METHOD_ID_DirectDraw2_GetFourCCCodes                            13
#define METHOD_ID_DirectDraw2_GetGDISurface                             14
#define METHOD_ID_DirectDraw2_GetMonitorFrequency                       15
#define METHOD_ID_DirectDraw2_GetScanLine                               16
#define METHOD_ID_DirectDraw2_GetVerticalBlankStatus                    17
#define METHOD_ID_DirectDraw2_Initialize                                18
#define METHOD_ID_DirectDraw2_RestoreDisplayMode                        19
#define METHOD_ID_DirectDraw2_SetCooperativeLevel                       20
#define METHOD_ID_DirectDraw2_SetDisplayMode                            21
#define METHOD_ID_DirectDraw2_WaitForVerticalBlank                      22
#define METHOD_ID_DirectDraw2_GetAvailableVidMem                        23

#define METHODCALLBACK_ID_DirectDraw2_EnumDisplayModes                  0
#define METHODCALLBACK_ID_DirectDraw2_EnumSurfaces                      1

#define OBJECT_ID_DirectDraw4                                           3

#define METHOD_ID_DirectDraw4_QueryInterface                            0
#define METHOD_ID_DirectDraw4_AddRef                                    1
#define METHOD_ID_DirectDraw4_Release                                   2
#define METHOD_ID_DirectDraw4_Compact                                   3
#define METHOD_ID_DirectDraw4_CreateClipper                             4
#define METHOD_ID_DirectDraw4_CreatePalette                             5
#define METHOD_ID_DirectDraw4_CreateSurface                             6
#define METHOD_ID_DirectDraw4_DuplicateSurface                          7
#define METHOD_ID_DirectDraw4_EnumDisplayModes                          8
#define METHOD_ID_DirectDraw4_EnumSurfaces                              9
#define METHOD_ID_DirectDraw4_FlipToGDISurface                          10
#define METHOD_ID_DirectDraw4_GetCaps                                   11
#define METHOD_ID_DirectDraw4_GetDisplayMode                            12
#define METHOD_ID_DirectDraw4_GetFourCCCodes                            13
#define METHOD_ID_DirectDraw4_GetGDISurface                             14
#define METHOD_ID_DirectDraw4_GetMonitorFrequency                       15
#define METHOD_ID_DirectDraw4_GetScanLine                               16
#define METHOD_ID_DirectDraw4_GetVerticalBlankStatus                    17
#define METHOD_ID_DirectDraw4_Initialize                                18
#define METHOD_ID_DirectDraw4_RestoreDisplayMode                        19
#define METHOD_ID_DirectDraw4_SetCooperativeLevel                       20
#define METHOD_ID_DirectDraw4_SetDisplayMode                            21
#define METHOD_ID_DirectDraw4_WaitForVerticalBlank                      22
#define METHOD_ID_DirectDraw4_GetAvailableVidMem                        23
#define METHOD_ID_DirectDraw4_GetSurfaceFromDC                          24
#define METHOD_ID_DirectDraw4_RestoreAllSurfaces                        25
#define METHOD_ID_DirectDraw4_TestCooperativeLevel                      26
#define METHOD_ID_DirectDraw4_GetDeviceIdentifier                       27

#define METHODCALLBACK_ID_DirectDraw4_EnumDisplayModes                  0
#define METHODCALLBACK_ID_DirectDraw4_EnumSurfaces                      1

#define OBJECT_ID_DirectDraw7                                           4

#define METHOD_ID_DirectDraw7_QueryInterface                            0
#define METHOD_ID_DirectDraw7_AddRef                                    1
#define METHOD_ID_DirectDraw7_Release                                   2
#define METHOD_ID_DirectDraw7_Compact                                   3
#define METHOD_ID_DirectDraw7_CreateClipper                             4
#define METHOD_ID_DirectDraw7_CreatePalette                             5
#define METHOD_ID_DirectDraw7_CreateSurface                             6
#define METHOD_ID_DirectDraw7_DuplicateSurface                          7
#define METHOD_ID_DirectDraw7_EnumDisplayModes                          8
#define METHOD_ID_DirectDraw7_EnumSurfaces                              9
#define METHOD_ID_DirectDraw7_FlipToGDISurface                          10
#define METHOD_ID_DirectDraw7_GetCaps                                   11
#define METHOD_ID_DirectDraw7_GetDisplayMode                            12
#define METHOD_ID_DirectDraw7_GetFourCCCodes                            13
#define METHOD_ID_DirectDraw7_GetGDISurface                             14
#define METHOD_ID_DirectDraw7_GetMonitorFrequency                       15
#define METHOD_ID_DirectDraw7_GetScanLine                               16
#define METHOD_ID_DirectDraw7_GetVerticalBlankStatus                    17
#define METHOD_ID_DirectDraw7_Initialize                                18
#define METHOD_ID_DirectDraw7_RestoreDisplayMode                        19
#define METHOD_ID_DirectDraw7_SetCooperativeLevel                       20
#define METHOD_ID_DirectDraw7_SetDisplayMode                            21
#define METHOD_ID_DirectDraw7_WaitForVerticalBlank                      22
#define METHOD_ID_DirectDraw7_GetAvailableVidMem                        23
#define METHOD_ID_DirectDraw7_GetSurfaceFromDC                          24
#define METHOD_ID_DirectDraw7_RestoreAllSurfaces                        25
#define METHOD_ID_DirectDraw7_TestCooperativeLevel                      26
#define METHOD_ID_DirectDraw7_GetDeviceIdentifier                       27
#define METHOD_ID_DirectDraw7_StartModeTest                             28
#define METHOD_ID_DirectDraw7_EvaluateMode                              29

#define METHODCALLBACK_ID_DirectDraw7_EnumDisplayModes                  0
#define METHODCALLBACK_ID_DirectDraw7_EnumSurfaces                      1

#define OBJECT_ID_DirectDrawClipper                                     5

#define METHOD_ID_DirectDrawClipper_QueryInterface                      0
#define METHOD_ID_DirectDrawClipper_AddRef                              1
#define METHOD_ID_DirectDrawClipper_Release                             2
#define METHOD_ID_DirectDrawClipper_GetClipList                         3
#define METHOD_ID_DirectDrawClipper_GetHWnd                             4
#define METHOD_ID_DirectDrawClipper_Initialize                          5
#define METHOD_ID_DirectDrawClipper_IsClipListChanged                   6
#define METHOD_ID_DirectDrawClipper_SetClipList                         7
#define METHOD_ID_DirectDrawClipper_SetHWnd                             8

#define OBJECT_ID_DirectDrawColorControl                                6

#define METHOD_ID_DirectDrawColorControl_QueryInterface                 0
#define METHOD_ID_DirectDrawColorControl_AddRef                         1
#define METHOD_ID_DirectDrawColorControl_Release                        2
#define METHOD_ID_DirectDrawColorControl_GetColorControls               3
#define METHOD_ID_DirectDrawColorControl_SetColorControls               4

#define OBJECT_ID_DirectDrawGammaControl                                7

#define METHOD_ID_DirectDrawGammaControl_QueryInterface                 0
#define METHOD_ID_DirectDrawGammaControl_AddRef                         1
#define METHOD_ID_DirectDrawGammaControl_Release                        2
#define METHOD_ID_DirectDrawGammaControl_GetGammaRamp                   3
#define METHOD_ID_DirectDrawGammaControl_SetGammaRamp                   4

#define OBJECT_ID_DirectDrawPalette                                     8

#define METHOD_ID_DirectDrawPalette_QueryInterface                      0
#define METHOD_ID_DirectDrawPalette_AddRef                              1
#define METHOD_ID_DirectDrawPalette_Release                             2
#define METHOD_ID_DirectDrawPalette_GetCaps                             3
#define METHOD_ID_DirectDrawPalette_GetEntries                          4
#define METHOD_ID_DirectDrawPalette_Initialize                          5
#define METHOD_ID_DirectDrawPalette_SetEntries                          6

#define OBJECT_ID_DirectDrawSurface                                     9

#define METHOD_ID_DirectDrawSurface_QueryInterface                      0
#define METHOD_ID_DirectDrawSurface_AddRef                              1
#define METHOD_ID_DirectDrawSurface_Release                             2
#define METHOD_ID_DirectDrawSurface_AddAttachedSurface                  3
#define METHOD_ID_DirectDrawSurface_AddOverlayDirtyRect                 4
#define METHOD_ID_DirectDrawSurface_Blt                                 5
#define METHOD_ID_DirectDrawSurface_BltBatch                            6
#define METHOD_ID_DirectDrawSurface_BltFast                             7
#define METHOD_ID_DirectDrawSurface_DeleteAttachedSurface               8
#define METHOD_ID_DirectDrawSurface_EnumAttachedSurfaces                9
#define METHOD_ID_DirectDrawSurface_EnumOverlayZOrders                  10
#define METHOD_ID_DirectDrawSurface_Flip                                11
#define METHOD_ID_DirectDrawSurface_GetAttachedSurface                  12
#define METHOD_ID_DirectDrawSurface_GetBltStatus                        13
#define METHOD_ID_DirectDrawSurface_GetCaps                             14
#define METHOD_ID_DirectDrawSurface_GetClipper                          15
#define METHOD_ID_DirectDrawSurface_GetColorKey                         16
#define METHOD_ID_DirectDrawSurface_GetDC                               17
#define METHOD_ID_DirectDrawSurface_GetFlipStatus                       18
#define METHOD_ID_DirectDrawSurface_GetOverlayPosition                  19
#define METHOD_ID_DirectDrawSurface_GetPalette                          20
#define METHOD_ID_DirectDrawSurface_GetPixelFormat                      21
#define METHOD_ID_DirectDrawSurface_GetSurfaceDesc                      22
#define METHOD_ID_DirectDrawSurface_Initialize                          23
#define METHOD_ID_DirectDrawSurface_IsLost                              24
#define METHOD_ID_DirectDrawSurface_Lock                                25
#define METHOD_ID_DirectDrawSurface_ReleaseDC                           26
#define METHOD_ID_DirectDrawSurface_Restore                             27
#define METHOD_ID_DirectDrawSurface_SetClipper                          28
#define METHOD_ID_DirectDrawSurface_SetColorKey                         29
#define METHOD_ID_DirectDrawSurface_SetOverlayPosition                  30
#define METHOD_ID_DirectDrawSurface_SetPalette                          31
#define METHOD_ID_DirectDrawSurface_Unlock                              32
#define METHOD_ID_DirectDrawSurface_UpdateOverlay                       33
#define METHOD_ID_DirectDrawSurface_UpdateOverlayDisplay                34
#define METHOD_ID_DirectDrawSurface_UpdateOverlayZOrder                 35

#define METHODCALLBACK_ID_DirectDrawSurface_EnumAttachedSurfaces        0
#define METHODCALLBACK_ID_DirectDrawSurface_EnumOverlayZOrders          1

#define OBJECT_ID_DirectDrawSurface2                                    10

#define METHOD_ID_DirectDrawSurface2_QueryInterface                     0
#define METHOD_ID_DirectDrawSurface2_AddRef                             1
#define METHOD_ID_DirectDrawSurface2_Release                            2
#define METHOD_ID_DirectDrawSurface2_AddAttachedSurface                 3
#define METHOD_ID_DirectDrawSurface2_AddOverlayDirtyRect                4
#define METHOD_ID_DirectDrawSurface2_Blt                                5
#define METHOD_ID_DirectDrawSurface2_BltBatch                           6
#define METHOD_ID_DirectDrawSurface2_BltFast                            7
#define METHOD_ID_DirectDrawSurface2_DeleteAttachedSurface              8
#define METHOD_ID_DirectDrawSurface2_EnumAttachedSurfaces               9
#define METHOD_ID_DirectDrawSurface2_EnumOverlayZOrders                 10
#define METHOD_ID_DirectDrawSurface2_Flip                               11
#define METHOD_ID_DirectDrawSurface2_GetAttachedSurface                 12
#define METHOD_ID_DirectDrawSurface2_GetBltStatus                       13
#define METHOD_ID_DirectDrawSurface2_GetCaps                            14
#define METHOD_ID_DirectDrawSurface2_GetClipper                         15
#define METHOD_ID_DirectDrawSurface2_GetColorKey                        16
#define METHOD_ID_DirectDrawSurface2_GetDC                              17
#define METHOD_ID_DirectDrawSurface2_GetFlipStatus                      18
#define METHOD_ID_DirectDrawSurface2_GetOverlayPosition                 19
#define METHOD_ID_DirectDrawSurface2_GetPalette                         20
#define METHOD_ID_DirectDrawSurface2_GetPixelFormat                     21
#define METHOD_ID_DirectDrawSurface2_GetSurfaceDesc                     22
#define METHOD_ID_DirectDrawSurface2_Initialize                         23
#define METHOD_ID_DirectDrawSurface2_IsLost                             24
#define METHOD_ID_DirectDrawSurface2_Lock                               25
#define METHOD_ID_DirectDrawSurface2_ReleaseDC                          26
#define METHOD_ID_DirectDrawSurface2_Restore                            27
#define METHOD_ID_DirectDrawSurface2_SetClipper                         28
#define METHOD_ID_DirectDrawSurface2_SetColorKey                        29
#define METHOD_ID_DirectDrawSurface2_SetOverlayPosition                 30
#define METHOD_ID_DirectDrawSurface2_SetPalette                         31
#define METHOD_ID_DirectDrawSurface2_Unlock                             32
#define METHOD_ID_DirectDrawSurface2_UpdateOverlay                      33
#define METHOD_ID_DirectDrawSurface2_UpdateOverlayDisplay               34
#define METHOD_ID_DirectDrawSurface2_UpdateOverlayZOrder                35
#define METHOD_ID_DirectDrawSurface2_GetDDInterface                     36
#define METHOD_ID_DirectDrawSurface2_PageLock                           37
#define METHOD_ID_DirectDrawSurface2_PageUnlock                         38

#define METHODCALLBACK_ID_DirectDrawSurface2_EnumAttachedSurfaces       0
#define METHODCALLBACK_ID_DirectDrawSurface2_EnumOverlayZOrders         1

#define OBJECT_ID_DirectDrawSurface3                                    11

#define METHOD_ID_DirectDrawSurface3_QueryInterface                     0
#define METHOD_ID_DirectDrawSurface3_AddRef                             1
#define METHOD_ID_DirectDrawSurface3_Release                            2
#define METHOD_ID_DirectDrawSurface3_AddAttachedSurface                 3
#define METHOD_ID_DirectDrawSurface3_AddOverlayDirtyRect                4
#define METHOD_ID_DirectDrawSurface3_Blt                                5
#define METHOD_ID_DirectDrawSurface3_BltBatch                           6
#define METHOD_ID_DirectDrawSurface3_BltFast                            7
#define METHOD_ID_DirectDrawSurface3_DeleteAttachedSurface              8
#define METHOD_ID_DirectDrawSurface3_EnumAttachedSurfaces               9
#define METHOD_ID_DirectDrawSurface3_EnumOverlayZOrders                 10
#define METHOD_ID_DirectDrawSurface3_Flip                               11
#define METHOD_ID_DirectDrawSurface3_GetAttachedSurface                 12
#define METHOD_ID_DirectDrawSurface3_GetBltStatus                       13
#define METHOD_ID_DirectDrawSurface3_GetCaps                            14
#define METHOD_ID_DirectDrawSurface3_GetClipper                         15
#define METHOD_ID_DirectDrawSurface3_GetColorKey                        16
#define METHOD_ID_DirectDrawSurface3_GetDC                              17
#define METHOD_ID_DirectDrawSurface3_GetFlipStatus                      18
#define METHOD_ID_DirectDrawSurface3_GetOverlayPosition                 19
#define METHOD_ID_DirectDrawSurface3_GetPalette                         20
#define METHOD_ID_DirectDrawSurface3_GetPixelFormat                     21
#define METHOD_ID_DirectDrawSurface3_GetSurfaceDesc                     22
#define METHOD_ID_DirectDrawSurface3_Initialize                         23
#define METHOD_ID_DirectDrawSurface3_IsLost                             24
#define METHOD_ID_DirectDrawSurface3_Lock                               25
#define METHOD_ID_DirectDrawSurface3_ReleaseDC                          26
#define METHOD_ID_DirectDrawSurface3_Restore                            27
#define METHOD_ID_DirectDrawSurface3_SetClipper                         28
#define METHOD_ID_DirectDrawSurface3_SetColorKey                        29
#define METHOD_ID_DirectDrawSurface3_SetOverlayPosition                 30
#define METHOD_ID_DirectDrawSurface3_SetPalette                         31
#define METHOD_ID_DirectDrawSurface3_Unlock                             32
#define METHOD_ID_DirectDrawSurface3_UpdateOverlay                      33
#define METHOD_ID_DirectDrawSurface3_UpdateOverlayDisplay               34
#define METHOD_ID_DirectDrawSurface3_UpdateOverlayZOrder                35
#define METHOD_ID_DirectDrawSurface3_GetDDInterface                     36
#define METHOD_ID_DirectDrawSurface3_PageLock                           37
#define METHOD_ID_DirectDrawSurface3_PageUnlock                         38
#define METHOD_ID_DirectDrawSurface3_SetSurfaceDesc                     39

#define METHODCALLBACK_ID_DirectDrawSurface3_EnumAttachedSurfaces       0
#define METHODCALLBACK_ID_DirectDrawSurface3_EnumOverlayZOrders         1

#define OBJECT_ID_DirectDrawSurface4                                    12

#define METHOD_ID_DirectDrawSurface4_QueryInterface                     0
#define METHOD_ID_DirectDrawSurface4_AddRef                             1
#define METHOD_ID_DirectDrawSurface4_Release                            2
#define METHOD_ID_DirectDrawSurface4_AddAttachedSurface                 3
#define METHOD_ID_DirectDrawSurface4_AddOverlayDirtyRect                4
#define METHOD_ID_DirectDrawSurface4_Blt                                5
#define METHOD_ID_DirectDrawSurface4_BltBatch                           6
#define METHOD_ID_DirectDrawSurface4_BltFast                            7
#define METHOD_ID_DirectDrawSurface4_DeleteAttachedSurface              8
#define METHOD_ID_DirectDrawSurface4_EnumAttachedSurfaces               9
#define METHOD_ID_DirectDrawSurface4_EnumOverlayZOrders                 10
#define METHOD_ID_DirectDrawSurface4_Flip                               11
#define METHOD_ID_DirectDrawSurface4_GetAttachedSurface                 12
#define METHOD_ID_DirectDrawSurface4_GetBltStatus                       13
#define METHOD_ID_DirectDrawSurface4_GetCaps                            14
#define METHOD_ID_DirectDrawSurface4_GetClipper                         15
#define METHOD_ID_DirectDrawSurface4_GetColorKey                        16
#define METHOD_ID_DirectDrawSurface4_GetDC                              17
#define METHOD_ID_DirectDrawSurface4_GetFlipStatus                      18
#define METHOD_ID_DirectDrawSurface4_GetOverlayPosition                 19
#define METHOD_ID_DirectDrawSurface4_GetPalette                         20
#define METHOD_ID_DirectDrawSurface4_GetPixelFormat                     21
#define METHOD_ID_DirectDrawSurface4_GetSurfaceDesc                     22
#define METHOD_ID_DirectDrawSurface4_Initialize                         23
#define METHOD_ID_DirectDrawSurface4_IsLost                             24
#define METHOD_ID_DirectDrawSurface4_Lock                               25
#define METHOD_ID_DirectDrawSurface4_ReleaseDC                          26
#define METHOD_ID_DirectDrawSurface4_Restore                            27
#define METHOD_ID_DirectDrawSurface4_SetClipper                         28
#define METHOD_ID_DirectDrawSurface4_SetColorKey                        29
#define METHOD_ID_DirectDrawSurface4_SetOverlayPosition                 30
#define METHOD_ID_DirectDrawSurface4_SetPalette                         31
#define METHOD_ID_DirectDrawSurface4_Unlock                             32
#define METHOD_ID_DirectDrawSurface4_UpdateOverlay                      33
#define METHOD_ID_DirectDrawSurface4_UpdateOverlayDisplay               34
#define METHOD_ID_DirectDrawSurface4_UpdateOverlayZOrder                35
#define METHOD_ID_DirectDrawSurface4_GetDDInterface                     36
#define METHOD_ID_DirectDrawSurface4_PageLock                           37
#define METHOD_ID_DirectDrawSurface4_PageUnlock                         38
#define METHOD_ID_DirectDrawSurface4_SetSurfaceDesc                     39
#define METHOD_ID_DirectDrawSurface4_SetPrivateData                     40
#define METHOD_ID_DirectDrawSurface4_GetPrivateData                     41
#define METHOD_ID_DirectDrawSurface4_FreePrivateData                    42
#define METHOD_ID_DirectDrawSurface4_GetUniquenessValue                 43
#define METHOD_ID_DirectDrawSurface4_ChangeUniquenessValue              44

#define METHODCALLBACK_ID_DirectDrawSurface4_EnumAttachedSurfaces       0
#define METHODCALLBACK_ID_DirectDrawSurface4_EnumOverlayZOrders         1

#define OBJECT_ID_DirectDrawSurface7                                    13

#define METHOD_ID_DirectDrawSurface7_QueryInterface                     0
#define METHOD_ID_DirectDrawSurface7_AddRef                             1
#define METHOD_ID_DirectDrawSurface7_Release                            2
#define METHOD_ID_DirectDrawSurface7_AddAttachedSurface                 3
#define METHOD_ID_DirectDrawSurface7_AddOverlayDirtyRect                4
#define METHOD_ID_DirectDrawSurface7_Blt                                5
#define METHOD_ID_DirectDrawSurface7_BltBatch                           6
#define METHOD_ID_DirectDrawSurface7_BltFast                            7
#define METHOD_ID_DirectDrawSurface7_DeleteAttachedSurface              8
#define METHOD_ID_DirectDrawSurface7_EnumAttachedSurfaces               9
#define METHOD_ID_DirectDrawSurface7_EnumOverlayZOrders                 10
#define METHOD_ID_DirectDrawSurface7_Flip                               11
#define METHOD_ID_DirectDrawSurface7_GetAttachedSurface                 12
#define METHOD_ID_DirectDrawSurface7_GetBltStatus                       13
#define METHOD_ID_DirectDrawSurface7_GetCaps                            14
#define METHOD_ID_DirectDrawSurface7_GetClipper                         15
#define METHOD_ID_DirectDrawSurface7_GetColorKey                        16
#define METHOD_ID_DirectDrawSurface7_GetDC                              17
#define METHOD_ID_DirectDrawSurface7_GetFlipStatus                      18
#define METHOD_ID_DirectDrawSurface7_GetOverlayPosition                 19
#define METHOD_ID_DirectDrawSurface7_GetPalette                         20
#define METHOD_ID_DirectDrawSurface7_GetPixelFormat                     21
#define METHOD_ID_DirectDrawSurface7_GetSurfaceDesc                     22
#define METHOD_ID_DirectDrawSurface7_Initialize                         23
#define METHOD_ID_DirectDrawSurface7_IsLost                             24
#define METHOD_ID_DirectDrawSurface7_Lock                               25
#define METHOD_ID_DirectDrawSurface7_ReleaseDC                          26
#define METHOD_ID_DirectDrawSurface7_Restore                            27
#define METHOD_ID_DirectDrawSurface7_SetClipper                         28
#define METHOD_ID_DirectDrawSurface7_SetColorKey                        29
#define METHOD_ID_DirectDrawSurface7_SetOverlayPosition                 30
#define METHOD_ID_DirectDrawSurface7_SetPalette                         31
#define METHOD_ID_DirectDrawSurface7_Unlock                             32
#define METHOD_ID_DirectDrawSurface7_UpdateOverlay                      33
#define METHOD_ID_DirectDrawSurface7_UpdateOverlayDisplay               34
#define METHOD_ID_DirectDrawSurface7_UpdateOverlayZOrder                35
#define METHOD_ID_DirectDrawSurface7_GetDDInterface                     36
#define METHOD_ID_DirectDrawSurface7_PageLock                           37
#define METHOD_ID_DirectDrawSurface7_PageUnlock                         38
#define METHOD_ID_DirectDrawSurface7_SetSurfaceDesc                     39
#define METHOD_ID_DirectDrawSurface7_SetPrivateData                     40
#define METHOD_ID_DirectDrawSurface7_GetPrivateData                     41
#define METHOD_ID_DirectDrawSurface7_FreePrivateData                    42
#define METHOD_ID_DirectDrawSurface7_GetUniquenessValue                 43
#define METHOD_ID_DirectDrawSurface7_ChangeUniquenessValue              44
#define METHOD_ID_DirectDrawSurface7_SetPriority                        45
#define METHOD_ID_DirectDrawSurface7_GetPriority                        46
#define METHOD_ID_DirectDrawSurface7_SetLOD                             47
#define METHOD_ID_DirectDrawSurface7_GetLOD                             48

#define METHODCALLBACK_ID_DirectDrawSurface7_EnumAttachedSurfaces       0
#define METHODCALLBACK_ID_DirectDrawSurface7_EnumOverlayZOrders         1

#define OBJECT_ID_DirectDrawVideoPort                                   14

#define METHOD_ID_DirectDrawVideoPort_QueryInterface                    0
#define METHOD_ID_DirectDrawVideoPort_AddRef                            1
#define METHOD_ID_DirectDrawVideoPort_Release                           2
#define METHOD_ID_DirectDrawVideoPort_Flip                              3
#define METHOD_ID_DirectDrawVideoPort_GetBandwidthInfo                  4
#define METHOD_ID_DirectDrawVideoPort_GetColorControls                  5
#define METHOD_ID_DirectDrawVideoPort_GetInputFormats                   6
#define METHOD_ID_DirectDrawVideoPort_GetOutputFormats                  7
#define METHOD_ID_DirectDrawVideoPort_GetFieldPolarity                  8
#define METHOD_ID_DirectDrawVideoPort_GetVideoLine                      9
#define METHOD_ID_DirectDrawVideoPort_GetVideoSignalStatus              10
#define METHOD_ID_DirectDrawVideoPort_SetColorControls                  11
#define METHOD_ID_DirectDrawVideoPort_SetTargetSurface                  12
#define METHOD_ID_DirectDrawVideoPort_StartVideo                        13
#define METHOD_ID_DirectDrawVideoPort_StopVideo                         14
#define METHOD_ID_DirectDrawVideoPort_UpdateVideo                       15
#define METHOD_ID_DirectDrawVideoPort_WaitForSync                       16

#define OBJECT_ID_DirectDrawVideoPortContainer                          15

#define METHOD_ID_DirectDrawVideoPortContainer_QueryInterface           0
#define METHOD_ID_DirectDrawVideoPortContainer_AddRef                   1
#define METHOD_ID_DirectDrawVideoPortContainer_Release                  2
#define METHOD_ID_DirectDrawVideoPortContainer_CreateVideoPort          3
#define METHOD_ID_DirectDrawVideoPortContainer_EnumVideoPorts           4
#define METHOD_ID_DirectDrawVideoPortContainer_GetVideoPortConnectInfo  5
#define METHOD_ID_DirectDrawVideoPortContainer_QueryVideoPortStatus     6

#define METHODCALLBACK_ID_DirectDrawVideoPortContainer_EnumVideoPorts   0

#define OBJECT_ID_Direct3D                                              16

#define METHOD_ID_Direct3D_QueryInterface                               0
#define METHOD_ID_Direct3D_AddRef                                       1
#define METHOD_ID_Direct3D_Release                                      2
#define METHOD_ID_Direct3D_Initialize                                   3
#define METHOD_ID_Direct3D_EnumDevices                                  4
#define METHOD_ID_Direct3D_CreateLight                                  5
#define METHOD_ID_Direct3D_CreateMaterial                               6
#define METHOD_ID_Direct3D_CreateViewport                               7
#define METHOD_ID_Direct3D_FindDevice                                   8

#define METHODCALLBACK_ID_Direct3D_EnumDevices                          0

#define OBJECT_ID_Direct3D2                                             17

#define METHOD_ID_Direct3D2_QueryInterface                              0
#define METHOD_ID_Direct3D2_AddRef                                      1
#define METHOD_ID_Direct3D2_Release                                     2
#define METHOD_ID_Direct3D2_EnumDevices                                 3
#define METHOD_ID_Direct3D2_CreateLight                                 4
#define METHOD_ID_Direct3D2_CreateMaterial                              5
#define METHOD_ID_Direct3D2_CreateViewport                              6
#define METHOD_ID_Direct3D2_FindDevice                                  7
#define METHOD_ID_Direct3D2_CreateDevice                                8

#define METHODCALLBACK_ID_Direct3D2_EnumDevices                         0

#define OBJECT_ID_Direct3D3                                             18

#define METHOD_ID_Direct3D3_QueryInterface                              0
#define METHOD_ID_Direct3D3_AddRef                                      1
#define METHOD_ID_Direct3D3_Release                                     2
#define METHOD_ID_Direct3D3_EnumDevices                                 3
#define METHOD_ID_Direct3D3_CreateLight                                 4
#define METHOD_ID_Direct3D3_CreateMaterial                              5
#define METHOD_ID_Direct3D3_CreateViewport                              6
#define METHOD_ID_Direct3D3_FindDevice                                  7
#define METHOD_ID_Direct3D3_CreateDevice                                8
#define METHOD_ID_Direct3D3_CreateVertexBuffer                          9
#define METHOD_ID_Direct3D3_EnumZBufferFormats                          10
#define METHOD_ID_Direct3D3_EvictManagedTextures                        11

#define METHODCALLBACK_ID_Direct3D3_EnumDevices                         0
#define METHODCALLBACK_ID_Direct3D3_EnumZBufferFormats                  1

#define OBJECT_ID_Direct3D7                                             19

#define METHOD_ID_Direct3D7_QueryInterface                              0
#define METHOD_ID_Direct3D7_AddRef                                      1
#define METHOD_ID_Direct3D7_Release                                     2
#define METHOD_ID_Direct3D7_EnumDevices                                 3
#define METHOD_ID_Direct3D7_CreateDevice                                4
#define METHOD_ID_Direct3D7_CreateVertexBuffer                          5
#define METHOD_ID_Direct3D7_EnumZBufferFormats                          6
#define METHOD_ID_Direct3D7_EvictManagedTextures                        7

#define METHODCALLBACK_ID_Direct3D7_EnumDevices                         0
#define METHODCALLBACK_ID_Direct3D7_EnumZBufferFormats                  1

#define OBJECT_ID_Direct3DDevice                                        20

#define METHOD_ID_Direct3DDevice_QueryInterface                         0
#define METHOD_ID_Direct3DDevice_AddRef                                 1
#define METHOD_ID_Direct3DDevice_Release                                2
#define METHOD_ID_Direct3DDevice_Initialize                             3
#define METHOD_ID_Direct3DDevice_GetCaps                                4
#define METHOD_ID_Direct3DDevice_SwapTextureHandles                     5
#define METHOD_ID_Direct3DDevice_CreateExecuteBuffer                    6
#define METHOD_ID_Direct3DDevice_GetStats                               7
#define METHOD_ID_Direct3DDevice_Execute                                8
#define METHOD_ID_Direct3DDevice_AddViewport                            9
#define METHOD_ID_Direct3DDevice_DeleteViewport                         10
#define METHOD_ID_Direct3DDevice_NextViewport                           11
#define METHOD_ID_Direct3DDevice_Pick                                   12
#define METHOD_ID_Direct3DDevice_GetPickRecords                         13
#define METHOD_ID_Direct3DDevice_EnumTextureFormats                     14
#define METHOD_ID_Direct3DDevice_CreateMatrix                           15
#define METHOD_ID_Direct3DDevice_SetMatrix                              16
#define METHOD_ID_Direct3DDevice_GetMatrix                              17
#define METHOD_ID_Direct3DDevice_DeleteMatrix                           18
#define METHOD_ID_Direct3DDevice_BeginScene                             19
#define METHOD_ID_Direct3DDevice_EndScene                               20
#define METHOD_ID_Direct3DDevice_GetDirect3D                            21

#define METHODCALLBACK_ID_Direct3DDevice_EnumTextureFormats             0

#define OBJECT_ID_Direct3DDevice2                                       21

#define METHOD_ID_Direct3DDevice2_QueryInterface                        0
#define METHOD_ID_Direct3DDevice2_AddRef                                1
#define METHOD_ID_Direct3DDevice2_Release                               2
#define METHOD_ID_Direct3DDevice2_GetCaps                               3
#define METHOD_ID_Direct3DDevice2_SwapTextureHandles                    4
#define METHOD_ID_Direct3DDevice2_GetStats                              5
#define METHOD_ID_Direct3DDevice2_AddViewport                           6
#define METHOD_ID_Direct3DDevice2_DeleteViewport                        7
#define METHOD_ID_Direct3DDevice2_NextViewport                          8
#define METHOD_ID_Direct3DDevice2_EnumTextureFormats                    9
#define METHOD_ID_Direct3DDevice2_BeginScene                            10
#define METHOD_ID_Direct3DDevice2_EndScene                              11
#define METHOD_ID_Direct3DDevice2_GetDirect3D                           12
#define METHOD_ID_Direct3DDevice2_SetCurrentViewport                    13
#define METHOD_ID_Direct3DDevice2_GetCurrentViewport                    14
#define METHOD_ID_Direct3DDevice2_SetRenderTarget                       15
#define METHOD_ID_Direct3DDevice2_GetRenderTarget                       16
#define METHOD_ID_Direct3DDevice2_Begin                                 17
#define METHOD_ID_Direct3DDevice2_BeginIndexed                          18
#define METHOD_ID_Direct3DDevice2_Vertex                                19
#define METHOD_ID_Direct3DDevice2_Index                                 20
#define METHOD_ID_Direct3DDevice2_End                                   21
#define METHOD_ID_Direct3DDevice2_GetRenderState                        22
#define METHOD_ID_Direct3DDevice2_SetRenderState                        23
#define METHOD_ID_Direct3DDevice2_GetLightState                         24
#define METHOD_ID_Direct3DDevice2_SetLightState                         25
#define METHOD_ID_Direct3DDevice2_SetTransform                          26
#define METHOD_ID_Direct3DDevice2_GetTransform                          27
#define METHOD_ID_Direct3DDevice2_MultiplyTransform                     28
#define METHOD_ID_Direct3DDevice2_DrawPrimitive                         29
#define METHOD_ID_Direct3DDevice2_DrawIndexedPrimitive                  30
#define METHOD_ID_Direct3DDevice2_SetClipStatus                         31
#define METHOD_ID_Direct3DDevice2_GetClipStatus                         32

#define METHODCALLBACK_ID_Direct3DDevice2_EnumTextureFormats            0

#define OBJECT_ID_Direct3DDevice3                                       22

#define METHOD_ID_Direct3DDevice3_QueryInterface                        0
#define METHOD_ID_Direct3DDevice3_AddRef                                1
#define METHOD_ID_Direct3DDevice3_Release                               2
#define METHOD_ID_Direct3DDevice3_GetCaps                               3
#define METHOD_ID_Direct3DDevice3_GetStats                              4
#define METHOD_ID_Direct3DDevice3_AddViewport                           5
#define METHOD_ID_Direct3DDevice3_DeleteViewport                        6
#define METHOD_ID_Direct3DDevice3_NextViewport                          7
#define METHOD_ID_Direct3DDevice3_EnumTextureFormats                    8
#define METHOD_ID_Direct3DDevice3_BeginScene                            9
#define METHOD_ID_Direct3DDevice3_EndScene                              10
#define METHOD_ID_Direct3DDevice3_GetDirect3D                           11
#define METHOD_ID_Direct3DDevice3_SetCurrentViewport                    12
#define METHOD_ID_Direct3DDevice3_GetCurrentViewport                    13
#define METHOD_ID_Direct3DDevice3_SetRenderTarget                       14
#define METHOD_ID_Direct3DDevice3_GetRenderTarget                       15
#define METHOD_ID_Direct3DDevice3_Begin                                 16
#define METHOD_ID_Direct3DDevice3_BeginIndexed                          17
#define METHOD_ID_Direct3DDevice3_Vertex                                18
#define METHOD_ID_Direct3DDevice3_Index                                 19
#define METHOD_ID_Direct3DDevice3_End                                   20
#define METHOD_ID_Direct3DDevice3_GetRenderState                        21
#define METHOD_ID_Direct3DDevice3_SetRenderState                        22
#define METHOD_ID_Direct3DDevice3_GetLightState                         23
#define METHOD_ID_Direct3DDevice3_SetLightState                         24
#define METHOD_ID_Direct3DDevice3_SetTransform                          25
#define METHOD_ID_Direct3DDevice3_GetTransform                          26
#define METHOD_ID_Direct3DDevice3_MultiplyTransform                     27
#define METHOD_ID_Direct3DDevice3_DrawPrimitive                         28
#define METHOD_ID_Direct3DDevice3_DrawIndexedPrimitive                  29
#define METHOD_ID_Direct3DDevice3_SetClipStatus                         30
#define METHOD_ID_Direct3DDevice3_GetClipStatus                         31
#define METHOD_ID_Direct3DDevice3_DrawPrimitiveStrided                  32
#define METHOD_ID_Direct3DDevice3_DrawIndexedPrimitiveStrided           33
#define METHOD_ID_Direct3DDevice3_DrawPrimitiveVB                       34
#define METHOD_ID_Direct3DDevice3_DrawIndexedPrimitiveVB                35
#define METHOD_ID_Direct3DDevice3_ComputeSphereVisibility               36
#define METHOD_ID_Direct3DDevice3_GetTexture                            37
#define METHOD_ID_Direct3DDevice3_SetTexture                            38
#define METHOD_ID_Direct3DDevice3_GetTextureStageState                  39
#define METHOD_ID_Direct3DDevice3_SetTextureStageState                  40
#define METHOD_ID_Direct3DDevice3_ValidateDevice                        41

#define METHODCALLBACK_ID_Direct3DDevice3_EnumTextureFormats            0

#define OBJECT_ID_Direct3DDevice7                                       23

#define METHOD_ID_Direct3DDevice7_QueryInterface                        0
#define METHOD_ID_Direct3DDevice7_AddRef                                1
#define METHOD_ID_Direct3DDevice7_Release                               2
#define METHOD_ID_Direct3DDevice7_GetCaps                               3
#define METHOD_ID_Direct3DDevice7_EnumTextureFormats                    4
#define METHOD_ID_Direct3DDevice7_BeginScene                            5
#define METHOD_ID_Direct3DDevice7_EndScene                              6
#define METHOD_ID_Direct3DDevice7_GetDirect3D                           7
#define METHOD_ID_Direct3DDevice7_SetRenderTarget                       8
#define METHOD_ID_Direct3DDevice7_GetRenderTarget                       9
#define METHOD_ID_Direct3DDevice7_Clear                                 10
#define METHOD_ID_Direct3DDevice7_SetTransform                          11
#define METHOD_ID_Direct3DDevice7_GetTransform                          12
#define METHOD_ID_Direct3DDevice7_SetViewport                           13
#define METHOD_ID_Direct3DDevice7_MultiplyTransform                     14
#define METHOD_ID_Direct3DDevice7_GetViewport                           15
#define METHOD_ID_Direct3DDevice7_SetMaterial                           16
#define METHOD_ID_Direct3DDevice7_GetMaterial                           17
#define METHOD_ID_Direct3DDevice7_SetLight                              18
#define METHOD_ID_Direct3DDevice7_GetLight                              19
#define METHOD_ID_Direct3DDevice7_SetRenderState                        20
#define METHOD_ID_Direct3DDevice7_GetRenderState                        21
#define METHOD_ID_Direct3DDevice7_BeginStateBlock                       22
#define METHOD_ID_Direct3DDevice7_EndStateBlock                         23
#define METHOD_ID_Direct3DDevice7_PreLoad                               24
#define METHOD_ID_Direct3DDevice7_DrawPrimitive                         25
#define METHOD_ID_Direct3DDevice7_DrawIndexedPrimitive                  26
#define METHOD_ID_Direct3DDevice7_SetClipStatus                         27
#define METHOD_ID_Direct3DDevice7_GetClipStatus                         28
#define METHOD_ID_Direct3DDevice7_DrawPrimitiveStrided                  29
#define METHOD_ID_Direct3DDevice7_DrawIndexedPrimitiveStrided           30
#define METHOD_ID_Direct3DDevice7_DrawPrimitiveVB                       31
#define METHOD_ID_Direct3DDevice7_DrawIndexedPrimitiveVB                32
#define METHOD_ID_Direct3DDevice7_ComputeSphereVisibility               33
#define METHOD_ID_Direct3DDevice7_GetTexture                            34
#define METHOD_ID_Direct3DDevice7_SetTexture                            35
#define METHOD_ID_Direct3DDevice7_GetTextureStageState                  36
#define METHOD_ID_Direct3DDevice7_SetTextureStageState                  37
#define METHOD_ID_Direct3DDevice7_ValidateDevice                        38
#define METHOD_ID_Direct3DDevice7_ApplyStateBlock                       39
#define METHOD_ID_Direct3DDevice7_CaptureStateBlock                     40
#define METHOD_ID_Direct3DDevice7_DeleteStateBlock                      41
#define METHOD_ID_Direct3DDevice7_CreateStateBlock                      42
#define METHOD_ID_Direct3DDevice7_Load                                  43
#define METHOD_ID_Direct3DDevice7_LightEnable                           44
#define METHOD_ID_Direct3DDevice7_GetLightEnable                        45
#define METHOD_ID_Direct3DDevice7_SetClipPlane                          46
#define METHOD_ID_Direct3DDevice7_GetClipPlane                          47
#define METHOD_ID_Direct3DDevice7_GetInfo                               48

#define METHODCALLBACK_ID_Direct3DDevice7_EnumTextureFormats            0

#define OBJECT_ID_Direct3DExecuteBuffer                                 24

#define METHOD_ID_Direct3DExecuteBuffer_QueryInterface                  0
#define METHOD_ID_Direct3DExecuteBuffer_AddRef                          1
#define METHOD_ID_Direct3DExecuteBuffer_Release                         2
#define METHOD_ID_Direct3DExecuteBuffer_Initialize                      3
#define METHOD_ID_Direct3DExecuteBuffer_Lock                            4
#define METHOD_ID_Direct3DExecuteBuffer_Unlock                          5
#define METHOD_ID_Direct3DExecuteBuffer_SetExecuteData                  6
#define METHOD_ID_Direct3DExecuteBuffer_GetExecuteData                  7
#define METHOD_ID_Direct3DExecuteBuffer_Validate                        8
#define METHOD_ID_Direct3DExecuteBuffer_Optimize                        9

#define METHODCALLBACK_ID_Direct3DExecuteBuffer_Validate                0

#define OBJECT_ID_Direct3DLight                                         25

#define METHOD_ID_Direct3DLight_QueryInterface                          0
#define METHOD_ID_Direct3DLight_AddRef                                  1
#define METHOD_ID_Direct3DLight_Release                                 2
#define METHOD_ID_Direct3DLight_Initialize                              3
#define METHOD_ID_Direct3DLight_SetLight                                4
#define METHOD_ID_Direct3DLight_GetLight                                5

#define OBJECT_ID_Direct3DMaterial                                      26

#define METHOD_ID_Direct3DMaterial_QueryInterface                       0
#define METHOD_ID_Direct3DMaterial_AddRef                               1
#define METHOD_ID_Direct3DMaterial_Release                              2
#define METHOD_ID_Direct3DMaterial_Initialize                           3
#define METHOD_ID_Direct3DMaterial_SetMaterial                          4
#define METHOD_ID_Direct3DMaterial_GetMaterial                          5
#define METHOD_ID_Direct3DMaterial_GetHandle                            6
#define METHOD_ID_Direct3DMaterial_Reserve                              7
#define METHOD_ID_Direct3DMaterial_Unreserve                            8

#define OBJECT_ID_Direct3DMaterial2                                     27

#define METHOD_ID_Direct3DMaterial2_QueryInterface                      0
#define METHOD_ID_Direct3DMaterial2_AddRef                              1
#define METHOD_ID_Direct3DMaterial2_Release                             2
#define METHOD_ID_Direct3DMaterial2_SetMaterial                         3
#define METHOD_ID_Direct3DMaterial2_GetMaterial                         4
#define METHOD_ID_Direct3DMaterial2_GetHandle                           5

#define OBJECT_ID_Direct3DMaterial3                                     28

#define METHOD_ID_Direct3DMaterial3_QueryInterface                      0
#define METHOD_ID_Direct3DMaterial3_AddRef                              1
#define METHOD_ID_Direct3DMaterial3_Release                             2
#define METHOD_ID_Direct3DMaterial3_SetMaterial                         3
#define METHOD_ID_Direct3DMaterial3_GetMaterial                         4
#define METHOD_ID_Direct3DMaterial3_GetHandle                           5

#define OBJECT_ID_Direct3DTexture                                       29

#define METHOD_ID_Direct3DTexture_QueryInterface                        0
#define METHOD_ID_Direct3DTexture_AddRef                                1
#define METHOD_ID_Direct3DTexture_Release                               2
#define METHOD_ID_Direct3DTexture_Initialize                            3
#define METHOD_ID_Direct3DTexture_GetHandle                             4
#define METHOD_ID_Direct3DTexture_PaletteChanged                        5
#define METHOD_ID_Direct3DTexture_Load                                  6
#define METHOD_ID_Direct3DTexture_Unload                                7

#define OBJECT_ID_Direct3DTexture2                                      30

#define METHOD_ID_Direct3DTexture2_QueryInterface                       0
#define METHOD_ID_Direct3DTexture2_AddRef                               1
#define METHOD_ID_Direct3DTexture2_Release                              2
#define METHOD_ID_Direct3DTexture2_GetHandle                            3
#define METHOD_ID_Direct3DTexture2_PaletteChanged                       4
#define METHOD_ID_Direct3DTexture2_Load                                 5

#define OBJECT_ID_Direct3DVertexBuffer                                  31

#define METHOD_ID_Direct3DVertexBuffer_QueryInterface                   0
#define METHOD_ID_Direct3DVertexBuffer_AddRef                           1
#define METHOD_ID_Direct3DVertexBuffer_Release                          2
#define METHOD_ID_Direct3DVertexBuffer_Lock                             3
#define METHOD_ID_Direct3DVertexBuffer_Unlock                           4
#define METHOD_ID_Direct3DVertexBuffer_ProcessVertices                  5
#define METHOD_ID_Direct3DVertexBuffer_GetVertexBufferDesc              6
#define METHOD_ID_Direct3DVertexBuffer_Optimize                         7

#define OBJECT_ID_Direct3DVertexBuffer7                                 32

#define METHOD_ID_Direct3DVertexBuffer7_QueryInterface                  0
#define METHOD_ID_Direct3DVertexBuffer7_AddRef                          1
#define METHOD_ID_Direct3DVertexBuffer7_Release                         2
#define METHOD_ID_Direct3DVertexBuffer7_Lock                            3
#define METHOD_ID_Direct3DVertexBuffer7_Unlock                          4
#define METHOD_ID_Direct3DVertexBuffer7_ProcessVertices                 5
#define METHOD_ID_Direct3DVertexBuffer7_GetVertexBufferDesc             6
#define METHOD_ID_Direct3DVertexBuffer7_Optimize                        7
#define METHOD_ID_Direct3DVertexBuffer7_ProcessVerticesStrided          8

#define OBJECT_ID_Direct3DViewport                                      33

#define METHOD_ID_Direct3DViewport_QueryInterface                       0
#define METHOD_ID_Direct3DViewport_AddRef                               1
#define METHOD_ID_Direct3DViewport_Release                              2
#define METHOD_ID_Direct3DViewport_Initialize                           3
#define METHOD_ID_Direct3DViewport_GetViewport                          4
#define METHOD_ID_Direct3DViewport_SetViewport                          5
#define METHOD_ID_Direct3DViewport_TransformVertices                    6
#define METHOD_ID_Direct3DViewport_LightElements                        7
#define METHOD_ID_Direct3DViewport_SetBackground                        8
#define METHOD_ID_Direct3DViewport_GetBackground                        9
#define METHOD_ID_Direct3DViewport_SetBackgroundDepth                   10
#define METHOD_ID_Direct3DViewport_GetBackgroundDepth                   11
#define METHOD_ID_Direct3DViewport_Clear                                12
#define METHOD_ID_Direct3DViewport_AddLight                             13
#define METHOD_ID_Direct3DViewport_DeleteLight                          14
#define METHOD_ID_Direct3DViewport_NextLight                            15

#define OBJECT_ID_Direct3DViewport2                                     34

#define METHOD_ID_Direct3DViewport2_QueryInterface                      0
#define METHOD_ID_Direct3DViewport2_AddRef                              1
#define METHOD_ID_Direct3DViewport2_Release                             2
#define METHOD_ID_Direct3DViewport2_Initialize                          3
#define METHOD_ID_Direct3DViewport2_GetViewport                         4
#define METHOD_ID_Direct3DViewport2_SetViewport                         5
#define METHOD_ID_Direct3DViewport2_TransformVertices                   6
#define METHOD_ID_Direct3DViewport2_LightElements                       7
#define METHOD_ID_Direct3DViewport2_SetBackground                       8
#define METHOD_ID_Direct3DViewport2_GetBackground                       9
#define METHOD_ID_Direct3DViewport2_SetBackgroundDepth                  10
#define METHOD_ID_Direct3DViewport2_GetBackgroundDepth                  11
#define METHOD_ID_Direct3DViewport2_Clear                               12
#define METHOD_ID_Direct3DViewport2_AddLight                            13
#define METHOD_ID_Direct3DViewport2_DeleteLight                         14
#define METHOD_ID_Direct3DViewport2_NextLight                           15
#define METHOD_ID_Direct3DViewport2_GetViewport2                        16
#define METHOD_ID_Direct3DViewport2_SetViewport2                        17

#define OBJECT_ID_Direct3DViewport3                                     35

#define METHOD_ID_Direct3DViewport3_QueryInterface                      0
#define METHOD_ID_Direct3DViewport3_AddRef                              1
#define METHOD_ID_Direct3DViewport3_Release                             2
#define METHOD_ID_Direct3DViewport3_Initialize                          3
#define METHOD_ID_Direct3DViewport3_GetViewport                         4
#define METHOD_ID_Direct3DViewport3_SetViewport                         5
#define METHOD_ID_Direct3DViewport3_TransformVertices                   6
#define METHOD_ID_Direct3DViewport3_LightElements                       7
#define METHOD_ID_Direct3DViewport3_SetBackground                       8
#define METHOD_ID_Direct3DViewport3_GetBackground                       9
#define METHOD_ID_Direct3DViewport3_SetBackgroundDepth                  10
#define METHOD_ID_Direct3DViewport3_GetBackgroundDepth                  11
#define METHOD_ID_Direct3DViewport3_Clear                               12
#define METHOD_ID_Direct3DViewport3_AddLight                            13
#define METHOD_ID_Direct3DViewport3_DeleteLight                         14
#define METHOD_ID_Direct3DViewport3_NextLight                           15
#define METHOD_ID_Direct3DViewport3_GetViewport2                        16
#define METHOD_ID_Direct3DViewport3_SetViewport2                        17
#define METHOD_ID_Direct3DViewport3_SetBackgroundDepth2                 18
#define METHOD_ID_Direct3DViewport3_GetBackgroundDepth2                 19
#define METHOD_ID_Direct3DViewport3_Clear2                              20

#define OBJECT_ID_Unknown                                               36

#define METHOD_ID_Unknown_QueryInterface                                0
#define METHOD_ID_Unknown_AddRef                                        1
#define METHOD_ID_Unknown_Release                                       2
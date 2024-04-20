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

#define METHOD_ID_Module_EnableMaximizedWindowedMode                    0
#define METHOD_ID_Module_ValidatePixelShader                            1
#define METHOD_ID_Module_ValidateVertexShader                           2
#define METHOD_ID_Module_DebugSetMute                                   3
#define METHOD_ID_Module_Direct3DCreate8                                4

#define OBJECT_ID_Direct3D8                                             1

#define METHOD_ID_Direct3D8_QueryInterface                              0
#define METHOD_ID_Direct3D8_AddRef                                      1
#define METHOD_ID_Direct3D8_Release                                     2
#define METHOD_ID_Direct3D8_RegisterSoftwareDevice                      3
#define METHOD_ID_Direct3D8_GetAdapterCount                             4
#define METHOD_ID_Direct3D8_GetAdapterIdentifier                        5
#define METHOD_ID_Direct3D8_GetAdapterModeCount                         6
#define METHOD_ID_Direct3D8_EnumAdapterModes                            7
#define METHOD_ID_Direct3D8_GetAdapterDisplayMode                       8
#define METHOD_ID_Direct3D8_CheckDeviceType                             9
#define METHOD_ID_Direct3D8_CheckDeviceFormat                           10
#define METHOD_ID_Direct3D8_CheckDeviceMultiSampleType                  11
#define METHOD_ID_Direct3D8_CheckDepthStencilMatch                      12
#define METHOD_ID_Direct3D8_GetDeviceCaps                               13
#define METHOD_ID_Direct3D8_GetAdapterMonitor                           14
#define METHOD_ID_Direct3D8_CreateDevice                                15

#define OBJECT_ID_Direct3DDevice8                                       2

#define METHOD_ID_Direct3DDevice8_QueryInterface                        0
#define METHOD_ID_Direct3DDevice8_AddRef                                1
#define METHOD_ID_Direct3DDevice8_Release                               2
#define METHOD_ID_Direct3DDevice8_TestCooperativeLevel                  3
#define METHOD_ID_Direct3DDevice8_GetAvailableTextureMem                4
#define METHOD_ID_Direct3DDevice8_ResourceManagerDiscardBytes           5
#define METHOD_ID_Direct3DDevice8_GetDirect3D                           6
#define METHOD_ID_Direct3DDevice8_GetDeviceCaps                         7
#define METHOD_ID_Direct3DDevice8_GetDisplayMode                        8
#define METHOD_ID_Direct3DDevice8_GetCreationParameters                 9
#define METHOD_ID_Direct3DDevice8_SetCursorProperties                   10
#define METHOD_ID_Direct3DDevice8_SetCursorPosition                     11
#define METHOD_ID_Direct3DDevice8_ShowCursor                            12
#define METHOD_ID_Direct3DDevice8_CreateAdditionalSwapChain             13
#define METHOD_ID_Direct3DDevice8_Reset                                 14
#define METHOD_ID_Direct3DDevice8_Present                               15
#define METHOD_ID_Direct3DDevice8_GetBackBuffer                         16
#define METHOD_ID_Direct3DDevice8_GetRasterStatus                       17
#define METHOD_ID_Direct3DDevice8_SetGammaRamp                          18
#define METHOD_ID_Direct3DDevice8_GetGammaRamp                          19
#define METHOD_ID_Direct3DDevice8_CreateTexture                         20
#define METHOD_ID_Direct3DDevice8_CreateVolumeTexture                   21
#define METHOD_ID_Direct3DDevice8_CreateCubeTexture                     22
#define METHOD_ID_Direct3DDevice8_CreateVertexBuffer                    23
#define METHOD_ID_Direct3DDevice8_CreateIndexBuffer                     24
#define METHOD_ID_Direct3DDevice8_CreateRenderTarget                    25
#define METHOD_ID_Direct3DDevice8_CreateDepthStencilSurface             26
#define METHOD_ID_Direct3DDevice8_CreateImageSurface                    27
#define METHOD_ID_Direct3DDevice8_CopyRects                             28
#define METHOD_ID_Direct3DDevice8_UpdateTexture                         29
#define METHOD_ID_Direct3DDevice8_GetFrontBuffer                        30
#define METHOD_ID_Direct3DDevice8_SetRenderTarget                       31
#define METHOD_ID_Direct3DDevice8_GetRenderTarget                       32
#define METHOD_ID_Direct3DDevice8_GetDepthStencilSurface                33
#define METHOD_ID_Direct3DDevice8_BeginScene                            34
#define METHOD_ID_Direct3DDevice8_EndScene                              35
#define METHOD_ID_Direct3DDevice8_Clear                                 36
#define METHOD_ID_Direct3DDevice8_SetTransform                          37
#define METHOD_ID_Direct3DDevice8_GetTransform                          38
#define METHOD_ID_Direct3DDevice8_MultiplyTransform                     39
#define METHOD_ID_Direct3DDevice8_SetViewport                           40
#define METHOD_ID_Direct3DDevice8_GetViewport                           41
#define METHOD_ID_Direct3DDevice8_SetMaterial                           42
#define METHOD_ID_Direct3DDevice8_GetMaterial                           43
#define METHOD_ID_Direct3DDevice8_SetLight                              44
#define METHOD_ID_Direct3DDevice8_GetLight                              45
#define METHOD_ID_Direct3DDevice8_LightEnable                           46
#define METHOD_ID_Direct3DDevice8_GetLightEnable                        47
#define METHOD_ID_Direct3DDevice8_SetClipPlane                          48
#define METHOD_ID_Direct3DDevice8_GetClipPlane                          49
#define METHOD_ID_Direct3DDevice8_SetRenderState                        50
#define METHOD_ID_Direct3DDevice8_GetRenderState                        51
#define METHOD_ID_Direct3DDevice8_BeginStateBlock                       52
#define METHOD_ID_Direct3DDevice8_EndStateBlock                         53
#define METHOD_ID_Direct3DDevice8_ApplyStateBlock                       54
#define METHOD_ID_Direct3DDevice8_CaptureStateBlock                     55
#define METHOD_ID_Direct3DDevice8_DeleteStateBlock                      56
#define METHOD_ID_Direct3DDevice8_CreateStateBlock                      57
#define METHOD_ID_Direct3DDevice8_SetClipStatus                         58
#define METHOD_ID_Direct3DDevice8_GetClipStatus                         59
#define METHOD_ID_Direct3DDevice8_GetTexture                            60
#define METHOD_ID_Direct3DDevice8_SetTexture                            61
#define METHOD_ID_Direct3DDevice8_GetTextureStageState                  62
#define METHOD_ID_Direct3DDevice8_SetTextureStageState                  63
#define METHOD_ID_Direct3DDevice8_ValidateDevice                        64
#define METHOD_ID_Direct3DDevice8_GetInfo                               65
#define METHOD_ID_Direct3DDevice8_SetPaletteEntries                     66
#define METHOD_ID_Direct3DDevice8_GetPaletteEntries                     67
#define METHOD_ID_Direct3DDevice8_SetCurrentTexturePalette              68
#define METHOD_ID_Direct3DDevice8_GetCurrentTexturePalette              69
#define METHOD_ID_Direct3DDevice8_DrawPrimitive                         70
#define METHOD_ID_Direct3DDevice8_DrawIndexedPrimitive                  71
#define METHOD_ID_Direct3DDevice8_DrawPrimitiveUP                       72
#define METHOD_ID_Direct3DDevice8_DrawIndexedPrimitiveUP                73
#define METHOD_ID_Direct3DDevice8_ProcessVertices                       74
#define METHOD_ID_Direct3DDevice8_CreateVertexShader                    75
#define METHOD_ID_Direct3DDevice8_SetVertexShader                       76
#define METHOD_ID_Direct3DDevice8_GetVertexShader                       77
#define METHOD_ID_Direct3DDevice8_DeleteVertexShader                    78
#define METHOD_ID_Direct3DDevice8_SetVertexShaderConstant               79
#define METHOD_ID_Direct3DDevice8_GetVertexShaderConstant               80
#define METHOD_ID_Direct3DDevice8_GetVertexShaderDeclaration            81
#define METHOD_ID_Direct3DDevice8_GetVertexShaderFunction               82
#define METHOD_ID_Direct3DDevice8_SetStreamSource                       83
#define METHOD_ID_Direct3DDevice8_GetStreamSource                       84
#define METHOD_ID_Direct3DDevice8_SetIndices                            85
#define METHOD_ID_Direct3DDevice8_GetIndices                            86
#define METHOD_ID_Direct3DDevice8_CreatePixelShader                     87
#define METHOD_ID_Direct3DDevice8_SetPixelShader                        88
#define METHOD_ID_Direct3DDevice8_GetPixelShader                        89
#define METHOD_ID_Direct3DDevice8_DeletePixelShader                     90
#define METHOD_ID_Direct3DDevice8_SetPixelShaderConstant                91
#define METHOD_ID_Direct3DDevice8_GetPixelShaderConstant                92
#define METHOD_ID_Direct3DDevice8_GetPixelShaderFunction                93
#define METHOD_ID_Direct3DDevice8_DrawRectPatch                         94
#define METHOD_ID_Direct3DDevice8_DrawTriPatch                          95
#define METHOD_ID_Direct3DDevice8_DeletePatch                           96

#define OBJECT_ID_Direct3DResource8                                     3

#define METHOD_ID_Direct3DResource8_QueryInterface                      0
#define METHOD_ID_Direct3DResource8_AddRef                              1
#define METHOD_ID_Direct3DResource8_Release                             2
#define METHOD_ID_Direct3DResource8_GetDevice                           3
#define METHOD_ID_Direct3DResource8_SetPrivateData                      4
#define METHOD_ID_Direct3DResource8_GetPrivateData                      5
#define METHOD_ID_Direct3DResource8_FreePrivateData                     6
#define METHOD_ID_Direct3DResource8_SetPriority                         7
#define METHOD_ID_Direct3DResource8_GetPriority                         8
#define METHOD_ID_Direct3DResource8_PreLoad                             9
#define METHOD_ID_Direct3DResource8_GetType                             10

#define OBJECT_ID_Direct3DIndexBuffer8                                  4

#define METHOD_ID_Direct3DIndexBuffer8_QueryInterface                   0
#define METHOD_ID_Direct3DIndexBuffer8_AddRef                           1
#define METHOD_ID_Direct3DIndexBuffer8_Release                          2
#define METHOD_ID_Direct3DIndexBuffer8_GetDevice                        3
#define METHOD_ID_Direct3DIndexBuffer8_SetPrivateData                   4
#define METHOD_ID_Direct3DIndexBuffer8_GetPrivateData                   5
#define METHOD_ID_Direct3DIndexBuffer8_FreePrivateData                  6
#define METHOD_ID_Direct3DIndexBuffer8_SetPriority                      7
#define METHOD_ID_Direct3DIndexBuffer8_GetPriority                      8
#define METHOD_ID_Direct3DIndexBuffer8_PreLoad                          9
#define METHOD_ID_Direct3DIndexBuffer8_GetType                          10
#define METHOD_ID_Direct3DIndexBuffer8_Lock                             11
#define METHOD_ID_Direct3DIndexBuffer8_Unlock                           12
#define METHOD_ID_Direct3DIndexBuffer8_GetDesc                          13

#define OBJECT_ID_Direct3DVertexBuffer8                                 5

#define METHOD_ID_Direct3DVertexBuffer8_QueryInterface                  0
#define METHOD_ID_Direct3DVertexBuffer8_AddRef                          1
#define METHOD_ID_Direct3DVertexBuffer8_Release                         2
#define METHOD_ID_Direct3DVertexBuffer8_GetDevice                       3
#define METHOD_ID_Direct3DVertexBuffer8_SetPrivateData                  4
#define METHOD_ID_Direct3DVertexBuffer8_GetPrivateData                  5
#define METHOD_ID_Direct3DVertexBuffer8_FreePrivateData                 6
#define METHOD_ID_Direct3DVertexBuffer8_SetPriority                     7
#define METHOD_ID_Direct3DVertexBuffer8_GetPriority                     8
#define METHOD_ID_Direct3DVertexBuffer8_PreLoad                         9
#define METHOD_ID_Direct3DVertexBuffer8_GetType                         10
#define METHOD_ID_Direct3DVertexBuffer8_Lock                            11
#define METHOD_ID_Direct3DVertexBuffer8_Unlock                          12
#define METHOD_ID_Direct3DVertexBuffer8_GetDesc                         13

#define OBJECT_ID_Direct3DBaseTexture8                                  6

#define METHOD_ID_Direct3DBaseTexture8_QueryInterface                   0
#define METHOD_ID_Direct3DBaseTexture8_AddRef                           1
#define METHOD_ID_Direct3DBaseTexture8_Release                          2
#define METHOD_ID_Direct3DBaseTexture8_GetDevice                        3
#define METHOD_ID_Direct3DBaseTexture8_SetPrivateData                   4
#define METHOD_ID_Direct3DBaseTexture8_GetPrivateData                   5
#define METHOD_ID_Direct3DBaseTexture8_FreePrivateData                  6
#define METHOD_ID_Direct3DBaseTexture8_SetPriority                      7
#define METHOD_ID_Direct3DBaseTexture8_GetPriority                      8
#define METHOD_ID_Direct3DBaseTexture8_PreLoad                          9
#define METHOD_ID_Direct3DBaseTexture8_GetType                          10
#define METHOD_ID_Direct3DBaseTexture8_SetLOD                           11
#define METHOD_ID_Direct3DBaseTexture8_GetLOD                           12
#define METHOD_ID_Direct3DBaseTexture8_GetLevelCount                    13

#define OBJECT_ID_Direct3DTexture8                                      7

#define METHOD_ID_Direct3DTexture8_QueryInterface                       0
#define METHOD_ID_Direct3DTexture8_AddRef                               1
#define METHOD_ID_Direct3DTexture8_Release                              2
#define METHOD_ID_Direct3DTexture8_GetDevice                            3
#define METHOD_ID_Direct3DTexture8_SetPrivateData                       4
#define METHOD_ID_Direct3DTexture8_GetPrivateData                       5
#define METHOD_ID_Direct3DTexture8_FreePrivateData                      6
#define METHOD_ID_Direct3DTexture8_SetPriority                          7
#define METHOD_ID_Direct3DTexture8_GetPriority                          8
#define METHOD_ID_Direct3DTexture8_PreLoad                              9
#define METHOD_ID_Direct3DTexture8_GetType                              10
#define METHOD_ID_Direct3DTexture8_SetLOD                               11
#define METHOD_ID_Direct3DTexture8_GetLOD                               12
#define METHOD_ID_Direct3DTexture8_GetLevelCount                        13
#define METHOD_ID_Direct3DTexture8_GetLevelDesc                         14
#define METHOD_ID_Direct3DTexture8_GetSurfaceLevel                      15
#define METHOD_ID_Direct3DTexture8_LockRect                             16
#define METHOD_ID_Direct3DTexture8_UnlockRect                           17
#define METHOD_ID_Direct3DTexture8_AddDirtyRect                         18

#define OBJECT_ID_Direct3DCubeTexture8                                  8

#define METHOD_ID_Direct3DCubeTexture8_QueryInterface                   0
#define METHOD_ID_Direct3DCubeTexture8_AddRef                           1
#define METHOD_ID_Direct3DCubeTexture8_Release                          2
#define METHOD_ID_Direct3DCubeTexture8_GetDevice                        3
#define METHOD_ID_Direct3DCubeTexture8_SetPrivateData                   4
#define METHOD_ID_Direct3DCubeTexture8_GetPrivateData                   5
#define METHOD_ID_Direct3DCubeTexture8_FreePrivateData                  6
#define METHOD_ID_Direct3DCubeTexture8_SetPriority                      7
#define METHOD_ID_Direct3DCubeTexture8_GetPriority                      8
#define METHOD_ID_Direct3DCubeTexture8_PreLoad                          9
#define METHOD_ID_Direct3DCubeTexture8_GetType                          10
#define METHOD_ID_Direct3DCubeTexture8_SetLOD                           11
#define METHOD_ID_Direct3DCubeTexture8_GetLOD                           12
#define METHOD_ID_Direct3DCubeTexture8_GetLevelCount                    13
#define METHOD_ID_Direct3DCubeTexture8_GetLevelDesc                     14
#define METHOD_ID_Direct3DCubeTexture8_GetCubeMapSurface                15
#define METHOD_ID_Direct3DCubeTexture8_LockRect                         16
#define METHOD_ID_Direct3DCubeTexture8_UnlockRect                       17
#define METHOD_ID_Direct3DCubeTexture8_AddDirtyRect                     18

#define OBJECT_ID_Direct3DVolumeTexture8                                9

#define METHOD_ID_Direct3DVolumeTexture8_QueryInterface                 0
#define METHOD_ID_Direct3DVolumeTexture8_AddRef                         1
#define METHOD_ID_Direct3DVolumeTexture8_Release                        2
#define METHOD_ID_Direct3DVolumeTexture8_GetDevice                      3
#define METHOD_ID_Direct3DVolumeTexture8_SetPrivateData                 4
#define METHOD_ID_Direct3DVolumeTexture8_GetPrivateData                 5
#define METHOD_ID_Direct3DVolumeTexture8_FreePrivateData                6
#define METHOD_ID_Direct3DVolumeTexture8_SetPriority                    7
#define METHOD_ID_Direct3DVolumeTexture8_GetPriority                    8
#define METHOD_ID_Direct3DVolumeTexture8_PreLoad                        9
#define METHOD_ID_Direct3DVolumeTexture8_GetType                        10
#define METHOD_ID_Direct3DVolumeTexture8_SetLOD                         11
#define METHOD_ID_Direct3DVolumeTexture8_GetLOD                         12
#define METHOD_ID_Direct3DVolumeTexture8_GetLevelCount                  13
#define METHOD_ID_Direct3DVolumeTexture8_GetLevelDesc                   14
#define METHOD_ID_Direct3DVolumeTexture8_GetVolumeLevel                 15
#define METHOD_ID_Direct3DVolumeTexture8_LockBox                        16
#define METHOD_ID_Direct3DVolumeTexture8_UnlockBox                      17
#define METHOD_ID_Direct3DVolumeTexture8_AddDirtyBox                    18

#define OBJECT_ID_Direct3DSurface8                                      10

#define METHOD_ID_Direct3DSurface8_QueryInterface                       0
#define METHOD_ID_Direct3DSurface8_AddRef                               1
#define METHOD_ID_Direct3DSurface8_Release                              2
#define METHOD_ID_Direct3DSurface8_GetDevice                            3
#define METHOD_ID_Direct3DSurface8_SetPrivateData                       4
#define METHOD_ID_Direct3DSurface8_GetPrivateData                       5
#define METHOD_ID_Direct3DSurface8_FreePrivateData                      6
#define METHOD_ID_Direct3DSurface8_GetContainer                         7
#define METHOD_ID_Direct3DSurface8_GetDesc                              8
#define METHOD_ID_Direct3DSurface8_LockRect                             9
#define METHOD_ID_Direct3DSurface8_UnlockRect                           10

#define OBJECT_ID_Direct3DSwapChain8                                    11

#define METHOD_ID_Direct3DSwapChain8_QueryInterface                     0
#define METHOD_ID_Direct3DSwapChain8_AddRef                             1
#define METHOD_ID_Direct3DSwapChain8_Release                            2
#define METHOD_ID_Direct3DSwapChain8_Present                            3
#define METHOD_ID_Direct3DSwapChain8_GetBackBuffer                      4

#define OBJECT_ID_Direct3DVolume8                                       12

#define METHOD_ID_Direct3DVolume8_QueryInterface                        0
#define METHOD_ID_Direct3DVolume8_AddRef                                1
#define METHOD_ID_Direct3DVolume8_Release                               2
#define METHOD_ID_Direct3DVolume8_GetDevice                             3
#define METHOD_ID_Direct3DVolume8_SetPrivateData                        4
#define METHOD_ID_Direct3DVolume8_GetPrivateData                        5
#define METHOD_ID_Direct3DVolume8_FreePrivateData                       6
#define METHOD_ID_Direct3DVolume8_GetContainer                          7
#define METHOD_ID_Direct3DVolume8_GetDesc                               8
#define METHOD_ID_Direct3DVolume8_LockBox                               9
#define METHOD_ID_Direct3DVolume8_UnlockBox                             10

#define OBJECT_ID_Unknown                                               13

#define METHOD_ID_Unknown_QueryInterface                                0
#define METHOD_ID_Unknown_AddRef                                        1
#define METHOD_ID_Unknown_Release                                       2
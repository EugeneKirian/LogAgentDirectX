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

#include "Module.hxx"

#define DIRECT_SOUND_TITLE "AgentDirectX"
#define DIRECT_SOUND_LOAD_ERROR_MESSAGE "Unable to load dsound.dll library."
#define DIRECT_SOUND_ALREADY_LOADED_ERROR_MESSAGE "The dsound.dll library already loaded."
#define DIRECT_SOUND_INITIALIZE_LOGGER_MESSAGE "Unable to initialize logger."

static VOID Exit(CONST LPCSTR title, CONST LPCSTR message)
{
    MessageBoxA(NULL, message, title, MB_OK | MB_ICONEXCLAMATION);

    ExitProcess(EXIT_SUCCESS);
}

VOID Initialize()
{
    if (Module.Initialized) { Exit(DIRECT_SOUND_TITLE, DIRECT_SOUND_ALREADY_LOADED_ERROR_MESSAGE); }

    switch (InitializeModule())
    {
    case INITIALIZE_MODULE_LOAD_ERROR: { Exit(DIRECT_SOUND_TITLE, DIRECT_SOUND_LOAD_ERROR_MESSAGE); break; }
    case INITIALIZE_MODULE_LOGGER_ERROR: { Exit(DIRECT_SOUND_TITLE, DIRECT_SOUND_INITIALIZE_LOGGER_MESSAGE); break; }
    }
    
    if (Module.Initialized) { LogAttachProcess(Module.Logger, LOGGER_LEVEL_DEBUG); }
}

VOID Release()
{
    if (Module.Initialized) { LogDetachProcess(Module.Logger, LOGGER_LEVEL_DEBUG); }

    ReleaseModule();
}

BOOL APIENTRY DllMain(HMODULE, DWORD ul_reason_for_call, LPVOID)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: { Initialize(); break; }
    case DLL_THREAD_ATTACH: { if (Module.Initialized) { LogAttachThread(Module.Logger, LOGGER_LEVEL_DEBUG); } break; }
    case DLL_THREAD_DETACH: { if (Module.Initialized) { LogDetachThread(Module.Logger, LOGGER_LEVEL_DEBUG); } break; }
    case DLL_PROCESS_DETACH: { Release(); break; }
    }

    return TRUE;
}
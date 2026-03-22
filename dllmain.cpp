#include "Negasth/Negasth.h"

JavaVM* vm;
JNIEnv* env;


void ThreadMain(HMODULE hModule) {
    AllocConsole();
    freopen_s(&Negasth::file, "CONOUT$", "w", stdout);


    if (Negasth::init(hModule)) {
        Negasth::Loop();
    }

    Negasth::Clear();

    FreeConsole();
    fclose(Negasth::file);
    FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //std::thread{ ThreadMain,hModule }.detach();
        CloseHandle(CreateThread(nullptr, 0ul, (LPTHREAD_START_ROUTINE)ThreadMain, hModule, 0ul, nullptr));
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


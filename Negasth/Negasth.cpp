#include "Negasth.h"
#include "Cache/Cache.h"
#include"Modules/Modules.h"
#include "Hook/glHook.h"
#include "../net/Minecraft/item/ItemBow/ItemBow.h"
#include "../net/Minecraft/network/play/client/C03PacketPlayer/C06PacketPlayerPosLook/C06PacketPlayerPosLook.h"
#include "../net/Minecraft/network/play/client/C03PacketPlayer/C04PacketPlayerPosition/C04PacketPlayerPosition.h"
#include "Mappings/mappings_major_1_8_9.h"
#include "Mappings/mappings_major_1_18.h"

WNDPROC oldWinProc;

extern Negasth::Version Negasth::versions[] = {
    Mappings::mappings_major_1_8_9,Negasth::Version::MAJOR_1_8_9,
    Mappings::mappings_major_1_18,Negasth::Version::MAJOR_1_18
};

LRESULT CALLBACK myWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static JNIEnv* netEnv;
    if (netEnv == NULL) {
        Negasth::p_jvm->AttachCurrentThreadAsDaemon((void**)&netEnv, nullptr);
    }
    switch (uMsg) {
    case WM_RBUTTONUP: // 右键弹起
    {
        jobject holdItem = Negasth::cache->thePlayer.getHeldItem(netEnv).getItem(netEnv).getInstance();
        if (holdItem != NULL && Negasth::p_env->IsInstanceOf(holdItem, ItemBow::ItemBowClass.getJclass(netEnv))) {
            Negasth::Maths::Vector2d rotation = Negasth::cache->thePlayer.getRotation(netEnv);
            Negasth::Maths::Vector3d position = Negasth::cache->thePlayer.getPosition(netEnv);
            Negasth::Maths::Vector3d movement = Negasth::cache->thePlayer.getMovementVector(Negasth::cache->timer.getRenderPartialTicks());

            int itemUseDuraion = Negasth::cache->thePlayer.getItemInUseDuration(netEnv);
            int sendNum = 0;
            if (itemUseDuraion < 10) {
                sendNum = 5;
            }
            else {
                sendNum = 20 - itemUseDuraion;
            }
            for (int i = 0; i < sendNum; i++) {
                if (Negasth::cache->NetHandler.addToSendQueue(C06PacketPlayerPosLook::newObject(position + Negasth::Maths::Vector3d(0, 1.1E-9, 0), rotation, false, netEnv), netEnv))
                {
                    Negasth::Modules::CheckPackets::packetsList.push_front(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch()));
                    Negasth::Modules::CheckPackets::nowPackets++;
                }
            }
            std::cout << "当前时间：" << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch()).count() << " 当前发包数量 ：" << Negasth::Modules::CheckPackets::nowPackets << std::endl;
        }
        break;
    }
    case WM_KEYDOWN: 
        if (wParam == 'T') { // 检查是否按下T键  
            Negasth::Maths::Vector2d rotation = Negasth::cache->thePlayer.getRotation(netEnv);
            Negasth::Maths::Vector3d position = Negasth::cache->thePlayer.getPosition(netEnv);
            for (int i = 0; i < 8; i++) {
                if (Negasth::cache->NetHandler.addToSendQueue(C06PacketPlayerPosLook::newObject(position + Negasth::Maths::Vector3d(0, 1.1E-9, 0), rotation, true, netEnv), netEnv))
                {
                    Negasth::Modules::CheckPackets::packetsList.push_front(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch()));
                    Negasth::Modules::CheckPackets::nowPackets++;
                }
            }
            std::cout <<"当前时间："<< std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch()).count() << " 当前发包数量 ：" << Negasth::Modules::CheckPackets::nowPackets << std::endl;
        }
        else if (wParam == VK_NUMPAD1) {
            Negasth::enable = !Negasth::enable;
        }
        break;
    }
    return CallWindowProc(oldWinProc, hwnd, uMsg, wParam, lParam);
}

void Negasth::Clear() {
    glHOOK::removeHook();
    cache->Clear();
    SetWindowLongPtr(Negasth::window, GWLP_WNDPROC, (LONG_PTR)oldWinProc);
    Negasth::p_jvm->DetachCurrentThread();
   // Negasth::p_tienv->DisposeEnvironment();
}

void Negasth::Loop() {
    while (!GetAsyncKeyState(VK_END))
    {

        static Negasth::CTimer timer = std::chrono::milliseconds(2);

        if (!timer.isElapsed() || !Negasth::cache->fillCache())continue;

        if (GetAsyncKeyState(VK_SPACE)) {
            Negasth::cache->thePlayer.setjumpTicks();
        }
        if(Negasth::enable)
            Negasth::Modules::runModules();
    }
}

struct Process {
    DWORD pid;
    HWND window;
};

static BOOL CALLBACK EnumWindowsCallback(_In_ HWND hwnd, _In_ LPARAM lParam) {
    Process* p_Process = reinterpret_cast<Process*>(lParam);
    DWORD pid{ 0 };
    GetWindowThreadProcessId(hwnd, &pid);
    if (pid == p_Process->pid && GetWindow(hwnd, GW_OWNER) == NULL && IsWindowVisible(hwnd) && GetConsoleWindow() != hwnd) {
        p_Process->window = hwnd;
        return FALSE;
    }
    return TRUE;
}

HWND Negasth::getCurrentWindow() {
    HANDLE currentProc = GetCurrentProcess();
    Process process = { GetProcessId(currentProc) };
    CloseHandle(currentProc);
    EnumWindows(EnumWindowsCallback, reinterpret_cast<LPARAM>(&process));
    return process.window;
}

BOOL Negasth::init(HMODULE hModule) {
    InitializeCriticalSection(&Critical_getclass);
    InitializeCriticalSection(&Critical_findclass);

    Negasth::hModule = hModule;
    Negasth::window = getCurrentWindow();

    oldWinProc = (WNDPROC)SetWindowLongPtr(Negasth::window, GWLP_WNDPROC, (LONG_PTR)myWindowProc);

    glHOOK::SetupHook();

    jsize count{ 0 };
    if (JNI_GetCreatedJavaVMs(&Negasth::p_jvm, 1, &count) != JNI_OK) {
        MessageBox(0, "JNI_GetCreatedJavaVMs", 0, 0);
        return FALSE;
    }

    Negasth::p_jvm->AttachCurrentThreadAsDaemon(reinterpret_cast<void**>(&Negasth::p_env), nullptr);
    if (Negasth::p_env == nullptr) {
        MessageBox(0, "AttachCurrentThreadAsDaemon", 0, 0);
        return FALSE;
    }
    Negasth::p_jvm->GetEnv(reinterpret_cast<void**>(&Negasth::p_env), JNI_VERSION_1_8);

    Negasth::version = Negasth::versions[0];
    Negasth::jsonInit = Negasth::JavaClass::init();

    return TRUE;
}
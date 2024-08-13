#include "Negasth.h"
#include "Cache/Cache.h"
#include"Modules/Modules.h"
#include "Hook/glHook.h"
#include "../net/Minecraft/item/ItemBow.h"
#include "../net/Minecraft/network/play/client/C03PacketPlayer/C06PacketPlayerPosLook/C06PacketPlayerPosLook.h"
#include "../net/Minecraft/network/play/client/C03PacketPlayer/C04PacketPlayerPosition/C04PacketPlayerPosition.h"

WNDPROC oldWinProc;

LRESULT CALLBACK myWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static JNIEnv* netEnv;
    if (netEnv == NULL) {
        Negasth::p_jvm->AttachCurrentThreadAsDaemon((void**)&netEnv, nullptr);
    }
    switch (uMsg) {
    case WM_RBUTTONUP: // ÓÒ¼üµ¯Æð
        jobject holdItem = Negasth::cache->thePlayer.getHeldItem(netEnv).getItem(netEnv).getInstance();
        if (holdItem != NULL && Negasth::p_env->IsInstanceOf(holdItem, ItemBow::ItemBowClass.getJclass(netEnv))) {
            Negasth::Maths::Vector2d rotation = Negasth::cache->thePlayer.getRotation(netEnv);
            Negasth::Maths::Vector3d position = Negasth::cache->thePlayer.getPosition(netEnv);
            Negasth::Maths::Vector3d movement = Negasth::cache->thePlayer.getMovementVector(Negasth::cache->timer.getRenderPartialTicks());
            
            if (movement.x > 0.0) {
                Negasth::cache->NetHandler.addToSendQueue(C06PacketPlayerPosLook::newObject(position + Negasth::Maths::Vector3d(1.0E-5, 0, 0), rotation, true, netEnv), netEnv);
			}
			if (movement.x < 0.0) {
				Negasth::cache->NetHandler.addToSendQueue(C06PacketPlayerPosLook::newObject(position - Negasth::Maths::Vector3d(1.0E-5, 0, 0), rotation, true, netEnv), netEnv);
			}
            if (movement.z > 0.0) {
                Negasth::cache->NetHandler.addToSendQueue(C06PacketPlayerPosLook::newObject(position + Negasth::Maths::Vector3d(0, 0, 1.0E-5), rotation, true, netEnv), netEnv);
            }
            if (movement.z < 0.0) {
                Negasth::cache->NetHandler.addToSendQueue(C06PacketPlayerPosLook::newObject(position - Negasth::Maths::Vector3d(0, 0, 1.0E-5), rotation, true, netEnv), netEnv);
            }
			//if (Negasth::cache->thePlayer.getTicksExisted() % 2 == 0) {
			//	Negasth::cache->NetHandler.addToSendQueue(C04PacketPlayerPosition::newObject(position - Negasth::Maths::Vector3d(0, 0, 1.0E-6), true, netEnv), netEnv);
			//}
   //         else if (Negasth::cache->thePlayer.getTicksExisted() % 3 == 0) {
   //             Negasth::cache->NetHandler.addToSendQueue(C04PacketPlayerPosition::newObject(position - Negasth::Maths::Vector3d(1.0E-6, 0, 0), true, netEnv), netEnv);
   //         }

           //for (int i = 0; i < 5; i++) {
            //    Negasth::cache->NetHandler.addToSendQueue(C06PacketPlayerPosLook::newObject(position + Negasth::Maths::Vector3d(0, i*1.0E-9, 0), rotation+ Negasth::Maths::Vector2d(0.0f, 1.0E-5f), true, netEnv), netEnv);
            //    if (Negasth::cache->thePlayer.getTicksExisted() % 2 == 0) {
            //        Negasth::cache->NetHandler.addToSendQueue(C04PacketPlayerPosition::newObject(position - Negasth::Maths::Vector3d(0, 1.0E-6, 0), true, netEnv), netEnv);
            //    }
            //}
        }
    }
    return CallWindowProc(oldWinProc, hwnd, uMsg, wParam, lParam);
}

void Negasth::Loop() {
    while (!GetAsyncKeyState(VK_END))
    {

        static Negasth::CTimer timer = std::chrono::milliseconds(2);
        if (!timer.isElapsed() || !Negasth::cache->fillCache())continue;

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
    InitializeCriticalSection(&Critical);


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


    return TRUE;
}
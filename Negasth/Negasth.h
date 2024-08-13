#pragma once

#include<Windows.h>
#include<thread>
#include<iostream>

#include"JNI/jni.h"
#include"JNI/jvmti.h"

namespace Negasth {
	inline HINSTANCE hModule = nullptr;
	inline HWND window = nullptr;

	inline JavaVM* p_jvm = nullptr;
	inline JNIEnv* p_env = nullptr;
	inline jvmtiEnv* p_tienv = nullptr;
	inline FILE* file;

	BOOL init(HMODULE hModule);
	void Loop();
	HWND getCurrentWindow();

	class CTimer {
	public:
		CTimer(std::chrono::milliseconds everyXms);
		bool isElapsed();
		void setEvery(std::chrono::milliseconds everyXms);
		void reset();
	private:
		std::chrono::steady_clock::time_point timerBegin;
		std::chrono::milliseconds targetMs;
	};
}
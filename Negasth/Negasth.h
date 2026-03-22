#pragma once

#include<Windows.h>
#include<thread>
#include<iostream>

#include"JNI/jni.h"
#include"JNI/jvmti.h"

namespace Negasth {
	inline HINSTANCE hModule = nullptr;
	inline HWND window = nullptr;

	struct Version{
		const char* mapping_text = nullptr;
		enum {
			UNDEFINED,
			MAJOR_1_8_9,
			MAJOR_1_18
		}type = UNDEFINED;
	};
	extern Version versions[];
	inline Version version{};

	inline JavaVM* p_jvm = nullptr;
	inline JNIEnv* p_env = nullptr;
	inline jvmtiEnv* p_tienv = nullptr;
	inline FILE* file;
	inline BOOL jsonInit;
	inline BOOL enable = true;

	BOOL init(HMODULE hModule);
	void Clear();
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
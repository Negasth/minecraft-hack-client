#include "C0DPacketCloseWindow.h"

C0DPacketCloseWindow C0DPacketCloseWindow::newObject(JNIEnv* env)
{
	if (!env) C0DPacketCloseWindow(nullptr, env);
	return C0DPacketCloseWindow(
		env->NewObject(C0DPacketCloseWindowClass.getJclass(env), C0DPacketCloseWindowClass.getMethodID("<init>"))
	);
}

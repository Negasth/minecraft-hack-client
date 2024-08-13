#include "RenderPlayer.h"

void RenderPlayer::renderOffsetLivingLabel(EntityPlayer target, EntityPlayer thePlayer, JNIEnv* otherEnv)
{
	if (!instance)return;
	Negasth::Maths::Vector3d sub = target.getPosition(otherEnv) - thePlayer.getPosition(otherEnv);
	const char* str = "Hello from C++";
	jstring jStr = env->NewStringUTF(str);
	jint maxDis = 64;
	otherEnv->CallVoidMethod(instance, otherEnv->GetMethodID(RenderPlayerClass.getJclass(otherEnv), "func_177069_a", "(Lnet/minecraft/client/entity/AbstractClientPlayer;DDDLjava/lang/String;FD)V"), target.getInstance(), (jdouble)sub.x, (jdouble)sub.y, (jdouble)sub.z, jStr, (jfloat)0.0f, (jdouble)0.0);
}

#include "Render.h"

void Render::renderLivingLabel(EntityPlayer target, EntityPlayer thePlayer, JNIEnv* otherEnv)
{
	if (!instance)return;
	Negasth::Maths::Vector3d Sub = target.getPosition(otherEnv) - thePlayer.getPosition(otherEnv);
	const char* str = "Hello from C++";
	jstring jStr = env->NewStringUTF(str);
	jint maxDis = 64;
	otherEnv->CallVoidMethod(instance, otherEnv->GetMethodID(RenderClass.getJclass(otherEnv), "func_147906_a", "(Lnet/minecraft/entity/Entity;Ljava/lang/String;DDDI)V"), target.getInstance(), jStr, Sub.x, Sub.y, Sub.z, maxDis);
}

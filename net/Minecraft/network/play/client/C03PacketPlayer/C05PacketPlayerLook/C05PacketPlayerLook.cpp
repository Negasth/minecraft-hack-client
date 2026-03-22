#include "C05PacketPlayerLook.h"

C05PacketPlayerLook C05PacketPlayerLook::newObject(float yaw, float pitch, bool isOnGround, JNIEnv* otherEnv)
{
	if (!otherEnv)return C05PacketPlayerLook{};
	return C05PacketPlayerLook(
		otherEnv->NewObject(C05PacketPlayerLookClass.getJclass(otherEnv),C05PacketPlayerLookClass.getMethodID("<init>"),(jfloat)yaw,(jfloat)pitch, (isOnGround ? JNI_TRUE : JNI_FALSE))
	);
}

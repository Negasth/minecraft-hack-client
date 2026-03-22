#include "C06PacketPlayerPosLook.h"

C06PacketPlayerPosLook C06PacketPlayerPosLook::newObject(const Negasth::Maths::Vector3d& position, const Negasth::Maths::Vector2d& rotation, bool isOnGround, JNIEnv* env)
{
	if (!env)
		return C06PacketPlayerPosLook(nullptr, env);
	return C06PacketPlayerPosLook
	(
		env->NewObject
		(
			C06PacketPlayerPosLookClass.getJclass(env),
			C06PacketPlayerPosLookClass.getMethodID("<init>"),
			(jdouble)position.x,
			(jdouble)position.y,
			(jdouble)position.z,
			(jfloat)rotation.x,
			(jfloat)rotation.y,
			(isOnGround ? JNI_TRUE : JNI_FALSE)
		),
		env
	);
}


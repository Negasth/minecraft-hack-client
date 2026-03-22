#include "C04PacketPlayerPosition.h"

C04PacketPlayerPosition C04PacketPlayerPosition::newObject(const Negasth::Maths::Vector3d& position, bool isOnGround, JNIEnv* env)
{
	if (!env)
		return C04PacketPlayerPosition(nullptr, env);
	return C04PacketPlayerPosition
	(
		env->NewObject
		(
			C04PacketPlayerPositionClass.getJclass(env),
			C04PacketPlayerPositionClass.getMethodID("<init>"),
			(jdouble)position.x,
			(jdouble)position.y,
			(jdouble)position.z,
			(isOnGround ? JNI_TRUE : JNI_FALSE)
		),
		env
	);
}
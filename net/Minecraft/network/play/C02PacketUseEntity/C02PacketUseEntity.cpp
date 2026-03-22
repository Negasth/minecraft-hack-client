#include "C02PacketUseEntity.h"

C02PacketUseEntity C02PacketUseEntity::newObject(Entity target,JNIEnv* env)
{
	if (!env)return C02PacketUseEntity();
	jobject attackAction = env->GetStaticObjectField(ActionClass.getJclass(env), env->GetStaticFieldID(ActionClass.getJclass(env), "ATTACK", "Lnet/minecraft/network/play/client/C02PacketUseEntity$Action;"));
	return C02PacketUseEntity(env->NewObject(C02PacketUseEntityClass.getJclass(env),C02PacketUseEntityClass.getMethodID("<init>"), target.getInstance(), attackAction));
}

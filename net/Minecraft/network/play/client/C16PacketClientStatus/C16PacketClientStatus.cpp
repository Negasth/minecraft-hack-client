#include "C16PacketClientStatus.h"

C16PacketClientStatus C16PacketClientStatus::newObject(JNIEnv* env)
{
	if (!env) return C16PacketClientStatus(nullptr, env);
	jobject enumState = env->GetStaticObjectField(EnumStateClass.getJclass(env), env->GetStaticFieldID(EnumStateClass.getJclass(env), "OPEN_INVENTORY_ACHIEVEMENT", "Lnet/minecraft/network/play/client/C16PacketClientStatus$EnumState;"));
	return C16PacketClientStatus(env->NewObject(C16PacketClientStatusClass.getJclass(env), C16PacketClientStatusClass.getMethodID("<init>"), enumState));
}//()Lnet/minecraft/network/play/client/C16PacketClientStatus$EnumState;

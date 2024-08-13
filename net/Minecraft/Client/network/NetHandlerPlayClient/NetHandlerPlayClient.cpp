#include "NetHandlerPlayClient.h"

void NetHandlerPlayClient::addToSendQueue(const Packet& packet, JNIEnv* otherEnv)
{
	if (!instance)
		return;
	otherEnv->CallVoidMethod(instance, otherEnv->GetMethodID(NetHandlerPlayClientClass.getJclass(otherEnv), "func_147297_a","(Lnet/minecraft/network/Packet;)V"), packet.getInstance());
}
#include "NetHandlerPlayClient.h"
<<<<<<< HEAD
#include "../Negasth/Modules/Modules.h"

bool NetHandlerPlayClient::addToSendQueue(const Packet& packet, JNIEnv* otherEnv)
{
	if (!instance)
		return false;

	if (Negasth::Modules::CheckPackets::packetsList.size() >= Negasth::Modules::CheckPackets::maxPackets) {
		//std::cout << "达到最大发包数量!!!" << std::endl;
		return false;
	}

	otherEnv->CallVoidMethod(instance, NetHandlerPlayClientClass.getMethodID("addToSendQueue"), packet.getInstance());
	return true;
=======

void NetHandlerPlayClient::addToSendQueue(const Packet& packet, JNIEnv* otherEnv)
{
	if (!instance)
		return;
	otherEnv->CallVoidMethod(instance, otherEnv->GetMethodID(NetHandlerPlayClientClass.getJclass(otherEnv), "func_147297_a","(Lnet/minecraft/network/Packet;)V"), packet.getInstance());
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
}
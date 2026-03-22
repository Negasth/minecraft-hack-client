#include "NetHandlerPlayClient.h"
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
}
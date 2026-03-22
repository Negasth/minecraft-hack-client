#pragma once
#include "../../Packet/Packet.h"
#include "../../../entity/Entity/Entity.h"

class C02PacketUseEntity :public Packet {
public:
	using Packet::Packet;
	static C02PacketUseEntity newObject(Entity target,JNIEnv* env = Negasth::p_env);
protected:
	inline static Negasth::JavaClass C02PacketUseEntityClass{ "net/minecraft/network/play/client/C02PacketUseEntity" };
	inline static Negasth::JavaClass ActionClass{ "net/minecraft/network/play/client/C02PacketUseEntity$Action" };
};
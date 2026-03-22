#pragma once
#include "../../../Packet/Packet.h"

class C16PacketClientStatus : public Packet
{
public:
	using Packet::Packet;
	static C16PacketClientStatus newObject(JNIEnv* env = Negasth::p_env);
protected:
	inline static Negasth::JavaClass C16PacketClientStatusClass{ "net/minecraft/network/play/client/C16PacketClientStatus" };
	inline static Negasth::JavaClass EnumStateClass{ "net/minecraft/network/play/client/C16PacketClientStatus$EnumState" };
};
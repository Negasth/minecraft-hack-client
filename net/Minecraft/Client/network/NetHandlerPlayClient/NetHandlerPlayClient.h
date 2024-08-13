#pragma once
#include "../../../../../java/lang/Object/Object.h"
#include "../../../network/Packet/Packet.h"
#include "../Negasth/JavaClass/JavaClass.h"

class NetHandlerPlayClient : public Object
{
public:
	using Object::Object;
	void addToSendQueue(const Packet& packet, JNIEnv* otherEnv = Negasth::p_env);
protected:
	inline static Negasth::JavaClass NetHandlerPlayClientClass{ "net/minecraft/client/network/NetHandlerPlayClient" };
};
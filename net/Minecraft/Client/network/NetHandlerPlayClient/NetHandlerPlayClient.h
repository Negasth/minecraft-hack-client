#pragma once
#include "../../../../../java/lang/Object/Object.h"
#include "../../../network/Packet/Packet.h"
#include "../Negasth/JavaClass/JavaClass.h"

class NetHandlerPlayClient : public Object
{
public:
	using Object::Object;
<<<<<<< HEAD
	bool addToSendQueue(const Packet& packet, JNIEnv* otherEnv = Negasth::p_env);
=======
	void addToSendQueue(const Packet& packet, JNIEnv* otherEnv = Negasth::p_env);
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
protected:
	inline static Negasth::JavaClass NetHandlerPlayClientClass{ "net/minecraft/client/network/NetHandlerPlayClient" };
};
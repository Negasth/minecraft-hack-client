#pragma once
#include "../../../../java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class Packet : public Object
{
public:
	using Object::Object;
protected:
	inline static Negasth::JavaClass PacketClass{ "net/minecraft/network/Packet" };
};
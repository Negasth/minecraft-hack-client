#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
#include "MovingObjectType/MovingObjectType.h"
#include "../net/Minecraft/entity/Entity/Entity.h"

class MovingObjectPosition : public Object {
public:
	using Object::Object;
	MovingObjectType getType();
	Entity getEntityHit();
protected:
	inline static Negasth::JavaClass MovingObjectPositionClass{ "net/minecraft/util/MovingObjectPosition" };
};
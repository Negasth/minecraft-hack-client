#pragma once

#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class InventoryPlayer : public Object {
public:
	using Object::Object;
	int getCurrentItem();
	jobjectArray getMainInventory();
	jobjectArray getArmorInventory();
protected:
	inline static Negasth::JavaClass InventoryPlayerClass{ "net/minecraft/entity/player/InventoryPlayer" };
};

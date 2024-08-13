#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class Item : public Object {
public:
	using Object::Object;

protected:
	inline static Negasth::JavaClass ItemClass{ "net/minecraft/item/Item" };
};
#pragma once
#include "Item.h"

class ItemStack : public Object {
public:
	using Object::Object;
	Item getItem(JNIEnv* otherEnv = Negasth::p_env);
protected:
	inline static Negasth::JavaClass ItemStackClass{ "net/minecraft/item/ItemStack" };
};
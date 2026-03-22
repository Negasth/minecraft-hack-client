#pragma once
#include "../Item/Item.h"

class ItemArmor : public Item {
public:
	using Item::Item;
	int getArmorType();
	int getdamageReduceAmount();
	inline static Negasth::JavaClass ItemArmorClass{ "net/minecraft/item/ItemArmor" };
protected:

};
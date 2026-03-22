#pragma once
#include "../Item/Item.h"

class ItemSword : public Item {
public:
	using Item::Item;
	inline static Negasth::JavaClass ItemSwordClass{ "net/minecraft/item/ItemSword" };
protected:

};
#pragma once
#include "Item.h"

class ItemBow : public Item {
public:
	using Item::Item;
	inline static Negasth::JavaClass ItemBowClass{ "net/minecraft/item/ItemBow" };
protected:

};
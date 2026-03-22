#pragma once
#include "../Item/Item.h"

class ItemBlock : public Item {
public:
	using Item::Item;
	inline static Negasth::JavaClass ItemBlockClass{ "net/minecraft/item/ItemBlock" };
protected:

};
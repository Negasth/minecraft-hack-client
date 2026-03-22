#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
class GuiInventory : public Object
{
public:
	using Object::Object;
	inline static Negasth::JavaClass GuiInventoryClass{ "net/minecraft/client/gui/inventory/GuiInventory" };
protected:
	
};


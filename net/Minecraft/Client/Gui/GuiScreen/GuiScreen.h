#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
class GuiScreen : public Object
{
public:
	using Object::Object;
protected:
	inline static Negasth::JavaClass GuiScreenClass{ "net/minecraft/client/gui/GuiScreen" };
};


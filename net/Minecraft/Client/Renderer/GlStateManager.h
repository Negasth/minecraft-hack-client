#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class GlStateManager :public Object{
public:
	using Object::Object;
	static void disableDepth();
protected:
	inline static Negasth::JavaClass GlStateManagerClass{ "net/minecraft/client/renderer/GlStateManager" };
};
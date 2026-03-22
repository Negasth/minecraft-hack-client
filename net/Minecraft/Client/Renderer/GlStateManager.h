<<<<<<< HEAD
#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class GlStateManager :public Object{
public:
	using Object::Object;
	static void disableDepth();
protected:
	inline static Negasth::JavaClass GlStateManagerClass{ "net/minecraft/client/renderer/GlStateManager" };
=======
#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class GlStateManager :public Object{
public:
	using Object::Object;
	static void disableDepth();
protected:
	inline static Negasth::JavaClass GlStateManagerClass{ "net/minecraft/client/renderer/GlStateManager" };
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
};
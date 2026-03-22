#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class Container :public Object {
public:
	using Object::Object;
	int getwindowId();
protected:
	Negasth::JavaClass ContainerClass{ "net/minecraft/inventory/Container" };
};
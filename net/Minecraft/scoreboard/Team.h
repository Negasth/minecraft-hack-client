#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class Team : public Object {
public:
	using Object::Object;
protected:
	inline static Negasth::JavaClass TeamClass{ "net/minecraft/scoreboard/Team" };
};
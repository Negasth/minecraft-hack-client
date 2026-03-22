#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
#include "../Java/util/Collection/Collection.h"

class Scoreboard : public Object {
public:
	using Object::Object;
	Collection getTeamNames();
protected:
	inline static Negasth::JavaClass ScoreboardClass{ "net/minecraft/scoreboard/Scoreboard" };
};
#pragma once
#include "Team.h"

class ScorePlayerTeam : public Team {
public:
	using Team::Team;
	const char* getTeamName(JNIEnv* otherEnv = Negasth::p_env) const;
	const char* getColorPrefix() const;
protected:
	inline static Negasth::JavaClass ScorePlayerTeamClass{ "net/minecraft/scoreboard/ScorePlayerTeam" };
};
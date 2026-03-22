#include "Scoreboard.h"

Collection Scoreboard::getTeamNames()
{
	if (!instance)return Collection();
	env->CallObjectMethod(instance, ScoreboardClass.getMethodID("getTeamNames"));
	return Collection();
}

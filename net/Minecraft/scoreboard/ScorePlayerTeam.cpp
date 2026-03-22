#include "ScorePlayerTeam.h"

const char* ScorePlayerTeam::getTeamName(JNIEnv* otherEnv) const
{
	if (!instance)return NULL;
	jstring jName = (jstring)otherEnv->CallObjectMethod(instance, ScorePlayerTeamClass.getMethodID("getTeamName"));
	const char* cName = otherEnv->GetStringUTFChars(jName, nullptr);
	return cName;
}

const char* ScorePlayerTeam::getColorPrefix() const
{
	if (!instance)return NULL;
	jstring jName = (jstring)env->CallObjectMethod(instance, ScorePlayerTeamClass.getMethodID("getColorPrefix"));
	const char* cName = env->GetStringUTFChars(jName, nullptr);
	return cName;
}

#include "EntityPlayer.h"

bool EntityPlayer::canAttackPlayer(EntityPlayer other)
{
	if (!instance)return false;
	return env->CallBooleanMethod(instance, env->GetMethodID(EntityPlayerClass.getJclass(env), "func_96122_a", "(Lnet/minecraft/entity/player/EntityPlayer;)Z"), other.getInstance());
}

jstring EntityPlayer::getName() const
{
	if (!instance)return jstring();
	jstring jName = (jstring)env->CallObjectMethod(instance, env->GetMethodID(EntityPlayerClass.getJclass(env), "func_70005_c_", "()Ljava/lang/String;"));
	return jName;
}

Team EntityPlayer::getTeam(JNIEnv* otherEnv) const
{
	if (!instance)return Team();
	return Team(otherEnv->CallObjectMethod(instance, otherEnv->GetMethodID(EntityPlayerClass.getJclass(otherEnv), "func_96124_cp", "()Lnet/minecraft/scoreboard/Team;")));
}

ItemStack EntityPlayer::getHeldItem(JNIEnv* otherEnv)
{
	if (!instance)return ItemStack{};
	return ItemStack(otherEnv->CallObjectMethod(instance,otherEnv->GetMethodID(EntityPlayerClass.getJclass(otherEnv),"func_70694_bm","()Lnet/minecraft/item/ItemStack;")));
}

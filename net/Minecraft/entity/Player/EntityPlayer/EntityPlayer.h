#pragma once
#include "../../EntityLivingBase/EntityLivingBase.h"
#include "../net/Minecraft/scoreboard/ScorePlayerTeam.h"
#include "../../../item/ItemStack.h"

class EntityPlayer : public EntityLivingBase {
public:
	using EntityLivingBase::EntityLivingBase;
	bool canAttackPlayer(EntityPlayer other);
	jstring getName() const;
	Team getTeam(JNIEnv* otherEnv = Negasth::p_env)const;
	ItemStack getHeldItem(JNIEnv* otherEnv = Negasth::p_env);

	inline static Negasth::JavaClass EntityPlayerClass{ "net/minecraft/entity/player/EntityPlayer" };
protected:
	
};
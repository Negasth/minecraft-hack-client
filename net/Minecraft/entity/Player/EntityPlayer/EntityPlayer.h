#pragma once
#include "../../EntityLivingBase/EntityLivingBase.h"
#include "../net/Minecraft/scoreboard/ScorePlayerTeam.h"
#include "../../../item/ItemStack/ItemStack.h"
#include "../InventoryPlayer/InventoryPlayer.h"
#include "../../../Inventory/Container/Container.h"

class EntityPlayer : public EntityLivingBase {
public:
	using EntityLivingBase::EntityLivingBase;
	bool canAttackPlayer(EntityPlayer other);
	jstring getName() const;
	Team getTeam(JNIEnv* otherEnv = Negasth::p_env)const;
	ItemStack getHeldItem(JNIEnv* otherEnv = Negasth::p_env);
	InventoryPlayer getInventory();
	int getItemInUseDuration(JNIEnv* otherEnv = Negasth::p_env);
	Container getOpenContainer();
	bool isBlocking();

	void setItemInUse(ItemStack itemStack);
	inline static Negasth::JavaClass EntityPlayerClass{ "net/minecraft/entity/player/EntityPlayer" };
protected:
	
};
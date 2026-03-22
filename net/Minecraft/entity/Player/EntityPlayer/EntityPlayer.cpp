<<<<<<< HEAD
#include "EntityPlayer.h"

bool EntityPlayer::canAttackPlayer(EntityPlayer other)
{
	if (!instance)return false;
	return env->CallBooleanMethod(instance, EntityPlayerClass.getMethodID("canAttackPlayer"), other.getInstance());
}

jstring EntityPlayer::getName() const
{
	if (!instance)return jstring();
	jstring jName = (jstring)env->CallObjectMethod(instance, EntityPlayerClass.getMethodID("getName"));
	return jName;
}

Team EntityPlayer::getTeam(JNIEnv* otherEnv) const
{
	if (!instance)return Team();
	return Team(otherEnv->CallObjectMethod(instance, EntityPlayerClass.getMethodID("getTeam")));
}

ItemStack EntityPlayer::getHeldItem(JNIEnv* otherEnv)
{
	if (!instance)return ItemStack{};
	return ItemStack(otherEnv->CallObjectMethod(instance,EntityPlayerClass.getMethodID("getHeldItem")));
}

InventoryPlayer EntityPlayer::getInventory()
{
	if (!instance)return InventoryPlayer();
	return InventoryPlayer(
		env->GetObjectField(instance, EntityPlayerClass.getFieldID("inventory")),
		env, true
	);
}

int EntityPlayer::getItemInUseDuration(JNIEnv* otherEnv)
{
	if (!instance)return 0;
	return otherEnv->CallIntMethod(instance, EntityPlayerClass.getMethodID("getItemInUseDuration"));
}

Container EntityPlayer::getOpenContainer()
{
	if (!instance)return Container();
	return Container(env->GetObjectField(instance, EntityPlayerClass.getFieldID("openContainer")));
}

bool EntityPlayer::isBlocking()
{
	if (!instance)return false;
	return env->CallBooleanMethod(instance,EntityPlayerClass.getMethodID("isBlocking"));
}
//Î´Ìí¼Ójson
void EntityPlayer::setItemInUse(ItemStack itemStack)
{
	if (!instance)return;
	env->SetObjectField(instance,EntityPlayerClass.getFieldID("itemInUse"),itemStack.getInstance());
}
=======
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
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87

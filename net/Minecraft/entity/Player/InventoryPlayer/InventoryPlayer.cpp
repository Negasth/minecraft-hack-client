#include "InventoryPlayer.h"

int InventoryPlayer::getCurrentItem()
{
	if (!instance)return -1;
	return env->GetIntField(instance, InventoryPlayerClass.getFieldID("currentItem"));
}

jobjectArray InventoryPlayer::getMainInventory()
{
	if (!instance)return NULL;
	return (jobjectArray)env->GetObjectField(instance,InventoryPlayerClass.getFieldID("mainInventory"));
}

jobjectArray InventoryPlayer::getArmorInventory()
{
	if (!instance)return NULL;
	return (jobjectArray)env->GetObjectField(instance,InventoryPlayerClass.getFieldID("armorInventory"));
}

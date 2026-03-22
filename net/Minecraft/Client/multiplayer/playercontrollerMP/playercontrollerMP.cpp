#include "playercontrollerMP.h"

void PlayercontrollerMP::WindowClick(jint windowId, jint slotId, jint mouseButtonClicked, jint mode, EntityPlayer playerIn)
{
	if (!instance)return;
	env->CallObjectMethod(instance, PlayercontrollerMPClass.getMethodID("windowClick"), windowId, slotId, mouseButtonClicked, mode, playerIn.getInstance());
}

float PlayercontrollerMP::getcurBlockDamageMP()
{
	if (!instance)return 0.0f;
	return env->GetFloatField(instance,PlayercontrollerMPClass.getFieldID("curBlockDamageMP"));
}

void PlayercontrollerMP::setcurBlockDamageMP(float val)
{
	if (!instance)return;
	return env->SetFloatField(instance, PlayercontrollerMPClass.getFieldID("curBlockDamageMP"),(jfloat)val);
}

void PlayercontrollerMP::AttackEntity(EntityPlayer player, Entity target)
{
	if (!instance)return;
	env->CallVoidMethod(instance, PlayercontrollerMPClass.getMethodID("attackEntity"),player.getInstance(),target.getInstance());
}
//Î´Ð´Èëjson
void PlayercontrollerMP::onStoppedUsingItem(EntityPlayer player)
{
	if (!instance)return;
	env->CallVoidMethod(instance, PlayercontrollerMPClass.getMethodID("onStoppedUsingItem"), player.getInstance());
}
//Î´Ð´Èëjson
void PlayercontrollerMP::sendUseItem(EntityPlayer player, World world, ItemStack itemStack)
{
	if (!instance)return;
	env->CallBooleanMethod(instance, PlayercontrollerMPClass.getMethodID("sendUseItem"), player.getInstance(),world.getInstance(),itemStack.getInstance());
}

#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
#include "../net/Minecraft/entity/Player/EntityPlayer/EntityPlayer.h"
#include "../net/Minecraft/World/world.h"

class PlayercontrollerMP :public Object {
public:
	using Object::Object;
	void WindowClick(jint windowId, jint slotId, jint mouseButtonClicked, jint mode, EntityPlayer playerIn);
	float getcurBlockDamageMP();
	void setcurBlockDamageMP(float val);
	void AttackEntity(EntityPlayer player, Entity target);
	void onStoppedUsingItem(EntityPlayer player);
	void sendUseItem(EntityPlayer player, World world, ItemStack itemStack);
protected:
	inline static Negasth::JavaClass PlayercontrollerMPClass{ "net/minecraft/client/multiplayer/PlayerControllerMP" };
};
#include "Modules.h"
#include "../Cache/Cache.h"
#include "../net/Minecraft/Client/Gui/Inventory/GuiInventory/GuiInventory.h"
#include "../net/Minecraft/item/ItemArmor/ItemArmor.h"

void Negasth::Modules::AutoArmor::run() {
	if (!cache->theMinecraft.getCurrentScreen().isValid())
		return;
	if (!Negasth::p_env->IsInstanceOf(cache->theMinecraft.getCurrentScreen().getInstance(), GuiInventory::GuiInventoryClass.getJclass(Negasth::p_env)))
		return;

	for (int type = 0; type < 4; type++) {
		if (Negasth::p_env->GetObjectArrayElement(cache->inventory.getArmorInventory(), type) == nullptr) {
			int value = -1;
			int index = -1;

			jobjectArray mainInventory = cache->inventory.getMainInventory();
			jint len = Negasth::p_env->GetArrayLength(mainInventory);
			for (jint i = 0; i < len; i++) {
				if (ItemStack(Negasth::p_env->GetObjectArrayElement(mainInventory, i)).getItem().isValid() &&
					Negasth::p_env->IsInstanceOf(ItemStack(Negasth::p_env->GetObjectArrayElement(mainInventory, i)).getItem().getInstance(), ItemArmor::ItemArmorClass.getJclass(Negasth::p_env)) &&
					ItemArmor(ItemStack(Negasth::p_env->GetObjectArrayElement(mainInventory, i)).getItem().getInstance()).getArmorType() == abs(type - 3) &&
					ItemArmor(ItemStack(Negasth::p_env->GetObjectArrayElement(mainInventory, i)).getItem().getInstance()).getdamageReduceAmount() > value
					) {
					value = ItemArmor(ItemStack(Negasth::p_env->GetObjectArrayElement(mainInventory, i)).getItem().getInstance()).getdamageReduceAmount();
					index = i;
				}
			}
			if (index >= 0) {
				if (index < 9)
					index += 36;
				cache->playerController.WindowClick(cache->thePlayer.getOpenContainer().getwindowId(), index, 0, 1, cache->thePlayer);
			}
		}
	}
}
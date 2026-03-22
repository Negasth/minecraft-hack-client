#include "Modules.h"
#include "../Cache/Cache.h"
#include "../net/Minecraft/network/play/client/C16PacketClientStatus/C16PacketClientStatus.h"
#include "../net/Minecraft/network/play/client/C0DPacketCloseWindow/C0DPacketCloseWindow.h"

void Negasth::Modules::Refill::run() {
	if (!(GetKeyState(VK_RBUTTON) & 0x8000)|| cache->theMinecraft.getCurrentScreen().isValid())return;

	if (cache->inventory.getCurrentItem() != preIndex) {
		preItem = cache->thePlayer.getHeldItem().getItem();
		preIndex = cache->inventory.getCurrentItem();
		return;
	}

	if (cache->thePlayer.getHeldItem().getItem().isValid()) {
		preItem = cache->thePlayer.getHeldItem().getItem();
		preIndex = cache->inventory.getCurrentItem();
		return;
	}
	if (!preItem.isValid())
		return;

	jobjectArray mainInventory = cache->inventory.getMainInventory();
	jint len = Negasth::p_env->GetArrayLength(mainInventory);
	for (jint i = 0; i < len; i++) {
		jobject tmpObject = Negasth::p_env->GetObjectArrayElement(mainInventory, i);

		ItemStack tmpStack(tmpObject);
		if (tmpStack.getItem().isEqualto(preItem)) {
			int index = 0;
			if (i < 9)
				index = i + 36;
			else
				index = i;
			cache->NetHandler.addToSendQueue(C16PacketClientStatus::newObject());
			cache->playerController.WindowClick(cache->thePlayer.getOpenContainer().getwindowId(), index, cache->inventory.getCurrentItem(), 2, cache->thePlayer);
			cache->NetHandler.addToSendQueue(C0DPacketCloseWindow::newObject());
			return;
		}


		Negasth::p_env->DeleteLocalRef(tmpStack.getInstance());
	}

	Negasth::p_env->DeleteLocalRef(mainInventory);
}
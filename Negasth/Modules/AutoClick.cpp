#include "Modules.h"
#include "../Cache/Cache.h"

void Negasth::Modules::AutoClick::run() {
	static CTimer timer(std::chrono::milliseconds(1000 / min_cps));
	if (!(GetKeyState(VK_LBUTTON) & 0x8000)||cache->theMinecraft.getCurrentScreen().isValid())
		return;
	if (!timer.isElapsed())
		return;
	POINT cursorPos{};
	GetCursorPos(&cursorPos);
	if (Negasth::cache->theMinecraft.getObjectMouseOver().getType().isEqualto(MovingObjectType::getType("BLOCK"))) {
		PostMessageA(Negasth::window, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));
		return;
	}
	if (cache->thePlayer.isBlocking()) {
		//cache->thePlayer.setItemInUse(ItemStack{});
		//PostMessageA(Negasth::window, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));
		//PostMessageA(Negasth::window, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));

		//cache->playerController.sendUseItem(cache->thePlayer, cache->theWorld, cache->thePlayer.getHeldItem());
		//cache->thePlayer.setItemInUse(cache->thePlayer.getHeldItem());
		//PostMessageA(Negasth::window, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));
		//PostMessageA(Negasth::window, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));

		cache->theMinecraft.ClickMouse();
	}
	else {
		//cache->playerController.onStoppedUsingItem(cache->thePlayer);
		PostMessageA(Negasth::window, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));
		PostMessageA(Negasth::window, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));
	}
	//cache->theMinecraft.ClickMouse();


	std::uniform_int_distribution<> distr(min_cps, max_cps);
	timer.setEvery(std::chrono::milliseconds(1000 / distr(gen)));
}
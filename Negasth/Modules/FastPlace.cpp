#include "Modules.h"
#include "../Cache/Cache.h"

void Negasth::Modules::FastPlace::run() {
	if (!GetAsyncKeyState(VK_RBUTTON))return;
	if (Negasth::cache->theMinecraft.getRightClickDelayTimer() == 4) {
		Negasth::cache->theMinecraft.setRightClickDelayTimer(0);
	}
}
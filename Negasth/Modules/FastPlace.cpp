#include "Modules.h"
#include "../Cache/Cache.h"

void Negasth::Modules::FastPlace::run() {
	if (!(GetKeyState(VK_RBUTTON) & 0x8000))return;
	if (Negasth::cache->theMinecraft.getRightClickDelayTimer() == 4) {
		Negasth::cache->theMinecraft.setRightClickDelayTimer(0);
	}
}
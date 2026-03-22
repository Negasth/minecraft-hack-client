<<<<<<< HEAD
#include "Modules.h"
#include "../Cache/Cache.h"

void Negasth::Modules::FastPlace::run() {
	if (!(GetKeyState(VK_RBUTTON) & 0x8000))return;
	if (Negasth::cache->theMinecraft.getRightClickDelayTimer() == 4) {
		Negasth::cache->theMinecraft.setRightClickDelayTimer(0);
	}
=======
#include "Modules.h"
#include "../Cache/Cache.h"

void Negasth::Modules::FastPlace::run() {
	if (!GetAsyncKeyState(VK_RBUTTON))return;
	if (Negasth::cache->theMinecraft.getRightClickDelayTimer() == 4) {
		Negasth::cache->theMinecraft.setRightClickDelayTimer(0);
	}
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
}
#include "Modules.h"
#include "../Cache/Cache.h"

void Negasth::Modules::AutoClick::run() {
	static CTimer timer(std::chrono::milliseconds(1000 / min_cps));
	if (!(GetKeyState(VK_LBUTTON) & 0x8000)||cache->theMinecraft.getCurrentScreen().isValid())
		return;
	if (!timer.isElapsed())
		return;
	if (Negasth::cache->theMinecraft.getObjectMouseOver().getType().isEqualto(MovingObjectType::getType("BLOCK")))
		return;

	POINT cursorPos{};
	GetCursorPos(&cursorPos);
	PostMessageA(Negasth::window, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));
	PostMessageA(Negasth::window, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(cursorPos.x, cursorPos.y));
	std::uniform_int_distribution<> distr(min_cps, max_cps);
	timer.setEvery(std::chrono::milliseconds(1000 / distr(gen)));
}
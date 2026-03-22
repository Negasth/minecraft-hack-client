#include "Modules.h"
#include "../Cache/Cache.h"

void Negasth::Modules::FastBreak::run() {
	if (!(GetKeyState(VK_LBUTTON) & 0x8000) || cache->theMinecraft.getCurrentScreen().isValid())
	{
		lastBlockDamageMP = 0.0f;
		return;
	}
	if (!Negasth::cache->theMinecraft.getObjectMouseOver().getType().isEqualto(MovingObjectType::getType("BLOCK")))
	{
		lastBlockDamageMP = 0.0f;
		return;
	}

	float curBlockDamage = cache->playerController.getcurBlockDamageMP();
	if (curBlockDamage > lastBlockDamageMP) {
		curBlockDamage = (float)(curBlockDamage + (curBlockDamage - lastBlockDamageMP) * 0.05f);
		cache->playerController.setcurBlockDamageMP(curBlockDamage);
		lastBlockDamageMP = curBlockDamage;
	}
	else {
		lastBlockDamageMP = 0.0f;
	}
}
#include "Modules.h"
#include "../Cache/Cache.h"
#include "../net/Minecraft/network/play/C02PacketUseEntity/C02PacketUseEntity.h"


void Negasth::Modules::KillAura::AttackEntitybySendPacket(Entity target) {

	cache->thePlayer.SwingItem();
	Negasth::cache->NetHandler.addToSendQueue(C02PacketUseEntity::newObject(target));

}


void Negasth::Modules::KillAura::run()
{
	static CTimer timer(std::chrono::milliseconds(1000 / min_cps));
	if (!(GetKeyState(VK_LBUTTON) & 0x8000) || cache->theMinecraft.getCurrentScreen().isValid())
		return;
	if (!timer.isElapsed())
		return;
	if (!Negasth::cache->theMinecraft.getObjectMouseOver().getType().isEqualto(MovingObjectType::getType("ENTITY")))
		return;

	AttackEntitybySendPacket(Negasth::cache->theMinecraft.getObjectMouseOver().getEntityHit());


	std::uniform_int_distribution<> distr(min_cps, max_cps);
	timer.setEvery(std::chrono::milliseconds(1000 / distr(gen)));
}
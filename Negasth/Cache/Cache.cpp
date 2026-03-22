#include "Cache.h"

bool Negasth::Cache::fillCache()
{
	theMinecraft = Minecraft::getTheMinecraft();
	if (!theMinecraft.isValid()) {
		return false;
	}


	thePlayer = theMinecraft.getThePlayer();
	if (!thePlayer.isValid()) {
		return false;
	}

	if (!prev_thePlayer.isEqualto(thePlayer)) {
		NetHandler = theMinecraft.getNetHandler();
		playerController = theMinecraft.getPlayerController();
		prev_thePlayer = thePlayer;
		theWorld = theMinecraft.getTheWorld();
		playerEntities = theWorld.getPlayerEntities();
		timer = theMinecraft.getTimer();
		theRenderManager = theMinecraft.getRenderManager();
		RenderPlayer = theRenderManager.getRenderLivingEntity();
		inventory = thePlayer.getInventory();
	}

	return true;
}

void Negasth::Cache::Clear()
{
	theMinecraft.Clear();
	thePlayer.Clear();
	playerEntities.Clear();
	theWorld.Clear();
	timer.Clear();
	theRenderManager.Clear();
	RenderPlayer.Clear();
	glManager.Clear();
	NetHandler.Clear();
	inventory.Clear();
	playerController.Clear();
}

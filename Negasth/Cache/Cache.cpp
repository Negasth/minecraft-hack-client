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
		prev_thePlayer = thePlayer;
		theWorld = theMinecraft.getTheWorld();
		playerEntities = theWorld.getPlayerEntities();
		timer = theMinecraft.getTimer();
		theRenderManager = theMinecraft.getRenderManager();
		RenderPlayer = theRenderManager.getRenderLivingEntity();
	}

	return true;
}

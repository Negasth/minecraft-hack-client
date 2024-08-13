#include "Modules.h"
#include "../Cache/Cache.h"

void Negasth::Modules::NameTag::run() {
	if (Negasth::cache->playerEntities.isValid()) {
		for (EntityPlayer& target : Negasth::cache->playerEntities.toVector<EntityPlayer>())
		{
			if (!target.isValid() /*|| target.isEqualto(cache->thePlayer)*/ /*|| target.getTicksExisted() < 10*/)
				continue;
			cache->RenderPlayer.renderLivingLabel(target, cache->thePlayer);
		}
	}
}
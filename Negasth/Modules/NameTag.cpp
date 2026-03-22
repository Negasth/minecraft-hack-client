<<<<<<< HEAD
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
=======
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
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
}
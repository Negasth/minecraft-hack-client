#pragma once
#include "RenderLivingEntity.h"

class RenderPlayer : public RenderLivingEntity {
public:
	using RenderLivingEntity::RenderLivingEntity;
	void renderOffsetLivingLabel(EntityPlayer target, EntityPlayer thePlayer, JNIEnv* otherEnv);
protected:
	inline static Negasth::JavaClass RenderPlayerClass{ "net/minecraft/client/renderer/entity/RenderPlayer" };
};
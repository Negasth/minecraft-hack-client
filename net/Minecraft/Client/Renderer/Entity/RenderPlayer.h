<<<<<<< HEAD
#pragma once
#include "RenderLivingEntity.h"

class RenderPlayer : public RenderLivingEntity {
public:
	using RenderLivingEntity::RenderLivingEntity;
	void renderOffsetLivingLabel(EntityPlayer target, EntityPlayer thePlayer, JNIEnv* otherEnv);
protected:
	inline static Negasth::JavaClass RenderPlayerClass{ "net/minecraft/client/renderer/entity/RenderPlayer" };
=======
#pragma once
#include "RenderLivingEntity.h"

class RenderPlayer : public RenderLivingEntity {
public:
	using RenderLivingEntity::RenderLivingEntity;
	void renderOffsetLivingLabel(EntityPlayer target, EntityPlayer thePlayer, JNIEnv* otherEnv);
protected:
	inline static Negasth::JavaClass RenderPlayerClass{ "net/minecraft/client/renderer/entity/RenderPlayer" };
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
};
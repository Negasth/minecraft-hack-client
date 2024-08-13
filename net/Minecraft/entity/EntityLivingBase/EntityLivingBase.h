#pragma once
#include "../Entity/Entity.h"

class EntityLivingBase : public Entity {
public:
	using Entity::Entity;
	float getHealth(JNIEnv* otherEnv = Negasth::p_env);
	float getMaxHealth(JNIEnv* otherEnv = Negasth::p_env);
	bool canEntityBeSeen(Entity target);
protected:
	inline static Negasth::JavaClass EntityLivingBaseClass{ "net/minecraft/entity/EntityLivingBase" };
};
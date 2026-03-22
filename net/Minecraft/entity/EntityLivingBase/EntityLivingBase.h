<<<<<<< HEAD
#pragma once
#include "../Entity/Entity.h"

class EntityLivingBase : public Entity {
public:
	using Entity::Entity;
	float getHealth(JNIEnv* otherEnv = Negasth::p_env);
	float getMaxHealth(JNIEnv* otherEnv = Negasth::p_env);
	bool canEntityBeSeen(Entity target);
	void setjumpTicks(JNIEnv* otherEnv = Negasth::p_env);
protected:
	inline static Negasth::JavaClass EntityLivingBaseClass{ "net/minecraft/entity/EntityLivingBase" };
=======
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
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
};
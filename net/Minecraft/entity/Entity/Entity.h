#pragma once

#include "../Java/lang/Object/Object.h"
#include "../Negasth/Maths/Maths.h"
#include "../Negasth/JavaClass/JavaClass.h"
#include "../net/Minecraft/util/AxisAlignedBB/AxisAlignedBB.h"

class Entity : public Object {
public:
	using Object::Object;

	Negasth::Maths::Vector3d getPosition(JNIEnv* otherEnv = Negasth::p_env) const;
	Negasth::Maths::Vector2d getRotation(JNIEnv* otherEnv = Negasth::p_env) const;
	Negasth::Maths::Vector3d getMovementVector(float partialTicks)const;
	Negasth::Maths::Vector3d getLastTickPosition()const;
	float getEyeHeight() const;
	AxisAlignedBB getBoundingBox(JNIEnv* otherEnv = Negasth::p_env);
	int getTicksExisted(JNIEnv* otherEnv = Negasth::p_env);

	void setRotation(const Negasth::Maths::Vector2d& yawPitch);

protected:
	inline static Negasth::JavaClass EntityClass{ "net/minecraft/entity/Entity" };
};

#include "Entity.h"

Negasth::Maths::Vector3d Entity::getPosition(JNIEnv* otherEnv) const
{
	if (!instance) return Negasth::Maths::Vector3d();
	return Negasth::Maths::Vector3d(
		otherEnv->GetDoubleField(instance, EntityClass.getFieldID("posX")),
		otherEnv->GetDoubleField(instance, EntityClass.getFieldID("posY")),
		otherEnv->GetDoubleField(instance, EntityClass.getFieldID("posZ"))
	);
}

Negasth::Maths::Vector2d Entity::getRotation(JNIEnv* otherEnv) const
{
	if (!instance)return Negasth::Maths::Vector2d();
	return Negasth::Maths::Vector2d(
		otherEnv->GetFloatField(instance, EntityClass.getFieldID("rotationYaw")),
		otherEnv->GetFloatField(instance, EntityClass.getFieldID("rotationPitch"))
	);
}

Negasth::Maths::Vector3d Entity::getMovementVector(float partialTicks) const
{
	if (!instance)return Negasth::Maths::Vector3d();
	return (getPosition() - getLastTickPosition()) * partialTicks;
}

Negasth::Maths::Vector3d Entity::getLastTickPosition() const
{
	if (!instance)return Negasth::Maths::Vector3d();
	return Negasth::Maths::Vector3d(
		env->GetDoubleField(instance, EntityClass.getFieldID("lastTickPosX")),
		env->GetDoubleField(instance, EntityClass.getFieldID("lastTickPosY")),
		env->GetDoubleField(instance, EntityClass.getFieldID("lastTickPosZ"))
		);
}

float Entity::getEyeHeight() const
{
	if (!instance)return 0.0f;
	return env->CallFloatMethod(instance, EntityClass.getMethodID("getEyeHeight"));
}

AxisAlignedBB Entity::getBoundingBox(JNIEnv* otherEnv)
{
	if (!instance)return AxisAlignedBB(nullptr, otherEnv);
	return AxisAlignedBB(otherEnv->GetObjectField(instance,EntityClass.getFieldID("boundingBox")));
}

int Entity::getTicksExisted(JNIEnv* otherEnv)
{
	if (!instance)return 0;
	return otherEnv->GetIntField(instance,EntityClass.getFieldID("ticksExisted"));
}

void Entity::setRotation(const Negasth::Maths::Vector2d& yawPitch)
{
	if (!instance)return;
	env->SetFloatField(instance, EntityClass.getFieldID("rotationYaw"), (jfloat)yawPitch.x);
	env->SetFloatField(instance, EntityClass.getFieldID("rotationPitch"), (jfloat)yawPitch.y);
}

#include "Entity.h"

Negasth::Maths::Vector3d Entity::getPosition(JNIEnv* otherEnv) const
{
	if (!instance) return Negasth::Maths::Vector3d();
	return Negasth::Maths::Vector3d(
		otherEnv->GetDoubleField(instance, EntityClass.getFieldId(otherEnv, "field_70165_t", "D")),
		otherEnv->GetDoubleField(instance, EntityClass.getFieldId(otherEnv, "field_70163_u", "D")),
		otherEnv->GetDoubleField(instance, EntityClass.getFieldId(otherEnv, "field_70161_v", "D"))
	);
}

Negasth::Maths::Vector2d Entity::getRotation(JNIEnv* otherEnv) const
{
	if (!instance)return Negasth::Maths::Vector2d();
	return Negasth::Maths::Vector2d(
		otherEnv->GetFloatField(instance, EntityClass.getFieldId(otherEnv, "field_70177_z", "F")),
		otherEnv->GetFloatField(instance, EntityClass.getFieldId(otherEnv, "field_70125_A", "F"))
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
		env->GetDoubleField(instance, EntityClass.getFieldId(env, "field_70142_S", "D")),
		env->GetDoubleField(instance, EntityClass.getFieldId(env, "field_70137_T", "D")),
		env->GetDoubleField(instance, EntityClass.getFieldId(env, "field_70136_U", "D"))
		);
}

float Entity::getEyeHeight() const
{
	if (!instance)return 0.0f;
	return env->CallFloatMethod(instance, env->GetMethodID(EntityClass.getJclass(env), "func_70047_e", "()F"));
}

AxisAlignedBB Entity::getBoundingBox(JNIEnv* otherEnv)
{
	if (!instance)return AxisAlignedBB(nullptr, otherEnv);
	return AxisAlignedBB(otherEnv->GetObjectField(instance,EntityClass.getFieldId(otherEnv,"field_70121_D","Lnet/minecraft/util/AxisAlignedBB;")));
}

int Entity::getTicksExisted(JNIEnv* otherEnv)
{
	if (!instance)return 0;
	return otherEnv->GetIntField(instance,otherEnv->GetFieldID(EntityClass.getJclass(otherEnv),"field_70173_aa","I"));
}

void Entity::setRotation(const Negasth::Maths::Vector2d& yawPitch)
{
	if (!instance)return;
	env->SetFloatField(instance, EntityClass.getFieldId(env, "field_70177_z", "F"), (jfloat)yawPitch.x);
	env->SetFloatField(instance, EntityClass.getFieldId(env, "field_70125_A", "F"), (jfloat)yawPitch.y);
}

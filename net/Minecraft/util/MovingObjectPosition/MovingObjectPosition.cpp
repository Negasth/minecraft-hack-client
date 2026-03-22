#include "MovingObjectPosition.h"

MovingObjectType MovingObjectPosition::getType()
{
	if (!instance)return MovingObjectType(nullptr, env);

	return MovingObjectType(env->GetObjectField(instance,MovingObjectPositionClass.getFieldID("typeOfHit")),env);
}

Entity MovingObjectPosition::getEntityHit()
{
	if (!instance)return Entity();
	return Entity(
		env->GetObjectField(instance, MovingObjectPositionClass.getFieldID("entityHit"))
	);
}

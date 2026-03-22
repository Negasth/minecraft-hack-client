#include "MovingObjectType.h"

MovingObjectType MovingObjectType::getType(const std::string& name, JNIEnv* env)
{
	jclass MovingObjectTypeJclass = MovingObjectTypeClass.getJclass(env);
	return MovingObjectType(
		env->GetStaticObjectField(
			MovingObjectTypeJclass,
			env->GetStaticFieldID(MovingObjectTypeJclass, name.c_str(), "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;")
		),env
	);
}

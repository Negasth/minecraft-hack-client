#include "world.h"

List World::getPlayerEntities()
{
	if (!instance)return{};
	return List(env->GetObjectField(instance,WorldClass.getFieldID("playerEntities")),
		env, true
	);
}

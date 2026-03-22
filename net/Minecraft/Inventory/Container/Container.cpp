#include "Container.h"

int Container::getwindowId()
{
	if (!instance)return 0;
	return env->GetIntField(instance,ContainerClass.getFieldID("windowId"));
}

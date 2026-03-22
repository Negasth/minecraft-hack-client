#include "EntityPlayerSP.h"

void EntityPlayerSP::SwingItem()
{
	if (!instance)return;
	env->CallVoidMethod(instance, EntityPlayerSPClass.getMethodID("swingItem"));
}

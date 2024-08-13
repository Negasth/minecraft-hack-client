#include "EntityPlayerSP.h"

void EntityPlayerSP::SwingItem()
{
	if (!instance)return;
	env->CallVoidMethod(instance, env->GetMethodID(EntityPlayerSPClass.getJclass(env), "func_71038_i", "()V"));
}

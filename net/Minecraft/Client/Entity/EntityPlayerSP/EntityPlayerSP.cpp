#include "EntityPlayerSP.h"

void EntityPlayerSP::SwingItem()
{
	if (!instance)return;
<<<<<<< HEAD
	env->CallVoidMethod(instance, EntityPlayerSPClass.getMethodID("swingItem"));
=======
	env->CallVoidMethod(instance, env->GetMethodID(EntityPlayerSPClass.getJclass(env), "func_71038_i", "()V"));
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
}

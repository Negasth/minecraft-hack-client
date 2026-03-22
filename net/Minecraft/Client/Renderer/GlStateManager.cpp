<<<<<<< HEAD
#include "GlStateManager.h"
//Î´Ð´Èëjson
void GlStateManager::disableDepth()
{
	Negasth::p_env->CallStaticVoidMethod(GlStateManagerClass.getJclass(Negasth::p_env), Negasth::p_env->GetStaticMethodID(GlStateManagerClass.getJclass(Negasth::p_env), "func_179097_i", "()V"));
}
=======
#include "GlStateManager.h"

void GlStateManager::disableDepth()
{
	Negasth::p_env->CallStaticVoidMethod(GlStateManagerClass.getJclass(Negasth::p_env), Negasth::p_env->GetStaticMethodID(GlStateManagerClass.getJclass(Negasth::p_env), "func_179097_i", "()V"));
}
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87

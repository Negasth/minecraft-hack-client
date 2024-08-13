#include "GlStateManager.h"

void GlStateManager::disableDepth()
{
	Negasth::p_env->CallStaticVoidMethod(GlStateManagerClass.getJclass(Negasth::p_env), Negasth::p_env->GetStaticMethodID(GlStateManagerClass.getJclass(Negasth::p_env), "func_179097_i", "()V"));
}

#include "RenderManager.h"

RenderPlayer RenderManager::getRenderLivingEntity()
{
	if (!instance)return {nullptr,env};
	return RenderPlayer(env->GetObjectField(instance,env->GetFieldID(RenderManagerClass.getJclass(env),"field_178637_m","Lnet/minecraft/client/renderer/entity/RenderPlayer;")),env);
}

double RenderManager::getRenderPosX(JNIEnv* renderEnv)
{
	if (!instance)return 0.0;
	return renderEnv->GetDoubleField(instance, renderEnv->GetFieldID(RenderManagerClass.getJclass(renderEnv), "field_78725_b", "D"));
}

double RenderManager::getRenderPosY(JNIEnv* renderEnv)
{
	if (!instance)return 0.0;
	return renderEnv->GetDoubleField(instance, renderEnv->GetFieldID(RenderManagerClass.getJclass(renderEnv), "field_78726_c", "D"));
}

double RenderManager::getRenderPosZ(JNIEnv* renderEnv)
{
	if (!instance)return 0.0;
	return renderEnv->GetDoubleField(instance, renderEnv->GetFieldID(RenderManagerClass.getJclass(renderEnv), "field_78723_d", "D"));
}

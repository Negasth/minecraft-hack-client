<<<<<<< HEAD
#include "RenderManager.h"
RenderPlayer RenderManager::getRenderLivingEntity()
{
	if (!instance)return {nullptr,env};
	return RenderPlayer(env->GetObjectField(instance,RenderManagerClass.getFieldID("playerRenderer")),
		env, true
	);
}

double RenderManager::getRenderPosX(JNIEnv* renderEnv)
{
	if (!instance)return 0.0;
	return renderEnv->GetDoubleField(instance, RenderManagerClass.getFieldID("renderPosX"));
}

double RenderManager::getRenderPosY(JNIEnv* renderEnv)
{
	if (!instance)return 0.0;
	return renderEnv->GetDoubleField(instance, RenderManagerClass.getFieldID("renderPosY"));
}

double RenderManager::getRenderPosZ(JNIEnv* renderEnv)
{
	if (!instance)return 0.0;
	return renderEnv->GetDoubleField(instance, RenderManagerClass.getFieldID("renderPosZ"));
}
=======
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
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87

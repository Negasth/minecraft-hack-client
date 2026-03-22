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

#pragma once
#include "RenderPlayer.h"

class RenderManager :public Object {
public:
	using Object::Object;
	RenderPlayer getRenderLivingEntity();
	double getRenderPosX(JNIEnv* renderEnv);
	double getRenderPosY(JNIEnv* renderEnv);
	double getRenderPosZ(JNIEnv* renderEnv);
protected:
	inline static Negasth::JavaClass RenderManagerClass{ "net/minecraft/client/renderer/entity/RenderManager" };
};
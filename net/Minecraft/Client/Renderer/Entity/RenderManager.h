<<<<<<< HEAD
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
=======
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
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
};
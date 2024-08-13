#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
#include "../../Entity/EntityPlayerSP/EntityPlayerSP.h"

class Render : public Object {
public:
	using Object::Object;
	void renderLivingLabel(EntityPlayer target,EntityPlayer thePlayer,JNIEnv* otherEnv = Negasth::p_env);
protected:
	inline static Negasth::JavaClass RenderClass{ "net/minecraft/client/renderer/entity/Render" };
};
#pragma once

#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
#include "../Gui/GuiScreen/GuiScreen.h"
#include "../../util/MovingObjectPosition/MovingObjectPosition.h"
#include "../Entity/EntityPlayerSP/EntityPlayerSP.h"
#include "../../Client/multiplayer/worldclient/WorldClient.h"
#include "../net/Minecraft/util/Timer/Timer.h"
#include "../Renderer/Entity/RenderManager.h"
#include "../Renderer/GlStateManager.h"
#include "../network/NetHandlerPlayClient/NetHandlerPlayClient.h"

class Minecraft :public Object {
public:
	using Object::Object; //= Minecraft(JNIEnv* env = Negasth::p_env, bool is_global = false)

	static Minecraft getTheMinecraft(JNIEnv* env = Negasth::p_env);
	int getRightClickDelayTimer();
	GuiScreen getCurrentScreen();
	MovingObjectPosition getObjectMouseOver();
	EntityPlayerSP getThePlayer();
	WorldClient getTheWorld();
	Timer getTimer();
	RenderManager getRenderManager();
	NetHandlerPlayClient getNetHandler();

	void setRightClickDelayTimer(int value);
protected:
	static inline Negasth::JavaClass MinecraftClass{ "net/minecraft/client/Minecraft" };
};
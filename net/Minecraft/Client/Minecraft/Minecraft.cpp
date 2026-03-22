#include "Minecraft.h"

Minecraft Minecraft::getTheMinecraft(JNIEnv* env) {
	//Lnet/minecraft/client/Minecraft;
	jclass minecraftclass = MinecraftClass.getJclass(env);

	return Minecraft(env->GetStaticObjectField(minecraftclass,
		MinecraftClass.getFieldID("theMinecraft")),env,true);
}

int Minecraft::getRightClickDelayTimer()
{
	if (!instance)return 0;
	return env->GetIntField(instance,MinecraftClass.getFieldID("rightClickDelayTimer"));
}

void Minecraft::ClickMouse()
{
	if (!instance)return;
	env->CallVoidMethod(instance, MinecraftClass.getMethodID("clickMouse"));
}

void Minecraft::setRightClickDelayTimer(int value)
{
	if (!instance)return;
	env->SetIntField(instance, MinecraftClass.getFieldID("rightClickDelayTimer"), value);
}

GuiScreen Minecraft::getCurrentScreen()
{
	if (!instance)
		return GuiScreen(env);
	return GuiScreen(env->GetObjectField(instance,MinecraftClass.getFieldID("currentScreen")));
}

MovingObjectPosition Minecraft::getObjectMouseOver()
{
	if (!instance) return MovingObjectPosition(nullptr,env);
	return MovingObjectPosition(env->GetObjectField(instance,MinecraftClass.getFieldID("objectMouseOver")),env);
}

EntityPlayerSP Minecraft::getThePlayer()
{
	if (!instance)return EntityPlayerSP(nullptr, env);
	return EntityPlayerSP(
		env->GetObjectField(instance,MinecraftClass.getFieldID("thePlayer")),env,true
	);
}

WorldClient Minecraft::getTheWorld()
{
	if (!instance)return WorldClient( nullptr,env );
	return WorldClient(env->GetObjectField(instance,MinecraftClass.getFieldID("theWorld")),
		env, true
		);
}

Timer Minecraft::getTimer()
{
	if (!instance)return Timer();
	return Timer(env->GetObjectField(instance,MinecraftClass.getFieldID("timer")),
		env, true
		);
}

RenderManager Minecraft::getRenderManager()
{
	if (!instance)return RenderManager(nullptr, env);
	return RenderManager(env->GetObjectField(instance,MinecraftClass.getFieldID("renderManager")),
		env, true
	);
}

NetHandlerPlayClient Minecraft::getNetHandler()
{
	if (!instance)return NetHandlerPlayClient(nullptr, env);
	return NetHandlerPlayClient(env->CallObjectMethod(instance,MinecraftClass.getMethodID("getNetHandler")),
		env, true
		);
}

PlayercontrollerMP Minecraft::getPlayerController()
{
	if (!instance)return PlayercontrollerMP(nullptr, env);
	return PlayercontrollerMP(
		env->GetObjectField(instance, MinecraftClass.getFieldID("playerController")),
		env, true
	);
}

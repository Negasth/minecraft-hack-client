#include "Minecraft.h"

Minecraft Minecraft::getTheMinecraft(JNIEnv* env) {
	//Lnet/minecraft/client/Minecraft;
	jclass minecraftclass = MinecraftClass.getJclass(env);

	return Minecraft(env->GetStaticObjectField(minecraftclass,
		env->GetStaticFieldID(minecraftclass,"field_71432_P", "Lnet/minecraft/client/Minecraft;")),env,true);
}

int Minecraft::getRightClickDelayTimer()
{
	if (!instance)return 0;
	return env->GetIntField(instance,MinecraftClass.getFieldId(env,"field_71467_ac","I"));
}

void Minecraft::setRightClickDelayTimer(int value)
{
	if (!instance)return;
	env->SetIntField(instance, MinecraftClass.getFieldId(env, "field_71467_ac", "I"), value);
}

GuiScreen Minecraft::getCurrentScreen()
{
	if (!instance)
		return GuiScreen(env);
	return GuiScreen(env->GetObjectField(instance,MinecraftClass.getFieldId(env,"field_71462_r","Lnet/minecraft/client/gui/GuiScreen;")));
}

MovingObjectPosition Minecraft::getObjectMouseOver()
{
	if (!instance) return MovingObjectPosition(nullptr,env);
	return MovingObjectPosition(env->GetObjectField(instance,MinecraftClass.getFieldId(env,"field_71476_x","Lnet/minecraft/util/MovingObjectPosition;")),env);
}

EntityPlayerSP Minecraft::getThePlayer()
{
	if (!instance)return EntityPlayerSP(nullptr, env);
	return EntityPlayerSP(
		env->GetObjectField(instance,env->GetFieldID(MinecraftClass.getJclass(env),"field_71439_g","Lnet/minecraft/client/entity/EntityPlayerSP;")),env,true
	);
}

WorldClient Minecraft::getTheWorld()
{
	if (!instance)return WorldClient( nullptr,env );
	return WorldClient(env->GetObjectField(instance,MinecraftClass.getFieldId(env,"field_71441_e","Lnet/minecraft/client/multiplayer/WorldClient;")));
}

Timer Minecraft::getTimer()
{
	if (!instance)return Timer();
	return Timer(env->GetObjectField(instance,MinecraftClass.getFieldId(env,"field_71428_T","Lnet/minecraft/util/Timer;")));
}

RenderManager Minecraft::getRenderManager()
{
	if (!instance)return RenderManager(nullptr, env);
	return RenderManager(env->GetObjectField(instance,MinecraftClass.getFieldId(env,"field_175616_W","Lnet/minecraft/client/renderer/entity/RenderManager;")));
}

NetHandlerPlayClient Minecraft::getNetHandler()
{
	if (!instance)return NetHandlerPlayClient(nullptr, env);
	return NetHandlerPlayClient(env->CallObjectMethod(instance,env->GetMethodID(MinecraftClass.getJclass(env),"func_147114_u","()Lnet/minecraft/client/network/NetHandlerPlayClient;")));
}

#pragma once
#include "../C03PacketPlayer.h"

class C05PacketPlayerLook :public C03PacketPlayer {
public:
	using C03PacketPlayer::C03PacketPlayerClass;
	static C05PacketPlayerLook newObject(float yaw, float pitch, bool isOnGround,JNIEnv* otherEnv = Negasth::p_env);
protected:
	inline static Negasth::JavaClass C05PacketPlayerLookClass{"net/minecraft/network/play/client/C03PacketPlayer$C05PacketPlayerLook"};
};
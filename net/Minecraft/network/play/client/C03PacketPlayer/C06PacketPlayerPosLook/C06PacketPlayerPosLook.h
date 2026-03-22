#pragma once
#include "../C03PacketPlayer.h"

class C06PacketPlayerPosLook : public C03PacketPlayer
{
public:
	using C03PacketPlayer::C03PacketPlayer;
	static C06PacketPlayerPosLook newObject(const Negasth::Maths::Vector3d& position, const Negasth::Maths::Vector2d& rotation, bool isOnGround, JNIEnv* env = Negasth::p_env);

	protected:
	inline static Negasth::JavaClass C06PacketPlayerPosLookClass{ "net/minecraft/network/play/client/C03PacketPlayer$C06PacketPlayerPosLook" };
};
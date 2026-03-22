#pragma once
#include "../C03PacketPlayer.h"
class C04PacketPlayerPosition : public C03PacketPlayer
{
public:
	using C03PacketPlayer::C03PacketPlayer;
	static C04PacketPlayerPosition newObject(const Negasth::Maths::Vector3d& position, bool isOnGround, JNIEnv* env = Negasth::p_env);
protected:
	inline static Negasth::JavaClass C04PacketPlayerPositionClass{ "net/minecraft/network/play/client/C03PacketPlayer$C04PacketPlayerPosition" };
};
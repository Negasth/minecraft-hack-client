#pragma once
#include "../../../Packet/Packet.h"
#include "../../../../../../Negasth/Maths/Maths.h"
class C03PacketPlayer : public Packet
{
public:
	using Packet::Packet;
	static C03PacketPlayer newObject(bool isOnGround, JNIEnv* env = Negasth::p_env); //not valid on 1.19.4

	Negasth::Maths::Vector3d getXYZ();
	void setXYZ(const Negasth::Maths::Vector3d& vector);

	Negasth::Maths::Vector2d getYawPitch();
	void setYawPitch(Negasth::Maths::Vector2d yawPitch);

	bool getOnGround();
	void setOnGround(bool state);

	bool getMoving();
	void setMoving(bool state);

	bool getRotating();
	void setRotating(bool state);
protected:
	inline static Negasth::JavaClass C03PacketPlayerClass{ "net/minecraft/network/play/client/C03PacketPlayer" };
};
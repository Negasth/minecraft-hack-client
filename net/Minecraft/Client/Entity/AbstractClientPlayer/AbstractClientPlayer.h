#pragma once
#include "../../../entity/player/EntityPlayer/EntityPlayer.h"

class AbstractClientPlayer : public EntityPlayer {
public:
	using EntityPlayer::EntityPlayer;
protected:
	inline static Negasth::JavaClass AbstractClientPlayerClass{ "net/minecraft/client/entity/AbstractClientPlayer" };
};
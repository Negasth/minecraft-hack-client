#pragma once
#include "../AbstractClientPlayer/AbstractClientPlayer.h"

class EntityPlayerSP : public AbstractClientPlayer {
public:
	using AbstractClientPlayer::AbstractClientPlayer;
	void SwingItem();
protected:
	inline static Negasth::JavaClass EntityPlayerSPClass{ "net/minecraft/client/entity/EntityPlayerSP" };
	inline static Negasth::JavaClass EntityPlayerMPClass{ "net/minecraft/client/entity/EntityClientPlayerMP" };
};

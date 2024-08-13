#pragma once
#include "../../../World/world.h"

class WorldClient : public World {
public:
	using World::World;
	List getPlayerEntities() override;
protected:
	inline static Negasth::JavaClass WorldClientClass{ "net/minecraft/client/multiplayer/WorldClient" };
};
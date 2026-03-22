<<<<<<< HEAD
#pragma once
#include "../../../World/world.h"

class WorldClient : public World {
public:
	using World::World;
	List getPlayerEntities() override;
protected:
	inline static Negasth::JavaClass WorldClientClass{ "net/minecraft/client/multiplayer/WorldClient" };
=======
#pragma once
#include "../../../World/world.h"

class WorldClient : public World {
public:
	using World::World;
	List getPlayerEntities() override;
protected:
	inline static Negasth::JavaClass WorldClientClass{ "net/minecraft/client/multiplayer/WorldClient" };
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
};
#pragma once
#include "../Java/lang/Object/Object.h"
#include"../Java/util/List/List.h"
#include  "../Negasth/JavaClass/JavaClass.h"

class World : public Object {
public:
	using Object::Object;
	virtual List getPlayerEntities();

protected:
	inline static Negasth::JavaClass WorldClass{ "net/minecraft/world/World" };
	inline static Negasth::JavaClass IBlockAccessClass{ "net/minecraft/world/IBlockAccess" };
};
#include "WorldClient.h"

List WorldClient::getPlayerEntities()
{
	if (!instance)return{};
	return World::getPlayerEntities();
}

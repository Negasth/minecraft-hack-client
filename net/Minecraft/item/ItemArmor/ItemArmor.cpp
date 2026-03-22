#include "ItemArmor.h"

int ItemArmor::getArmorType()
{
	if (!instance)return 0;
	return env->GetIntField(instance,ItemArmorClass.getFieldID("armorType"));
}

int ItemArmor::getdamageReduceAmount()
{
	if (!instance)return 0;
	return env->GetIntField(instance, ItemArmorClass.getFieldID("damageReduceAmount"));
}

#include "ItemStack.h"

Item ItemStack::getItem(JNIEnv* otherEnv)
{
	if (!instance)return Item{};
	return Item(otherEnv->CallObjectMethod(instance,otherEnv->GetMethodID(ItemStackClass.getJclass(otherEnv),"func_77973_b","()Lnet/minecraft/item/Item;")));
}

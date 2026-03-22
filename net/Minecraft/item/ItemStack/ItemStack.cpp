#include "ItemStack.h"

Item ItemStack::getItem(JNIEnv* otherEnv)
{
	if (!instance)return Item{};
	return Item(otherEnv->CallObjectMethod(instance,ItemStackClass.getMethodID("getItem")));
}

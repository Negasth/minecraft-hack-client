<<<<<<< HEAD
#include "Collection.h"

void Collection::clear()
{
	if (!instance)return;
	env->CallVoidMethod(instance, env->GetMethodID(CollectionClass.getJclass(env), "clear", "()V"));
}

bool Collection::add(const Object& element)
{
	if (!instance)return false;
	return env->CallBooleanMethod(instance,env->GetMethodID(CollectionClass.getJclass(env),"add","(Ljava/lang/Object;)Z"),element.getInstance()) == JNI_OK;
}
=======
#include "Collection.h"

void Collection::clear()
{
	if (!instance)return;
	env->CallVoidMethod(instance, env->GetMethodID(CollectionClass.getJclass(env), "clear", "()V"));
}

bool Collection::add(const Object& element)
{
	if (!instance)return false;
	return env->CallBooleanMethod(instance,env->GetMethodID(CollectionClass.getJclass(env),"add","(Ljava/lang/Object;)Z"),element.getInstance()) == JNI_OK;
}
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87

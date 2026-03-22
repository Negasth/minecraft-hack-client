<<<<<<< HEAD
#include "List.h"

List List::newObject(JNIEnv* env)
{
	jclass arrayListClass = env->FindClass("java/util/ArrayList");
	jmethodID constructor = env->GetMethodID(arrayListClass, "<init>", "()V");
	return List(env->NewObject(arrayListClass, constructor), env);
}
=======
#include "List.h"

List List::newObject(JNIEnv* env)
{
	jclass arrayListClass = env->FindClass("java/util/ArrayList");
	jmethodID constructor = env->GetMethodID(arrayListClass, "<init>", "()V");
	return List(env->NewObject(arrayListClass, constructor), env);
}
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87

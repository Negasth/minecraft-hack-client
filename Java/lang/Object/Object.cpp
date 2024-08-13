#include "Object.h"

Object::Object(jobject instance, JNIEnv* env, bool is_global) {
	this->env = env;
	this->is_global = is_global;
	if (instance) {
		this->instance = (is_global ? env->NewGlobalRef(instance) : instance);
	}
	else this->instance = nullptr;
}

Object::Object(JNIEnv* env, bool is_global)
{
	this->is_global = is_global;
	this->env = env;
}

bool Object::isValid()
{
	return this->instance != nullptr;
}

bool Object::isEqualto(const Object& other_object)
{
	if (this->instance == other_object.instance) {
		return true;
	}
	if (this->instance && other_object.instance) {
		return env->IsSameObject(this->instance, other_object.instance) == JNI_TRUE;
	}
	return false;
}

void Object::Clear()
{
	if (!Negasth::p_env)
		return;
	if (isValid()) {
		if (is_global)
			env->DeleteGlobalRef(instance);
		else
			env->DeleteLocalRef(instance);
		this->instance = nullptr;
	}
}

const jobject& Object::getInstance() const
{
	return instance;
}

JNIEnv* Object::getOwnEnv()
{
	return this->env;
}

void Object::setOwnEnv(JNIEnv* env)
{
	this->env = env;
}

#pragma once
#include "../Negasth/Negasth.h"

class Object {
public:
	Object(jobject instance, JNIEnv* env = Negasth::p_env, bool is_global = false);
	Object(JNIEnv* env = Negasth::p_env, bool is_global = false);

	bool isValid();
	bool isEqualto(const Object& other_object);
	void Clear();

	const jobject& getInstance()const;
	JNIEnv* getOwnEnv();

	void setOwnEnv(JNIEnv* env);
protected:
	JNIEnv* env = Negasth::p_env;
	jobject instance = nullptr;
	bool is_global = false;
};


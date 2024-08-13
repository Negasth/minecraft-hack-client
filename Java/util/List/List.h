#pragma once
#include "../Collection/Collection.h"

class List : public Collection {
public:
	using Collection::Collection;
	static List newObject(JNIEnv* env = Negasth::p_env);
protected:
	inline static Negasth::JavaClass ListClass{ "java/util/List" };
};
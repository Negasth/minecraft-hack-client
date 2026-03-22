<<<<<<< HEAD
#pragma once
#include "../Collection/Collection.h"

class List : public Collection {
public:
	using Collection::Collection;
	static List newObject(JNIEnv* env = Negasth::p_env);
protected:
	inline static Negasth::JavaClass ListClass{ "java/util/List" };
=======
#pragma once
#include "../Collection/Collection.h"

class List : public Collection {
public:
	using Collection::Collection;
	static List newObject(JNIEnv* env = Negasth::p_env);
protected:
	inline static Negasth::JavaClass ListClass{ "java/util/List" };
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
};
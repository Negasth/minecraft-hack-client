#pragma once
#include "../../lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

#include <vector>

class Collection : public Object {
public:
	using Object::Object;
	void clear();
	bool add(const Object& element);
	template<class T>
	std::vector<T> toVector(JNIEnv* otherEnv = Negasth::p_env);

protected:
	inline static Negasth::JavaClass CollectionClass{ "java/util/Collection" };
};

template<class T>
inline std::vector<T> Collection::toVector(JNIEnv* otherEnv) {
	if (!instance)return {};
	jobjectArray array = (jobjectArray)otherEnv->CallObjectMethod(instance, otherEnv->GetMethodID(CollectionClass.getJclass(otherEnv), "toArray", "()[Ljava/lang/Object;"));
	if (!array)return {};
	jsize size = otherEnv->GetArrayLength(array);
	if (size == 0)return{};
	std::vector<T> vector(size);
	for (jsize i = 0; i < size; i++) {
		vector.push_back(T(otherEnv->GetObjectArrayElement(array, i),otherEnv));
	}
	otherEnv->DeleteLocalRef(array);
	return vector;
}
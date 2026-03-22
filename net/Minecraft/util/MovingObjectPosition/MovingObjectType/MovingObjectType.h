#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class MovingObjectType : public Object {
public:
	using Object::Object;
	static MovingObjectType getType(const std::string& name, JNIEnv* env = Negasth::p_env);
protected:
	inline static Negasth::JavaClass MovingObjectTypeClass{ "net/minecraft/util/MovingObjectPosition$MovingObjectType" };
};
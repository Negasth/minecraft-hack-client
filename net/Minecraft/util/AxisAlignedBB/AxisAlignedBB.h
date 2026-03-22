#pragma once
#include "../../../../java/lang/Object/Object.h"
#include "../../../../Negasth/Maths/Maths.h"
#include "../Negasth/JavaClass/JavaClass.h"

class AxisAlignedBB : public Object
{
public:
	using Object::Object;

	double getMinX(JNIEnv* otherEnv = Negasth::p_env) const;
	double getMinY(JNIEnv* otherEnv = Negasth::p_env) const;
	double getMinZ(JNIEnv* otherEnv = Negasth::p_env) const;
	double getMaxX(JNIEnv* otherEnv = Negasth::p_env) const;
	double getMaxY(JNIEnv* otherEnv = Negasth::p_env) const;
	double getMaxZ(JNIEnv* otherEnv = Negasth::p_env) const;

	void setMinX(double value);
	void setMinY(double value);
	void setMinZ(double value);
	void setMaxX(double value);
	void setMaxY(double value);
	void setMaxZ(double value);

	double getXWidth();
	double getZWidth();
	double getHeight();
	Negasth::Maths::Vector3d getCenter();
protected:
	inline static Negasth::JavaClass AxisAlignedBBClass{ "net/minecraft/util/AxisAlignedBB" };
};
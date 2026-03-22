#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"

class Timer :public Object{
public:
	using Object::Object;
	float getRenderPartialTicks();
	void setTimeSyncAdjustment(double val);
	void setTimerSpeed(float val);
protected:
	inline static Negasth::JavaClass TimerClass{ "net/minecraft/util/Timer" };
};

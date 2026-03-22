#include "Timer.h"

float Timer::getRenderPartialTicks()
{
	if (!instance)return 0.0f;
	return env->GetFloatField(instance,TimerClass.getFieldID("renderPartialTicks"));
}
//Î´Ð´Èëjson
void Timer::setTimeSyncAdjustment(double val)
{
	if (!instance)return;
	env->SetDoubleField(instance, TimerClass.getFieldID("timeSyncAdjustment"), (jdouble)val);
}
//Î´Ð´Èëjson
void Timer::setTimerSpeed(float val)
{
	if (!instance)return;
	env->SetFloatField(instance, TimerClass.getFieldID("timerSpeed"), (jfloat)val);
}

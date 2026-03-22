#include "EntityLivingBase.h"

float EntityLivingBase::getHealth(JNIEnv* otherEnv)
{
    if(!instance)return 0.0f;
    return otherEnv->CallFloatMethod(instance,EntityLivingBaseClass.getMethodID("getHealth"));
}

float EntityLivingBase::getMaxHealth(JNIEnv* otherEnv)
{
    if(!instance)return 0.0f;
    return otherEnv->CallFloatMethod(instance, EntityLivingBaseClass.getMethodID("getMaxHealth"));
}

bool EntityLivingBase::canEntityBeSeen(Entity target)
{
    if (!instance)return false;
    return env->CallBooleanMethod(instance, EntityLivingBaseClass.getMethodID("canEntityBeSeen"),target.getInstance());
}

void EntityLivingBase::setjumpTicks(JNIEnv* otherEnv)
{
    if (!instance)return;
    otherEnv->SetIntField(instance, EntityLivingBaseClass.getFieldID("jumpTicks"), 0);
}

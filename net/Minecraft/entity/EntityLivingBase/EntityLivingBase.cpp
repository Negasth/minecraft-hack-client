#include "EntityLivingBase.h"

float EntityLivingBase::getHealth(JNIEnv* otherEnv)
{
    if(!instance)return 0.0f;
    return otherEnv->CallFloatMethod(instance,otherEnv->GetMethodID(EntityLivingBaseClass.getJclass(otherEnv), "func_110143_aJ", "()F"));
}

float EntityLivingBase::getMaxHealth(JNIEnv* otherEnv)
{
    if(!instance)return 0.0f;
    return otherEnv->CallFloatMethod(instance, otherEnv->GetMethodID(EntityLivingBaseClass.getJclass(otherEnv), "func_110138_aP", "()F"));
}

bool EntityLivingBase::canEntityBeSeen(Entity target)
{
    if (!instance)return false;
    return env->CallBooleanMethod(instance,env->GetMethodID(EntityLivingBaseClass.getJclass(env),"func_70685_l","(Lnet/minecraft/entity/Entity;)Z"),target.getInstance());
}

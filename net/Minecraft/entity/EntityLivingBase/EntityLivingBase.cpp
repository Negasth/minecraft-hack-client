<<<<<<< HEAD
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
=======
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
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87

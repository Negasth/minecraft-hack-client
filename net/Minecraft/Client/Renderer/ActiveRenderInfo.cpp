#include "ActiveRenderInfo.h"

GLfloat* ActiveRenderInfo::m_MODELVIEW = new GLfloat[16];
GLfloat* ActiveRenderInfo::m_PROJECTION = new GLfloat[16];

GLfloat* ActiveRenderInfo::Get_MODELVIEW(JNIEnv* env)
{

	jobject OMODELVIEW =  env->GetStaticObjectField(ActiveRenderInfoClass.getJclass(env), env->GetStaticFieldID(ActiveRenderInfoClass.getJclass(env), "field_178812_b", "Ljava/nio/FloatBuffer;"));
	jclass CFloatBuffer = env->FindClass("java/nio/FloatBuffer");
	jmethodID MIDget = env->GetMethodID(CFloatBuffer, "get", "(I)F");
	for (int i = 0; i < 16; i++)
	{
		ActiveRenderInfo::m_MODELVIEW[i] = env->CallFloatMethod(OMODELVIEW, MIDget, i);
	}
	env->DeleteLocalRef(OMODELVIEW);
	env->DeleteLocalRef(CFloatBuffer);
	return ActiveRenderInfo::m_MODELVIEW;
}

GLfloat* ActiveRenderInfo::Get_PROJECTION(JNIEnv* env)
{
	jobject OPROJECTION = env->GetStaticObjectField(ActiveRenderInfoClass.getJclass(env), env->GetStaticFieldID(ActiveRenderInfoClass.getJclass(env), "field_178813_c", "Ljava/nio/FloatBuffer;"));
	jclass CFloatBuffer = env->FindClass("java/nio/FloatBuffer");
	jmethodID MIDget = env->GetMethodID(CFloatBuffer, "get", "(I)F");
	for (int i = 0; i < 16; i++)
	{
		ActiveRenderInfo::m_PROJECTION[i] = env->CallFloatMethod(OPROJECTION, MIDget, i);
	}
	env->DeleteLocalRef(OPROJECTION);
	env->DeleteLocalRef(CFloatBuffer);

	return ActiveRenderInfo::m_PROJECTION;
}

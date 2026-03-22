<<<<<<< HEAD
#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
#include "gl/GL.h"

class ActiveRenderInfo : public Object {
public:
	using Object::Object;
	static GLfloat* Get_MODELVIEW(JNIEnv* env);
	static GLfloat* Get_PROJECTION(JNIEnv* env);

	static GLfloat* m_MODELVIEW;
	static GLfloat* m_PROJECTION;
protected:
	inline static Negasth::JavaClass ActiveRenderInfoClass{ "net/minecraft/client/renderer/ActiveRenderInfo" };
};

=======
#pragma once
#include "../Java/lang/Object/Object.h"
#include "../Negasth/JavaClass/JavaClass.h"
#include "gl/GL.h"

class ActiveRenderInfo : public Object {
public:
	using Object::Object;
	static GLfloat* Get_MODELVIEW(JNIEnv* env);
	static GLfloat* Get_PROJECTION(JNIEnv* env);

	static GLfloat* m_MODELVIEW;
	static GLfloat* m_PROJECTION;
protected:
	inline static Negasth::JavaClass ActiveRenderInfoClass{ "net/minecraft/client/renderer/ActiveRenderInfo" };
};

>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87

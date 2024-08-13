#include "JavaClass.h"
//#include<mutex>

CRITICAL_SECTION Critical;

jclass Negasth::JavaClass::FindClass(const std::string& classPath, JNIEnv* env)
{
    static std::unordered_map<std::string, jclass> classMap;

    if (classMap.empty())
    {
        JavaVM* jvm = nullptr;
        env->GetJavaVM(&jvm);
        jvmtiEnv* tienv = nullptr;
        jvm->GetEnv((void**)&tienv, JVMTI_VERSION);
        jint classCount = 0;
        jclass* classes = nullptr;
        tienv->GetLoadedClasses(&classCount, &classes);
        jclass ClassClass = env->FindClass("java/lang/Class");
        jmethodID getName = env->GetMethodID(ClassClass, "getName", "()Ljava/lang/String;");

        for (int i = 0; i < classCount; ++i)
        {
            jstring name = (jstring)env->CallObjectMethod(classes[i], getName);
            const char* chars = env->GetStringUTFChars(name, nullptr);
            jsize size = env->GetStringUTFLength(name);
            std::string className(chars, size);
            env->ReleaseStringUTFChars(name, chars);
            for (char& character : className)
            {
                if (character == '.') character = '/';
            }
            classMap.insert({ className, classes[i] });
        }
        tienv->Deallocate((unsigned char*)classes);
    }

    jclass foundclass = nullptr;
    try
    {
        foundclass = classMap.at(classPath);
    }
    catch (...)
    {
        std::cerr << "[-] Failed to find class " + classPath << std::endl;
    }
    return foundclass;
}

jclass Negasth::JavaClass::getJclass(JNIEnv* env) const
{
    EnterCriticalSection(&Critical);
    JclassCache& env_Jclass_cache = get_Jclass_cache(env);
    if (!env_Jclass_cache.cached_classes.contains(class_path)) {
        jclass global_ref = reinterpret_cast<jclass>( env->NewGlobalRef(FindClass(class_path, env)));
        env_Jclass_cache.cached_classes.insert({class_path,global_ref });
        LeaveCriticalSection(&Critical);
        return global_ref;
    }
    LeaveCriticalSection(&Critical);
    return env_Jclass_cache.cached_classes.at(class_path);
}

jfieldID Negasth::JavaClass::getFieldId(JNIEnv* env, std::string fileName, std::string sig) const
{
    return env->GetFieldID(getJclass(env), fileName.c_str(), sig.c_str());
}


Negasth::JavaClass::JclassCache& Negasth::JavaClass::get_Jclass_cache(JNIEnv* env)
{
    for (JclassCache& jclass_cache : Jclass_caches) {
        if (jclass_cache.owning_env != env)
            continue;
        return jclass_cache;
    }
    Jclass_caches.push_back({ env,{} });
    JclassCache& jclass_cache = *(Jclass_caches.end() - 1);
    return jclass_cache;
}

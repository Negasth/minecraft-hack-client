#include "JavaClass.h"
//#include<mutex>

CRITICAL_SECTION Critical_getclass;
CRITICAL_SECTION Critical_findclass;

std::unordered_map<std::string, Negasth::JavaClass::JclassData> Negasth::JavaClass::data{};

jclass Negasth::JavaClass::FindClass(const std::string& classPath, JNIEnv* env)
{
    static std::unordered_map<std::string, jclass> classMap;

    EnterCriticalSection(&Critical_findclass);

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

    LeaveCriticalSection(&Critical_findclass);

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

bool Negasth::JavaClass::init()
{
    try {
        Negasth::JavaClass::mappings = nlohmann::json::parse(version.mapping_text);
    }
    catch (const nlohmann::json::exception& e) {
        std::cout << "Failed to parse mapping file" << '\n';
        std::cerr << e.what() << '\n';
        return false;
    }

    if (mappings.empty())
        return false;

    for (auto& [className, classcontent] : mappings.items()) {
       // std::cout << classcontent["obfuscated"] << std::endl;
        jclass javaclass = FindClass(classcontent["obfuscated"]);
        if (javaclass == nullptr)
            continue;
        JclassData classData{};
        for (auto& field : classcontent["fields"]) {
            jfieldID fieldID = NULL;
            if (field["static"] == true) {
                fieldID = Negasth::p_env->GetStaticFieldID(javaclass, std::string(field["obfuscated"]).c_str(), std::string(field["signature"]).c_str());
            }
            else {
                fieldID = Negasth::p_env->GetFieldID(javaclass, std::string(field["obfuscated"]).c_str(), std::string(field["signature"]).c_str());
            }
            if (!fieldID) {
                std::cerr << "Failed to find field ID: " + std::string(field["name"]) << '\n'
                    << "For class: " << className << '\n';
                continue;
            }
            classData.fields.insert({ field["name"],fieldID });
        }

        for (auto& method : classcontent["methods"]) {
            jmethodID methodID = NULL;
            if (method["static"] == true) {
                methodID = Negasth::p_env->GetStaticMethodID(javaclass, std::string(method["obfuscated"]).c_str(), std::string(method["signature"]).c_str());
            }
            else {
                methodID = Negasth::p_env->GetMethodID(javaclass, std::string(method["obfuscated"]).c_str(), std::string(method["signature"]).c_str());
            }
            if (!methodID)
            {
                std::cerr << "Failed to find method ID: " + std::string(method["name"]) << '\n'
                    << "For class: " << className << '\n';
                continue;
            }
            classData.methods.insert({ method["name"],methodID });
        }
        data.insert({ className,classData });
    }
    return true;
}

jfieldID Negasth::JavaClass::getFieldID(const std::string& name) const
{
    try
    {
        return data.at(class_path).fields.at(name);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "Failed to get field ID " << name << std::endl;
        std::cerr << "for class " << class_path << std::endl;
        std::cin.ignore();
        return nullptr;
    }
}

jmethodID Negasth::JavaClass::getMethodID(const std::string& name) const
{
    try
    {
        return data.at(class_path).methods.at(name);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "Failed to get method ID " << name << std::endl;
        std::cerr << "for class " << class_path << std::endl;
        std::cin.ignore();
        return nullptr;
    }
}

jclass Negasth::JavaClass::getJclass(JNIEnv* env) const
{
    EnterCriticalSection(&Critical_getclass);
    JclassCache& env_Jclass_cache = get_Jclass_cache(env);
    if (!env_Jclass_cache.cached_classes.contains(class_path)) {
        jclass global_ref = reinterpret_cast<jclass>( env->NewGlobalRef(FindClass(class_path, env)));
        env_Jclass_cache.cached_classes.insert({class_path,global_ref });
        LeaveCriticalSection(&Critical_getclass);
        return global_ref;
    }
    LeaveCriticalSection(&Critical_getclass);
    return env_Jclass_cache.cached_classes.at(class_path);
}

//jfieldID Negasth::JavaClass::getFieldId(JNIEnv* env, std::string fileName, std::string sig) const
//{
//    return env->GetFieldID(getJclass(env), fileName.c_str(), sig.c_str());
//}


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

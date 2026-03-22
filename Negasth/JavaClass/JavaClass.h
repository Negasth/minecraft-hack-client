<<<<<<< HEAD
#pragma once

#include "../Negasth.h"
#include <unordered_map>
#include"../includes/json.hpp"

extern CRITICAL_SECTION Critical_getclass;
extern CRITICAL_SECTION Critical_findclass;

namespace Negasth{
	class JavaClass {
	public:
		JavaClass(const std::string& class_path) :class_path(class_path) {};

		static jclass FindClass(const std::string& classPath, JNIEnv* env = Negasth::p_env);
		static bool init();

		jclass get_jclass(JNIEnv* env) const;

		jfieldID getFieldID(const std::string& name) const;

		jmethodID getMethodID(const std::string& name) const;

		jclass getJclass(JNIEnv* env) const;
		//jfieldID getFieldId(JNIEnv* env,std::string fileName,std::string sig)const;

	private:
		struct JclassData{
			std::unordered_map<std::string, jfieldID> fields{};
			std::unordered_map<std::string, jmethodID> methods{};
		};
		static std::unordered_map<std::string, JclassData> data;

		struct JclassCache
		{
			JNIEnv* owning_env;
			std::unordered_map<std::string, jclass> cached_classes;
		};
		inline static std::vector<JclassCache> Jclass_caches{};

		std::string class_path;
		inline static nlohmann::json mappings{};

		static JclassCache& get_Jclass_cache(JNIEnv* env);
	};
=======
#pragma once

#include "../Negasth.h"
#include <unordered_map>

extern CRITICAL_SECTION Critical;

namespace Negasth{
	class JavaClass {
	public:
		JavaClass(const std::string& class_path) :class_path(class_path) {};

		static jclass FindClass(const std::string& classPath, JNIEnv* env = Negasth::p_env);
		jclass getJclass(JNIEnv* env) const;
		jfieldID getFieldId(JNIEnv* env,std::string fileName,std::string sig)const;

	private:
		struct JclassCache
		{
			JNIEnv* owning_env;
			std::unordered_map<std::string, jclass> cached_classes;
		};
		inline static std::vector<JclassCache> Jclass_caches{};
		std::string class_path;

		static JclassCache& get_Jclass_cache(JNIEnv* env);
	};
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
}
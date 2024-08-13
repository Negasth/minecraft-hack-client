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
}
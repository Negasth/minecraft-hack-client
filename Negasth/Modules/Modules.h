#pragma once
#include "../Negasth.h"
#include "../net/Minecraft/entity/Player/EntityPlayer/EntityPlayer.h"
#include <random>

namespace Negasth {
	namespace Modules {

		class IModule {
		public:
			IModule(const char* name);
			virtual void run();
			bool enable = false;
		protected:
			inline static std::random_device rd{};
			inline static std::mt19937 gen{ rd() };

		private:
			const char* name;
		};

		class AimAssist :public IModule {
		public:
			AimAssist() : IModule("Aim Assist") {};
			void run() override;
		private:
			float max_distance = 6.0f;
			float max_angle = 60.0f;
			float multiplier = 1.0f;
			float multiplierPitch = 0.4f;
			EntityPlayer prev_selected_target{ Negasth::p_env, true };
		};

		class AutoClick : public IModule {
		public:
			AutoClick() :IModule("Left Clicker") {};
			void run() override;
		private:
			int min_cps = 10;
			int max_cps = 14;
		};

		class FastPlace : public IModule {
		public:
			FastPlace() :IModule("Fast place") {};
			void run()override;
		private:
			int tickDelay = 0;
		};

		class NameTag :public IModule {
		public:
			NameTag() :IModule("NameTag") {};
			void run()override;
		};

		class KillAura :public IModule {
		public:
			KillAura() :IModule("KillAura") {};
			void run()override;
			void AttackEntitybySendPacket(Entity target);
			int min_cps = 10;
			int max_cps = 14;
		};

		class Category {
		public:
			Category(const Category& cat) = delete;
			~Category()
			{
				for (IModule* module : modules) {
					delete module;
				}
			}

			const char* name;
			std::vector<IModule*> modules;

			template<typename... T, typename = std::enable_if_t<((std::is_base_of_v<IModule,T> && ...))>>
			inline static Category create(const char* name) {
				std::vector<IModule*> modules{};
				modules.reserve(sizeof...(T));
				(modules.push_back(new T()), ...);
				return Category(name, std::move(modules));
			}

		private:
			Category(const char* name, std::vector<IModule*>&& modules) :name(name), modules(std::move(modules)) {}
		};

		inline Category categories[] = {
			Category::create<AimAssist,AutoClick,KillAura>("Combat"),
			Category::create<FastPlace>("Player"),
			//Category::create<NameTag>("Render"),
		};

		void runModules();
	}
}
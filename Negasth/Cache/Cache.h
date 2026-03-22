<<<<<<< HEAD
#pragma once
#include "../net/Minecraft/Client/Minecraft/Minecraft.h"

namespace Negasth {
	class Cache {
	public:
		Minecraft theMinecraft{ Negasth::p_env,true};
		EntityPlayerSP thePlayer{ Negasth::p_env,true };
		List playerEntities{ Negasth::p_env,true };
		WorldClient theWorld{ Negasth::p_env,true };
		Timer timer{ Negasth::p_env, true };
		RenderManager theRenderManager{ Negasth::p_env, true };
		RenderPlayer RenderPlayer{ Negasth::p_env, true };
		GlStateManager glManager{ Negasth::p_env, true };
		NetHandlerPlayClient NetHandler{ Negasth::p_env, true };
		InventoryPlayer inventory{ Negasth::p_env, true };
		PlayercontrollerMP playerController{ Negasth::p_env, true };

		bool fillCache();
		void Clear();

	private:
		EntityPlayerSP prev_thePlayer{ Negasth::p_env, true };
	};
	inline Cache* cache = new Cache();
=======
#pragma once
#include "../net/Minecraft/Client/Minecraft/Minecraft.h"

namespace Negasth {
	class Cache {
	public:
		Minecraft theMinecraft{ Negasth::p_env,true};
		EntityPlayerSP thePlayer{ Negasth::p_env,true };
		List playerEntities{ Negasth::p_env,true };
		WorldClient theWorld{ Negasth::p_env,true };
		Timer timer{ Negasth::p_env, true };
		RenderManager theRenderManager{ Negasth::p_env, true };
		RenderPlayer RenderPlayer{ Negasth::p_env, true };
		GlStateManager glManager{ Negasth::p_env, true };
		NetHandlerPlayClient NetHandler{ Negasth::p_env, true };

		bool fillCache();

	private:
		EntityPlayerSP prev_thePlayer{ Negasth::p_env, true };
	};
	inline Cache* cache = new Cache();
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
}
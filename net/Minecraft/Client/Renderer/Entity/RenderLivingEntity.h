#pragma once
#include "Render.h"

class RenderLivingEntity : public Render {
public:
	using Render::Render;
protected:
	inline static Negasth::JavaClass RenderLivingEntityClass{ "net/minecraft/client/renderer/entity/RendererLivingEntity" };
};
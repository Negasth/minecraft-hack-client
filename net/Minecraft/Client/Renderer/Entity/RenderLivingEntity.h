<<<<<<< HEAD
#pragma once
#include "Render.h"

class RenderLivingEntity : public Render {
public:
	using Render::Render;
protected:
	inline static Negasth::JavaClass RenderLivingEntityClass{ "net/minecraft/client/renderer/entity/RendererLivingEntity" };
=======
#pragma once
#include "Render.h"

class RenderLivingEntity : public Render {
public:
	using Render::Render;
protected:
	inline static Negasth::JavaClass RenderLivingEntityClass{ "net/minecraft/client/renderer/entity/RendererLivingEntity" };
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
};
#ifndef CHEETAH_ENGINE_RENDERER_RENDERACTION_H_
#define CHEETAH_ENGINE_RENDERER_RENDERACTION_H_

#include "RenderAPI.h"
#include "Core/Core.h"

#include <memory>

namespace cheetah
{
	class CH_API RenderAction
	{
	public:
		static void init();
		static void setViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		static void setClearColor(float r, float g, float b, float a);
		static void clear();
		static void drawIndexed(short unsigned int count, RenderAPI::APITypes type);
	private:
		static std::unique_ptr<RenderAPI> s_renderAPI;

		// TODO: Draw index
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_RENDERACTION_H_

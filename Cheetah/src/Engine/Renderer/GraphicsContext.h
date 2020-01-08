#ifndef CHEETAH_ENGINE_RENDERER_GRAPHICSCONTEXT_H_
#define CHEETAH_ENGINE_RENDERER_GRAPHICSCONTEXT_H_

#include <memory>

namespace cheetah
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual void init() = 0;
		virtual void swapBuffers() = 0;

		static std::unique_ptr<GraphicsContext> create(void* window);
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_GRAPHICSCONTEXT_H_

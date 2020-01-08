#ifndef CHEETAH_ENGINE_RENDERER_RENDERER_H_
#define CHEETAH_ENGINE_RENDERER_RENDERER_H_

namespace cheetah
{
	class Renderer
	{
	public:
		static void init();	
		static void setViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		static void shutDown();
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_RENDERER_H_

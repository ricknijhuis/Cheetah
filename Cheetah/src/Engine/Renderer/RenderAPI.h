#ifndef CHEETAH_ENGINE_RENDERER_RENDERAPI_H_
#define CHEETAH_ENGINE_RENDERER_RENDERAPI_H_

#include "Shader.h"

#include <memory>

namespace cheetah
{
	class RenderAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL = 1
			// TODO: DirectX
			// TODO: Vulkan
		};

		enum class APITypes
		{
			None = 0,
			Int = 1,
			UInt = 2,
			UShortInt = 3,
			Float = 4,
			Double = 5,
			Bool = 6
		};

		virtual ~RenderAPI() = default;

		virtual void init() = 0;
		virtual void setViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;
		virtual void clearColor(float r, float g, float b, float a) = 0;
		virtual void clear() = 0;
		virtual void drawIndexed(short unsigned int count, APITypes type) = 0;

		static API getAPI();
		static const short int getAPIType(APITypes type);
		static const short int getAPIType(Shader::ShaderTypes type);
		static std::unique_ptr<RenderAPI> create();

	private:
		static API m_API;
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_RENDERAPI_H_
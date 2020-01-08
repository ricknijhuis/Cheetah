#ifndef CHEETAH_PLATFORM_OPENGL_OPENGLRENDERAPI_H_
#define CHEETAH_PLATFORM_OPENGL_OPENGLRENDERAPI_H_

#include "Renderer/RenderAPI.h"

#include "Renderer/Shader.h"

namespace cheetah
{
	namespace opengl
	{
		class OpenGLRenderAPI : public RenderAPI
		{
		public:
			void init() override;
			void setViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height) override;
			void clearColor(float r, float g, float b, float a) override;
			void clear() override;
			void drawIndexed(short unsigned int count, APITypes type) override;
			static const short int getAPIType(APITypes type);
			static const short int getAPIType(Shader::ShaderTypes type);
		};
	}
}

#endif // !CHEETAH_PLATFORM_OPENGL_RENDERAPI_H_

#include "GraphicsContext.h"

#include "RenderAPI.h";
#include "Platform/OpenGL/OpenGLGraphicsContext.h"

namespace cheetah
{
	std::unique_ptr<GraphicsContext> GraphicsContext::create(void* window)
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::OpenGL:
				return std::make_unique<opengl::OpenGLGraphicsContext>(static_cast<GLFWwindow*>(window));
			default:
				return nullptr;
		}
	}
}
#include "VertexArray.h"
#include "RenderAPI.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace cheetah
{
	std::shared_ptr<VertexArray> VertexArray::create()
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::OpenGL:
			return std::make_shared<opengl::OpenGLVertexArray>();
		default:
			break;
		}
	}
}

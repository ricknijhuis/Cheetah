#include "VertexBuffer.h"

#include "RenderAPI.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

namespace cheetah
{
	std::shared_ptr<VertexBuffer> VertexBuffer::create()
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::OpenGL:
			return std::make_shared<opengl::OpenGLVertexBuffer>();
		default:
			return nullptr;
		}
	}
}
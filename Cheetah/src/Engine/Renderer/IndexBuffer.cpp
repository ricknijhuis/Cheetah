#include "IndexBuffer.h"

#include "RenderAPI.h"
#include "Platform/OpenGL/OpenGLIndexBuffer.h"

namespace cheetah
{
	std::shared_ptr<IndexBuffer> IndexBuffer::create()
	{
		switch (RenderAPI::getAPI())
		{
			case RenderAPI::API::OpenGL:
				return std::make_shared<opengl::OpenGLIndexBuffer>();
		default:
			return nullptr;
		}
	}
}
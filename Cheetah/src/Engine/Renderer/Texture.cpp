#include "Texture.h"

#include "RenderAPI.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace cheetah
{
	std::unique_ptr<Texture> Texture::create(const CreateTextureParams& params)
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::OpenGL:
			return std::make_unique<opengl::OpenGLTexture>(params);
		default:
			return nullptr;
		}
	}

	Texture* Texture::createRaw(const CreateTextureParams& params)
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::OpenGL:
			return new opengl::OpenGLTexture(params);
		default:
			return nullptr;
		}
	}
}
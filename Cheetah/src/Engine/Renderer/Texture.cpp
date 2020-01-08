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

	//std::unique_ptr<Texture> Texture::create(unsigned int width, unsigned int height, void* data, short int nrOfChannels)
	//{
	//	switch (RenderAPI::getAPI())
	//	{
	//	case RenderAPI::API::OpenGL:
	//		return std::make_unique<opengl::OpenGLTexture>(width, height, data, nrOfChannels);
	//	default:
	//		return nullptr;
	//	}
	//}
}
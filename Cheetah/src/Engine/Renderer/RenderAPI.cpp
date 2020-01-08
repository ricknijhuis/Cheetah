#include "RenderAPI.h"

#include "Platform/OpenGL/OpenGLRenderAPI.h"

namespace cheetah
{
	// TODO: Get Api type from game settings in s_Create
	RenderAPI::API RenderAPI::m_API = RenderAPI::API::OpenGL;

	std::unique_ptr<RenderAPI> RenderAPI::create()
	{
		// TODO: Get Api type from game settings
		switch (m_API)
		{
		case API::OpenGL:
			return std::make_unique<opengl::OpenGLRenderAPI>();
		default:
			return nullptr;
		}
	}

	RenderAPI::API RenderAPI::getAPI()
	{
		return m_API;
	}

	const short int RenderAPI::getAPIType(Shader::ShaderTypes type)
	{
		switch (getAPI())
		{
		case API::OpenGL:
			return opengl::OpenGLRenderAPI::getAPIType(type);
		}
	}

	const short int RenderAPI::getAPIType(APITypes type)
	{
		switch (getAPI())
		{
		case API::OpenGL:
			return opengl::OpenGLRenderAPI::getAPIType(type);
		}
	}
}
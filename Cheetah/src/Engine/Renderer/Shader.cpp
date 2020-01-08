#include "Shader.h"

#include "RenderAPI.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace cheetah
{
	std::unique_ptr<Shader> Shader::create(const std::string& contents)
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::OpenGL:
			return std::make_unique<opengl::OpenGLShader>(contents);
		default:
			return nullptr;
		}
	}

	std::unique_ptr<Shader> Shader::create(const std::string& vertContents, const std::string& fragContents)
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::OpenGL:
			return std::make_unique<opengl::OpenGLShader>(vertContents, fragContents);
		default:
			return nullptr;
		}
	}

	short int Shader::getShaderTypeSize(ShaderTypes shaderType)
	{
		switch (shaderType)
		{
		case ShaderTypes::Bool:		return 1;
		case ShaderTypes::Float:	return 4;
		case ShaderTypes::Float2:	return 4 * 2;
		case ShaderTypes::Float3:	return 4 * 3;
		case ShaderTypes::Float4:	return 4 * 4;
		case ShaderTypes::Int:		return 4;
		case ShaderTypes::Int2:		return 4 * 2;
		case ShaderTypes::Int3:		return 4 * 3;
		case ShaderTypes::Int4:		return 4 * 4;
		case ShaderTypes::Mat3:		return 3 * 3 * 4;
		case ShaderTypes::Mat4:		return 4 * 4 * 4;
		}
		return 0;
	}

	short int Shader::getShaderTypeComponentCount(ShaderTypes shaderType)
	{
		switch (shaderType)
		{
		case ShaderTypes::Int:
		case ShaderTypes::Bool:
		case ShaderTypes::Float:	return 1;
		case ShaderTypes::Float2:	return 2;
		case ShaderTypes::Float3:	return 3;
		case ShaderTypes::Float4:	return 4;
		case ShaderTypes::Int2:		return 2;
		case ShaderTypes::Int3:		return 3;
		case ShaderTypes::Int4:		return 4;
		case ShaderTypes::Mat3:		return 3 * 3;
		case ShaderTypes::Mat4:		return 4 * 4;
		default:					return 0;
		}
	}
}
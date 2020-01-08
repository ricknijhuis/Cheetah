#include "OpenGLRenderAPI.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace cheetah
{
	namespace opengl
	{
#ifdef DEBUG
		void APIENTRY glDebugOutput(GLenum source,
			GLenum type,
			GLuint id,
			GLenum severity,
			GLsizei length,
			const GLchar* message,
			const void* userParam)
		{
			// ignore non-significant error/warning codes
			if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

			std::cout << "---------------" << std::endl;
			std::cout << "Debug message (" << id << "): " << message << std::endl;

			switch (source)
			{
			case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
			case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
			case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
			case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
			case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
			} std::cout << std::endl;

			switch (type)
			{
			case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break;
			case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
			case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
			case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
			case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
			case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
			case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
			} std::cout << std::endl;

			switch (severity)
			{
			case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
			case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
			case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
			case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
			} std::cout << std::endl;
			std::cout << std::endl;
		}
#endif // DEBUG

		void OpenGLRenderAPI::init()
		{
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_BLEND);
			glEnable(GL_MULTISAMPLE);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#ifdef DEBUG
			GLint flags;
			glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

			if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
			{
				glEnable(GL_DEBUG_OUTPUT);
				glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
				glDebugMessageCallback(glDebugOutput, nullptr);
				glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
			}
#endif // DEBUG
		}

		void OpenGLRenderAPI::setViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
		{
			glViewport(x, y, width, height);
		}

		void OpenGLRenderAPI::clearColor(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);
		}

		void OpenGLRenderAPI::clear()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void OpenGLRenderAPI::drawIndexed(short unsigned int count, APITypes type)
		{
			glDrawElements(GL_TRIANGLES, count, this->getAPIType(type), 0);
		}

		const short OpenGLRenderAPI::getAPIType(APITypes type)
		{
			switch (type)	
			{
			case cheetah::RenderAPI::APITypes::Int:			return GL_INT;
			case cheetah::RenderAPI::APITypes::UInt:		return GL_UNSIGNED_INT;
			case cheetah::RenderAPI::APITypes::UShortInt:	return GL_UNSIGNED_SHORT;
			case cheetah::RenderAPI::APITypes::Float:		return GL_FLOAT;
			case cheetah::RenderAPI::APITypes::Double:		return GL_DOUBLE;
			case cheetah::RenderAPI::APITypes::Bool:		return GL_BOOL;
			default:										return NULL;
			}
		}

		const short OpenGLRenderAPI::getAPIType(Shader::ShaderTypes type)
		{
			switch (type)
			{
			case cheetah::Shader::ShaderTypes::Int:
			case cheetah::Shader::ShaderTypes::Int2:
			case cheetah::Shader::ShaderTypes::Int3:
			case cheetah::Shader::ShaderTypes::Int4:		return GL_INT;
			case cheetah::Shader::ShaderTypes::Mat3:
			case cheetah::Shader::ShaderTypes::Mat4:
			case cheetah::Shader::ShaderTypes::Float:
			case cheetah::Shader::ShaderTypes::Float2:
			case cheetah::Shader::ShaderTypes::Float3:
			case cheetah::Shader::ShaderTypes::Float4:		return GL_FLOAT;
			case cheetah::Shader::ShaderTypes::Bool:		return GL_BOOL;
			default:										return NULL;
			}
		}
	}
}
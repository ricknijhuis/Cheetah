#include "OpenGLShader.h"

#include <string>
#include <iostream>

namespace cheetah
{
	namespace opengl
	{
		OpenGLShader::OpenGLShader(const std::string& content)
		{
			std::string contents[] = { content };
			std::unordered_map<GLenum, std::string> shaders = processShader(contents, 1);
			this->m_id = glCreateProgram();

			compile(shaders);
		}

		OpenGLShader::OpenGLShader(const std::string& vertContent, const std::string fragContent)
		{
			std::string contents[] = { vertContent, fragContent };
			std::unordered_map<GLenum, std::string> shaders = processShader(contents, 2);
			this->m_id = glCreateProgram();

			compile(shaders);
		}

		OpenGLShader::~OpenGLShader()
		{
			glDeleteProgram(m_id);
		}

		GLenum OpenGLShader::getShaderTypeFromString(const std::string& typeString) const
		{
			if (typeString == "vertex")
				return GL_VERTEX_SHADER;
			if (typeString == "fragment" || typeString == "pixel")
				return GL_FRAGMENT_SHADER;

			return 0;
		}

		void OpenGLShader::compile(const std::unordered_map<GLenum, std::string>& shaders) const
		{
			std::vector<unsigned int> shaderIds;
			for (auto& shader : shaders)
			{
				unsigned int shaderId = glCreateShader(shader.first);

				shaderIds.push_back(shaderId);
				const char* shaderSource = shader.second.c_str();
				const int shaderLength = strlen(shaderSource);

				glShaderSource(shaderId, 1, &shaderSource, &shaderLength);
				glCompileShader(shaderId);

				isSuccesShader(shaderId);

				glAttachShader(this->m_id, shaderId);
			}

			glLinkProgram(m_id);

			isSuccesProgram(m_id);

			for (auto& shaderId : shaderIds)
				glDeleteShader(shaderId);
		}

		void OpenGLShader::isSuccesShader(unsigned int id) const
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			GLint success;
			GLchar infolog[512];
			glGetShaderiv(id, GL_COMPILE_STATUS, &success);

			if (success != GL_TRUE)
			{
				glGetShaderInfoLog(id, 512, NULL, infolog);
				std::cout << "Error" << infolog << std::endl;
			}
		}

		void OpenGLShader::isSuccesProgram(unsigned int id) const
		{
			int length;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
			GLint success;
			char* infolog = "";
			glGetProgramiv(id, GL_LINK_STATUS, &success);

			if (success != GL_TRUE)
			{
				glGetProgramInfoLog(id, length, NULL, infolog);
				std::cout << "Error" << infolog << std::endl;
			}
		}

		// TODO: read for uniforms and add to cache
		std::unordered_map<GLenum, std::string> OpenGLShader::processShader(std::string contents[], short size) const
		{
			std::unordered_map<GLenum, std::string> shaders;

			const char* typeToken = "#type";
			const short typeTokenLength = strlen(typeToken);

			for (short i = 0; i < size; i++)
			{
				std::vector<size_t> typeTokenLocations;
				size_t pos = contents[i].find(typeToken, 0);
				while (pos != std::string::npos)
				{
					typeTokenLocations.push_back(pos);
					pos = contents[i].find(typeToken, pos + typeTokenLength);
				}

				for (size_t j = 0; j < typeTokenLocations.size(); j++)
				{
					const size_t endOfTypeLine = contents[i].find_first_of("\r\n", typeTokenLocations[j]);
					const size_t begin = typeTokenLocations[j] + typeTokenLength + 1;
					const GLenum ShaderType = getShaderTypeFromString(contents[i].substr(begin, endOfTypeLine - begin));
					const size_t startSourcePos = contents[i].find_first_not_of("\r\n", endOfTypeLine);
					const size_t sourceLength = typeTokenLocations.size() - 1 > j ? (typeTokenLocations[j + 1] - startSourcePos) : std::string::npos;
					const std::string source = contents[i].substr(startSourcePos, sourceLength);
					shaders.try_emplace(ShaderType, source);
				}
			}
			return shaders;
		}

		void OpenGLShader::use() const
		{
			glUseProgram(m_id);
		}

		void OpenGLShader::unUse() const
		{
			glUseProgram(0);
		}

		void OpenGLShader::setInt(const std::string& name, int value) const
		{
			const int location = glGetUniformLocation(m_id, name.c_str());
			glUniform1i(location, value);
		}

		void OpenGLShader::setFloat(const std::string& name, float value) const
		{
			const int location = glGetUniformLocation(m_id, name.c_str());
			glUniform1f(location, value);
		}

		void OpenGLShader::setFloat3(const std::string& name, int value) const
		{
			const int location = glGetUniformLocation(m_id, name.c_str());
			glUniform1f(location, value);
		}

		void OpenGLShader::setFloat4(const std::string& name, float x, float y, float z, float w) const
		{
			int location = glGetUniformLocation(this->m_id, name.c_str());
			if (location == -1)
			{
				std::cout << "WARNING: No location found" << std::endl;
			}
			glUniform4f(location, x, y, z, w);
		}

		void OpenGLShader::setMat4f(const std::string& name, const bool& transpose, float* value) const
		{
			int location = glGetUniformLocation(this->m_id, name.c_str());
			if (location == -1)
			{
				std::cout << "WARNING: No location found" << std::endl;
			}
			glUniformMatrix4fv(location, 1, transpose, value);
		}
	}
}
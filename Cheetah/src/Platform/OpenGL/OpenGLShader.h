#ifndef CHEETAH_PLATFORM_OPENGL_OPENGLSHADER_H_
#define CHEETAH_PLATFORM_OPENGL_OPENGLSHADER_H_

#include "Renderer/Shader.h"

#include <glad/glad.h>

#include <unordered_map>

namespace cheetah
{
	namespace opengl
	{
		class OpenGLShader : public Shader
		{
		public:
			OpenGLShader(const std::string& contents);
			OpenGLShader(const std::string& vertContents, const std::string fragContents);
			~OpenGLShader();

			void use() const override;
			void unUse() const override;

			void setInt(const std::string& name, int value) const override;
			void setFloat(const std::string& name, float value) const override;
			void setFloat3(const std::string& name, int value) const override;
			void setFloat4(const std::string& name, float x, float y, float z, float w) const override;
			void setMat4f(const std::string& name, const bool& transpose, float* value) const override;

			const unsigned int getId() const override;
			const unsigned int getCurrentBound() const override;

		private:
			void isSuccesShader(unsigned int id) const;
			void isSuccesProgram(unsigned int id) const;
			void compile(const std::unordered_map<GLenum, std::string>& shaders) const;
			std::unordered_map<GLenum, std::string> processShader(std::string contents[], short size) const;
			GLenum getShaderTypeFromString(const std::string& typeString) const;

		private:
			unsigned int m_id;
			static unsigned int s_currentBound;
		};
	}
}

#endif // !CHEETAH_PLATFORM_OPENGL_OPENGLSHADER_H_

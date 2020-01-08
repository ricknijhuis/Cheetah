#ifndef CHEETAH_ENGINE_RENDERER_SHADER_H_
#define CHEETAH_ENGINE_RENDERER_SHADER_H_

#include <memory>
#include <string>

namespace cheetah
{
	class Shader
	{
	public:

		enum class ShaderTypes
		{
			None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
		};

		virtual ~Shader() = default;

		virtual void use() const = 0;
		virtual void unUse() const = 0;

		virtual void setInt(const std::string& name, int value) const = 0;
		virtual void setFloat(const std::string& name, float value) const = 0;
		virtual void setFloat3(const std::string& name, int value) const = 0;
		virtual void setFloat4(const std::string& name, float x, float y, float z, float w) const = 0;
		virtual void setMat4f(const std::string& name, const bool& transpose, float* value) const = 0;

		static short int getShaderTypeSize(ShaderTypes shaderType);
		static short int getShaderTypeComponentCount(ShaderTypes shaderType);
		static std::unique_ptr<Shader> create(const std::string& contents);
		static std::unique_ptr<Shader> create(const std::string& vertContents, const std::string& fragContents);
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_SHADER_H_

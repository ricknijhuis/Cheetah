#ifndef CHEETAH_ENGINE_RENDERER_VERTEXBUFFERLAYOUT_H_
#define CHEETAH_ENGINE_RENDERER_VERTEXBUFFERLAYOUT_H_

#include "Shader.h"

#include <vector>

namespace cheetah
{
	struct VertexBufferElement
	{
		VertexBufferElement(Shader::ShaderTypes type, bool normalized, int offset)
			: type(type), normalized(normalized), offset(offset)
		{
		}

		Shader::ShaderTypes type;
		bool normalized;
		int offset;
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout();

		const unsigned int& getStride() const;
		const std::vector<VertexBufferElement>& getElements() const;
		void addElement(Shader::ShaderTypes shaderType, bool normalized);
	private:
		unsigned int m_stride;
		std::vector<VertexBufferElement> m_elements;
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_VERTEXBUFFERLAYOUT_H_

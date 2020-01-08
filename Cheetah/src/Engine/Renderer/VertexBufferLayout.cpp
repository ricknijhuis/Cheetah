#include "VertexBufferLayout.h"

namespace cheetah
{
	VertexBufferLayout::VertexBufferLayout()
		: m_stride(0)
	{
	}

	void VertexBufferLayout::addElement(Shader::ShaderTypes type, bool normalized)
	{
		this->m_elements.emplace_back(type, normalized, this->m_stride);
		this->m_stride += Shader::getShaderTypeSize(type);
	}

	const unsigned int& VertexBufferLayout::getStride() const
	{
		return m_stride;
	}

	const std::vector<VertexBufferElement>& VertexBufferLayout::getElements() const
	{
		return m_elements;
	}
}
#include "OpenGLVertexArray.h"

#include "OpenGLRenderAPI.h"

#include <glad/glad.h>
#include <iostream>
#include <memory>

namespace cheetah
{
	namespace opengl
	{
		OpenGLVertexArray::OpenGLVertexArray()
		{
			glGenVertexArrays(1, &this->m_id);
		}

		OpenGLVertexArray::~OpenGLVertexArray()
		{
			glDeleteVertexArrays(1, &this->m_id);
		}

		void OpenGLVertexArray::bind() const
		{
			glBindVertexArray(this->m_id);
		}

		void OpenGLVertexArray::unBind() const
		{
			glBindVertexArray(0);
		}

		void OpenGLVertexArray::addBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) const
		{
			this->bind();
			vertexBuffer->bind();

			const VertexBufferLayout layout = vertexBuffer->getLayout();
			const std::vector<VertexBufferElement>& elements = layout.getElements();

			for (int i = 0; i < elements.size(); i++)
			{
				int componentCount = Shader::getShaderTypeComponentCount(elements[i].type);
				int apiType = OpenGLRenderAPI::getAPIType(elements[i].type);
				glEnableVertexAttribArray(i);
				glVertexAttribPointer(i, componentCount, apiType, GL_FALSE, layout.getStride(), (const void*)elements[i].offset);
			}
		}

		void OpenGLVertexArray::addBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) const
		{
			this->bind();
			indexBuffer->bind();
		}
	}
}


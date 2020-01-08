#include "OpenGLVertexBuffer.h"
#include <iostream>

namespace cheetah
{
	namespace opengl
	{
		OpenGLVertexBuffer::OpenGLVertexBuffer()
		{
			glGenBuffers(1, &this->m_id);
			//this->bind();
			//glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
			//this->unBind();
		}

		OpenGLVertexBuffer::~OpenGLVertexBuffer()
		{
			glDeleteBuffers(1, &this->m_id);
		}


		void OpenGLVertexBuffer::addData(const void* vertices, unsigned int size) const
		{
			this->bind();
			glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		}

		void OpenGLVertexBuffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, this->m_id);
		}

		void OpenGLVertexBuffer::unBind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		const VertexBufferLayout& OpenGLVertexBuffer::getLayout() const
		{
			return m_vertexBufferLayout;
		}

		void OpenGLVertexBuffer::setLayout(const VertexBufferLayout& layout)
		{
			this->m_vertexBufferLayout = layout;
		}
	}
}
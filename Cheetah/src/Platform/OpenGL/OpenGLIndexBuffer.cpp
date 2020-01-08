#include "OpenGLIndexBuffer.h"
#include <iostream>

namespace cheetah
{
	namespace opengl
	{
		OpenGLIndexBuffer::OpenGLIndexBuffer()
			: m_count(0)
		{
			glGenBuffers(1, &this->m_id);
		}

		OpenGLIndexBuffer::~OpenGLIndexBuffer()
		{
			glDeleteBuffers(1, &this->m_id);
		}

		void OpenGLIndexBuffer::addData(void* indices, unsigned int size, short int count)
		{
			this->bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
			this->m_count = count;
		}

		short int OpenGLIndexBuffer::getCount() const
		{
			return m_count;
		}

		void OpenGLIndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_id);
		}

		void OpenGLIndexBuffer::unBind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}
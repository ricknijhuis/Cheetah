#ifndef CHEETAH_PLATFORM_OPENGL_OPENGLVERTEXBUFFER_H_
#define CHEETAH_PLATFORM_OPENGL_OPENGLVERTEXBUFFER_H_

#include "Renderer/VertexBuffer.h"

#include "glad/glad.h"

namespace cheetah
{
	namespace opengl
	{
		class OpenGLVertexBuffer : public VertexBuffer
		{
		public:
			OpenGLVertexBuffer();
			~OpenGLVertexBuffer();

			void addData(const void* vertices, unsigned int size) const override;

			void bind() const override;
			void unBind() const override;

			void setLayout(const VertexBufferLayout& layout) override;
			const VertexBufferLayout& OpenGLVertexBuffer::getLayout() const override;

		private:
			unsigned int m_id;
			VertexBufferLayout m_vertexBufferLayout;
		};
	}
}

#endif // !CHEETAH_PLATFORM_OPENGL_OPENGLVERTEXBUFFER_H_

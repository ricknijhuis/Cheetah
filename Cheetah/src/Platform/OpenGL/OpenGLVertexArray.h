#ifndef CHEETAH_PLATFORM_OPENGL_OPENGLVERTEXARRAY_H_
#define CHEETAH_PLATFORM_OPENGL_OPENGLVERTEXARRAY_H_

#include "Renderer/VertexArray.h"

#include "Renderer/VertexBuffer.h"

namespace cheetah
{
	namespace opengl
	{
		class OpenGLVertexArray : public VertexArray
		{
		public:
			OpenGLVertexArray();
			~OpenGLVertexArray();

			void bind() const override;
			void unBind() const override;
			void addBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) const override;
			void addBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) const override;
		private:
			unsigned int m_id;
		};
	}
}

#endif // !CHEETAH_PLATFORM_OPENGL_OPENGLVERTEXARRAY_H_

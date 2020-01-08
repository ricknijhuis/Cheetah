#ifndef CHEETAH_PLATFORM_OPENGL_OPENGLINDEXBUFFER_H_
#define CHEETAH_PLATFORM_OPENGL_OPENGLINDEXBUFFER_H_

#include "Renderer/IndexBuffer.h"

#include <glad/glad.h>

namespace cheetah
{
	namespace opengl
	{
		class OpenGLIndexBuffer : public IndexBuffer
		{
		public:
			OpenGLIndexBuffer();
			~OpenGLIndexBuffer();

			void addData(void* indices, unsigned int size, short int count) override;
			void bind() const override;
			void unBind() const override;

			short int getCount() const override;

		private:
			unsigned int m_id;
			short int m_count;
		};
	}
}

#endif // !CHEETAH_PLATFORM_OPENGL_OPENGLBUFFERINDEX_H_

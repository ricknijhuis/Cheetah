#ifndef CHEETAH_ENGINE_RENDERING_VERTEXBUFFER_H_
#define CHEETAH_ENGINE_RENDERING_VERTEXBUFFER_H_

#include "VertexBufferLayout.h"

#include <memory>

namespace cheetah
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void addData(const void* vertices, unsigned int size) const = 0;
		virtual void bind() const = 0;
		virtual void unBind() const = 0;

		virtual const VertexBufferLayout& getLayout() const = 0;
		virtual void setLayout(const VertexBufferLayout& layout) = 0;

		static std::shared_ptr<VertexBuffer> create();
	};
}

#endif // !CHEETAH_ENGINE_RENDERING_VERtEXBUFFER_H_

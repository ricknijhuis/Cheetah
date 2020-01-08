#ifndef CHEETAH_ENGINE_RENDERER_VERTEXARRAY_H_
#define CHEETAH_ENGINE_RENDERER_VERTEXARRAY_H_

#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include <memory>

namespace cheetah
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void bind() const = 0;
		virtual void unBind() const = 0;
		virtual void addBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) const = 0;
		virtual void addBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) const = 0;

		static std::shared_ptr<VertexArray> create();
	};

}

#endif // !CHEETAH_ENGINE_RENDERER_VERTEXARRAY_H_

#ifndef CHEETAH_ENGINE_RENDERER_INDEXBUFFER_H_
#define CHEETAH_ENGINE_RENDERER_INDEXBUFFER_H_

#include <memory>

namespace cheetah
{
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void addData(void* indices, unsigned int size, short int count) = 0;
		virtual void bind() const = 0;
		virtual void unBind() const = 0;
		
		virtual short int getCount() const = 0;

		static std::shared_ptr<IndexBuffer> create();
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_INDEXBUFFER_H_

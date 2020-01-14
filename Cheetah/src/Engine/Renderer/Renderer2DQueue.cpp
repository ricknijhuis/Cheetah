#include "Renderer2DQueue.h"

#include <algorithm>
#include <functional>

namespace cheetah
{
	using namespace math;

	std::vector<Renderer2DQueueItem> Renderer2DQueue::s_queue = std::vector<Renderer2DQueueItem>();
	std::vector<Renderer2DMatrixQueueItem> Renderer2DQueue::s_matrixQueue = std::vector<Renderer2DMatrixQueueItem>();

	void Renderer2DQueue::add(Renderer2DQueueAddParams params, Mat4x4f transform, Vector4f color)
	{
		std::vector<Renderer2DQueueItem>::iterator it = std::find_if(
			s_queue.begin(),
			s_queue.end(),
			[&params](const Renderer2DQueueItem& obj) { return obj.shaderId == params.shaderId && obj.textureId == params.textureId && obj.z == params.z; }
		);

		if (it != s_queue.end())
		{
			s_matrixQueue.emplace_back(Renderer2DMatrixQueueItem{ it->id, transform });
		}
		else
		{
			unsigned int index = s_queue.end() - s_queue.begin();
			s_queue.emplace_back(Renderer2DQueueItem{ index, params.z, params.shaderId, params.textureId });
			s_matrixQueue.emplace_back(Renderer2DMatrixQueueItem{ index, transform, color });
		}
	}

	void Renderer2DQueue::sort()
	{
		std::sort(s_queue.begin(), s_queue.end(), std::bind(&Renderer2DQueue::compare, this, std::placeholders::_1, std::placeholders::_2));
	}

	bool Renderer2DQueue::compare(const Renderer2DQueueItem& a, const Renderer2DQueueItem& b)
	{
		if (a.z != b.z)
			return a.z > b.z;

		if (a.shaderId != b.shaderId)
			return a.shaderId > b.shaderId;

		return a.textureId > b.textureId;

	}
}

#include "Renderer2DQueue.h"

#include <algorithm>
#include <functional>

namespace cheetah
{
	using namespace math;

	std::vector<Renderer2DQueueItem> Renderer2DQueue::s_queue = std::vector<Renderer2DQueueItem>();
	std::vector<Renderer2DMatrixQueueItem> Renderer2DQueue::s_matrixQueue = std::vector<Renderer2DMatrixQueueItem>();

	void Renderer2DQueue::add(Renderer2DQueueAddParams params, Mat4x4f transform, Rgba color)
	{
		std::vector<Renderer2DQueueItem>::iterator it = std::find_if(
			s_queue.begin(),
			s_queue.end(),
			[&params](const Renderer2DQueueItem& obj) { return obj.z == params.z && obj.shader->getId() == params.shader->getId() && obj.texture->getId() == params.texture->getId(); }
		);

		if (it != s_queue.end())
		{
			s_matrixQueue.emplace_back(Renderer2DMatrixQueueItem{ it->id, transform });
		}
		else
		{
			unsigned int index = s_queue.end() - s_queue.begin();
			s_queue.emplace_back(Renderer2DQueueItem{ index, params.z, params.shader, params.texture });
			s_matrixQueue.emplace_back(Renderer2DMatrixQueueItem{ index, transform, color });
		}
	}

	void Renderer2DQueue::sort()
	{
		std::sort(s_queue.begin(), s_queue.end(), std::bind(&Renderer2DQueue::compare, this, std::placeholders::_1, std::placeholders::_2));
	}

	void Renderer2DQueue::clear()
	{
		s_matrixQueue.empty();
		s_queue.empty();
	}

	bool Renderer2DQueue::compare(const Renderer2DQueueItem& a, const Renderer2DQueueItem& b)
	{
		if (a.z != b.z)
			return a.z < b.z;

		if (a.shader->getId() != b.shader->getId())
			return a.shader->getId() < b.shader->getId();

		return a.texture->getId() < b.texture->getId();

	}
}

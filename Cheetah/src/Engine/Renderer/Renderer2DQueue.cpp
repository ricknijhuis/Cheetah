#include "Renderer2DQueue.h"

namespace cheetah
{
	unsigned int Render2DQueue::createId(const float& z, const unsigned int& textureId, const unsigned int& shaderId)
	{
		
	}

	void Render2DQueue::add(const Render2DQueueAddParams& params)
	{
		const std::iterator<float, unsigned int> it;
		//if( != m_queue.end())
		//	m_objectQueue
	}
}

bool compare(const Test& a, const Test& b)
{
	if (a.z != b.z)
		return a.z < b.z;

	if (a.shaderId != b.shaderId)
		return a.shaderId < b.shaderId;

	return a.textureId < b.textureId;

}

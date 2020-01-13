#ifndef CHEETAH_ENGINE_RENDERER_RENDERER2DQUEUE_H_
#define CHEETAH_ENGINE_RENDERER_RENDERER2DQUEUE_H_

#include "Texture.h"
#include "Shader.h"
#include "Math/Mat4x4"

#include <vector>
#include <memory>
#include <map>
#include <string>

namespace cheetah
{
	struct Render2DQueueItem
	{
		std::unique_ptr<Shader> shader;
		std::unique_ptr<Texture> texture;
	};

	struct Render2DQueueAddParams
	{
		float z = 0.0f;
		Mat4x4f transform;
		std::unique_ptr<Shader> shader;
		std::unique_ptr<Texture> texture;
	};

	class Render2DQueue
	{
	public:
		Render2DQueue() = default;
		~Render2DQueue() = default;

		void add(const Render2DQueueAddParams& params);

	private:
		unsigned int nextId;
		unsigned int createId(const float& z, const unsigned int& textureId, const unsigned int& shaderId);
		std::map<unsigned int, float> m_queue;
		std::map<unsigned int[2], Render2DQueueItem> m_objectQueue;
		std::map<unsigned int[2], std::vector<Mat4x4f>> m_transformQueue;
	};
}


#endif // !CHEETAH_ENGINE_RENDERER_RENDERER2DQUEUE_H_

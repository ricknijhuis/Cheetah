#ifndef CHEETAH_ENGINE_CORE_LAYERSTACK_H_
#define CHEETAH_ENGINE_CORE_LAYERSTACK_H_

#include "UpdateLayer.h"

#include <vector>

namespace cheetah {
	class CH_API UpdateLayerQueue
	{
	public:
		UpdateLayerQueue();
		~UpdateLayerQueue();

		void pushLayer(UpdateLayer* layer);
		void pushOverlay(UpdateLayer* overlay);
		void popLayer(UpdateLayer* layer);
		void popOverlay(UpdateLayer* layer);
		void onUpdate(const float& deltaTime);

		std::vector<UpdateLayer*>::iterator begin();
		std::vector<UpdateLayer*>::iterator end();
		std::vector<UpdateLayer*>::reverse_iterator rbegin();
		std::vector<UpdateLayer*>::reverse_iterator rend();
	private:
		std::vector<UpdateLayer*> m_layerQueue;
		std::vector<UpdateLayer*>::iterator m_layerInsertPos;
	};
}

#endif // !CHEETAH_ENGINE_CORE_LAYERSTACK_H_

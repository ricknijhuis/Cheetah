#ifndef CHEETAH_ENGINE_CORE_LAYER_H_
#define CHEETAH_ENGINE_CORE_LAYER_H_

#include "Core.h"

#include "../Events/Event.h"

#include <string>

namespace cheetah {
	class CH_API UpdateLayer
	{
	public:
		std::string name;
	public:
		UpdateLayer(const std::string& name = "Layer");
		virtual ~UpdateLayer() = default;
		virtual void onAttach() {};
		virtual void onDetach() {};
		virtual void onUpdate(const float& deltaTime) {};
		virtual void onEvent(Event& event) {};
	};
}

#endif // !CHEETAH_ENGINE_CORE_LAYER_H_
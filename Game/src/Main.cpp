#include "EntryPoint.h"
#include "Cheetah.h"

#include "GameLayer.h"

#include <iostream>

namespace game
{
	class Game : public cheetah::Application
	{
	public:
		Game()
		{
			this->pushLayer(new GameLayer());
		}

		~Game()
		{
		}
	};
}

cheetah::Application* cheetah::createApplication()
{
	return new game::Game();
}


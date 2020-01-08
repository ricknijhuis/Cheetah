#ifndef GAME_GAMELAYER_H_
#define GAME_GAMELAYER_H_

#include "Cheetah.h"
#include "GameObject.h"
#include "GameScene.h"

namespace game
{
	class GameLayer : public cheetah::UpdateLayer
	{
	public:
		GameLayer();
		~GameLayer();
		void onAttach() override;
		void onEvent(cheetah::Event& event) override;
		void onUpdate(const float& deltaTime) override;

	private:
		float m_minFps;
		float m_maxFps;

		//GameObject m_player;
		//GameObject m_background;
		
		GameScene m_gameScene;

		cheetah::OrthoGraphicCamera m_camera;
	};

}

#endif // !GAME_GAMELAYER_H_
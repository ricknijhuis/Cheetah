#ifndef GAME_GAMESCENE_H_
#define GAME_GAMESCENE_H_

#include "Scene.h"

#include "Cheetah.h"

namespace game
{
	class GameScene : public Scene
	{
	public:
		GameScene();
		void updateScene(float deltaTime) override;
	private:
		void handleInput(float deltaTime);
		void spawnLaser(cheetah::math::Vector3f pos);
		void updateLasers(const float& deltaTime);

	private:
		float m_fireRate;
		float m_fireRateDeltaTime;
		bool m_fireSide;
		std::vector<std::string> m_lasers;
	};
}

#endif // !GAME_GAMESCENE_H_

#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_

#include "Cheetah.h"

#include "GameObject.h"

#include<map>
#include<memory>

namespace game
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		void addGameObject(const std::string& name, const GameObjectParams& params);
		GameObject& getGameObject(const std::string& name);
		bool containsGameObject(const std::string& name);
		virtual void updateScene(float deltaTime) = 0;
		void drawScene();

	protected:
		std::map<std::string, std::unique_ptr<GameObject>> m_objects;
	};
}

#endif // !GAME_SCENE_H_

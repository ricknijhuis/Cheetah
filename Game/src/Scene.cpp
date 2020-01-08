#include "Scene.h"

using namespace cheetah;

namespace game
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::addGameObject(const std::string& name, const GameObjectParams& params)
	{
		m_objects.try_emplace(name, std::make_unique<GameObject>(params));
	}

	bool Scene::containsGameObject(const std::string& name)
	{
		return (m_objects.find(name) != m_objects.end());
	}

	GameObject& Scene::getGameObject(const std::string& name)
	{
		return *(m_objects.at(name));

	
	}

	void Scene::drawScene()
	{
		for (const auto& object : m_objects)
			object.second->draw();
	}
}
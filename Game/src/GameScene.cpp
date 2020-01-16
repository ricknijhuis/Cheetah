#include "GameScene.h"

#include <algorithm>

using namespace cheetah;
using namespace math;

namespace game
{
	GameScene::GameScene()
		: m_fireRate(200.0f), m_fireRateDeltaTime(1000.0f)
	{
	}
	void GameScene::updateScene(float deltaTime)
	{
		handleInput(deltaTime);

		GameObject& bg1 = this->getGameObject("background1");
		GameObject& bg2 = this->getGameObject("background2");

		float height = (float)Application::getWindow().getHeight();

		if (bg1.m_position.y >= height)
		{
			bg1.setPosition(Vector3f(bg1.m_position.x, 0.0 - height, 0.0f));
			bg1.setScale(Vector3f((float)Application::getWindow().getWidth(), (float)Application::getWindow().getHeight(), 0.0f));
		}

		if (bg2.m_position.y >= height)
		{
			bg2.setPosition(Vector3f(bg2.m_position.x, 0.0 - height, 0.0f));
			bg2.setScale(Vector3f((float)Application::getWindow().getWidth(), (float)Application::getWindow().getHeight(), 0.0f));
		}

		this->getGameObject("background1").translate(Vector3f(0.0, 0.02 * deltaTime, 0.0f));
		this->getGameObject("background2").translate(Vector3f(0.0, 0.02 * deltaTime, 0.0f));

		this->updateLasers(deltaTime);
	}

	void GameScene::handleInput(float deltaTime)
	{
		GameObject& player = this->getGameObject("player");
		GameObject& bg1 = this->getGameObject("background1");
		GameObject& bg2 = this->getGameObject("background2");

		if (Input::isKeyPressed(input::keys::W))
		{
			player.translate(Vector3f(0.0f, -(0.5f * deltaTime), 0.0f));
		}

		if (Input::isKeyPressed(input::keys::S))
		{
			player.translate(Vector3f(0.0f, 0.5f * deltaTime, 0.0f));
		}

		if (Input::isKeyPressed(input::keys::D))
		{
			player.translate(Vector3f(0.5f * deltaTime, 0.0f, 0.0f));
			bg1.translate(Vector3f(-(0.01 * deltaTime), 0.0, 0.0f));
			bg2.translate(Vector3f(-(0.01 * deltaTime), 0.0, 0.0f));
		}

		if (Input::isKeyPressed(input::keys::A))
		{
			player.translate(Vector3f(-(0.5f * deltaTime), 0.0f, 0.0f));
			bg1.translate(Vector3f(0.01 * deltaTime, 0.0, 0.0f));
			bg2.translate(Vector3f(0.01 * deltaTime, 0.0, 0.0f));
		}

		if (Input::isMouseBtnPressed(input::mouseBtns::MouseBtnLeft))
		{
			this->m_fireRateDeltaTime += deltaTime;
			if (this->m_fireRateDeltaTime > this->m_fireRate)
			{
				this->m_fireRateDeltaTime = 0.0f;
				this->spawnLaser(player.m_position);
			}
		}
	}

	void GameScene::spawnLaser(Vector3f pos)
	{
		for (int i = 0; i < 100; i++)
		{
			std::string name = std::to_string(i);
			if (!this->containsGameObject(name))
			{
				m_lasers.emplace_back(name);
				this->addGameObject(
					name,
					GameObjectParams{
						Vector3f(m_fireSide ? pos.x + 25.0f : pos.x - 25.0f, pos.y - 30.0f, 1.0f),
						Vector3f(1.0f, 25.0f, 1.0f),
						Quaternionf(),
						Rgba(1.0f, 0.0f, 0.0f, 0.7f),
						nullptr
					}
				);
				m_fireSide = !m_fireSide;
				return;
			}
		}
	}

	void GameScene::updateLasers(const float& deltaTime)
	{
		for (const auto& name : m_lasers)
		{
			GameObject& laser = this->getGameObject(name);
			if (laser.m_position.x > Application::getWindow().getWidth() || laser.m_position.y > Application::getWindow().getHeight() || laser.m_position.x < -200.0f || laser.m_position.y < -200.0f)
			{
				this->m_objects.erase(name);
				this->m_lasers.erase(std::remove(this->m_lasers.begin(), this->m_lasers.end(), name), this->m_lasers.end());
				return;
			}
			laser.translate(Vector3f(0.0, -(0.8f * deltaTime), 0.0f));
		}
	}
}
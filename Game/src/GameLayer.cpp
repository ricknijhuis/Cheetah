#include "GameLayer.h"

#include "Cheetah.h"

#include <iostream>

using namespace cheetah;

static ResourceLoader resourceLoader;

namespace game
{
	GameLayer::GameLayer()
		: 
		m_camera({ -50.0f, 50.0f, -50, 50.0f, -1.0f, 5.0f, (float)Application::getWindow().getWidth() / (float)Application::getWindow().getHeight(), Vector3f(0.0f) }),
		m_maxFps(0.0f),
		m_minFps(0.0f)


	{
		Texture* background = resourceLoader.getTexturePtr("../../../../Game/assets/background.jpg");
		Texture* fighter = resourceLoader.getTexturePtr("../../../../Game/assets/fighter2.png");

		background->scale = 2.0f;

		m_gameScene.addGameObject(
			"background1",
			{
				Vector3f(0.0f, 0.0f, 0.0f),
				Vector3f((float)Application::getWindow().getWidth(), (float)Application::getWindow().getHeight(), 0.0f),
				Quaternion(),
				Vector4f(1.0f),
				background
			});

		m_gameScene.addGameObject(
			"background2",
			{
				Vector3f(0.0f, 0.0f -((float)Application::getWindow().getHeight()), 0.0f),
				Vector3f((float)Application::getWindow().getWidth(), (float)Application::getWindow().getHeight(), 0.0f),
				Quaternion(),
				Vector4f(1.0f),
				background
			});

		m_gameScene.addGameObject(
			"player",
			{
				Vector3f(0.0f, 0.0f, 1.0),
				Vector3f(100.0f, 70.0f, 1.0f),
				Quaternion(),
				Vector4f(1.0f),
				fighter
			}
		);
	}

	void GameLayer::onAttach()
	{
	}

	void GameLayer::onEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowResizeEvent>(EventTypes::WindowResize, std::bind(&OrthoGraphicCamera::onWindowResize, &m_camera, std::placeholders::_1));
	}

	void GameLayer::onUpdate(const float& deltaTime)
	{
		float fps = Time::getFps();
		m_maxFps = fps > m_maxFps ? fps : m_maxFps;
		m_minFps = m_minFps == 0.0f || fps < m_minFps ? fps : m_minFps;

		RenderAction::setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		RenderAction::clear();

		m_gameScene.updateScene(deltaTime);

		{
			Renderer2D::beginScene(this->m_camera);
		
			m_gameScene.drawScene();

			Renderer2D::endScene();
		}
	}

	GameLayer::~GameLayer()
	{
		std::cout << m_minFps << std::endl;
		std::cout << m_maxFps << std::endl;
	}
}
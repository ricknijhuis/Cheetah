#include "Application.h"

#include "Events/EventDispatcher.h"
#include "Events/ApplicationEvents.h"
#include "Core/Time.h"
#include "Input/Input.h"
#include "Renderer/Renderer.h"

#include <iostream>

namespace cheetah
{
	Application* Application::s_instance = NULL;

	Application::Application()
	{
		s_instance = this;
		m_window = std::unique_ptr<Window>((Window::create()));
		m_window->setEventCallBack(std::bind(&Application::onEvent, this, std::placeholders::_1));

		Renderer::init();
	}

	void Application::run()
	{
		while (m_isRunning)
		{
			Time::getInstance()->setTime();
			Time::getInstance()->setDeltaTime();
			Time::getInstance()->setLastFrameTime();

			m_layerStack.onUpdate(Time::getDeltaTimeMsec());

			m_window->onUpdate();
		}
	}

	// events
	void Application::onEvent(Event& event)
	{

		EventDispatcher dispatcher(event);

		dispatcher.dispatch<WindowCloseEvent>(EventTypes::WindowClose, std::bind(&Application::onWindowClose, this, std::placeholders::_1));
		dispatcher.dispatch<WindowResizeEvent>(EventTypes::WindowResize, std::bind(&Application::onWindowResize, this, std::placeholders::_1));

		for (auto it = m_layerStack.rbegin(); it != m_layerStack.rend(); it++)
		{
			(*it)->onEvent(event);
			if (event.m_isHandled)
				break;
		}
	}

	bool Application::onWindowResize(WindowResizeEvent& event)
	{
		Renderer::setViewPort(0, 0, event.m_width, event.m_height);
		return true;
	}

	bool Application::onWindowClose(WindowCloseEvent& event)
	{
		m_isRunning = false;
		Renderer::shutDown();
		return true;
	}

	// layers
	void Application::pushLayer(UpdateLayer* layer)
	{
		m_layerStack.pushLayer(layer);
	}

	void Application::pushOverlay(UpdateLayer* overlay)
	{
		m_layerStack.popLayer(overlay);
	}

	Application& Application::getApplication()
	{
		return *s_instance;
	}

	Window& Application::getWindow()
	{
		return *Application::getApplication().m_window;
	}
}

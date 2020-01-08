#include "WindowsWindow.h"

#include "Events/EventTypes.h"
#include "Events/ApplicationEvents.h"
#include "Events/InputEvents.h"
#include "Renderer/RenderAPI.h"

#include <iostream>

namespace cheetah
{
	static bool s_IsGlfwInitialized = false;

	Window* Window::create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		this->init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		this->shutDown();
	}

	void WindowsWindow::init(const WindowProps& props)
	{
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.heigth = props.height;

		if (!s_IsGlfwInitialized)
		{
			s_IsGlfwInitialized = glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

			if (RenderAPI::getAPI() == RenderAPI::API::OpenGL)
			{
				glfwWindowHint(GLFW_SAMPLES, 4);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef DEBUG
				glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);
#endif // DEBUG

			}
		}

		this->m_window = glfwCreateWindow(m_data.width, m_data.heigth, m_data.title.c_str(), nullptr, nullptr);

		if (this->m_window == nullptr)
			glfwTerminate();

		// set context
		m_context = GraphicsContext::create(m_window);
		m_context->init();

		glfwSetWindowUserPointer(m_window, &m_data);

		//events
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				data->width = width;
				data->heigth = height;

				WindowResizeEvent event(width, height, EventTypes::WindowResize);
				data->eventCallBack(event);
			});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event(EventTypes::WindowClose);
				data->eventCallBack(event);
			});

		glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int codePoint)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				CharInputEvent event(codePoint);
				data->eventCallBack(event);
			});
	}

	void WindowsWindow::setEventCallBack(const EventCallBackFn& callback)
	{
		m_data.eventCallBack = callback;
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(this->m_window);
	}

	void WindowsWindow::shutDown()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void* WindowsWindow::getNativeWindow() const
	{
		return m_window;
	}

	unsigned int WindowsWindow::getWidth() const
	{
		return m_data.width;
	}

	unsigned int WindowsWindow::getHeight() const
	{
		return m_data.heigth;
	}
}

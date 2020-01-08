#include "WindowsInput.h"

#include "Core/Application.h"

#include "GLFW/glfw3.h"

namespace cheetah
{
	Input* Input::getInstance()
	{
		if (s_instance == nullptr)
			s_instance = new WindowsInput();

		return s_instance;
	}

	bool WindowsInput::isKeyPressedImpl(int keyCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::getApplication().getWindow().getNativeWindow());
		int state = glfwGetKey(window, keyCode);
		if (state == GLFW_PRESS)
			return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::isMouseBtnPressedImpl(int btnCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::getApplication().getWindow().getNativeWindow());
		int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
		if(state == GLFW_PRESS)
			return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::getMousePositionImpl()
	{
		double x, y;
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::getApplication().getWindow().getNativeWindow());
		glfwGetCursorPos(window, &x, &y);
		return { (float)x, (float)y };
	}

	float WindowsInput::getMousePositionXImpl()
	{
		auto test = getMousePositionImpl();
		return test.first;
	}

	float WindowsInput::getMousePositionYImpl()
	{
		auto test = getMousePositionImpl();
		return test.second;
	}
}
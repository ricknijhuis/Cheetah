#include "WindowsTime.h"

#include <GLFW/glfw3.h>

namespace cheetah
{
	Time* Time::getInstance()
	{
		if (s_instance == nullptr)
			s_instance = new WindowsTime();

		return s_instance;
	}

	float WindowsTime::getCurrentTime()
	{
		return (float)glfwGetTime();
	}
}

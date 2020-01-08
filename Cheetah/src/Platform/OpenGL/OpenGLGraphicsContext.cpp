#include "OpenGLGraphicsContext.h"

#include <iostream>

namespace cheetah
{
	namespace opengl
	{
		OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow* window)
			: m_windowHandle(window)
		{

		}

		void OpenGLGraphicsContext::init()
		{
			glfwMakeContextCurrent(m_windowHandle);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
				return;
			}
		}

		void OpenGLGraphicsContext::swapBuffers()
		{
			glfwSwapBuffers(m_windowHandle);
		}
	}
}
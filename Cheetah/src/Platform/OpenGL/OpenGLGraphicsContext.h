#ifndef CHEETAH_PLATFORM_OPENGL_OPENGLGRAPHICSCONTEXT
#define CHEETAH_PLATFORM_OPENGL_OPENGLGRAPHICSCONTEXT

#include "Renderer/GraphicsContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace cheetah
{
	namespace opengl
	{
		class OpenGLGraphicsContext : public GraphicsContext
		{
		public:
			OpenGLGraphicsContext(GLFWwindow* window);

			virtual void init() override;
			virtual void swapBuffers() override;
		private:
			GLFWwindow* m_windowHandle;
		};
	}
}

#endif // !CHEETAH_PLATFORM_OPENGL_OPENGLGRAPHICSCONTEXT

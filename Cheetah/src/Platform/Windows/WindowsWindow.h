#ifndef CHEETAH_CORE_WINDOW_H_
#define CHEETAH_CORE_WINDOW_H_

#include "Core/Window.h"

#include "Renderer/GraphicsContext.h"

#include "GLFW/glfw3.h"

#include <string>

namespace cheetah {
	class WindowsWindow : public Window {
	public:
		using EventCallBackFn = std::function<void(Event&)>;
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;
		void setEventCallBack(const EventCallBackFn& callback) override;
		unsigned int getWidth() const override;
		unsigned int getHeight() const override;
		virtual void* getNativeWindow() const override;

	private:
		void init(const WindowProps&) override;
		void shutDown();

	private:
		GLFWwindow* m_window;
		std::unique_ptr<GraphicsContext> m_context;

		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int heigth;
			bool vSync;
			EventCallBackFn eventCallBack;
		};

		WindowData m_data;
	};
}

#endif // !CHEETAH_CORE_WINDOW_H_

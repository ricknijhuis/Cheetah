#ifndef CHEETAH_ENGINE_CORE_WindowBase_H_
#define CHEETAH_ENGINE_CORE_WindowBase_H_

#include "Core.h"
#include "../Events/Event.h"

#include <functional>
#include <string>

namespace cheetah
{

	struct WindowProps
	{
		unsigned int width;
		unsigned int height;
		const std::string title;

		WindowProps(const std::string& title = "Cheetah Engine", unsigned int width = 1280, unsigned int height = 720)
			: title(title), width(width), height(height)
		{
		}
	};

	class CH_API Window
	{
	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() = default;
		virtual void onUpdate() = 0;
		virtual void setEventCallBack(const EventCallBackFn& callback) = 0;
		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;
		virtual void* getNativeWindow() const = 0;

		static Window* create(const WindowProps & = WindowProps());
	protected:
		virtual void init(const WindowProps&) = 0;
		virtual void shutDown() = 0;
	};
}

#endif // !CHEETAH_CORE_WINDOW_H_

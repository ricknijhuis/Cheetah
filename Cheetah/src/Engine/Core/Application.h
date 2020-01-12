#ifndef CHEETAH_ENGINE_CORE_APPLICATION_H_
#define CHEETAH_ENGINE_CORE_APPLICATION_H_

#include "Core.h"

#include "Window.h"
#include "UpdateLayerQueue.h"
#include "../Events/ApplicationEvents.h"

namespace cheetah
{
	class CH_API Application
	{
	public:
		Application();
		virtual ~Application() = default;
		void run();

		void onEvent(Event& event);

		bool onWindowClose(WindowCloseEvent& event);
		bool onWindowResize(WindowResizeEvent& event);

		void pushLayer(UpdateLayer* layer);
		void pushOverlay(UpdateLayer* overlay);

		void exit();

		static Window& getWindow();
		static Application& getApplication();

	private:
		bool m_isRunning = true;
		UpdateLayerQueue m_layerStack;
		std::unique_ptr<Window> m_window;

		static Application* s_instance;
	};

	//To be defined in CLIENT!
	Application* createApplication();
}

#endif // !CHEETAH_ENGINE_CORE_APPLICATION_H_

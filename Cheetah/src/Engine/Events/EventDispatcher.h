#ifndef CHEETAH_ENGINE_EVENTS_EVENTDISPATCHER_H_
#define CHEETAH_ENGINE_EVENTS_EVENTDISPATCHER_H_

#include "Core/Core.h"
#include "Events/Event.h"

#include <functional>

namespace cheetah {
	class CH_API EventDispatcher
	{
	public:
		using EventCallBackFn = std::function<bool(Event&)>;

		EventDispatcher(Event& event);
		~EventDispatcher() {}

		template<class T, typename F>
		void dispatch(EventTypes eventType, F callBack)
		{
			if (eventType == m_event.getEventType())
				m_event.m_isHandled = callBack(static_cast<T&>(m_event));
		}

	private:
		Event& m_event;
	};
}
#endif // !CHEETAH_ENGINE_EVENTS_EVENTDISPATCHER_H_


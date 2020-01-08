#ifndef CHEETAH_ENGINE_EVENTS_WINDOWCLOSEEVENT_H_
#define CHEETAH_ENGINE_EVENTS_WINDOWCLOSEEVENT_H_

#include "Event.h"
#include "EventTypes.h"

namespace cheetah {
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent(EventTypes eventType);
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height, EventTypes eventType);
	public:
		unsigned int m_height, m_width;
	};
}

#endif // !CHEETAH_ENGINE_EVENTS_WINDOWCLOSEEVENT_H_

#include "ApplicationEvents.h"

namespace cheetah {
	WindowCloseEvent::WindowCloseEvent(EventTypes eventType = EventTypes::WindowClose)
		: Event(eventType) {
		m_eventType = eventType;
	}

	WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height, EventTypes eventType = EventTypes::WindowResize)
		: m_height(height), m_width(width), Event(eventType)
	{
	}
}
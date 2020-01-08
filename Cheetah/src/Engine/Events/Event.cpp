#include "Event.h"

#include "EventTypes.h"

namespace cheetah {
	Event::Event(EventTypes eventType)
		: m_eventType(eventType)
	{
		
	}

	EventTypes Event::getEventType() 
	{
		return m_eventType;
	}

}

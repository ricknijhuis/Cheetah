#ifndef CHEETAH_ENGINE_EVENT_EVENT_H_
#define CHEETAH_ENGINE_EVENT_EVENT_H_

#include "EventTypes.h"

namespace cheetah {

	class Event
	{
	protected:
		Event(EventTypes eventType);
		~Event() {};
	public:
		bool m_isHandled = false;
		virtual EventTypes getEventType();

	protected:
		EventTypes m_eventType;
	};
}

#endif // !CHEETAH_ENGINE_EVENT_EVENT_H_

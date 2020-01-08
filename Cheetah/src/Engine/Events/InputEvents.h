#ifndef CHEETAH_ENGINE_EVENTS_CHARINPUTEVENT_H_
#define CHEETAH_ENGINE_EVENTS_CHARINPUTEVENT_H_

#include "Event.h"

namespace cheetah
{
	class CharInputEvent : public Event
	{
	public:
		CharInputEvent(unsigned int codePoint, EventTypes eventType = EventTypes::CharInput);

	private:
		unsigned int m_codePoint;
	};
}

#endif // !CHEETAH_ENGINE_EVENTS_CHARINPUTEVENT_H_
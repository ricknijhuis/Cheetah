#include "InputEvents.h"

namespace cheetah
{
	CharInputEvent::CharInputEvent(unsigned int codePoint, EventTypes eventType)
		: m_codePoint(codePoint), Event(eventType)
	{
		m_eventType = eventType;
	}
}
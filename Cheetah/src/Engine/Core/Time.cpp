#include "Time.h"

namespace cheetah
{
	Time* Time::s_instance = nullptr;

	Time::Time(float time, float lastFrameTime )
		: m_Time(time), m_LastFrameTime(lastFrameTime), m_DeltaTime(0.0f)
	{

	}

	void Time::setDeltaTime()
	{
		getInstance()->m_DeltaTime = getCurrentTime() - m_LastFrameTime;
	}

	void Time::setLastFrameTime()
	{
		getInstance()->m_LastFrameTime = getCurrentTime();
	}

	void Time::setTime()
	{
		getInstance()->m_Time = getCurrentTime();
	}

	float Time::getTime()
	{
		return getInstance()->m_Time;
	}

	float Time::getDeltaTimeSec()
	{
		return getInstance()->m_DeltaTime;
	}

	float Time::getDeltaTimeMsec()
	{
		return getInstance()->m_DeltaTime * 1000.0f;
	}

	float Time::getFps()
	{
		return 1.0f / getInstance()->m_DeltaTime;
	}
}
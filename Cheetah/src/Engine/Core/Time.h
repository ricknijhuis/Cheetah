#ifndef CHEETAH_ENGINE_CORE_TIME_H_
#define CHEETAH_ENGINE_CORE_TIME_H_

#include "Application.h"
#include "Core.h"

namespace cheetah
{
	class CH_API Time
	{
	private:
		static Time* s_instance;
	protected:
		float m_Time;
		float m_DeltaTime;
		float m_LastFrameTime;
	private:
		void friend Application::run();
		void setTime();
		void setDeltaTime();
		void setLastFrameTime();
	protected:
		Time(float time = 0.0f, float lastFrameTime = 0.0f);
		virtual float getCurrentTime() = 0;
		static Time* getInstance();

	public:
		static float getTime();
		static float getDeltaTimeSec();
		static float getDeltaTimeMsec();
		static float getFps();
	};
}

#endif // !CHEETAH_ENGINE_CORE_TIMIT_H_
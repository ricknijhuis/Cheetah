#ifndef CHEETAH_PLATFORM_WINDOWS_WINDOWSTIME_H_
#define CHEETAH_PLATFORM_WINDOWS_WINDOWSTIME_H_

#include "Core/Time.h"

namespace cheetah
{
	class WindowsTime : public Time
	{
	public:
		WindowsTime() = default;
	private:
		virtual float getCurrentTime() override;
	};

}

#endif // !CHEETAH_PLATFORM_WINDOWS_WINDOWSTIME_H_
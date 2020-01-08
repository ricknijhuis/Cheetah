#ifndef CHEETAH_PLATFORM_WINDOWS_WINDOWSINPUT_H_
#define CHEETAH_PLATFORM_WINDOWS_WINDOWSINPUT_H_

#include "Input/Input.h"

namespace cheetah
{
	class WindowsInput : public Input
	{
	private:
		virtual bool isKeyPressedImpl(int keyCode) override;
		virtual bool isMouseBtnPressedImpl(int btnCode) override;
		virtual std::pair<float, float> getMousePositionImpl() override;
		virtual float getMousePositionXImpl() override;
		virtual float getMousePositionYImpl() override;
	};
}

#endif // !CHEETAH_PLATFORM_WINDOWS_WINDOWSINPUT_H_

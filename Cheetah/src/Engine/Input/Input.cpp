#include "Input.h"

namespace cheetah
{
	Input* Input::s_instance = nullptr;

	bool Input::isKeyPressed(int keyCode)
	{
		return Input::getInstance()->isKeyPressedImpl(keyCode);
	}

	bool Input::isMouseBtnPressed(int btnCode)
	{
		return Input::getInstance()->isMouseBtnPressedImpl(btnCode);
	}

	std::pair<float, float> Input::getMousePosition()
	{
		return Input::getInstance()->getMousePositionImpl();
	}

	float Input::getMousePositionX()
	{
		return Input::getInstance()->getMousePositionXImpl();
	}

	float Input::getMousePositionY()
	{
		return Input::getInstance()->getMousePositionYImpl();
	}
}
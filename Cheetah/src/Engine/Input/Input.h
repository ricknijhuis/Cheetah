#ifndef CHEETAH_ENGINE_INPUT_INPUT_H_
#define CHEETAH_ENGINE_INPUT_INPUT_H_

#include "Core/Core.h"

namespace cheetah
{
	class CH_API Input
	{
	private:
		static Input* s_instance;

	public:
		static Input* getInstance();

		/// <summary>Gets x and y position of mouse</summary>
		/// <returns>std::pair<float, float>: x, y</returns>
		static std::pair<float, float> getMousePosition();

		/// <summary>Gets x position of mouse</summary>
		/// <returns>float</returns>
		static float getMousePositionX();

		/// <summary>Gets y position of mouse</summary>
		/// <returns>float</returns>
		static float getMousePositionY();

		/// <summary>Checks if key is pressed by key code</summary>
		/// <param name='keyCode'>keycode to check if pressed use int or input::keys::keyCodes</param>
		/// <returns>bool</returns>
		static bool isKeyPressed(int keyCode);

		/// <summary>Checks if mouse button is pressed by button code</summary>
		/// <param name='btnCode'>keycode to check if pressed use int or input::mouseBtns::MouseButtonCodes</param>
		/// <returns>bool</returns>
		static bool isMouseBtnPressed(int btnCode);

	protected:
		virtual bool isKeyPressedImpl(int keyCode) = 0;
		virtual bool isMouseBtnPressedImpl(int btnCode) = 0;
		virtual std::pair<float, float> getMousePositionImpl() = 0;
		virtual float getMousePositionXImpl() = 0;
		virtual float getMousePositionYImpl() = 0;
	};

	namespace input
	{
		namespace mouseBtns
		{
			enum MouseButtonCodes
			{
				Unknown = -1,
				MouseBtnLeft = 0,
				MouseBtnRight = 1,
				MouseBtnMidlle = 2,
				MouseBtn4 = 3,
				MouseBtn5 = 4,
				MouseBtn6 = 5,
				MouseBtn7 = 6,
				MouseBtn8 = 7
			};
		}

		namespace keys
		{
			enum KeyCodes
			{
				Unknown = -1,
				Space = 32,
				Apostrophe = 39,
				Comma = 44,
				Minus = 45,
				Period = 46,
				Slash = 47,
				Nr0 = 48,
				Nr1 = 49,
				Nr2 = 50,
				Nr3 = 51,
				Nr4 = 52,
				Nr5 = 53,
				Nr6 = 54,
				Nr7 = 55,
				Nr8 = 56,
				Nr9 = 57,
				SemiColon = 59,
				Equal = 61,
				A = 65,
				B = 66,
				C = 67,
				D = 68,
				E = 69,
				F = 70,
				G = 71,
				H = 72,
				I = 73,
				J = 74,
				K = 75,
				L = 76,
				M = 77,
				N = 78,
				O = 79,
				P = 80,
				Q = 81,
				R = 82,
				S = 83,
				T = 84,
				U = 85,
				V = 86,
				W = 87,
				X = 88,
				Y = 89,
				Z = 90,
				LBracket = 91,
				BackSlash = 92,
				RBracket = 93,
				AccentGrave = 96,
				Esc = 256,
				Enter = 257,
				Tab = 258,
				BackSpace = 259,
				Insert = 260,
				Delete = 261,
				Right = 262,
				Left = 263,
				Down = 264,
				Up = 265,
				PageUp = 266,
				PageDown = 267,
				Home = 268,
				End = 269,
				CapsLock = 280,
				ScrollLock = 281,
				NumLock = 282,
				PrintScreen = 283,
				Pause = 284,
				F1 = 290,
				F2 = 291,
				F3 = 292,
				F4 = 293,
				F5 = 294,
				F6 = 295,
				F7 = 296,
				F8 = 297,
				F9 = 298,
				F10 = 299,
				F11 = 300,
				F12 = 301,
				F13 = 302,
				F14 = 303,
				F15 = 304,
				F16 = 305,
				F17 = 306,
				F18 = 307,
				F19 = 308,
				F20 = 309,
				F21 = 310,
				F22 = 311,
				F23 = 312,
				F24 = 313,
				F25 = 314,
				KP0 = 320,
				KP1 = 321,
				KP2 = 322,
				KP3 = 323,
				KP4 = 324,
				KP5 = 325,
				KP6 = 326,
				KP7 = 327,
				KP8 = 328,
				KP9 = 329,
				KPDecimal = 330,
				KPDivide = 331,
				KPMultiply = 332,
				KPSubtract = 333,
				KPAdd = 334,
				KPEnter = 335,
				KPEqual = 336,
				LShift = 340,
				LCtrl = 341,
				LAlt = 342,
				LSuper = 343,
				RShift = 344,
				RCtrl = 345,
				RAlt = 346,
				RSuper = 347,
				Menu = 348,
			};
		}

	}
}

#endif // !CHEETAH_ENGINE_INPUT_INPUT_H_

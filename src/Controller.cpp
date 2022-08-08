#include "Controller.h"

namespace Controller
{
	Control keyboardInput()
	{
		if (GetKeyState(VK_UP) & 0x8000)
			return Control::UP;
		else if (GetKeyState(VK_DOWN) & 0x8000)
			return Control::DOWN;
		else if (GetKeyState(VK_LEFT) & 0x8000)
			return Control::LEFT;
		else if (GetKeyState(VK_RIGHT) & 0x8000)
			return Control::RIGHT;
		return Control::IDLE;
	}
}

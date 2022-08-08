#include <windows.h>

#pragma once

namespace Controller
{
	enum Control
	{
		IDLE,
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};
	Control keyboardInput();
}

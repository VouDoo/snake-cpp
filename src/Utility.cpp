#include "Utility.h"

namespace Utility
{
	void initRand()
	{
		srand((unsigned int)time(NULL));
	}
	int randInt(int min, int max)
	{
		return rand() % max + min;
	}
}

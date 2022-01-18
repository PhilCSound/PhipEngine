#pragma once
#include "PhipEngine.h"

int main()
{
	PhipEngine _phipEngine("Phip Engine Test", 800, 600);

	while (_phipEngine.IsRunning())
	{
		_phipEngine.Run();
	}

	return 0;
}
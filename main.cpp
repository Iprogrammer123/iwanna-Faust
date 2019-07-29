#include "motion_control.h"

int main(void)
{
	InitializeGame();
	while (1)
	{
		Refresh();
		UpdateWithoutInput();
		UpdateWithInput();
		Sleep(F);
	}

	return 0;
}
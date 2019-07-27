#include "motion_control.h"

int main(void)
{
	Initialize();
	while (1)
	{
		Refresh();
		UpdateWithoutInput();
		UpdateWithInput();
		Sleep(30);
	}

	return 0;
}
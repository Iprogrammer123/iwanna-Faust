#include "motion_control.h"

int main(void)
{
	Initialize();
	while (isDie==FALSE)
	{
		Refresh();
		UpdateWithoutInput();
		UpdateWithInput();
		Sleep(30);
	}

	return 0;
}

#include "motion_control.h"

void UpdateWithoutInput(void)
{
	if (isRun)
	{
		DealRun();
	}
	if (isJump)
	{
		DealJump();
	}
	if (!isRun && !isJump)
	{
		DealIdle();
	}

	return;
}

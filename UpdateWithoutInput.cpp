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

	if (CheckWallUnder())
	{
		ableJump = JUMP_COUNT;
	}
	else
	{
		DealFreeFall();
	}

	return;
}


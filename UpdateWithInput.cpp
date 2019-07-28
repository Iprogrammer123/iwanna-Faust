#include "motion_control.h"

void UpdateWithInput(void)
{
	if (KEY_LEFT_DOWN)
	{
		isRun = TRUE;
		guy_direction = LEFT;
	}
	if (KEY_RIGHT_DOWN)
	{
		isRun = TRUE;
		guy_direction = RIGHT;
	}
	if (_kbhit())
	{
		if (_getch() == KEY_JUMP && ableJump > 0)
		{
			isJump = TRUE;
			ableJump--;
			rejump_flag = TRUE;
		}
	}
	
	return;
}
#include "motion_control.h"

void DealIdle()
{
	static int count = 0;

	count++;
	if (count == 6)
	{
		idle_loop++;
		count = 0;
	}
	idle_loop = idle_loop % 4;

	return;
}

void DealRun()
{
	static int count = 0;

	switch (guy_direction)
	{
	case LEFT:
		{
			guy_x -= SPEED;
			guy_y = guy_y;
			break;
		}
	case RIGHT:
		{
			guy_x += SPEED;
			guy_y = guy_y;
			break;
		}
	}

	count++;
	if (count == 3)
	{
		run_loop++;
		count = 0;
	}
	run_loop = run_loop % 4;

	switch (guy_direction)
	{
	case LEFT:
		{
			if (KEY_LEFT_UP) isRun = FALSE;
			break;
		}
	case RIGHT:
		{
			if (KEY_RIGHT_UP) isRun = FALSE;
			break;
		}
	}

	return;
}

void DealJump()
{
	static int count = 0;
	static int time = 0;
	static int y;

	static int dcount = 0;
	static int dtime = 0;
	static int dy;

	if (isDoubleJump)
	{
		if (dtime == 0)
		{
			dy = guy_y;
		}
		else
		{
			guy_y = dy - (20 * dtime - 1 * dtime * dtime);
		}
	
		if (guy_y >= y && dtime > 0)
		{
			guy_y = y;
			isDoubleJump = FALSE;
			dtime = 0;
			isJump = FALSE;
			time = 0;
		}
		else
		{
			dtime++;
			dcount++;
			if (dcount == 3)
			{
				jump_loop++;
				dcount = 0;
			}
			jump_loop = jump_loop % 10;
		}
		
		return;
	}
	else
	{
		if (time == 0)
		{
			y = guy_y;
		}
		else
		{
			guy_y = y - (20 * time - 1 * time * time);
		}
	
		if (guy_y >= y && time > 0)
		{
			isJump = FALSE;
			time = 0;
		}
		else
		{
			time++;
			count++;
			if (count == 3)
			{
				jump_loop++;
				count = 0;
			}
			jump_loop = jump_loop % 10;
		}
		
		return;
	}
}
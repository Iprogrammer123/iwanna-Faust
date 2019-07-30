#include "motion_control.h"

static int free_fall_delta;

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
			if (CheckWallSide())		//hit side walls, no position change occurs
			{
				break;
			}
			else
			{
				guy_x -= SPEED;
				guy_y = guy_y;
				break;
			}
		}
	case RIGHT:
		{
			if (CheckWallSide())		//hit side walls, no position change occurs
			{
				break;
			}
			else
			{
				guy_x += SPEED;
				guy_y = guy_y;
				break;
			}
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
	static int delta = JUMP_HEIGHT;

	if (rejump_flag)
	{
		delta = JUMP_HEIGHT;
		rejump_flag = FALSE;
	}

	if (CheckWallOver())		//There is a wall over the head. End rising in advance
	{
		delta = JUMP_HEIGHT;
		isJump = FALSE;
	}
	else
	{
		guy_y -= delta;
		delta -= GRAVITY;
		count++;
	}
	
	
	if (count == 3)
	{
		jump_loop++;
		count = 0;
	}
	jump_loop = jump_loop % 10;

	if (delta == 0)
	{
		delta = JUMP_HEIGHT;
		isJump = FALSE;
		free_fall_delta = 0;
	
		return;
	}

	return;
}

void DealFreeFall(void)
{
	if (isJump)
	{
		guy_y = guy_y;
	}
	else
	{
		guy_y += free_fall_delta;
		free_fall_delta += 1;
	}
	if (CheckWallUnder())
	{
		guy_y = (guy_y + GUY_SIZE) / UNIT * UNIT - GUY_SIZE;
		free_fall_delta = 0;
	}

	return;
}

void DealWin(void)
{
	Sleep(3000);
	game_state = BEGIN;

	return;
}

void DealDie(void)
{
	static int count = 0;

	count++;
	if (count == 6)
	{
		count = 0;
		die_loop++;
	}
	if (die_loop == 8)
	{
		die_loop = 0;
		game_state = END;
	}

	return;
}
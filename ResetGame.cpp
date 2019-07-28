#include "motion_control.h"

void ResetGame(void)
{
	isRun = FALSE;
	isJump = FALSE;
	rejump_flag = FALSE;
	ableJump = JUMP_COUNT;
	guy_direction = RIGHT;
	guy_x = 1*UNIT;
	guy_y = 17*UNIT;

	idle_loop = 0;
	run_loop = 0;
	jump_loop = 0;

	return;
}
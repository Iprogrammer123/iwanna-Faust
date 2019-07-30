#include "motion_control.h"

static void UpdateBegin(void);
static void UpdatePlay(void);
static void UpdateEnd(void);

void UpdateWithoutInput(void)
{
	switch (game_state)
	{
	case BEGIN:
		{
			UpdateBegin();
			break;
		}
	case PLAY:
		{
			UpdatePlay();
			break;
		}
	case END:
		{
			UpdateEnd();
			break;
		}
	}

	return;
}

static void UpdateBegin(void)
{
	return;		//nothing to do
}

static void UpdatePlay(void)
{
	CheckTheLifeState();
	switch (guy_state)
	{
	case WIN:
		{
			DealWin();
			break;
		}
	case DIE:
		{
			DealDie();
			break;
		}
	case LIVE:
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
			break;
		}
	}

	return;
}

static void UpdateEnd(void)
{
	return;		//nothing to do
}
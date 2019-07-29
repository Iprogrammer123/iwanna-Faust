#include "motion_control.h"

static void UpdateBegin(void);
static void UpdatePlay(void);
static void UpdateEnd(void);

#define InStart(mx, my) ((mx > BUTTON1_X && mx < BUTTON1_X+BUTTON_WIDTH && my > BUTTON1_Y && my < BUTTON1_Y+BUTTON_HEIGHT)? 1: 0)
#define InRetry(mx, my) ((mx > BUTTON1_X && mx < BUTTON1_X+BUTTON_WIDTH && my > BUTTON1_Y && my < BUTTON1_Y+BUTTON_HEIGHT)? 1: 0)
#define InExit(mx, my) ((mx > BUTTON2_X && mx < BUTTON2_X+BUTTON_WIDTH && my > BUTTON2_Y && my < BUTTON2_Y+BUTTON_HEIGHT)? 1: 0)

void UpdateWithInput(void)
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
	MOUSEMSG m;

	if (MouseHit())
	{
		m = GetMouseMsg();
		if (m.mkLButton)
		{
			if (mouse_on_start)
			{
				InitializeGuy();
				game_state = PLAY;
			}
			if (mouse_on_exit)
			{
				exit(0);
			}
		}
		else
		{
			if (InStart(m.x, m.y))
			{
				mouse_on_start = TRUE;
				mouse_on_exit = FALSE;
			}
			else if (InExit(m.x, m.y))
			{
				mouse_on_start = FALSE;
				mouse_on_exit = TRUE;
			}
			else
			{
				mouse_on_start = FALSE;
				mouse_on_exit = FALSE;
			}
		}
	}

	return;
}

static void UpdatePlay(void)
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
			guy_state = WIN;
		} 
	}
	
	return;
}

static void UpdateEnd(void)
{
	MOUSEMSG m;

	if (MouseHit())
	{
		m = GetMouseMsg();
		if (m.mkLButton)
		{
			if (mouse_on_retry)
			{
				InitializeGuy();
				game_state = PLAY;
			}
			if (mouse_on_exit)
			{
				exit(0);
			}
		}
		else
		{
			if (InRetry(m.x, m.y))
			{
				mouse_on_retry = TRUE;
				mouse_on_exit = FALSE;
			}
			else if (InExit(m.x, m.y))
			{
				mouse_on_retry = FALSE;
				mouse_on_exit = TRUE;
			}
			else
			{
				mouse_on_retry = FALSE;
				mouse_on_exit = FALSE;
			}
		}
	}

	return;
}
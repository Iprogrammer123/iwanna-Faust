#include "motion_control.h"

static void DrawBeginMenu(void);
static void DrawBackground(void);
static void DrawMap(void);
static void DrawGuy(void);
static void DrawWinGuy(void);
static void DrawDieGuy(void);
static void DrawLiveGuy(void);
static void DrawEndMenu(void);

void Refresh(void)
{
	switch (game_state)
	{
	case BEGIN:
		{
			DrawBeginMenu();
			break;
		}
	case PLAY:
		{
			DrawBackground();
			DrawMap();
			DrawGuy();
			break;
		}
	case END:
		{
			DrawEndMenu();
			break;
		}
	}
	FlushBatchDraw();

	return;
}

static void DrawBeginMenu(void)
{
	putimage(0, 0, &begin_img);

	if (mouse_on_start)
	{
		putimage(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &start_bk_img, 0, 0, NOTSRCERASE);
		putimage(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &start_img, 0, 0, SRCINVERT);
	}
	else
	{
		putimage(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &ostart_bk_img, 0, 0, NOTSRCERASE);
		putimage(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &ostart_img, 0, 0, SRCINVERT);
	}

	if (mouse_on_exit)
	{
		putimage(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &exit_bk_img, 0, 0, NOTSRCERASE);
		putimage(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &exit_img, 0, 0, SRCINVERT);
	}
	else
	{
		putimage(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &oexit_bk_img, 0, 0, NOTSRCERASE);
		putimage(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &oexit_img, 0, 0, SRCINVERT);
	}

	return;
}

static void DrawBackground(void)
{
	putimage(0, 0, &background_img);

	return;
}

static void DrawMap(void)
{
	int i = 0, j = 0;

	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT; j++)
		{
			switch (map_array[i][j])
			{
			case BLANK:
				{
					continue;
				}
			case WALL:
				{
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &wall_img, 0, 0, SRCCOPY);
					break;
				}
			case TL:
				{
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &tl_bk_img, 0, 0, NOTSRCERASE);
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &tl_img, 0, 0, SRCINVERT);
					break;
				}
			case TR:
				{
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &tr_bk_img, 0, 0, NOTSRCERASE);
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &tr_img, 0, 0, SRCINVERT);
					break;
				}
			case TU:
				{
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &tu_bk_img, 0, 0, NOTSRCERASE);
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &tu_img, 0, 0, SRCINVERT);
					break;
				}
			case TD:
				{
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &td_bk_img, 0, 0, NOTSRCERASE);
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &td_img, 0, 0, SRCINVERT);
					break;
				}
			case GOAL:
				{
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &goal_bk_img, 0, 0, NOTSRCERASE);
					putimage(i*UNIT, j*UNIT, UNIT, UNIT, &goal_img, 0, 0, SRCINVERT);
					break;
				}

			}
		}
	}

	return;
}

static void DrawGuy(void)
{
	switch (guy_state)
	{
	case WIN:
		{
			DrawWinGuy();
			break;
		}
	case DIE:
		{
			DrawDieGuy();
			break;
		}
	case LIVE:
		{
			DrawLiveGuy();
			break;
		}
	}

	return;
}

static void DrawWinGuy(void)
{
	switch (guy_direction)
	{
	case LEFT:
		{
			putimage(guy_x , guy_y - 20, 30, 40, &win_left_bk_img, 0, 0, NOTSRCERASE);
			putimage(guy_x, guy_y - 20, 30, 40, &win_left_img, 0, 0, SRCINVERT);
			break;
		}
	case RIGHT:
		{
			putimage(guy_x , guy_y - 20, 30, 40, &win_right_bk_img, 0, 0, NOTSRCERASE);
			putimage(guy_x, guy_y - 20, 30, 40, &win_right_img, 0, 0, SRCINVERT);
			break;
		}
	}

	return;
}

static void DrawDieGuy(void)
{
	switch (guy_direction)
	{
	case LEFT:
		{
			putimage(guy_x, guy_y - 10, UNIT, UNIT, &die_left_bk_img, die_loop*UNIT, 0, NOTSRCERASE);
			putimage(guy_x, guy_y - 10, UNIT, UNIT, &die_left_img, die_loop*UNIT, 0, SRCINVERT);
			break;
		}
	case RIGHT:
		{
			putimage(guy_x, guy_y - 10, UNIT, UNIT, &die_right_bk_img, die_loop*UNIT, 0, NOTSRCERASE);
			putimage(guy_x, guy_y - 10, UNIT, UNIT, &die_right_img, die_loop*UNIT, 0, SRCINVERT);
			break;
		}
	}

	return;
}

static void DrawLiveGuy(void)
{
	if (isJump)
	{
		switch (guy_direction)
		{
		case LEFT:
			{
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &jump_left_bk_img, jump_loop*GUY_SIZE, 0, NOTSRCERASE);
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &jump_left_img, jump_loop*GUY_SIZE, 0, SRCINVERT);
				break;
			}
		case RIGHT:
			{
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &jump_right_bk_img, jump_loop*GUY_SIZE, 0, NOTSRCERASE);
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &jump_right_img, jump_loop*GUY_SIZE, 0, SRCINVERT);
				break;
			}
		}
	}
	else if (isRun)
	{
		switch (guy_direction)
		{
		case LEFT:
			{
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &run_left_bk_img, run_loop*GUY_SIZE, 0, NOTSRCERASE);
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &run_left_img, run_loop*GUY_SIZE, 0, SRCINVERT);
				break;
			}
		case RIGHT:
			{
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &run_right_bk_img, run_loop*GUY_SIZE, 0, NOTSRCERASE);
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &run_right_img, run_loop*GUY_SIZE, 0, SRCINVERT);
				break;
			}
		}
	}
	else
	{
		switch (guy_direction)
		{
		case LEFT:
			{
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &idle_left_bk_img, idle_loop*GUY_SIZE, 0, NOTSRCERASE);
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &idle_left_img, idle_loop*GUY_SIZE, 0, SRCINVERT);
				break;
			}
		case RIGHT:
			{
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &idle_right_bk_img, idle_loop*GUY_SIZE, 0, NOTSRCERASE);
				putimage(guy_x, guy_y, GUY_SIZE, GUY_SIZE, &idle_right_img, idle_loop*GUY_SIZE, 0, SRCINVERT);
				break;
			}
		}
	}

	return;
}

static void DrawEndMenu(void)
{
	putimage(0, 100, &end_img);

	if (mouse_on_retry)
	{
		putimage(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &retry_bk_img, 0, 0, NOTSRCERASE);
		putimage(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &retry_img, 0, 0, SRCINVERT);
	}
	else
	{
		putimage(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &oretry_bk_img, 0, 0, NOTSRCERASE);
		putimage(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &oretry_img, 0, 0, SRCINVERT);
	}

	if (mouse_on_exit)
	{
		putimage(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &exit_bk_img, 0, 0, NOTSRCERASE);
		putimage(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &exit_img, 0, 0, SRCINVERT);
	}
	else
	{
		putimage(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &oexit_bk_img, 0, 0, NOTSRCERASE);
		putimage(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, &oexit_img, 0, 0, SRCINVERT);
	}

	return;
}
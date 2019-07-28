#include "motion_control.h"

static void DrawBackground(void);
static void DrawMap(void);
static void DrawGuy(void);

void Refresh(void)
{
	DrawBackground();
	DrawMap();
	DrawGuy();
	
	FlushBatchDraw();

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
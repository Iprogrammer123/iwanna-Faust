#include "motion_control.h"

static void LoadImage(void);
static void LoadMap(void);

guy_state_type guy_state;
game_state_type game_state;
direction_type guy_direction;
int guy_x;
int guy_y;

bool isRun;
bool isJump;
bool rejump_flag;
int ableJump;
bool mouse_on_start;
bool mouse_on_retry;
bool mouse_on_exit;

int idle_loop;
int run_loop;
int jump_loop;
int die_loop;

IMAGE background_img;
IMAGE idle_left_img;
IMAGE idle_left_bk_img;
IMAGE idle_right_img;
IMAGE idle_right_bk_img;
IMAGE run_left_img;
IMAGE run_left_bk_img;
IMAGE run_right_img;
IMAGE run_right_bk_img;
IMAGE jump_left_img;
IMAGE jump_left_bk_img;
IMAGE jump_right_img;
IMAGE jump_right_bk_img;
IMAGE win_left_img;
IMAGE win_left_bk_img;
IMAGE win_right_img;
IMAGE win_right_bk_img;
IMAGE die_left_img;
IMAGE die_left_bk_img;
IMAGE die_right_img;
IMAGE die_right_bk_img;

IMAGE wall_img;
IMAGE tl_img;
IMAGE tl_bk_img;
IMAGE tr_img;
IMAGE tr_bk_img;
IMAGE tu_img;
IMAGE tu_bk_img;
IMAGE td_img;
IMAGE td_bk_img;
IMAGE goal_img;
IMAGE goal_bk_img;

IMAGE begin_img;
IMAGE end_img;
IMAGE start_img;
IMAGE start_bk_img;
IMAGE ostart_img;
IMAGE ostart_bk_img;
IMAGE retry_img;
IMAGE retry_bk_img;
IMAGE oretry_img;
IMAGE oretry_bk_img;
IMAGE exit_img;
IMAGE exit_bk_img;
IMAGE oexit_img;
IMAGE oexit_bk_img;

static map_type medium[HEIGHT][WIDTH] =
{
#include "map.txt"
};
map_type map_array[WIDTH][HEIGHT];

void InitializeGame(void)
{
	LoadImage();
	LoadMap();
	initgraph(WIDTH*UNIT, HEIGHT*UNIT);
	game_state = BEGIN;
	mouse_on_start = FALSE;
	mouse_on_retry = FALSE;
	mouse_on_exit = FALSE;
	BeginBatchDraw();

	return;
}

static void LoadImage(void)
{
	loadimage(&background_img, _T("image\\background.jpg"));
	loadimage(&idle_left_img, _T("image\\idle_left.jpg"));
	loadimage(&idle_right_img, _T("image\\idle_right.jpg"));
	loadimage(&idle_left_bk_img, _T("image\\idle_left_bk.jpg"));
	loadimage(&idle_right_bk_img, _T("image\\idle_right_bk.jpg"));
	loadimage(&run_left_img, _T("image\\run_left.jpg"));
	loadimage(&run_right_img, _T("image\\run_right.jpg"));
	loadimage(&run_left_bk_img, _T("image\\run_left_bk.jpg"));
	loadimage(&run_right_bk_img, _T("image\\run_right_bk.jpg"));
	loadimage(&jump_left_img, _T("image\\jump_left.jpg"));
	loadimage(&jump_right_img, _T("image\\jump_right.jpg"));
	loadimage(&jump_left_bk_img, _T("image\\jump_left_bk.jpg"));
	loadimage(&jump_right_bk_img, _T("image\\jump_right_bk.jpg"));
	loadimage(&win_left_img, _T("image\\win_left.jpg"));
	loadimage(&win_right_img, _T("image\\win_right.jpg"));
	loadimage(&win_left_bk_img, _T("image\\win_left_bk.jpg"));
	loadimage(&win_right_bk_img, _T("image\\win_right_bk.jpg"));
	loadimage(&die_left_img, _T("image\\die_left.jpg"));
	loadimage(&die_right_img, _T("image\\die_right.jpg"));
	loadimage(&die_left_bk_img, _T("image\\die_left_bk.jpg"));
	loadimage(&die_right_bk_img, _T("image\\die_right_bk.jpg"));

	loadimage(&wall_img, _T("image\\wall.jpg"));
	loadimage(&tl_img, _T("image\\tl.jpg"));
	loadimage(&tl_bk_img, _T("image\\tl_bk.jpg"));
	loadimage(&tr_img, _T("image\\tr.jpg"));
	loadimage(&tr_bk_img, _T("image\\tr_bk.jpg"));
	loadimage(&tu_img, _T("image\\tu.jpg"));
	loadimage(&tu_bk_img, _T("image\\tu_bk.jpg"));
	loadimage(&td_img, _T("image\\td.jpg"));
	loadimage(&td_bk_img, _T("image\\td_bk.jpg"));
	loadimage(&goal_img, _T("image\\goal.jpg"));
	loadimage(&goal_bk_img, _T("image\\goal_bk.jpg"));
	
	loadimage(&begin_img, _T("image\\begin.jpg"));
	loadimage(&end_img, _T("image\\end.jpg"));
	loadimage(&start_img, _T("image\\start.jpg"));
	loadimage(&start_bk_img, _T("image\\start_bk.jpg"));
	loadimage(&ostart_img, _T("image\\ostart.jpg"));
	loadimage(&ostart_bk_img, _T("image\\ostart_bk.jpg"));
	loadimage(&retry_img, _T("image\\retry.jpg"));
	loadimage(&retry_bk_img, _T("image\\retry_bk.jpg"));
	loadimage(&oretry_img, _T("image\\oretry.jpg"));
	loadimage(&oretry_bk_img, _T("image\\oretry_bk.jpg"));
	loadimage(&exit_img, _T("image\\exit.jpg"));
	loadimage(&exit_bk_img, _T("image\\exit_bk.jpg"));
	loadimage(&oexit_img, _T("image\\oexit.jpg"));
	loadimage(&oexit_bk_img, _T("image\\oexit_bk.jpg"));

	return;
}

static void LoadMap(void)
{
	int i = 0, j = 0;

	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT; j++)
		{
			map_array[i][j] = medium[j][i];
		}
	}

	return;
}

void InitializeGuy(void)
{
	guy_state = LIVE;
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
	die_loop = 0;

	return;
}
#include "motion_control.h"

bool isWin;
bool isDie;
bool isRun;
bool isJump;
bool rejump_flag;
int ableJump;
direction_type guy_direction;
int guy_x;
int guy_y;

int idle_loop;
int run_loop;
int jump_loop;

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

static map_type medium[HEIGHT][WIDTH] =
{
#include "map.txt"
};
map_type map_array[WIDTH][HEIGHT];

void Initialize(void)
{
	int i = 0, j = 0;

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

	initgraph(WIDTH*UNIT, HEIGHT*UNIT);

	isWin = FALSE;
	isDie = FALSE;
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

	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT; j++)
		{
			map_array[i][j] = medium[j][i];
		}
	}

	BeginBatchDraw();

	return;
}
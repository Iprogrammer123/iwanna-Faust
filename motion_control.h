#ifndef MOTION_CONTROL_H
#define MOTION_CONTROL_H

#include <graphics.h>
#include <conio.h>

#define UNIT 30		//30 pixels for each unit
#define WIDTH 30		//30 units wide
#define HEIGHT 20		//20 units high
#define GUY_SIZE 20		//20 times 20 pixels for the guy

#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_JUMP 'j'

#define KEY_LEFT_DOWN ((GetKeyState(0x41) & 0x8000) ? 1 : 0)
#define KEY_RIGHT_DOWN ((GetKeyState(0x44) & 0x8000) ? 1 : 0)
#define KEY_LEFT_UP ((GetKeyState(0x41) & 0x8000) ? 0 : 1)
#define KEY_RIGHT_UP ((GetKeyState(0x44) & 0x8000) ? 0 : 1)

#define SPEED 5		//run speed
#define JUMP_COUNT 2
#define JUMP_HEIGHT 10
#define GRAVITY 1

void Initialize(void);
void Refresh(void);
void UpdateWithInput(void);
void UpdateWithoutInput(void);
void DealIdle(void);
void DealRun(void);
void DealJump(void);
void DealFreeFall(void);
bool CheckWallUnder(void);
bool CheckWallSide(void);
bool CheckWallOver(void);
bool CheckTheLifeState(int x,int y);
	
typedef enum
{
	LEFT = 1, RIGHT
} direction_type;

typedef enum
{
	BLANK = 0, WALL, TL, TR, TU, TD, GOAL, SAVE
} map_type;

extern bool isWin;
extern bool isDie;
extern bool isRun;
extern bool isJump;
extern bool rejump_flag;
extern int ableJump;
extern direction_type guy_direction;
extern int guy_x;
extern int guy_y;

extern int idle_loop;
extern int run_loop;
extern int jump_loop;

extern IMAGE background_img;

extern IMAGE idle_left_img;
extern IMAGE idle_left_bk_img;
extern IMAGE idle_right_img;
extern IMAGE idle_right_bk_img;

extern IMAGE run_left_img;
extern IMAGE run_left_bk_img;
extern IMAGE run_right_img;
extern IMAGE run_right_bk_img;

extern IMAGE jump_left_img;
extern IMAGE jump_left_bk_img;
extern IMAGE jump_right_img;
extern IMAGE jump_right_bk_img;

extern IMAGE wall_img;
extern IMAGE tl_img;
extern IMAGE tl_bk_img;
extern IMAGE tr_img;
extern IMAGE tr_bk_img;
extern IMAGE tu_img;
extern IMAGE tu_bk_img;
extern IMAGE td_img;
extern IMAGE td_bk_img;
extern IMAGE goal_img;
extern IMAGE goal_bk_img;

extern map_type map_array[WIDTH][HEIGHT];

#endif

#ifndef MOTION_CONTROL_H
#define MOTION_CONTROL_H

#include <graphics.h>
#include <conio.h>

#define UNIT 30		//30 pixels for each unit
#define WIDTH 30		//30 units wide
#define HEIGHT 20		//20 units high
#define GUY_SIZE 20		//20 times 20 pixels for the guy
#define BUTTON1_X 200
#define BUTTON1_Y 175
#define BUTTON2_X 200
#define BUTTON2_Y 325
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 100

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

void InitializeGame(void);
void InitializeGuy(void);
void Refresh(void);
void UpdateWithInput(void);
void UpdateWithoutInput(void);
void DealIdle(void);
void DealRun(void);
void DealJump(void);
void DealFreeFall(void);
void DealWin(void);
void DealDie(void);
void CheckGuyState(void);
bool CheckWallUnder(void);
bool CheckWallSide(void);
bool CheckWallOver(void);

typedef enum
{
	LEFT, RIGHT
} direction_type;

typedef enum
{
	BLANK, WALL, TL, TR, TU, TD, GOAL, SAVE
} map_type;

typedef enum
{
	WIN, DIE, LIVE
} guy_state_type;

typedef enum
{
	BEGIN, PLAY, END
} game_state_type;

extern guy_state_type guy_state;
extern game_state_type game_state;
extern direction_type guy_direction;
extern int guy_x;
extern int guy_y;

extern bool isRun;
extern bool isJump;
extern bool rejump_flag;
extern int ableJump;
extern bool mouse_on_start;
extern bool mouse_on_retry;
extern bool mouse_on_exit;

extern int idle_loop;
extern int run_loop;
extern int jump_loop;
extern int die_loop;

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
extern IMAGE win_left_img;
extern IMAGE win_left_bk_img;
extern IMAGE win_right_img;
extern IMAGE win_right_bk_img;
extern IMAGE die_left_img;
extern IMAGE die_left_bk_img;
extern IMAGE die_right_img;
extern IMAGE die_right_bk_img;

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

extern IMAGE begin_img;
extern IMAGE end_img;
extern IMAGE start_img;
extern IMAGE start_bk_img;
extern IMAGE ostart_img;
extern IMAGE ostart_bk_img;
extern IMAGE retry_img;
extern IMAGE retry_bk_img;
extern IMAGE oretry_img;
extern IMAGE oretry_bk_img;
extern IMAGE exit_img;
extern IMAGE exit_bk_img;
extern IMAGE oexit_img;
extern IMAGE oexit_bk_img;

extern map_type map_array[WIDTH][HEIGHT];

#endif
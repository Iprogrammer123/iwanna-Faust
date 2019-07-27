#ifndef MOTION_CONTROL_H
#define MOTION_CONTROL_H

#include <graphics.h>
#include <conio.h>

#define UNIT 25		//25 pixels for each unit
#define WIDTH 36		//36 units wide
#define HEIGHT 24		//24 units high
#define GUY_SIZE 20		//20 times 20 pixels for the guy

#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_JUMP 'j'

#define KEY_DOWN(vk_code) ((GetKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetKeyState(vk_code) & 0x8000) ? 0 : 1)

#define SPEED 4		//run speed

void Initialize(void);
void Refresh(void);
void UpdateWithInput(void);
void UpdateWithoutInput(void);
void DealIdle(void);
void DealRun(void);
void DealJump(void);

typedef enum
{
	LEFT = 1, RIGHT
} DIRECTION;

extern bool isRun;
extern bool isJump;
extern bool isDoubleJump;
extern DIRECTION guy_direction;
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

#endif

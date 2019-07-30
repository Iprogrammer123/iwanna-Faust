#include "motion_control.h"

int main(void)
{
	InitializeGame();
	while (1)
	{
		Refresh();
		UpdateWithoutInput();
		UpdateWithInput();
		Sleep(game_state==PLAY? 27: 0);
	}

	return 0;
}
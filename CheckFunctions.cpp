#include "motion_control.h"

/*
 * Functions to check walls
 * Change the pixel coordinate into the unit coordinate 
 * Check the element's type in map_array by using unit coordinate
 * If there is a wall, return TRUE, if not, return FALSE
 * By the way, it is necessary to add so many bound conditions when checking
 */

bool CheckWallUnder(void)
{
	int lower_left_i, lower_right_i;
	int lower_j;

	lower_left_i = guy_x / UNIT;
	lower_right_i = (guy_x + GUY_SIZE) / UNIT;
	lower_j = (guy_y + GUY_SIZE) / UNIT;

	if (map_array[lower_left_i][lower_j] == WALL && (guy_x+GUY_SIZE/2) <= (lower_left_i+1)*UNIT)
		//Under the left foot is wall and the center of mass stay over this wall
	{
		return TRUE;
	}
	else if (map_array[lower_right_i][lower_j] == WALL && (guy_x+GUY_SIZE/2) >= lower_right_i*UNIT)
		//Under the right foot is wall and the center of mass stay over this wall
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool CheckWallSide(void)
{
	int left_i, right_i;
	int upper_j, lower_j;

	left_i = guy_x / UNIT;
	right_i = (guy_x + GUY_SIZE) / UNIT;
	upper_j = guy_y / UNIT;
	lower_j = (guy_y + GUY_SIZE - 1) / UNIT;		//minus one is necessary for some reason

	if (
		guy_direction == LEFT
		&& ((map_array[left_i][upper_j] == WALL && guy_x < (left_i+1)*UNIT)
		|| (map_array[left_i][lower_j] == WALL && guy_x < (left_i+1)*UNIT))
		)
		//either upper or lower left of the guy hit the left wall
	{
		return TRUE;
	}
	else if (
		guy_direction == RIGHT
		&& ((map_array[right_i][upper_j] == WALL && (guy_x+GUY_SIZE) > (right_i)*UNIT)
		|| (map_array[right_i][lower_j] == WALL && (guy_x+GUY_SIZE) > (right_i)*UNIT))
		)
		//either upper or lower right of the guy hit the right wall
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool CheckWallOver(void)
{
	int upper_left_i, upper_right_i;
	int upper_j;

	upper_left_i = guy_x / UNIT;
	upper_right_i = (guy_x + GUY_SIZE) / UNIT;
	upper_j = guy_y / UNIT;

	if (
		map_array[upper_left_i][upper_j] != WALL
		&& map_array[upper_right_i][upper_j] != WALL
		)
		//The unit over the guy is not wall
	{
		return FALSE;
	}
	else if (
		map_array[upper_left_i][upper_j] == WALL
		&& map_array[upper_right_i][upper_j] != WALL
		&& (guy_x+GUY_SIZE/2) > (upper_left_i+1)*UNIT
		)
		//The upper left unit is wall, but the upper right unit is not, and the center of mass stay on the right
	{
		return FALSE;
	}
	else if (
		map_array[upper_left_i][upper_j] != WALL
		&& map_array[upper_right_i][upper_j] == WALL
		&& (guy_x+GUY_SIZE/2) < upper_right_i*UNIT
		)
		//The upper left unit is not wall, but the upper right unit is, and the center of mass stay on the left
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
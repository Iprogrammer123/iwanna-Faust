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

//trx1 and try1 is the position of triangle,tr1s is the shape of the triangle
//the triwidth and trilength is the size of the triangle
//the x and the y is the guy's position
//the width and the length is the guy's size
bool CheckTheLifeState(int x,int y)
{
        bool state=FALSE;
	
	state=CheckTheTriangle(x,y,trx1,try1,shape);
	return state;
}

bool CheckOnePointTheTriangle(int x,int y,int trx1,int try1,enum map_type shape)
{
	bool tristate=FALSE;
	int nx=x-trx1,ny=y-try1;
	switch(shape)
	{
	case TL:
		if(nx<=UNIT&&((2*ny+nx)>=UNIT)&&((2*ny-nx)<=UNIT))
			tristate=TRUE;
	case TR:
		if(nx>=0&&((2*ny+nx)<=2*UNIT)&&((2*ny-nx)>=0))
			tristate=TRUE;
	case TU:
		if(ny>=0&&((ny+2*nx)<=2*UNIT)&&((ny-2*nx)<=0))
			tristate=TRUE;
	case TD:
		if(ny<=UNIT&&((ny+2*nx)>=UNIT)&&((ny-2*nx)>=(-UNIT)))
			tristate=TRUE;
	default:
	}
	return tristate;
}
bool CheckTheTriangle(int x,int y,int trx1,int trx2,enum map_type shape)
{
	bool state=FALSE;
	int ALU[2]={x,y+guy_size};
	int ARU[2]={x+guy_size,y+guy_size};
	int ALD[2]={x,y};
	int ARD[2]={x+guy_size,y};
	int AngleDirection[4][2]={{ALU[0],ALU[1]},
				  {ARU[0],ARU[1]},
				  {ALD[0],ALD[1]},
				  {ARD[0],ARD[1]}};
	int i;
	for(i=0;i<4;i++)
	{
		state=CheckOnePointTheTriangle(x,y,AngleDirection[i][0],ALU[i][1],shape);
		if(state==TRUE)
			break;
	}
	return state;
}

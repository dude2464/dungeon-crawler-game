#ifndef __FLOORTILE_H__
#define __FLOORTILE_H__

#include "WalkableCell.h"

class FloorTile: public WalkableCell { 
public:
	FloorTile(int xpos, int ypos);
	bool enemyCanWalk();
};

#endif
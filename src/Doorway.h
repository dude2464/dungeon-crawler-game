#ifndef __DOORWAY_H__
#define __DOORWAY_H__

#include "WalkableCell.h"

class Doorway: public WalkableCell { 
public:
	Doorway(int xpos, int ypos);
	bool enemyCanWalk();
	
};

#endif
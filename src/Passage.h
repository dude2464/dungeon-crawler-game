#ifndef __PASSAGE_H__
#define __PASSAGE_H__

#include "WalkableCell.h"

class Passage: public WalkableCell { 
public:
	Passage(int xpos, int ypos);
	bool enemyCanWalk();
};

#endif
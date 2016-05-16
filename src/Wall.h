#ifndef __WALL_H__
#define __WALL_H__

#include "NonWalkableCell.h"

class Wall: public NonWalkableCell {
public:
	Wall(char w, int xpos, int ypos);
};

#endif
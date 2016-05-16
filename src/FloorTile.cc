#include "FloorTile.h"

FloorTile::FloorTile(int xpos, int ypos) {
	this->symbol = '.';
	this->enemyWalkable = true;
	this->above = NULL;
	//this->above = '0';
	this->xpos = xpos;
	this->ypos = ypos;
};


bool FloorTile::enemyCanWalk(){
	return true;
}


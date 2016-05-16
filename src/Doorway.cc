#include "Doorway.h"

Doorway::Doorway(int xpos, int ypos) {
	this->symbol = '+';
	this->enemyWalkable = false;
	this->above = NULL;
	//this->above = '0';
	this->xpos = xpos;
	this->ypos = ypos;
};


bool Doorway::enemyCanWalk(){
	return false;
}

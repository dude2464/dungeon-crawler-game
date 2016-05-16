#include "Passage.h"

Passage::Passage(int xpos, int ypos) {
	this->symbol = '#';
	this->enemyWalkable = false;
	this->above = NULL;
	//this->above = '0';
	this->xpos = xpos;
	this->ypos = ypos;
};


bool Passage::enemyCanWalk(){
	return false;
}

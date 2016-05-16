#include "Cell.h"
//class character;
#include "character.h"

Cell::Cell(): filled(false){ }

char Cell::getSymbol(){
	//std::cout << "getSymbol called from Cell class" << std::endl;
	return this->symbol;
}

bool Cell::isOccupied(){
	return false;
}
void Cell::addAbove(character* a){
	std::cout << "ERROR calling addAbove on a NON walkable Cell" << std::endl;
}

bool Cell::walkable(){
	return false;
}

int Cell::getXpos(){
	return xpos;
}

int Cell::getYpos(){
	return ypos;
}

bool Cell::enemyCanWalk(){
	return false;
}

character* Cell::getAbove(){
	return NULL;
}

bool Cell::isFilled(){
	return filled;
}

void Cell::fill(){
	this->filled = true;
}
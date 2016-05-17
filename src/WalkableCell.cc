#include "WalkableCell.h"
//class character;

bool WalkableCell::walkable(){
	return true;
}

char WalkableCell::getSymbol(){
	if(above==NULL){

	//std::cout << "getSymbol called from WalkableCell class A" << std::endl;
		return this->symbol;
	}
	//std::cout << "getSymbol called from WalkableCell class B" << std::endl;
	return this->above->getSymbol();

}

bool WalkableCell::isOccupied(){
	if(above==NULL){
		return false;
	}
	return true;
}

void WalkableCell::addAbove(character* a){
	// adding above in WalkableCell class
	this->above = a;
	if(a != NULL){ 
		a->setXpos(this->xpos);
		a->setYpos(this->ypos);
	} else {
	}
}

character* WalkableCell::getAbove(){
	return above;
}

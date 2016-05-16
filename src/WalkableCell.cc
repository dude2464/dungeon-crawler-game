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
	//std::cout << "adding above in WalkableCell class" << std::endl;
	this->above = a;
	//std::cout << "Aadded something to above in WalkableCell" << std::endl;
	if(a != NULL){ 
	//	std::cout << "setting coordinates of " << std::endl;
	//	std::cout << a->getSymbol() << std::endl;
		a->setXpos(this->xpos);
		a->setYpos(this->ypos);
	//	std::cout << "coordinates set" << std::endl;
	} else {
	//	std::cout << "above was NULL" << std::endl;
	}
}

character* WalkableCell::getAbove(){
	return above;
}


//WalkableCell::~WalkableCell(){
//	delete above;
//}
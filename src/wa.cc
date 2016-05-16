#include "wa.h"

wa::wa(): tempPotion(-5, 0) {}

//character* wa::use(character* c){
//	if(ch != NULL){
//		std::cout << "using ch's use" << std::endl;
//		ch = ch->use(c);
//	} else {
//		std::cout << "setting ch = c" << std::endl;
//		ch = c;	
//	}
//	return this;
//}

character* wa::useReverse(character* c){
	//if(ch !=NULL){
//		return c->use(this);
//	}
	ch = c;
	this->atk *= -1;
	return this;
}
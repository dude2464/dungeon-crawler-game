#include "ba.h"

ba::ba(): tempPotion(5, 0) {}

//character* ba::use(character* c){
//	ch = c;
//	return this;
//}

character* ba::useReverse(character* c){
	ch = c;
	this->atk *= -1;
	return this;
}
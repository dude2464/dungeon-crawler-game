#include "bd.h"

bd::bd(): tempPotion(0, 5) {}

//character* bd::use(character* c){
//	ch = c;
//	return this;
//}

character* bd::useReverse(character* c){
	ch = c;
	this->def *= -1;
	return this;
}
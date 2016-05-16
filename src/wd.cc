#include "wd.h"

wd::wd(): tempPotion(0, -5) {}

//character* wd::use(character* c){
//	ch = c;
//	return this;
//}

character* wd::useReverse(character* c){
	ch = c;
	this->def *= -1;
	return this;
}
#include "rh.h"

rh::rh(): permaPotion(10) {}

character* rh::use(character* c){
	c->addHP(this->HP);
	return c;
}

character* rh::useReverse(character* c){
	c->addHP(-1*this->HP);
	return c;
}
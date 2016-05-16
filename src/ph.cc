#include "ph.h"

ph::ph(): permaPotion(-10) {}

character* ph::use(character* c){
	c->addHP(this->HP);
	return c;
}

character* ph::useReverse(character* c){
	c->addHP(-1*this->HP);
	return c;
}
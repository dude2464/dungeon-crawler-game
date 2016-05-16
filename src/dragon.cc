#include "dragon.h"

dragon::dragon(Gold *pGold) :
	enemy('D', 150, 20, 20, 0), pGold(pGold) {}


bool dragon::isAggro(Floor *f) {
	return f->PCInRange(pGold->getXpos(), pGold->getYpos());
}

void dragon::canPickUpGold() {
	
	this->pGold->nowCanPickUp();
}
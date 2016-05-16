#include "dragonHorde.h"

dragonHorde::dragonHorde(): Gold(6), canPickUp(false) {}

void dragonHorde::nowCanPickUp() {
	this->canPickUp = true;
}

bool dragonHorde::getCanPickUp() {
	return this->canPickUp;
}
#include "merchant.h"


merchant::merchant() : enemy('M', 30, 70, 5, 4), hostile(false) {}


void merchant::becomeHostile() {
	this->hostile = true;
}

bool merchant::isHostile() {
	return hostile;
}

// Notifies observers (all other merchants) to become hostile
void merchant::notifyMerchants(character** e, int numEnemies) {
	for (int i = 0; i < numEnemies; i++) {
		if (e[i]->getSymbol() == 'M') {
			e[i]->becomeHostile();
		} 
	}
}


bool merchant::isAggro(Floor *f) {
	return (this->hostile && f->PCInRange(this->xpos, this->ypos));
}
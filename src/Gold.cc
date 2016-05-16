#include "Gold.h"


Gold::Gold(int gold): 
	item("gold", 'G', 0, 0, 0, gold){}

character* Gold::use(character* c) {
	c->addGold(gold);
	return c;
}

bool Gold::getCanPickUp() {
	true;
}

void Gold::nowCanPickUp() {

}
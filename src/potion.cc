#include "potion.h"

bool potion::isTemp(){
	return false;
}

potion::potion(int HP, int atk, int def): 
	item("potion", 'P', HP, atk, def, 0) { }
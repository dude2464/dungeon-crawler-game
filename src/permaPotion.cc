#include "permaPotion.h"

bool permaPotion::isTemp(){
	return false;
}

permaPotion::permaPotion(int HP):
	potion(HP, 0, 0){ }

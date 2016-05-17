#include "enemy.h"
#include <ctime>
#include <cstdlib>

enemy::enemy(char symbol, int HP, int atk, int def, int gold) :
	character("enemy", symbol, HP, atk, def, gold) {}

// enemy is ready to attack
bool enemy::isAggro(Floor *f) {

	f->PCInRange(this->xpos, this->ypos);
}


void enemy::move(Floor *f, int x, int y){
	
	f->move(this, x, y);
}

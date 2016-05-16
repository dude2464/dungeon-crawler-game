#include "enemy.h"
#include <ctime>
#include <cstdlib>

enemy::enemy(char symbol, int HP, int atk, int def, int gold) :
	character("enemy", symbol, HP, atk, def, gold) {}


bool enemy::isAggro(Floor *f) {
	//std::cout << "entered enemy->isAggro method" << std::endl;
	f->PCInRange(this->xpos, this->ypos);
}


void enemy::move(Floor *f, int x, int y){
	//bool valid = false;
	//string move;
	//int newx = -1;
	//int newy = -1;
/*	int index;

	int width = f->getWidth();
	int height = f->getHeight();

	int xcoords[9];
	int ycoords[9];
	int count = 0;

	for(int y = -1; y<2; y++){
		for(int x = -1; x<2; x++){
			
			if(f->enemyWalkable(this->xpos+x, this->ypos+y)){
				xcoords[count] = this->xpos+x;
				ycoords[count] = this->ypos+y;
				count++;
			}
		}
	}

	srand(time(0));
	index = rand()%count;
*/	
	f->move(this, x, y);
	// might want to take out this part	
//	this->xpos = xcoords[index];
//	this->ypos = ycoords[index];

}



/* bool isHostile() {
	return false;
}

void becomeHostile() {

}


void notifyMerchants(character** e, int numEnemies) {

} */
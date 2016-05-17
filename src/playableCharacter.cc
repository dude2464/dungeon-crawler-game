#include "playableCharacter.h"
#include <iostream>
#include <string>
#include "Floor.h"

using namespace std;


PC::PC(int HP, int atk, int def) :
	character("PC", '@', HP, atk, def, 0) {} 

int PC::dirOnX(string dir) {
	int newx = -1;
	if(dir == "no") {
		newx = this->xpos;
	}
	else if (dir == "so") {
		newx = this->xpos;
	}
	else if (dir == "ea") {
		newx = this->xpos + 1;
	}
	else if (dir == "we") {
		newx = this->xpos - 1;
	}
	else if (dir ==  "ne") {
		newx = this->xpos + 1;
	}
	else if (dir ==  "nw") {
		newx = this->xpos - 1;
	}
	else if (dir ==  "se") {
		newx = this->xpos + 1;
	}
	else if (dir ==  "sw") {
		newx = this->xpos - 1;
	}
	return newx;
}

int PC::dirOnY(string dir) {
	int newy = -1;
	if(dir == "no") {
		newy = this->ypos - 1;
	}
	else if (dir == "so") {
		newy = this->ypos + 1;
	}
	else if (dir == "ea") {
		newy = this->ypos;
	}
	else if (dir == "we") {
		newy = this->ypos;
	}
	else if (dir ==  "ne") {
		newy = this->ypos - 1;
	}
	else if (dir ==  "nw") {
		newy = this->ypos - 1;
	}
	else if (dir ==  "se") {
		newy = this->ypos + 1;
	}
	else if (dir ==  "sw") {
		newy = this->ypos + 1;
	}
	return newy;
}


void PC::move(Floor *f, int x, int y){

			f->move(this, x, y);
	
}

character* PC::use(character* c){
	cout << "using original playableCharacter use method" << endl;
	return c->use(this);
}
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
/*	bool valid = false;
	string move;
	int newx = -1;
	int newy = -1;

	int width = f->getWidth();
	int height = f->getHeight();

	while(!valid){
		cin >> move;

		cout << "checking if valid move" << endl;
		//cout << "direction inputed correctly" << endl;
		if(move == "no"){
			newy = this->ypos - 1;
			newx = this->xpos;
		cout << "north direction inputed correctly" << endl;
		} else if (move == "so") {
			newy = this->ypos + 1;
			newx = this->xpos;
		cout << "south direction inputed correctly" << endl;
		} else if (move == "ea") {
				newx = this->xpos + 1;
				newy = this->ypos;
		cout << "east direction inputed correctly" << endl;
		} else if (move == "we"){
				newx = this->xpos - 1;
				newy = this->ypos;
		cout << "west direction inputed correctly" << endl;
		} else if (move ==  "ne"){
				newx = this->xpos + 1;
				newy = this->ypos - 1;
		cout << "northeast direction inputed correctly" << endl;
		} else if (move ==  "nw"){
				newx = this->xpos - 1;
				newy = this->ypos - 1;
		cout << "northwest direction inputed correctly" << endl;
		} else if (move ==  "se") {
				newx = this->xpos + 1;
				newy = this->ypos + 1;
		cout << "southeast direction inputed correctly" << endl;
		} else if (move ==  "sw") {
				newx = this->xpos - 1;
				newy = this->ypos + 1;
		cout << "southwest direction inputed correctly" << endl;
		} else {

			cout << "failed" << endl;
		}
*/
	//	if (f->PCWalkable(newx, newy)) {
		//cout << "in PC move" << endl;
			f->move(this, x, y);
	//		valid = true;
			// might want to take out this part
	//		this->xpos = newx;
	//		this->ypos = newy;
	//	} else {
	//		newx = -1;
	//		newy = -1;
	//	}
///
	//}
}

character* PC::use(character* c){
	cout << "using original playableCharacter use method" << endl;
	return c->use(this);
}
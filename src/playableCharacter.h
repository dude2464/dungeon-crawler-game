#ifndef __PLAYABLECHARACTER_H__
#define __PLAYABLECHARACTER_H__

#include <iostream>
#include <string>

#include "character.h"
#include "Floor.h"

class PC : public character {
public:
	PC(int HP, int atk, int def);
	void move(Floor *f, int x, int y);

	character* use(character* c);

	int dirOnX(std::string dir);		//returns new x position after a direction is applyed to original xpos
	int dirOnY(std::string dir);		//returns new y position after a direction is applyed to original yposn
};


#endif
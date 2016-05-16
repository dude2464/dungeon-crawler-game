#ifndef __ENEMY_H__
#define __ENEMY_H__


#include "character.h"

class enemy : public character {
public:
	enemy(char symbol, int HP, int atk, int def, int gold);
	void move(Floor *f, int x, int y);
	virtual bool isAggro(Floor *);
}; 


#endif
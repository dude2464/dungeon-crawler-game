#ifndef __WALKABLECELL_H__
#define __WALKABLECELL_H__

#include "Cell.h"
#include "character.h"

//class character;

class WalkableCell: public Cell {
protected:
	character *above;
	
	bool enemyWalkable;
public:
	bool walkable();
	//bool enemyCanWalk();
	char getSymbol();
	bool isOccupied();
	void addAbove(character* a);
	character* getAbove();
	//~WalkableCell();
};

#endif
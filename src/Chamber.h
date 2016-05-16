#ifndef __CHAMBER_H__
#define __CHAMBER_H__

//#include "Floor.h"
#include "Cell.h"
//#include "character.h"

class character;

class Chamber {

	Cell **cells;
	int numCells;
	Cell ***grid;

public:
	Chamber(Cell** c, int num, Cell*** grid);
	void spawnEnemy(character* ch);
	void spawnItem(character* ch);
	void spawnPC(character* ch);
	void spawnStairs(character* ch);

	
};

#endif
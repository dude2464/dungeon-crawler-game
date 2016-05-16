#ifndef __CELL_H__
#define __CELL_H__

//#include "character.h"
//#include "Floor.h"

class character;

class Cell {
protected:
	char symbol;
	int xpos;
	int ypos;
	bool filled;
public:
	Cell();
	virtual bool walkable();
	virtual char getSymbol();
	virtual bool isOccupied();
	virtual void addAbove(character* a);
	virtual bool enemyCanWalk();
	//virtual ~Cell();
	int getXpos();
	int getYpos();
	bool isFilled();
	void fill();
	virtual character* getAbove();

};

#endif
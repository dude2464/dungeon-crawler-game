#include "Chamber.h"
//#include "Passage.h"
//#include "dwarf.h"
//#include "Floor.h"
#include "stairs.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Chamber::Chamber(Cell **c, int num, Cell*** grid){
	this->cells = c;
	this->numCells = num;
	this->grid = grid;
}

void Chamber::spawnEnemy(character* ch){
	int index;
	srand(time(0));
	bool spawned = false;

	while(!spawned){
		index = rand()%numCells;
		
		if(!cells[index]->isOccupied()){
			cells[index]->addAbove(ch);
			spawned = true;
		}
		//TODO: make sure that you only spawn enemies where 
		// there is nothing else already there.
	}
}


void Chamber::spawnItem(character* ch){
	int index;
	srand(time(0));
	bool spawned = false;

	while(!spawned){
		index = rand()%numCells;
		
		if(!cells[index]->isOccupied()){
		// cell is unOccupied, adding item 
			cells[index]->addAbove(ch);
			spawned = true;
		}
	}
}


void Chamber::spawnPC(character* ch){
	int index;
	srand(time(0));
	bool spawned = false;	

	while(!spawned){
		index = rand()%numCells;
		if(!cells[index]->isOccupied()){
			cells[index]->addAbove(ch);
			spawned = true;
		}

	}

}

void Chamber::spawnStairs(character* ch){
	int index;
	srand(time(0));
	bool spawned = false;	

	int x;
	int y;

	while(!spawned){
		index = rand()%numCells;
		x = cells[index]->getXpos();
		y = cells[index]->getYpos();
		if(!cells[index]->isOccupied() && grid[x+1][y]->walkable()){


			cells[index]->addAbove(ch);
		// added stairs
			spawned = true;
		}
			
	}
}
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
//		while(index == oldIndex){
//			index = rand()%numCells;
//		}
		
		//delete cells[index];
		//cells[index] = new Passage();
	
		
		//	delete cells[index];
		//	cells[index] = new Passage();

		//	std::cout << "adding dwarf" << std::endl;
			

		//	std::cout << cells[index]->getSymbol() << std::endl;
		

	}
}


void Chamber::spawnItem(character* ch){
	int index;
	srand(time(0));
	bool spawned = false;

	while(!spawned){
		index = rand()%numCells;
		
		if(!cells[index]->isOccupied()){
		//	std::cout << "cell is unOccupied, adding item" << std::endl;
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
			//std::cout << "adding dwarf" << std::endl;
			cells[index]->addAbove(ch);
			spawned = true;
		}
			//delete cells[index];
			//cells[index] = new Passage();

			

			//std::cout << cells[index]->getSymbol() << std::endl;
		

	}

	//ch->setXpos(cells[index]->getXpos());
	//ch->setYpos(cells[index]->getYpos());

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
		//Cell** grid = f->getCells();
		if(!cells[index]->isOccupied() && grid[x+1][y]->walkable()){
	//		std::cout << "adding dwarf" << std::endl;

			//DELETE OLD CELL
		//	std::cout << "spawning cell" << std::endl;
			cells[index]->addAbove(ch);
	//		std::cout << "added pc" << std::endl;
			spawned = true;
		}
			//delete cells[index];
			//cells[index] = new Passage();
	}
}
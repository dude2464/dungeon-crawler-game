#ifndef __GAME_H__
#define __GAME_H__
#include <string>
#include "character.h"
#include "Floor.h"
#include "Cell.h"

class Game {

	int numEnemies;
	int numDrag;
	std::vector<character*> dragons;
	character **enemies;
	character *pc;
	Floor *f;
	Cell ***cells;
	int currentFloor;

public:
	Game(Floor *f, character *pc, int numEnemies);
	
	std::string playGame1(std::string file);
	std::string playGame2(std::string file);
	void moveEnemies();
	bool movePC(std::string move);
	std::string startGame(std::string file);
};

#endif
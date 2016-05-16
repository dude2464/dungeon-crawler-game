#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <string>
#include <vector>
// include chamber and cell.h files or just forward declare?
#include "Cell.h"
#include "Chamber.h"
//#include "character.h"
#include "linkedList.h"
//#include "character.h"

#include <string>

//class chamber;
class character;
class Gold;

 class Floor {

 	Cell ***cells;
 	int height;
 	int width;
    Chamber **chambers;
    linkedList **llist;
    int numChambers;
 	void makeChambers();

 public:
 	Floor(int width, int height, int numChambers);
	void constructFloor(std::string source);
 	//functions used for testing:
 	void printFloor();

 	Chamber* getChamber(int index);

 	character** spawnEnemy(int numEnemies);
 	void spawnPC(character* ch);
 	std::vector<character*> spawnItem(int numPotions, int numGold); // returns number of dragon hordes
 	character* spawnDragon(Gold* dh);

 	int getWidth();
 	int getHeight();
 	void move(character* c, int newx, int newy);
 	std::string PCWalkable(int newx, int newy);
 	bool enemyWalkable(int newx, int newy);

 	
  	Cell*** getCells();
  	
 	std::string whatIsHere(int xpos, int ypos, std::string dir);
 	bool PCInRange(int x, int y);


 	void floodFill(int x, int y, int chamberNum);

 	std::vector<character*> constructFloorSpecial(std::string source, character* pc);
 	//void makeChambersSpecial();

 };


 #endif
#include "Floor.h"
#include <iostream>
#include "Cell.h"
#include "FloorTile.h"
#include "Doorway.h"
#include "Passage.h"
#include "Wall.h"
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "character.h"
#include "linkedList.h"

#include "dragon.h"
#include "goblin.h"
#include "merchant.h"
#include "phoenix.h"
#include "troll.h"
#include "vampire.h"
#include "warewolf.h"
#include "ph.h"
#include "rh.h"
#include "ba.h"
#include "bd.h"
#include "wa.h"
#include "wd.h"
#include "normalGold.h"
#include "smallHoard.h"
#include "dragonHorde.h"
#include "stairs.h"

using namespace std;


Floor::Floor(int width, int height, int numChambers){
	this->width = width;
	this->height = height;
	this->cells = new Cell** [width];
	this->numChambers = numChambers;
	this->chambers = new Chamber* [numChambers];
	this->llist = new linkedList* [numChambers];
	//FloorTile *temp;
//	Cell *c;
	for(int i = 0; i<width; i++){
		cells[i] = new Cell* [height];
		for(int j = 0; j<height; j++){
			//temp = new FloorTile();
	//		c=temp;
			cells[i][j] = NULL; 
		}
	}
}

void Floor::printFloor(){
	for(int j =0; j<height; j++){
		for(int i = 0; i<width; i++){
			if(cells[i][j] == NULL){
				cout << " ";
			} else {
				cout << cells[i][j]->getSymbol();
			}
		}
		cout << endl;
	}
}

void Floor::constructFloor(string source){
	ifstream f(source.c_str());
	string line;
	string c;
	for(int j = 0; j<height; j++){
		getline(f, line);
		//cout << "read line: " << line << endl;
		for (int i = 0; i <width; i++)	{
			c = line.substr(i, 1);

		//	cout << "read character: " << c << endl;
			if(c == "#"){
				cells[i][j] = new Passage(i, j);
			} else if(c == "."){
				cells[i][j] = new FloorTile(i, j);
			} else if(c == "+"){
				cells[i][j] = new Doorway(i, j);
			} else if(c == "-"){
				cells[i][j] = new Wall('-', i, j);
			} else if(c == "|"){
				cells[i][j] = new Wall('|', i, j);
			} 
		}
	}
	cout << "making chambers" << endl;
	this->makeChambers();	
}

void Floor::makeChambers(){
	//cout << "making chambers" << endl;
	bool firstFound;
	int x;
	int y;

	for(int i = 0; i<numChambers; i++){
		firstFound = false;
	//	cout << "making chamber " << i << endl;
		x = 1;
		y = 1;
		while(!firstFound){
			if(cells[x][y] != NULL && cells[x][y]->getSymbol() == '.' && !cells[x][y]->isFilled()){
	//			cout << "first cell found at " << x << " " << y << endl;
				firstFound = true;
			} else {
				x++;
				//y++;
				if(x == this->width){
					x = 1;
					y++;
				}
				if(y == this->height){
					cout << "ERROR: more chambers than expected" << endl;
				}
			}
		}
	//	cout << "making first linkedList" << endl;
		llist[i] = new linkedList(cells[x][y]);
	//	cout << "starting flood fill" << endl;
		floodFill(x, y, i); 
	//	cout << "finished flood" << endl;
	}

	//cout << "linkedList sizes" << endl;
	
	for(int i = 0; i<numChambers; i++){
		linkedList* current = llist[i];
		//cout << llist[i]->getSize() <<endl;
		int lsize = llist[i]->getSize();
	//	cout << "making cell array" << endl;
		Cell** c = new Cell* [lsize];
		for(int j = 0; j<lsize; j++){

			c[j] = current->getCell();
			current = current->getNext();
		}
	//	cout << "filled cell array" << endl;
		chambers[i] = new Chamber(c, lsize, this->cells);
	}
}

Chamber* Floor::getChamber(int index){
	return this->chambers[index];
}

vector<character*> Floor::constructFloorSpecial(string source, character* pc){
	cout << "get this far" << endl;
	ifstream f(source.c_str());
	string line;
	string c;
	vector<character*> v;
	int es = 0 ;
	vector<character*> d;
	int numDrag;
	//character* pc;

	for(int j = 0; j<height; j++){
		getline(f, line);
		//cout << "read line: " << line << endl;
		for (int i = 0; i <width; i++)	{
			c = line.substr(i, 1);

		//	cout << "read character: " << c << endl;
			if(c == "#"){
				cells[i][j] = new Passage(i, j);
			} else if(c == "."){
				cells[i][j] = new FloorTile(i, j);
			} else if(c == "+"){
				cells[i][j] = new Doorway(i, j);
			} else if(c == "-"){
				cells[i][j] = new Wall('-', i, j);
			} else if(c == "|"){
				cells[i][j] = new Wall('|', i, j);
			} else if(c == "W"){
				cells[i][j] = new FloorTile(i, j);
				v.push_back(new warewolf());
				cells[i][j]->addAbove(v[es]);
				es++;
			} else if(c == "V"){
				cells[i][j] = new FloorTile(i, j);
				v.push_back(new vampire());
				cells[i][j]->addAbove(v[es]);
				es++;
			} else if(c == "N"){
				cells[i][j] = new FloorTile(i, j);
				v.push_back(new goblin());
				cells[i][j]->addAbove(v[es]);
				es++;
			} else if(c == "T"){
				cells[i][j] = new FloorTile(i, j);
				v.push_back(new troll());
				cells[i][j]->addAbove(v[es]);
				es++;
			} else if(c == "X"){
				cells[i][j] = new FloorTile(i, j);
				v.push_back(new phoenix());
				cells[i][j]->addAbove(v[es]);
				es++;
			} else if(c == "M"){
				cells[i][j] = new FloorTile(i, j);
				v.push_back(new merchant());
				cells[i][j]->addAbove(v[es]);
				es++;
			} else if(c == "D"){
				cells[i][j] = new FloorTile(i, j);
			} else if(c == "0"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new rh());
			} else if(c == "1"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new ba());
			} else if(c == "2"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new bd());
			} else if(c == "3"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new ph());
			} else if(c == "4"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new wa());
			} else if(c == "5"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new wd());
			} else if(c == "6"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new normalGold());
			} else if(c == "7"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new smallHoard());
			} else if(c == "8"){
				cells[i][j] = new FloorTile(i, j);
			//	cells[i][j]->addAbove(new rh());
			} else if(c == "9"){
				cells[i][j] = new FloorTile(i, j);
			//	cells[i][j]->addAbove(new ba());
			} else if(c == "\\"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(new stairs());
			} else if(c == "@"){
				cells[i][j] = new FloorTile(i, j);
				cells[i][j]->addAbove(pc);
			} 

		}
	}

//	character **enemies = new character* [es];
//	for(int k = 0; k<es; k++){
//		enemies[k] = v[k];
//	}
	this->makeChambers();
	return v;

	
}


character** Floor::spawnEnemy(int numEnemies){
	//int numEnemies =20;
	character **enemies = new character* [numEnemies]; 
	int c;
	int monster;
	srand(time(0));
	for(int i = 0; i<numEnemies; i++){
		monster = rand()%18;
		c = rand()%5;
		if(monster < 4){
			// spwan werewolf;
			enemies[i] = new warewolf();
			//chambers[c]->spawnEnemy(new warewolf());
		} else if(monster < 7){
			// spwan vampire;
			enemies[i] = new vampire();
			//chambers[c]->spawnEnemy(new vampire());
		} else if(monster < 12){
			// spwan goblin;
			enemies[i] = new goblin();
			//chambers[c]->spawnEnemy(new goblin());
		} else if(monster < 14){
			// spwan troll;
			enemies[i] = new troll();
			//chambers[c]->spawnEnemy(new troll());
		} else if(monster < 16){
			// spwan phoenix;
			enemies[i] = new phoenix();
			//chambers[c]->spawnEnemy(new phoenix());
		} else if(monster < 18) {
			enemies[i] = new merchant();
			//chambers[c]->spawnEnemy(new merchant());
		}
		//cout << "spawning enemies" << endl; 
		chambers[c]->spawnEnemy(enemies[i]);
	}
	return enemies;
}

void Floor::spawnPC(character* ch){
	srand(time(0));
	int c = rand()%5;
	chambers[c]->spawnPC(ch);
	int s = c;
	while(s == c){
		s = rand()%5;
		if(s != c) {
			chambers[s]->spawnStairs(new stairs());
		}
	}
}


character* Floor::spawnDragon(Gold* dh) {
	int dgxpos = dh->getXpos();
	int dgypos = dh->getYpos();
	character* d = new dragon(dh);

	while (true) {
		srand(time(0));
		int dxpos = dgxpos + rand()%3 - 1;
		int dypos = dgypos + rand()%3 - 1;

		if (cells[dxpos][dypos]->enemyCanWalk() && !cells[dxpos][dypos]->isOccupied()) {
			cells[dxpos][dypos]->addAbove(d);
			break;
		} else continue;
	}
	return d;
}


vector<character*> Floor::spawnItem(int numPotions, int numGold){
	//character **enemies = new character* [numEnemies]; 
	int c;
	int item;
	srand(time(0));
	for(int i = 0; i<numPotions; i++){
		item = rand()%6;
		c = rand()%5;
		if(item < 1){
	//		cout << "spawning potion" << endl;
			chambers[c]->spawnItem(new ba());
		} else if(item < 2){
	//		cout << "spawning potion" << endl;
			chambers[c]->spawnItem(new bd());
		} else if(item < 3){
	//		cout << "spawning potion" << endl;
			chambers[c]->spawnItem(new wa());
		} else if(item < 4){
	//		cout << "spawning potion" << endl;
			chambers[c]->spawnItem(new wd());
		} else if(item < 5){
	//		cout << "spawning potion" << endl;
			chambers[c]->spawnItem(new ph());
		} else if(item < 6){
	//		cout << "spawning potion" << endl;
			chambers[c]->spawnItem(new rh());
		} 
	//	cout << "spawned potion" << endl; 
	}

vector<character*> dragons;
	for(int i = 0; i<numGold; i++){

		item = rand()%8;
		c = rand()%5;
		if(item < 5){
			//cout << "spawning gold" << endl;
			chambers[c]->spawnItem(new normalGold());
		} else if(item < 7){
			//cout << "spawning gold" << endl;
			chambers[c]->spawnItem(new smallHoard());
		} else if(item < 8) {
			//cout << "spawned dragon gold" << endl;
			Gold* dh = new dragonHorde();
			chambers[c]->spawnItem(dh);
			int dxpos = dh->getXpos();
			int dypos = dh->getYpos();
			character* d = this->spawnDragon(dh);

			dragons.push_back(d);
		}
	}
	return dragons;
}

int Floor::getWidth(){
	return this->width;
}

int Floor::getHeight(){
	return this->height;
}

void Floor::move(character* c, int newx, int newy){
	int oldx = c->getXpos();
	int oldy = c->getYpos();
	//cout << "got X and Y pos: " << oldx << " " << oldy << endl;
	//cout << "New X and Y pos: " << newx << " " << newy << endl;
	cells[newx][newy]->addAbove(c);
	//cout << "copied pc to new cell" <<endl;
	cells[oldx][oldy]->addAbove(NULL);
	//cout << "removed pc from old cell" << endl;
}

string Floor::PCWalkable(int newx, int newy){
	//cout << "newx is: " << newx << endl;
	//cout << "newy is: " << newy << endl;
	
	if(newx >= 0 && newx < this->width && 
		newy >= 0 && newy < this->height ) {
	//	cout << "target cell is within board" << endl;
		if(cells[newx][newy] != NULL && cells[newx][newy]->walkable()){
			if(!cells[newx][newy]->isOccupied()) {
	//		cout << "valid target cell" << endl;
			return "free";
			} else if (this->cells[newx][newy]->getAbove()->getSubclass() == "gold"){

				return "gold";
			} else if (this->cells[newx][newy]->getAbove()->getSubclass() == "stairs"){

				return "stairs";
			}
		}
	}

	cout << "failed" << endl;
	return "occupied";
}

bool Floor::enemyWalkable(int newx, int newy){
	if(newx >= 0 && newx < this->width && 
		newy >= 0 && newy < this->height ) {
		//cout << "target cell is within board" << endl;
		if(cells[newx][newy] != NULL &&
			cells[newx][newy]->walkable() && 
			cells[newx][newy]->enemyCanWalk() &&
			!cells[newx][newy]->isOccupied()) {
		//	cout << "valid target cell" << endl;
			return true;
		}
		return false;
	}
}


string Floor::whatIsHere(int xpos, int ypos, string dir) {
	int newy;
	int newx;
	if(dir == "no") {
		newy = ypos - 1;
		newx = xpos;
	}
	else if (dir == "so") {
		newy = ypos + 1;
		newx = xpos;
	}
	else if (dir == "ea") {
		newx = xpos + 1;
		newy = ypos;
	}
	else if (dir == "we") {
		newx = xpos - 1;
		newy = ypos;
	}
	else if (dir ==  "ne") {
		newx = xpos + 1;
		newy = ypos - 1;
	}
	else if (dir ==  "nw") {
		newx = xpos - 1;
		newy = ypos - 1;
	}
	else if (dir ==  "se") {
		newx = xpos + 1;
		newy = ypos + 1;
	}
	else if (dir ==  "sw") {
		newx = xpos - 1;
		newy = ypos + 1;
	}
	else if (dir == "none"){
		newx = xpos;
		newy = ypos;
	}

	//cout << "in whatIsHere method" << endl;
	if (this->cells[newx][newy]->isOccupied()) {
		//cout << "isOccupied method works" << endl;
		return this->cells[newx][newy]->getAbove()->getSubclass();
	}
	else {
		return "nothing";
	}
}



bool Floor::PCInRange(int xpos, int ypos) {
	//cout << "in Floor->PCInRange method" << endl;
	int newx;
	int newy;
	for (int y = -1; y < 2; y++) {
		for (int x = -1; x < 2; x++) {
			newx = xpos + x;
			newy = ypos + y;
			if(cells[newx][newy] != NULL && cells[newx][newy]->walkable() &&
			cells[newx][newy]->isOccupied() && this->whatIsHere(newx, newy, "none") == "PC") {
				return true;
			}
		}
	}
	return false;
} 



Cell*** Floor::getCells(){
	return this->cells;
}

void Floor::floodFill(int x, int y, int chamberNum){
	if(cells[x][y] != NULL && cells[x][y]->getSymbol() == '.' && !cells[x][y]->isFilled()){
	//	cout << "pushing cell to llist" << endl;
		llist[chamberNum]->pushCell(cells[x][y]);
	//	cout << "pushed cell" << endl;
	//	cout << "calling fill()" << endl;
		cells[x][y]->fill();
	//	cout << "filled cell" << endl;

	//	cout << "calling floodFill with: " << x-1 << " " << y << endl;
		floodFill(x-1, y, chamberNum);
	//	cout << "calling floodFill with: " << x << " " << y-1 << endl;
		floodFill(x, y-1, chamberNum);
	//	cout << "calling floodFill with: " << x+1 << " " << y << endl;
		floodFill(x+1, y, chamberNum);
	//	cout << "calling floodFill with: " << x << " " << y+1 << endl;
		floodFill(x, y+1, chamberNum);

	} else {

	}
}
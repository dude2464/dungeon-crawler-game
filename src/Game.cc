#include "Game.h"
#include "Floor.h"
#include "Chamber.h"
#include "Cell.h"
//#include "NonWalkable.h"
//#include "Wall.h"
//#include "Walkbale.h"
#include "character.h"
#include "playableCharacter.h"
#include "Passage.h"
#include "Doorway.h"
#include "FloorTile.h"
#include "dwarf.h"
#include "elf.h"
#include "goblin.h"
#include "human.h"
#include "merchant.h"
#include "orc.h"
#include "phoenix.h"
#include "troll.h"
#include "vampire.h"
#include "warewolf.h"
#include "item.h"
#include "potion.h"
#include "permaPotion.h"
#include "rh.h"
#include "ph.h"


#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

Game::Game(Floor *f, character *pc,	int numEnemies){

	this->f = f;
	this->enemies = NULL;
	this->cells = NULL;
	this->numDrag = 0;
	this->numEnemies = numEnemies;
	this->pc = pc;
	this->currentFloor = 1;

}

bool isDir(string dir) {
	return dir == "no" || dir == "so" ||
			dir == "ea" || dir == "we" ||
			dir == "ne" || dir == "nw" ||
			dir == "se" || dir == "sw";
}

string Game::startGame(string file){
	//currentFloor = 1;
	bool playing = true;
	
	string result;



	while(playing){
		if(file == "defaultFloor.txt"){
			result = playGame2(file);
		} else {
			result = playGame1(file);
		}
		if(result == "pc dead" || result == "quit" || result == "restart"){
			return result;
		} if (result == "next level"){
			currentFloor++;
			if(currentFloor == 3){
				playing = false;
			}
		}
		pc = pc->removeTemps();
	}

	cout << "Congrats, you Won!" << endl;

	return result;

}

string Game::playGame1(string file) {
	//f->constructFloor("defaultFloor.txt");
//	enemies = f->constructFloorSpecial("textFile2.txt", pc);
//	int n = enemies.size();
//	this->numEnemies = enemies.size();
	cout << "get ehre" << endl;
	std::vector<character*> v = f->constructFloorSpecial(file, pc);
	cout << "past here" << endl;
	this->numEnemies = v.size();
	f->printFloor();

	enemies = new character* [numEnemies];
	for(int k = 0; k<numEnemies; k++){
		enemies[k] = v[k];
	}

//	f->spawnPC(pc);

//	dragons = f->spawnItem(10, 10);  //spawns items and puts dragons into dragon array
//	this->numDrag = dragons.size();
//	enemies = f->spawnEnemy(this->numEnemies-numDrag); // take in a number
	
	cells = f->getCells();

	f->printFloor();

	for(int i = 0; i<numEnemies; i++){
		//cout << enemies[i]->getSymbol() << endl;
	}
	cout << "starting" << endl;

	cout << "pc's coordinates: " << pc->getXpos()
	  << " " << pc->getYpos() << endl;

	string cmd;
	string dir;
	bool climbedStairs = false;
	//bool invInput = false;

	cout << "starting PC HP: " << pc->getHP() << endl;
	cout << "choose a command" << endl;

	//bool playing = true;

	while(true) {

		// entering first command until valid
		do {
			cin >> cmd;
			if (!isDir(cmd) && cmd != "q" && cmd != "a" && cmd != "u" && cmd != "r") {
					cerr << "invalid input" << endl;
			}
		} while (!isDir(cmd) && cmd != "q" && cmd != "a" && cmd != "u" && cmd != "r");

		if (cmd == "q") {
			cout << "quit command entered" << endl;
			return "quit";
		}
		else if (cmd == "a") {
			// reruns loop if invalid direction is entered
			cin >> dir;
			if (!isDir(dir)) {
				cerr << "invalid input" << endl;
				continue;
			}

			int newx = pc->dirOnX(dir);
			int newy = pc->dirOnY(dir);
			if (f->whatIsHere(pc->getXpos(), pc->getYpos(), dir) == "enemy") {
				cout << "pc attacked enemy" << endl;
				character* e = cells[newx][newy]->getAbove();
				pc->strike(e);
				if (e->getSymbol() == 'M' && !e->isHostile()) {
					e->becomeHostile();
					e->notifyMerchants(enemies, numEnemies);
					cout << "Merchants now hostile" << endl;
				}

				cout << e->getSymbol() << " HP: " << e->getHP() << endl;
				if (e->isDead()) {
					cells[newx][newy]->addAbove(NULL);
				}
			}
			else cout << "not a fucking enemy" << endl;
			//if (invInput) continue;	
		} 
		else if (cmd == "u") {
			// reruns loop if invalid direction is entered
			cin >> dir;
			if (!isDir(dir)) {
				cerr << "invalid input" << endl;
				continue;
			}
			int newx = pc->dirOnX(dir);
			int newy = pc->dirOnY(dir);
			
			if (f->whatIsHere(pc->getXpos(), pc->getYpos(), dir) == "potion") {			
				cout << "pc old stats: " << endl;
				cout << "pc HP: " << pc->getHP() << endl;
				cout << "pc atk: " << pc->getAtk() << endl;
				cout << "pc def: " << pc->getDef() << endl;
				cout << "pc using potion" << endl;
				pc = pc->use(cells[newx][newy]->getAbove());
				cout << "pc new stats: " << endl;
				cout << "pc HP: " << pc->getHP() << endl;
				cout << "pc atk: " << pc->getAtk() << endl;
				cout << "pc def: " << pc->getDef() << endl;
				cells[newx][newy]->addAbove(NULL);
			}
		}
		else {
			climbedStairs = movePC(cmd);
			if(climbedStairs){
				return "next level";
			}
			cout << "pc moved" << endl;	
		}
		// aggros are automatically set
		if(false){
			numDrag = dragons.size();
		}
		//cout << numDrag << endl;


		for(int i = 0; i < numEnemies-numDrag; i++) {
			//cout << i << endl;
			//cout << "checking enemies' aggros" << endl;
			if (!enemies[i]->isDead() && enemies[i]->isAggro(f)) {
				cout << enemies[i]->getSymbol() << " attacked" << endl;
				srand(time(0));
				int atkChance = rand()%2;
				if (atkChance == 0) {
					enemies[i]->strike(pc);
					cout << enemies[i]->getSymbol() << " hit!" << endl;
				}
				else cout << enemies[i]->getSymbol() <<" missed!" << endl;
				cout << "PC HP: " << pc->getHP() << endl;
				if (pc->isDead()) {
					f->printFloor();
					cout << "player died: game over" << endl;
					return "pc dead";
				}
			}	
		}
		for(int i = 0; i < numDrag; i++) {
			//cout << i << endl;
		//	cout << dragons[i]->getSymbol() << endl;
			//cout << dragons[i]->getAtk() << endl;
			if (!dragons[i]->isDead() && dragons[i]->isAggro(f)) {

				cout << dragons[i]->getSymbol() << " attacked" << endl;
				dragons[i]->strike(pc);
				cout << "PC HP: " << pc->getHP() << endl;
				if (pc->isDead()) {
					f->printFloor();
					cout << "player died: game over" << endl;
					return "pc dead";
				}
			}
		}
		moveEnemies();
		
		
	//	cout << "pc's coordinates: " << pc->getXpos()
	//	  << pc->getYpos() << endl;

		f->printFloor();	

		cout << "Gold: " << pc->getGold();
		cout << "                                                 Floor: " << currentFloor << endl;
		cout << "HP: " << pc->getHP() << endl;
		cout << "Atk: " << pc->getAtk() << endl;	
		cout << "Def: " << pc->getDef() << endl;

	}

	return "done";
}

string Game::playGame2(string file) {
	f->constructFloor(file);

	f->printFloor();

	f->spawnPC(pc);

	dragons = f->spawnItem(10, 10);  //spawns items and puts dragons into dragon array
	this->numDrag = dragons.size();
	enemies = f->spawnEnemy(this->numEnemies-numDrag); // take in a number
	
	cells = f->getCells();

	f->printFloor();

	cout << "pc's coordinates: " << pc->getXpos()
	  << " " << pc->getYpos() << endl;

	string cmd;
	string dir;
	bool climbedStairs = false;
	//bool invInput = false;

	cout << "starting PC HP: " << pc->getHP() << endl;
	cout << "choose a command" << endl;

	//bool playing = true;

	while(true) {

		// entering first command until valid
		do {
			cin >> cmd;
			if (cin.eof()) return "quit";
			if (!isDir(cmd) && cmd != "q" && cmd != "a" && cmd != "u" && cmd != "r") {
					cerr << "invalid input" << endl;
			}
		} while (!isDir(cmd) && cmd != "q" && cmd != "a" && cmd != "u" && cmd != "r");

		if (cmd == "q") {
			cout << "Quit command entered" << endl;
			return "quit";
		}
		else if (cmd == "r") {
			cout << "Restart command entered" << endl;
			return "restart";
		}
		else if (cmd == "a") {
			// reruns loop if invalid direction is entered
			cin >> dir;
			if (cin.eof()) return "quit";
			if (!isDir(dir)) {
				cerr << "invalid input" << endl;
				continue;
			}

			int newx = pc->dirOnX(dir);
			int newy = pc->dirOnY(dir);
			if (f->whatIsHere(pc->getXpos(), pc->getYpos(), dir) == "enemy") {
				cout << "pc attacked enemy" << endl;
				character* e = cells[newx][newy]->getAbove();
				pc->strike(e);
				if (e->getSymbol() == 'M' && !e->isHostile()) {
					e->becomeHostile();
					e->notifyMerchants(enemies, numEnemies);
					cout << "Merchants now hostile" << endl;
				}

				cout << e->getSymbol() << " HP: " << e->getHP() << endl;
				if (e->isDead()) {
					cells[newx][newy]->addAbove(NULL);
				}
			}
			//if (invInput) continue;	
		} 
		else if (cmd == "u") {
			// reruns loop if invalid direction is entered
			cin >> dir;
			if (cin.eof()) return "quit";
			if (!isDir(dir)) {
				cerr << "invalid input" << endl;
				continue;
			}
			int newx = pc->dirOnX(dir);
			int newy = pc->dirOnY(dir);
			
			if (f->whatIsHere(pc->getXpos(), pc->getYpos(), dir) == "potion") {			
				cout << "PC old stats: " << endl;
				cout << "PC HP: " << pc->getHP() << endl;
				cout << "PC atk: " << pc->getAtk() << endl;
				cout << "PC def: " << pc->getDef() << endl;
				cout << "PC using potion" << endl;
				pc = pc->use(cells[newx][newy]->getAbove());
				cout << "PC new stats: " << endl;
				cout << "PC HP: " << pc->getHP() << endl;
				cout << "PC atk: " << pc->getAtk() << endl;
				cout << "PC def: " << pc->getDef() << endl;
				cells[newx][newy]->addAbove(NULL);
				if (pc->isDead()) {
					f->printFloor();
					cout << "player died: game over" << endl;
					return "pc dead";
				}
			}
		}
		else {
			climbedStairs = movePC(cmd);
			if(climbedStairs){
				return "next level";
			}
			//cout << "pc moved" << endl;	
		}
		// aggros are automatically set
		numDrag = dragons.size();
		//cout << numDrag << endl;
		for(int i = 0; i < numEnemies-numDrag; i++) {
			//cout << i << endl;
			//cout << "checking enemies' aggros" << endl;
			if (!enemies[i]->isDead() && enemies[i]->isAggro(f)) {
				cout << enemies[i]->getSymbol() << " attacked" << endl;
				srand(time(0));
				int atkChance = rand()%2;
				if (atkChance == 0) {
					enemies[i]->strike(pc);
					cout << enemies[i]->getSymbol() << " hit!" << endl;
				}
				else cout << enemies[i]->getSymbol() <<" missed!" << endl;
				cout << "PC HP: " << pc->getHP() << endl;
				if (pc->isDead()) {
					f->printFloor();
					cout << "player died: game over" << endl;
					return "pc dead";
				}
			}	
		}
		for(int i = 0; i < numDrag; i++) {
			//cout << i << endl;
			//cout << dragons[i]->getSymbol() << endl;
			//cout << dragons[i]->getAtk() << endl;
			if (!dragons[i]->isDead() && dragons[i]->isAggro(f)) {
				srand(time(0));
				int atkChance = rand()%2;
				if (atkChance == 0) {
					dragons[i]->strike(pc);
					cout << dragons[i]->getSymbol() << " hit!" << endl;
				}
				else cout << dragons[i]->getSymbol() << " missed!" << endl;
				cout << dragons[i]->getSymbol() << " attacked" << endl;
				cout << "PC HP: " << pc->getHP() << endl;
				if (pc->isDead()) {
					f->printFloor();
					cout << "player died: game over" << endl;
					return "pc dead";
				}
			}
			if (dragons[i]->isDead()) {
				cout << "dragon dead" << endl;
				dragons[i]->canPickUpGold();
			}
		}
		moveEnemies();
		
		
	//	cout << "pc's coordinates: " << pc->getXpos()
	//	  << pc->getYpos() << endl;

		f->printFloor();	

		cout << "Gold: " << pc->getGold();
		cout << "                                                 Floor: " << currentFloor << endl;
		cout << "HP: " << pc->getHP() << endl;
		cout << "Atk: " << pc->getAtk() << endl;	
		cout << "Def: " << pc->getDef() << endl;

	}

	return "done";
}

void Game::moveEnemies(){
	int index;

	int width = f->getWidth();
	int height = f->getHeight();

	int xcoords[9];
	int ycoords[9];
	int count;
	srand(time(0));
	for(int i = 0; i<numEnemies-numDrag; i++){
		if(!enemies[i]->isDead() && !enemies[i]->isAggro(f)){
			count = 0;	

			for(int y = -1; y<2; y++){
				for(int x = -1; x<2; x++){
				
					if(f->enemyWalkable(enemies[i]->getXpos()+x,
					   enemies[i]->getYpos()+y)){
						xcoords[count] = enemies[i]->getXpos()+x;
						ycoords[count] = enemies[i]->getYpos()+y;
						count++;
					}
				}
			}

			index = rand()%count;
			enemies[i]->move(f, xcoords[index], ycoords[index]);
		}
	}
}

bool Game::movePC(string move){
	cout << endl;
	//bool valid = false;
	//string move;
	int newx = -1;
	int newy = -1;

	int width = f->getWidth();
	int height = f->getHeight();

	//while(!valid){
		//cin >> move;

	//	cout << "checking if valid move" << endl;
		//cout << "direction inputed correctly" << endl;
		if(move == "no"){
			newy = pc->getYpos() - 1;
			newx = pc->getXpos();
	//	cout << "north direction inputed correctly" << endl;
		} else if (move == "so") {
			newy = pc->getYpos() + 1;
			newx = pc->getXpos();
	//	cout << "south direction inputed correctly" << endl;
		} else if (move == "ea") {
				newx = pc->getXpos() + 1;
				newy = pc->getYpos();
	//	cout << "east direction inputed correctly" << endl;
		} else if (move == "we"){
				newx = pc->getXpos() - 1;
				newy = pc->getYpos();
	//	cout << "west direction inputed correctly" << endl;
		} else if (move ==  "ne"){
				newx = pc->getXpos() + 1;
				newy = pc->getYpos() - 1;
	//	cout << "northeast direction inputed correctly" << endl;
		} else if (move ==  "nw"){
				newx = pc->getXpos() - 1;
				newy = pc->getYpos() - 1;
	//	cout << "northwest direction inputed correctly" << endl;
		} else if (move ==  "se") {
				newx = pc->getXpos() + 1;
				newy = pc->getYpos() + 1;
	//	cout << "southeast direction inputed correctly" << endl;
		} else if (move ==  "sw") {
				newx = pc->getXpos() - 1;
				newy = pc->getYpos() + 1;
	//	cout << "southwest direction inputed correctly" << endl;
		} else {

	//		cout << "failed" << endl;
		}

		if (f->PCWalkable(newx, newy) == "free") {
			//cout << "PCWalkable returned true" << endl;
			pc->move(f, newx, newy);
		}
		else if (f->PCWalkable(newx, newy) == "gold") {
			//cout << this->cells[newx][newy]->getAbove()->getGold() << endl;
			if (this->cells[newx][newy]->getAbove()->getGold() == 6) {
				//cout << "yas" << endl;
				if (this->cells[newx][newy]->getAbove()->getCanPickUp()) {
					//cout << "yasss" << endl;
					pc = pc->use(cells[newx][newy]->getAbove());
					pc->move(f, newx, newy);
				}
				else {
					cout << "Dragon not slain! Re-enter command." << endl;
				}
			}
			else {
				pc = pc->use(cells[newx][newy]->getAbove());
				pc->move(f, newx, newy);
			}
		}
		else if (f->PCWalkable(newx, newy) == "stairs" && move == "we"){
			return true;
		}
		return false;
}
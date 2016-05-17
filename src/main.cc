#include "Floor.h"
#include "Chamber.h"
#include "Cell.h"
#include "character.h"
#include "playableCharacter.h"
#include "Passage.h"
#include "Doorway.h"
#include "FloorTile.h"
#include "Floor.h"
#include "Chamber.h"
#include "Cell.h"
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
#include "Game.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	string file = "";
	if (argc == 2){
		file = argv[1];
	} else {
		file = "defaultFloor.txt";
	}
	
	string race;
	character* pc;
	while (true) {
		

		bool raceQuit = false;
		bool raceRestart = false;

		cout << "Choose a race" << endl;


		while (true) {
			cin >> race;
			if (cin.eof()) {
				raceQuit = true;
				break;
			}
			if (race == "e") {
				pc = new elf();
			}
			else if (race == "h") {
				pc = new human();
			}
			else if (race == "d") {
				pc = new dwarf();
			}
			else if (race == "o") {
				pc = new orc();
			}
			else if (race == "r") {
				raceRestart = true;
				break;
			}
			else if (race == "q") {
				raceQuit = true;
				break;
			}
			else {
				cout << "Invalid input" << endl;
				continue;
			}
			break;
		}

		if (raceRestart) {
			continue;
		}
		if (raceQuit) {
			break;
		}

		Floor *f = new Floor(79, 25, 5);

		Game *g = new Game(f, pc, 5);

		string result = g->startGame(file);
		if (result == "restart") {
			continue;
		}
		else if (result == "quit") {
			break;
		}
		else if (result == "done") {
			cout << "Victory!" << endl;
		}
	}
}

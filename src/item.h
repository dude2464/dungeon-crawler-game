#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include "character.h"

class item: public character {
	//string itemType;
	//string name;
public:
	item(std::string subclass, char symbol, int HP, int atk, int def, int gold);
	virtual character* use(character* c);

}; 

#endif
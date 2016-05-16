#include "item.h"
#include <string>

character* item::use(character* c){
	return NULL;
}

item::item(std::string subclass, char symbol, int HP, int atk, int def, int gold):
	character(subclass, symbol, HP, atk, def, gold){

}
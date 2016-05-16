#ifndef __GOLD_H__
#define __GOLD_H__

#include "item.h"
//#include "character.h"
class character;

class Gold: public item {
public:
	Gold(int val);
	character* use(character* c);
};

#endif

#ifndef __POTION_H__
#define __POTION_H__

#include "item.h"

class potion: public item {

	//bool temp;

public:
	potion(int HP, int atk, int def);
	virtual bool isTemp();

};

#endif
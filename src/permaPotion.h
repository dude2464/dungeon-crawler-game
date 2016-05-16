#ifndef __PERMAPOTION_H__
#define __PERMAPOTION_H__

#include "potion.h"

class permaPotion: public potion {

public:
	permaPotion(int HP);
	bool isTemp();	

};

#endif
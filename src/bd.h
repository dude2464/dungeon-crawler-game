#ifndef __BD_H__
#define __BD_H__

#include "tempPotion.h"

class bd: public tempPotion {

public:
	bd();
//	character* use(character* c);
	character* useReverse(character* c);

};

#endif
#ifndef __BA_H__
#define __BA_H__

#include "tempPotion.h"

class ba: public tempPotion {

public:
	ba();
//	character* use(character* c);
	character* useReverse(character* c);

};

#endif
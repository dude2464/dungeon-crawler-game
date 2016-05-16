#ifndef __WD_H__
#define __WD_H__

#include "tempPotion.h"

class wd: public tempPotion {

public:
	wd();
//	character* use(character* c);
	character* useReverse(character* c);


};

#endif
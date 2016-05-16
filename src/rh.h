#ifndef __RH_H__
#define __RH_H__

#include "permaPotion.h"

class rh: public permaPotion {

public:
	rh();
	character* use(character* c);
	character* useReverse(character* c);
};

#endif
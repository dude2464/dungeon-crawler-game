#ifndef __PH_H__
#define __PH_H__

#include "permaPotion.h"

class ph: public permaPotion {

public:
	ph();
	character* use(character* c);
	character* useReverse(character* c);
};

#endif
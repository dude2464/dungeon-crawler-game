#ifndef __WA_H__
#define __WA_H__

#include "tempPotion.h"

class wa: public tempPotion {

public:
	wa();
//	character* use(character* c);
	character* useReverse(character* c);

};

#endif

#ifndef __DRAGONHORDE_H__
#define __DRAGONHORDE_H__

#include "Gold.h"

class dragonHorde: public Gold {
	bool canPickUp;
public:
	dragonHorde();
	bool getCanPickUp();
	void nowCanPickUp();
};

#endif
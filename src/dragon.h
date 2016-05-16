#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"
#include "Gold.h"
class Floor;


class dragon : public enemy {
protected:
	Gold *pGold;
public:
	dragon(Gold *pGold);
	bool isAggro(Floor *f);

	void canPickUpGold();
};


#endif
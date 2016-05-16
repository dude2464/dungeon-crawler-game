#ifndef __MERCHANT_H__
#define __MERCHANT_H__


#include "enemy.h"

class merchant : public enemy {
protected:
	bool hostile;
public:
	merchant();

	bool isAggro(Floor *f);

	void becomeHostile();
	bool isHostile();

	// Notifies observers (all other merchants) to become hostile
	void notifyMerchants(character** e, int numEnemies); 

};


#endif
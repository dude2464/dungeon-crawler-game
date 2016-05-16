#ifndef __TEMPPOTION_H__
#define __TEMPPOTION_H__

#include "potion.h"
#include "character.h"

class tempPotion: public potion {
protected:
	character *ch;
public:
	bool isTemp();
	tempPotion(int atk, int def);
	int getDef();
	int getAtk();
	int getHP();
	int getGold();

	void setHP(int value);
	void setXpos(int x);
	void setYpos(int y);
	int getXpos();
	int getYpos();
	std::string getSubclass();

	void addHP(int val);
	void addGold(int val);
	char getSymbol();
	void move(Floor *f, int x, int y);
	void strike(character* c);
	bool isDead();
	int dirOnX(std::string dir);
	int dirOnY(std::string dir);
	bool isAggro(Floor *);
	character* use(character* c);
	character* useReverse(character* c);
	character* removeTemps();
};

#endif
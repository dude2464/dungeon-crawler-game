#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Floor.h"
//class Floor;
//#include "character.h"
#include <iostream>
#include <string>
#include <cmath>


class character {
protected:
	std::string subclass;	// string of subclass name
	char symbol;
	int HP;
	int atk;
	int def;
	int xpos;
	int ypos;
	int gold;
	character(std::string subclass, char symbol, int HP, int atk, int def, int gold);
public:
	virtual char getSymbol();
	virtual int getDef();
	virtual int getAtk();
	virtual int getHP();
	virtual int getGold();
	virtual int getXpos();
	virtual int getYpos();

	virtual void setHP(int value);
	virtual void setXpos(int x);
	virtual void setYpos(int y);

	virtual std::string getSubclass();

	virtual void addHP(int val);
	virtual void addGold(int val);


	virtual void move(Floor *f, int x, int y);
	virtual void strike(character* c);
	virtual bool isDead();
	virtual int dirOnX(std::string dir);
	virtual int dirOnY(std::string dir);
	virtual bool isAggro(Floor *);
	virtual character* use(character* c);
	virtual character* useReverse(character* c);

	virtual character* removeTemps();

	//for merchants
	virtual bool isHostile();
	virtual void becomeHostile();
	virtual void notifyMerchants(character** e, int numEnemies);

	// for dragon
	virtual void canPickUpGold();

	//for dragon horde
	virtual bool getCanPickUp();
};

#endif
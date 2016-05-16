#include "tempPotion.h"
#include "character.h"
#include "Floor.h"
#include <string>

bool tempPotion::isTemp(){
	return true;
}

tempPotion::tempPotion(int atk, int def): potion(0, atk, def){

	ch = NULL;

 }

int tempPotion::getDef() {
	if(ch != NULL){
		return this->def + ch->getDef();
	}
	return character::getDef();
}

int tempPotion::getAtk(){
	if(ch != NULL){
		return this->atk + ch->getAtk();
	}
	return character::getAtk();
}

int tempPotion::getHP() {
	if(ch != NULL){
	//	std::cout << "get here:" << std::endl;
	//	std::cout << "ch->getHP returned: " << ch->getHP() << std::endl;
		return this->HP + ch->getHP();
	}
	//std::cout << "here instead" << std::endl;
	return character::getHP();
}

int tempPotion::getGold() {
	if(ch != NULL){
		return this->HP + ch->getGold();
	}
	return character::getGold();
}

void tempPotion::setHP(int value){
	if(ch != NULL){
		ch->setHP(value);
	} else {
		character::setHP(value);
	}
}
void tempPotion::setXpos(int x){
	if(ch != NULL){
		ch->setXpos(x);
	} else {
		//this->xpos = x;
		character::setXpos(x);
	}
}
void tempPotion::setYpos(int y){
	if(ch != NULL){
		ch->setYpos(y);
	} else {
		//this->ypos = y;
		character::setYpos(y);
	}
}
int tempPotion::getXpos(){
	if(ch != NULL){
		return ch->getXpos();
	} else{
		return character::getXpos();
	}
}
int tempPotion::getYpos(){
	if(ch != NULL){
		return ch->getYpos();
	} else {
		return character::getYpos();
	}
}
std::string tempPotion::getSubclass(){
	if(ch != NULL){
		return ch->getSubclass();
	}
	return character::getSubclass();
}

void tempPotion::addHP(int val){
	if(ch != NULL){
		ch->addHP(val);
	} else{
		character::addHP(val);
	}
}
void tempPotion::addGold(int val){
	if(ch != NULL){
		ch->addGold(val);
	} else {
		character::addGold(val);
	}
}
char tempPotion::getSymbol(){
	//std::cout << "in tempPotion getSymbol function" << std::endl;
	if(ch != NULL){
	//	std::cout << "going into ch pointer" << std::endl;
		return ch->getSymbol();
	}
	//std::cout << "getting this->symbol" << std::endl;
	//return this->symbol;
	return character::getSymbol();
}
void tempPotion::move(Floor *f, int x, int y){
	if(ch != NULL){
		ch->move(f, x, y);
	} else {
		character::move(f, x, y);
	}
}
void tempPotion::strike(character* c){
	if(ch != NULL){
		ch->strike(c);
	} else {
		character::strike(c);
	}
}
bool tempPotion::isDead(){
	if(ch != NULL){
		return ch->isDead();
	}
	return character::isDead();
}
int tempPotion::dirOnX(std::string dir){
	if(ch != NULL){
		return ch->dirOnX(dir);
	}
	return character::dirOnX(dir);
}
int tempPotion::dirOnY(std::string dir){
	if(ch != NULL){
		return ch->dirOnY(dir);
	}
	return character::dirOnY(dir);
}
bool tempPotion::isAggro(Floor *f){
	if(ch != NULL){
		return ch->isAggro(f);
	}
	return character::isAggro(f);
}
character* tempPotion::use(character* c){
	if(ch != NULL){
	//	std::cout << "using ch's use" << std::endl;
		ch = ch->use(c);
	} else {
	//	std::cout << "setting ch = c" << std::endl;
		ch = c;	
	}
	return this;

}
character* tempPotion::useReverse(character* c){
	if(ch != NULL){
		return ch->useReverse(c);
	}
	return character::useReverse(c);
}

character* tempPotion::removeTemps(){
	if(ch != NULL){
		return ch->removeTemps();
	}
	return character::removeTemps();
}



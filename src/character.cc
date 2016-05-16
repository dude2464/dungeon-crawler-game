#include "character.h"

using namespace std;

character::character(string subclass, char symbol, int HP, int atk, int def, int gold) :
	subclass(subclass), xpos(-1), ypos(-1), symbol(symbol), HP(HP), atk(atk), def(def), gold(gold) {}

void character::strike(character* c) {
	double defModifier = 100.0 / (100.0 + c->getDef());
	int dmg = ceil(defModifier * this->atk);
	int newHP = c->getHP() - dmg;
	c->setHP(newHP);
}

int character::getDef() {
	return this->def;
}

int character::getAtk(){
	return this->atk;
}

int character::getHP() {
	return this->HP;
}

int character::getGold() {
	return this->gold;
}

void character::setHP(int value) {
	this->HP = value;
}

char character::getSymbol() {
	return this->symbol;
}

bool character::isDead() {
	if (this->getHP() <= 0) {
		return true;
	}
	return false;
}

void character::move(Floor *f, int x, int y){

}

void character::setXpos(int x){
	this->xpos = x;
}

void character::setYpos(int y){
	this->ypos = y;
}

int character::getXpos(){
	return this->xpos;
}

int character::getYpos(){
	return this->ypos;
}

void character::addHP(int val){
	this->HP += val;
}

void character::addGold(int val){
	this->gold += val;
}

string character::getSubclass() {
	return this->subclass;
}


int character::dirOnX(std::string dir){
	return 0;
}

int character::dirOnY(std::string dir){
	return 0;
}

bool character::isAggro(Floor *) {
	return false;
}

character* character::use(character* c){
	return NULL;
}

character* character::useReverse(character* c){
	return NULL;
}

character* character::removeTemps(){
	return this;
}

bool character::isHostile() {
	return false;
}

void character::becomeHostile() {

}


void character::notifyMerchants(character** e, int numEnemies) {

}

void character::canPickUpGold() {

}

bool character::getCanPickUp() {
	return false;
}
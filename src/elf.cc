#include "elf.h"

elf::elf() : PC(140, 30, 10) {}


character* elf::use(character* c){
	if(c->getHP() < 0 || c->getAtk() < 0|| c->getDef() < 0){
		return c->useReverse(this);
	}
	return c->use(this);
}
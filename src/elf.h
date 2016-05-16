#ifndef __ELF_H__
#define __ELF_H__


#include "playableCharacter.h"

class elf : public PC {
public:
	elf();
	character* use(character* c);
};


#endif
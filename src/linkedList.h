#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <cstddef>
#include "Cell.h"

class linkedList {
	int size;
	Cell* c;
	linkedList* next;

public:
	linkedList(Cell* c);
	Cell* getCell();
	linkedList* getNext();
	int getSize();
	void addCell(Cell* c);
	void pushCell(Cell* ce);
};

#endif
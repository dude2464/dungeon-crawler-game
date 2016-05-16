#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

class linkedList {
	int size;
	Cell* c;
	linkedList* next;

public:
	linkedList(Cell* c, linkedList* l);
	Cell* getCell();
	linkedList* getNext();

};

#endif
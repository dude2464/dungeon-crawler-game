#include "linkedList.h"
#include "Cell.h"

linkedList::linkedList(Cell* ce){
	//if(l != NULL){
//		this->size = l->getSize() + 1;
//	} else {
//		this->size = 1;
//	}

	this->c = ce;
	this->next = NULL;
}

Cell* linkedList::getCell(){
	return this->c;
}

linkedList* linkedList::getNext(){
	return this->next;
}

int linkedList::getSize(){
	return this->size;

}

void linkedList::pushCell(Cell* ce){
	this->size++;
	if(this->next == NULL){
		this->next = new linkedList(ce); 
	} else {
		this->next->pushCell(ce);
	}
}
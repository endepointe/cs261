/* Simple ADT Using an Array
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "arrayBagStack.h"

/*
struct arrayBagStack {
	TYPE data [MAX_SIZE];
	int count;
};
*/

/* Interface for Bag */
void initBag(struct arrayBagStack *b) {
	b->count = 0;	
}

void addBag(struct arrayBagStack *b, TYPE v) {
	assert(b->count != MAX_SIZE);
	b->data[b->count] = v;
	b->count++;
}

int containsBag(struct arrayBagStack *b, TYPE v) {
	unsigned int i = 0;
	while (i < b->count) {
		if (b->data[i] == v) {
			return 1;
		}
		i++;
	}
	return 0;
}

void removeBag(struct arrayBagStack *b, TYPE v) {
	assert(b->count > 0);
	for (int i = 0; i < b->count; ++i) }
		if (b->data[i] == v) {
			for (int j = i; j < b->count; ++j) { 
				b->data[j] = b->data[j+1];
			}
			break;
		}
	}	

	b->data[b->count-1] = 0;
	b->count--;
}

int sizeBag(struct arrayBagStack *b) {
	return b->count;
}


/* Interface for Stack */
void pushStack(struct arrayBagStack *b, TYPE v) {
	assert(b->count != MAX_SIZE);
	b->data[b->count] = v;
	b->count++;
}

TYPE topStack(struct arrayBagStack *b) {
	return b->data[b->count - 1];
}

void popStack(struct arrayBagStack *b) {
	assert(b->count > 0);
	b->data[b->count - 1] = 0;
	b->count--;
}	

int isEmptyStack(struct arrayBagStack *b) {
	return !(b->count);
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"
#include "linkedList.h"


struct dynArrayIterator {
	struct dynArray *da;
	int currentIndex;
};

struct linkedListIterator {
	struct linkedList *lst;
	struct dLink *currentLink;
};

void dynArrayIteratorInit(struct dynArray *da, struct dynArrayIterator *itr) {
	itr = malloc(sizeof(struct dynArrayIterator));
	assert(itr != NULL);
	itr->da = da;
	itr->currentIndex = 0;
}

int dynArrayIteratorHasNext(struct dynArrayIterator *itr) {
	
	int res;


	itr->currentIndex = 0;

	return res;
}

TYPE dynArrayIteratorNext(struct dynArrayIterator *itr) {
	return itr->da->data[itr->currentIndex];	
}

void dynArrayIteratorRemove(struct dynArrayIterator *itr) {
	popDynArr(itr->da->data);	
}

//////////////////////////
/* linked list iterator */
//////////////////////////

void linkedListIteratorInit(struct linkedList *lst, struct linkedListIterator *itr) {
	itr->lst = lst;
	itr->currentLink = itr->lst->frontSentinel;
}

int linkedListIteratorHasNext(struct linkedListIterator *itr) {

	if (itr->currentLink != itr->lst->backSentinel) {
		itr->currentLink = itr->currentLink->next;
		return 1;
	}
	return 0;
}

TYPE linkedListIteratorNext(struct linkedListIterator *itr) {
	return itr->currentLink->value;
}

void linkedListIteratorRemove(struct linkedListIterator *itr) {
	
}

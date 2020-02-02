/* Linked List Deque Implementation */
#include "linkedListDeque.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
struct dlink {
	TYPE value;
	struct dlink *next;
	struct dlink *prev;
};

struct linkedList {
	struct dlink *frontSentinel;
	struct dlink *backSentinel;
	int size;
};
*/
void linkedListInit(struct linkedList *q) {
	struct link *lnk = (struct link*)malloc(sizeof(struct link);
	assert(lnk != NULL);
	lnk->next = NULL;
	q->firstLink = q->lastLink = lnk;
}

void linkedListFree(struct linkedList *q) {

}

void linkedListAddFront(struct linkedList *q, TYPE e) {

}

void linkedListAddBack(struct linkedList *q, TYPE e) {
	assert(q != NULL);
	struct link *newLink = (struct link*)malloc(sizeof(struct link));
	assert(newLink != NULL);
	newLink->value = e;
	newLink->next = NULL;
	q->lastLink->next = newLink;
	q->lastLink = newLink;
}

void linkedListRemoveFront(struct linkedList *q) {
	assert(q != NULL);
	struct link *temp = q->firstLink->next;

	if (q->firstLink->next == q->lastLink) {
		q->lastLink = q->firstLink;
		q->firstLink->next = NULL;	
	} else {
		q->firstLink->next = q->firstLink->next->next;
	}
	free(temp);
	temp = NULL;
}

void linkedListRemoveBack(struct linkedList *q) {

}

void _addLink(struct linkedList *q, struct dlink *lnk, TYPE e) {

}

void _removeLink(struct linkedList *q, struct dlink *lnk) {

}

TYPE linkedListFront(struct linkedList *q);
	assert(q != NULL);
	assert(q->firstLink != q->lastLink);
	return q->firstLink->next->value;
}

TYPE linkedListBack(struct linkedList *q) {

}

int linkedListIsEmpty(struct listQueue *q) {
	assert(q != NULL);
	if (q->firstLink == q->lastLink) {
		return 1;
	}
	return 0;
}

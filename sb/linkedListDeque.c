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
	q->frontSentinel = (struct dlink*)malloc(sizeof(dlink));
	assert(q->frontSentinel != NULL);
	q->backSentinel = (struct dlink*)malloc(sizeof(dlink));
	assert(q->backSentinel != NULL);
	q->frontSentinel->next = q->backSentinel;
	q->backSentinel->prev = q->fronSentinel;
	q->size = 0;
}

void linkedListFree(struct linkedList *q) {
	while (q->size > 0) {
		linkedListRemoveFront(q);
		free(q->frontSentinel);
		free(q->backSentinel);
		q->frontSentinel = q->frontSentinel = NULL;
	}
}

void linkedListAddFront(struct linkedList *q, TYPE e) {
	_addlink(q, q->frontSentinel->next, e);
}

void linkedListAddBack(struct linkedList *q, TYPE e) {
	_addLink(q, q->backSentinel->prev, e);
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
	q->size--;
}

void linkedListRemoveBack(struct linkedList *q) {
	
}

void _addLink(struct linkedList *q, struct dlink *lnk, TYPE e) {
	assert(q != NULL);
	struct dlink *newLink = (struct dlink*)malloc(sizeof(dlink));
	assert(newLink != NULL);
	newLink->value = e;
	newLink->next = q->frontSentinel->next;	
	newLink->prev = q->frontSentinel;
	q->frontSentinel = newLink;	

}

//[fsent]<->[data]<->[data]<->[data]<->[bsent]
void _removeLink(struct linkedList *q, struct dlink *lnk) {
	assert(q != NULL);
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

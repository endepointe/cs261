/* Linked List Queue Implementation */
#include "linkedListQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
struct link {
	TYPE value;
	struct link *next;
};

struct listQueue {
	struct link *firstLink;
	struct link *lastLink;
};
*/

void listQueueInit(struct listQueue *q) {
	struct link *lnk = (struct link*)malloc(sizeof(struct link);
	assert(lnk != NULL);
	lnk->next = NULL;
	q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack(struct listQueue *q, TYPE e) {
	assert(q != NULL);
	struct link *newLink = (struct link*)malloc(sizeof(struct link));
	assert(newLink != NULL);
	newLink->value = e;
	newLink->next = NULL;
	q->lastLink->next = newLink;
	q->lastLink = newLink;
}

TYPE listQueueFront(struct listQueue *q) {
	assert(q != NULL);
	assert(q->firstLink != q->lastLink);
	return q->firstLink->next->value;
}

void listQueueRemoveFront(struct listQueue *q) {
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

int listQueueIsEmpty(struct listQueue *q) {
	assert(q != NULL);
	if (q->firstLink == q->lastLink) {
		return 1;
	}
	return 0;
}
#endif

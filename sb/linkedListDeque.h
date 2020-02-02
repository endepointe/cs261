/* Linked List Deque Implementation */

#ifndef LINKEDLISTDEQUE_H
#define LINKEDLISTDEQUE_H
#ifndef TYPE
#define TYPE int
#endif

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

void linkedListInit(struct linkedList *q);

void linkedListFree(struct linkedList *q);

void linkedListAddFront(struct linkedList *q, TYPE e);

void linkedListAddBack(struct linkedList *q, TYPE e);

void linkedListRemoveFront(struct linkedList *q);

void linkedListRemoveBack(struct linkedList *q);

void _addLink(struct linkedList *q, struct dlink *lnk, TYPE e);

void _removeLink(struct linkedList *q, struct dlink *lnk);

TYPE linkedListFront(struct linkedList *q);

TYPE linkedListBack(struct linkedList *q);

int linkedListIsEmpty(struct linkedList *q);
#endif

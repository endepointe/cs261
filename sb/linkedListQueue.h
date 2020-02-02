/* Linked List Queue Implementation */

#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H
#ifndef TYPE
#define TYPE int
#endif

struct link {
	TYPE value;
	struct link *next;
};

struct listQueue {
	struct link *firstLink;
	struct link *lastLink;
};

void listQueueInit(struct listQueue *q);

void listQueueAddBack(struct listQueue *q, TYPE e);

TYPE listQueueFront(struct listQueue *q, TYPE e);

void listQueueRemoveFront(struct listQueue *q);

int listQueueIsEmpty(struct listQueue *q);
#endif

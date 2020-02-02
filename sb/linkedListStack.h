/* Linked List Stack Implementation */

#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H
#ifndef TYPE
#define TYPE int
#endif

struct link {
	TYPE value;
	struct link *next;
};

struct linkedListStack {
	struct link *firstLink;
};

void linkedListStackInit(struct linkedListStack *s);

void linkedListStackFree(struct linkdListStack *s);

void linkedListStackPush(struct linkedListStack *s, TYPE d);

TYPE linkedListStackTop(struct linkedListStack *s);

void linkedListStackPop(struct linkdListStack *s);

int linkedListStackIsEmpty(struct linkedListStack *s);
#endif

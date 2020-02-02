/* Linked List Stack Implementation */

#include "linkedListStack.h"
#include <assert.h>

/*
struct link {
	TYPE value;
	struct link *next;
};

struct linkedListStack {
	struct link *firstLink;
};
*/

void linkedListStackInit(struct linkedListStack *s) {
	s->firstLink = NULL;
}

void linkedListStackFree(struct linkdListStack *s) {
	while (!linkedListStackIsEmpty(s)) {
		linkedListStackPop(s);	
	}
}

void linkedListStackPush(struct linkedListStack *s, TYPE d) {
	struct link *newLink = (struct link*)malloc(sizeof(struct link));	
	assert(newLink != NULL);
	/* resume here */
}

TYPE linkedListStackTop(struct linkedListStack *s);

void linkedListStackPop(struct linkdListStack *s);

int linkedListStackIsEmpty(struct linkedListStack *s);
#endif

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
	newLink->value = d;
	assert(s != NULL);
	if (s->firstLink == 0) {
		newLink->next = 0;
	} else {
		newLink->next = s->firstLink;
	}	

	s->firstLink = newLink;
}

TYPE linkedListStackTop(struct linkedListStack *s) {
	assert(s != 0);
	assert(!linkedListStackIsEmpty(s));
	return s->firstLink->value;
}

void linkedListStackPop(struct linkdListStack *s) {
	assert(s != 0);
	assert(!linkedListStackIsEmpty(s));
	struct link *temp;
	temp = s->firstLink;
	s->firstLink = s->firstLink->next;
	free(temp);
	temp = NULL;
}

int linkedListStackIsEmpty(struct linkedListStack *s) {
	if (s->firstLink == NULL) {
		return 1;
	}
	return 0;
}
#endif

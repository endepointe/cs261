/* Worksheet 22: Constructing a Bag using a Linked List 
 * Author: Alvin Johns
 * Date: January 29, 2019
 * Desc: Construct a bag using a linked list.
 *	
 *	*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"

void linkedListInit(struct linkedList *lst) {

	lst->frontSentinel = (struct dLink*)malloc(sizeof(struct dLink));
	assert(lst->frontSentinel != 0);

	lst->backSentinel = (struct dLink*)malloc(sizeof(struct dLink));
	assert(lst->backSentinel != 0);

	lst->frontSentinel->next = lst->backSentinel;
	lst->backSentinel->prev = lst->frontSentinel;
	lst->size = 0;	
}

void linkedListFree(struct linkedList *lst) {

	assert(lst->size != 0);

	struct dLink *last = lst->backSentinel->prev;

	while (last != lst->frontSentinel) {
		last = last->prev;
		free(last->next);
	}

	free(last);
	free(lst->frontSentinel);
	free(lst->backSentinel);

	lst->frontSentinel = 0;
	lst->backSentinel = 0;
}

void _addLink(struct linkedList *lst, struct dLink *lnk, TYPE e) {

	assert(lst != 0);

	struct dLink *newLink = (struct dLink*)malloc(sizeof(struct dLink));
	assert(newLink != 0);

	newLink->value = e;
	newLink->next = lnk;
	newLink->prev = lnk->prev;

	lnk->prev->next = newLink;
	lnk->prev = newLink;

	lst->size++;
}

void _removeLink(struct linkedList *lst, struct dLink *lnk) {

	assert(lst != 0);

	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;

	free(lnk);	
	lnk = 0;

	lst->size--;
}

void linkedListAdd(struct linkedList *lst, TYPE e) {

	_addLink(lst, lst->frontSentinel->next, e);
}

int linkedListContains(struct linkedList *lst, TYPE e) {

	struct dLink *curr;
	unsigned int pos = 0;
	
	assert(lst != 0);

	curr = lst->frontSentinel->next;
	
	while (curr != lst->backSentinel) {
	
		pos++;	

		if (curr->value == e) {
			return pos;
		}

		curr = curr->next;
	}

	return 0;	
}

void linkedListRemove(struct linkedList *lst, TYPE e) {

	assert(lst != 0);
	struct dLink *curr = lst->frontSentinel->next;

	unsigned int i = linkedListContains(lst, e);
	unsigned int j = 1;
	
	while (curr != NULL) {
			
		if (i == j) {
			_removeLink(lst, curr);	
			break;
		}		

		j++;

		curr = curr->next;
	}	
}

void printLinkedList(struct linkedList *lst) {
	struct dLink *curr = lst->frontSentinel->next;

	while (curr != lst->backSentinel) {
		printf("%c ", curr->value);	
		curr = curr->next;
	}

	printf("\nSize: %i\n", lst->size);
}



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define TYPE char
/* ***************************************************************
Do something here for the week 4 worksheets
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/

struct dLink {
	TYPE value;
	struct dLink *next;
	struct dLink *prev;
};

struct linkedList {
	struct dLink *frontSentinel;
	struct dLink *backSentinel;
	int size;
};

void linkedListInit(struct linkedList *lst);
void linkedListFree(struct linkedList *lst);
void _addLink(struct linkedList *lst, struct dLink *lnk, TYPE e);
void _removeLink(struct linkedList *lst, struct dLink *lnk);

void linkedListAdd(struct linkedList *lst, TYPE e);

int linkedListContains(struct linkedList *lst, TYPE e);
void linkedListRemove(struct linkedList *lst, TYPE e);
void printLinkedList(struct linkedList *lst);
#endif

/* Worksheet 22: Constructing a Bag using a Linked List 
 * Author: Alvin Johns
 * Date: January 29, 2019
 * Desc: Construct a bag using a linked list.
 *	
 *	*/

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
char nextChar(char* s) {
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if (c == '\0') {
		return '\0';	
	}
	return c;
}

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

#endif

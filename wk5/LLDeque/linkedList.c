/***********************************************************
* Author: Alvin Johns
* Email: johnsal@oregonstate.edu
* Date Created: February 6, 2020
* Filename: linkedList.c
*
* Overview:
*   This program is a linked list implementation of the deque
*	(as worked on in Worksheet 19) and bag (as worked on in
*	Worksheet 22) ADTs.
*	The deque ADT allows for the following behavior:
*		- adding a new link to the front/back
*		- getting the value of the front/back links
*		- removing the front/back link
*	The bag ADT allows for the following behavior:
*		- adding a new link
*		- checking if a link exists with a given value
*		- removing a link  with a given value if it exists
*	Both allow for:
*		- checking if empty
*		- printing the values of all of the links
*
*	Note that both implementations utilize a linked list with
*	both a front and back sentinel and double links (links with
*	next and prev pointers).
************************************************************/
#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef FORMAT_SPECIFIER
#define FORMAT_SPECIFIER "%d"
#endif

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	struct Link* frontSentinel;
	struct Link* backSentinel;
	int size;
};

/**
  	Allocates the list's sentinel and sets the size to 0.
  	The sentinels' next and prev should point to eachother or NULL
  	as appropriate.
	param: 	list 	struct LinkedList ptr
	pre: 	list is not null
	post: 	list front and back sentinel not null
			front sentinel next points to back
			front sentinel prev points to null
			back sentinel prev points to front
			back sentinel next points to null
			list size is 0
 */
static void init(struct LinkedList* list) {
	/* FIXME: You will write this function */

	list->frontSentinel = (struct Link*)malloc(sizeof(struct Link));
	assert(list->frontSentinel != NULL);

	list->backSentinel = (struct Link*)malloc(sizeof(struct Link));
	assert(list->backSentinel != NULL);

	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;

	list->size = 0;
}

/**
	Removes the given link from the list and
	decrements the list's size.
	param: 	list 	struct LinkedList ptr
 	param:	link 	struct Link ptr
	pre: 	list and link are not null
	post: 	param link is removed from param list
			memory allocated to link is freed
			list size is decremented by 1
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	/* FIXME: You will write this function */
	assert(!linkedListIsEmpty(list));
	struct Link *temp = link;
	link->prev->next = link->next;
	link->next->prev = link->prev;
	free(temp);
	temp = NULL;
	list->size--;
}

/**
	Allocates and initializes a list.
	pre: 	none
	post: 	memory allocated for new struct LinkedList ptr
			list init (call to init func)
	return: list
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* list = malloc(sizeof(struct LinkedList));
	init(list);
	return list;
}

/**
	Deallocates every link in the list including the sentinels,
	and frees the list itself.
	param:	list 	struct LinkedList ptr
	pre: 	list is not null
	post: 	memory allocated to each link is freed
			" " front and back sentinel " "
			" " list " "
 */
void linkedListDestroy(struct LinkedList* list)
{
	//assert(list != NULL);
	while (!linkedListIsEmpty(list)) {
		removeLink(list, list->frontSentinel->next);
	}
	/*
	free(list->frontSentinel);
	list->frontSentinel = NULL;
	free(list->backSentinel);
	list->backSentinel = NULL;
	*/
	//free(list);
	//list = NULL;
}

/**
	Adds a new link with the given value to the front of the deque.
	param: 	deque 	struct LinkedList ptr
	param: 	value 	TYPE
	pre: 	deque is not null
	post: 	link is created w/ param value stored before current first link
			(call to addLinkBefore)
 */
void linkedListAddFront(struct LinkedList* deque, TYPE value)
{
	/* FIXME: You will write this function */
	assert(deque != NULL);
	struct Link *newLink = (struct Link*)malloc(sizeof(struct Link));
	assert(newLink != NULL);
	newLink->value = value;
	newLink->next = deque->frontSentinel->next;
	newLink->prev = deque->frontSentinel;
	deque->frontSentinel->next = newLink;
	deque->size++;
}

/**
	Adds a new link with the given value to the back of the deque.
	param: 	deque 	struct LinkedList ptr
	param: 	value 	TYPE
	pre: 	deque is not null
	post: 	link is created with given value before last link (sentinel)
			(call to addLinkBefore)
 */
void linkedListAddBack(struct LinkedList* deque, TYPE value)
{
	/* FIXME: You will write this function */
	assert(deque != NULL);
	struct Link *newLink = (struct Link*)malloc(sizeof(struct Link));
	assert(newLink != NULL);
	newLink->value = value;
	newLink->prev = deque->backSentinel->prev;
	newLink->next = deque->backSentinel;
	deque->backSentinel->prev =  newLink;
	deque->size++;
}

/**
	Returns the value of the link at the front of the deque.
	param: 	deque 	struct LinkedList ptr
	pre:	deque is not null
	pre:	deque is not empty
	post:	none
	ret:	first link's value
 */
TYPE linkedListFront(struct LinkedList* deque)
{
	/* FIXME: You will write this function */
	assert(!linkedListIsEmpty(deque));
	return deque->frontSentinel->next->value;
}

/**
	Returns the value of the link at the back of the deque.
	param: 	deque 	struct LinkedList ptr
	pre:	deque is not null
	pre:	deque is not empty
	post:	none
	ret:	last link's value
 */
TYPE linkedListBack(struct LinkedList* deque)
{
	/* FIXME: You will write this function */
	assert(!linkedListIsEmpty(deque));
	return deque->backSentinel->prev->value;
}

/**
	Removes the link at the front of the deque.
	param: 	deque 	struct LinkedList ptr
	pre:	deque is not null
	pre:	deque is not empty
	post:	first link is removed and freed (call to removeLink)
 */
void linkedListRemoveFront(struct LinkedList* deque)
{
	/* FIXME: You will write this function */
	removeLink(deque, deque->frontSentinel->next);
}

/**
	Removes the link at the back of the deque.
	param: 	deque 	struct LinkedList ptr
	pre:	deque is not null
	pre:	deque is not empty
	post:	last link is removed and freed (call to removeLink)
 */
void linkedListRemoveBack(struct LinkedList* deque)
{
	/* FIXME: You will write this function */
	removeLink(deque, deque->backSentinel->prev);
}

/**
	Returns 1 if the deque is empty and 0 otherwise.
	param:	deque	struct LinkedList ptr
	pre:	deque is not null
	post:	none
	ret:	1 if its size is 0 (empty), otherwise 0 (not empty)
 */
int linkedListIsEmpty(struct LinkedList* deque)
{
	/* FIXME: You will write this function */
	return !(deque->size);
}

/**
	Prints the values of the links in the deque from front to back.
	param:	deque	struct LinkedList ptr
	pre:	deque is not null
	post:	none
	ret:	outputs to the console the values of the links from front
			to back; if empty, prints msg that is empty
 */
void linkedListPrint(struct LinkedList* deque)
{
	/* FIXME: You will write this function */
	assert(!linkedListIsEmpty(deque));	
	struct Link *curr = deque->frontSentinel->next;
	int count = deque->size;

	if (linkedListIsEmpty(deque)) {
		printf("\nThe list is empty\n");
	} else {	
		printf("\nList: ");
		while (count > 0) {
			printf("%d ", curr->value);
			curr = curr->next;
			count--;
		}
		printf("\n");
	}
}

/**
	Adds a link with the given value to the bag.
	param:	bag		struct LinkedList ptr
	param: 	value 	TYPE
	pre: 	bag is not null
	post: 	link is created w/ given value before current first link
			(call to addLinkBefore)
			Note that bag doesn't specify where new link should be added;
			can be anywhere in bag according to its ADT.
 */
void linkedListAdd(struct LinkedList* bag, TYPE value)
{
	/* FIXME: You will write this function */

}

/**
	Returns 1 if a link with the value is in the bag and 0 otherwise.
	param:	bag		struct LinkedList ptr
	param: 	value 	TYPE
	pre: 	bag is not null
	post:	none
	ret:	1 if link with given value found; otherwise, 0
 */
int linkedListContains(struct LinkedList* bag, TYPE value)
{
	/* FIXME: You will write this function */
	struct Link *curr = bag->frontSentinel->next;

	while (curr->next != bag->backSentinel) {
		if (curr->value == value) {
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

/**
	Removes the first occurrence of a link with the given value.
	param:	bag		struct LinkedList ptr
	param: 	value 	TYPE
	pre: 	bag is not null
	post:	if link with given value found, link is removed
			(call to removeLink)
 */
void linkedListRemove(struct LinkedList* bag, TYPE value)
{
	/* FIXME: You will write this function */
	struct Link *curr = bag->frontSentinel->next;	
	while (curr->next != bag->backSentinel) {
		if (curr->value == value) {
			removeLink(bag, curr);
		}
	}	
}

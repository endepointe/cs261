

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"

int main(int argc, char* argv[]){

	printf("Worksheet 22\n");

	struct linkedList *L = (struct linkedList*)malloc(sizeof(struct linkedList));

	linkedListInit(L);

	linkedListAdd(L, 'a');
	linkedListAdd(L, 'b');
	linkedListAdd(L, 'c');
	linkedListAdd(L, 'd');
	linkedListAdd(L, 'e');
	linkedListAdd(L, 'f');
	linkedListAdd(L, 'g');
	linkedListAdd(L, 'h');

	printLinkedList(L);

	if (linkedListContains(L, 'b')) {
		printf("contains b\n");
	}

	linkedListRemove(L, 'b');
	
	if (!linkedListContains(L, 'b')) {
		printf("b removed\n");
	}
	
	printLinkedList(L);

	if (linkedListContains(L, 'h')) {
		printf("contains h\n");
	}

	linkedListRemove(L, 'h');
	
	if (!linkedListContains(L, 'h')) {
		printf("h removed\n");
	}

	printLinkedList(L);

	if (linkedListContains(L, 'c')) {
		printf("contains c\n");
	}

	linkedListRemove(L, 'c');
	
	if (!linkedListContains(L, 'c')) {
		printf("c removed\n");
	}

	printLinkedList(L);


	return 0;	
}

/*
 *
 * 1) O(1)
 * 2) linkedListContains is O(n) for worst case 
 *    the other two are O(1)
 *    */

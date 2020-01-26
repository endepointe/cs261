/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}
/* Checks if the given character is the type of punctuation in the list
 * 	of values given. returns true of false (1,0)
 * 	param: character in a string pointer
 * 	pre: 
 * 	post:
 * 	values to check: (40,41), (91, 93), (123,125)
 */
int checkPunc(char c) {

	int result = 0;

	switch (c) {
		case 40:
		case 41:
		case 91:
		case 93:
		case 123:
		case 125:
			result = 1;
		break;
		default:
			result = 0;
		break;
	}

	return result;
}	

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */		
	int bal = 0;	
	assert(s != 0);
	DynArr *stack = newDynArr(20);
	
	for (int i = 0; s[i] != '\0'; ++i) {
		if (checkPunc(s[i]) == 1) {
			pushDynArr(stack, s[i]);
		}
	}

	// If the size of the dyn arr is not even,
	// the punctuation stack cannot be balanced.	
	if (sizeDynArr(stack) % 2 != 0) {
		bal = 0;
	} else {

	}
/*
	for (int i = 0; i < sizeDynArr(stack); ++i) {
		printf("%c", getDynArr(stack, i));
	}
*/
	printf("\n");

	return 0;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}


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
 * 	values to check: (40, 91, 123)
 */
int checkOpenPunc(char c) {

	int result = 0;

	switch (c) {
		case 40:
		case 91:
		case 123:
			result = 1;
		break;
		default:
			result = 0;
		break;
	}

	return result;
}	

/* Helper function to check if the stack of open parentheses 
	contains a corresponding closing parenthesis 
	param: 	s pointer to a string  and DynArr*	
	pre: 	
	post:	
*/
int check(int val, DynArr *da) {

	int b;

	if (isEmptyDynArr(da)) {
		b = 0;
		return b;
	}
	if (topDynArr(da) == val) {
		popDynArr(da);
		b = 1;
	}	
	return b;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */		
	assert(s != 0);
	int bal = 0;
	char ch = ' ';
	DynArr *stack = newDynArr(8);
	
	while (ch != '\0') {	
	//for (int i = 0; s[i] != '\0'; ++i) {
		ch = nextChar(s);
		if (checkOpenPunc(ch /*(s[i]*/) == 1) {
			pushDynArr(stack, ch /*s[i]*/);
		}

		switch (ch /*s[i]*/) {
			case 41:
				bal = check(40, stack);
			break;					
			case 93:
				bal = check(91, stack);
			break;
			case 125:
				bal = check(123, stack);
			break;
		}			
		//printf("NextChar returns: %c\n", nextChar(s));
	}

	if (bal == 1 && !isEmptyDynArr(stack)) {
		bal = 0;
	}

	printf("\n");
	
	deleteDynArr(stack);

	return bal;
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


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

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
	values to check: (40,41), (91, 93), (123,125)
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */		
	
	assert(s != 0);

	rnt i = 0;

	while ( s[i] != '\0') {
		i++;
	}

	// Init a stack to hold, at most, i chars.
	DynArr* stack = newDynArr(i);

	while (s[i] != '\0') {
		switch (nextChar(*s[i])) {
			case 40:
			case 41:
			case 90:
			case 91:
			case 123:
			case 125:
				pushDynArr(stack, s[i]);
			break;
		}

	printf("\n");

	// starting at the end of the temp string, check if the closing 
	// types of parenthesis are matched
	printf("\n");

	printf("%s\n", stack);
	free(stack);

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


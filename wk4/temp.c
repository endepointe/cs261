/* Worksheet 22: Constructing a Bag using a Linked List 
 * Author: Alvin Johns
 * Date: January 29, 2019
 * Desc: Construct a bag using a linked list.
 *	
 *	*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"

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

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	
	printf("Worksheet week 4\n");

	return 0;	
}


/*******
 * CS261: Assignment 1 - Q.0
 * Name: Alvin Johns
 * Date: 01/12/20
 * Solution Desc: Demonstration file to display how pointers work in C
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fooA(int* iptr) {

	/* Print the value and address of the integer pointed to by iptr*/

	printf("Value of the integer pointed to by iptr: %d\n", *iptr);
	printf("Address that iptr points to: %p\n", &iptr);

	/* Increment the value of the integer pointed to by iptr by 5 */

	*iptr += 5;
	printf("Value that iptr points to, incremented by 5: %d\n", *iptr);

	/* Print the address of the iptr itself */

	printf("Address of iptr: %p\n", iptr);

	printf("\n\n");
}


void fooB(int* jptr) {

	/* Print the value and address of the integer pointed to by jptr */
	
	printf("Value that jptr points to: %d\n", *jptr);
	printf("Address of the integer jptr points to: %p\n", &jptr);

	/* Decrement the address by 1 pointed to by jptr using jptr */

	jptr -= 1;

	/* Print the address of jptr itself */

	printf("Address of jptr, decremented by 1: %p\n", jptr);

	printf("\n\n");
}


int main(int some, char ** thing) {
	
	srand(time(NULL));

	int x = rand() % 11;

	fooA(&x);
	fooB(&x);

	printf("The value of x: %d\n", x);
	printf("The address of x: %p\n", &x);

	/* 
	 * The value and address of x prior to the call to fooB
	 * are the same because iptr is a pointer to a memory location
	 * that holds the value of x. The address of x and the pointer,
	 * iptr are two different ways of returning the same result, using
	 * & and *, respectively. 
	 * */

	return 0;
}

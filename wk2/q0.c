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

	printf("Value of iptr: %d\n", *iptr);
	printf("Address of iptr: %p\n", &iptr);

	/* Increment the value of the integer pointed to by iptr by 5 */

	*iptr += 5;
	printf("Value of iptr incremented by 5: %d\n", *iptr);

	/* Print the address of the iptr itself */

	printf("Address of iptr: %p\n", iptr);

}

void fooB(int* jptr) {
	/* Print the value and address of the integer pointed to by jptr */
	
	printf("Value of jptr: %d\n", *jptr);
	printf("Address of jptr: %p\n", &jptr);

	/* Decrement the address by 1 pointed to by jptr using jptr */

	jptr -= -1;

	/* Print the address of jptr itself */
	printf("Address of jptr decremented by 1: %p\n", jptr);

}

int main(int some, char ** thing) {

	int x = 10;
	int *xptr = &x;

	fooA(xptr);
	fooB(xptr);

	return 0;
}

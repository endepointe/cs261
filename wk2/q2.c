/*******
 * CS261: Assignment 1 - Q.2
 * Name: Alvin Johns
 * Date: 01/13/20
 * Solution Desc: Demonstration file to display how swap pointer values 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c) {

	printf("value of a: %p\nvalue of b: %p\n", a, b);

	/* Swap the addresses stored in the pointer variables a and b */
	int *temp = a;
	a = b;
	b = temp;

	printf("value of a: %p\nvalue of b: %p\n", a, b);

	/* Decrement the value of integer variable c */
	temp = NULL;
	c -= 1;

	/* Return c */
	return c;
}

int main(int some, char ** thing) {

	srand(time(NULL));

	/* Declare three integers x,y,z and initialize them 
	 * randomly to values in [0,10] */
	int x = rand() % 11;
	int y = rand() % 11;
	int z = rand() % 11;

	printf("addy of x: %p\naddy of y: %p\n", &x, &y);

	/* Print the values of x,y,z */
	printf("x: %d, y: %d, z: %d\n\n", x, y, z);
	
	/* Call foo() appropriately, passing x,y,z as params */ 
	z = foo(&x,&y,z);

	/* Print the values of x,y,z */
	printf("x: %d, y: %d, z: %d\n\n", x, y, z);

	printf("addy of x: %p\naddy of y: %p\n", &x, &y);

	/* Print the value returned by foo */
	printf("foo() --> %d\n", z);

	return 0;
}

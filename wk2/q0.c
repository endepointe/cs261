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

	printf("fooA(...) called\n\n");

	/* Print the value and address of the integer pointed to by iptr*/
	printf("Value of the integer pointed to by iptr: %d\n\n", *iptr);
	printf("Address that iptr points to: %p\n\n", &iptr);

	/* Increment the value of the integer pointed to by iptr by 5 */
	*iptr += 5;
	printf("Value that iptr points to, incremented by 5: %d\n\n", *iptr);

	/* Print the address of iptr itself */
	printf("Address of iptr: %p\n\n", iptr);
	
	/* Dummy variable, ignore the warning */
	int c=5;
}


void fooB(int* jptr) {

	printf("fooB(...) called\n\n");

	/* Print the value and address of the integer pointed to by jptr */
	printf("Value that jptr points to: %d\n\n", *jptr);
	printf("Address of the integer jptr points to: %p\n\n", &jptr);

	/* Decrement the address by 1 pointed to by jptr using jptr */
	jptr -= 1;

	/* Print the address of jptr, decremented by 1 */
	printf("Address of jptr, decremented by 1: %p\n\n", jptr);
}


int main(int some, char ** thing) {
	
	srand(time(NULL));

	int x = rand() % 11;

	fooA(&x);
	
	printf("The value of x after fooA(...) is called: %d\n\n", x);

	/*
	 * The value of x is the same as the value that was printed first
	 * and incremented by 5. It is the same value because fooA(...)
	 * takes, as a parameter, a pointer to memory block that contains 
	 * the memory location of x. After fooA takes this parameter,
	 * the value contained can be altered by dereferencing the pointer.
	 */

	fooB(&x);

	printf("The value of x in main(): %i\n\n", x);
	printf("The address of x in main(): %p\n\n", &x);

	/* 
	 * The value and address of x is the same as the value and address
	 * prior to the call to fooB(...) because, unlike fooB(...), which
	 * increases the value of the memory address by 1, fooA(...) increments
	 * the dereferenced value by 5 without modifying the memory 
	 * address of its parameter.
	 */

	return 0;
}

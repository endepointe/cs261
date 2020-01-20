/*******
 * CS261: Assignment 1 - Q.0
 * Name: Alvin Johns
 * Date: 01/18/20
 * Solution Desc: Demonstration file to display how pointers work in C
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fooA(int* iptr) {

	printf("fooA(...) called\n\n");

	/* Print the value and address of the integer pointed to by iptr*/
	printf("Value of the integer pointed to by iptr: %i\n\n", *iptr);
	printf("Address that iptr points to: %p\n\n", iptr);

	/* Increment the value of the integer pointed to by iptr by 5 */
	*iptr += 5;

	/* Print the address of iptr itself */
	printf("Address of iptr: %p\n\n", &iptr);
	
	/* Dummy variable, ignore the warning */
	//int c=5;
}

void fooB(int* jptr) {

	printf("fooB(...) called\n\n");

	/* Print the value and address of the integer pointed to by jptr */
	printf("Value that jptr points to: %i\n\n", *jptr);
	printf("Address of the integer jptr points to: %p\n\n", jptr);

	/* Decrement the address by 1 pointed to by jptr using jptr */
	jptr -= 1;

	/* Print the address of jptr itself */
	printf("Address of jptr, decremented by 1: %p\n\n", &jptr);
}


int main(int some, char ** thing) {
	
	srand(time(NULL));

	/* Declare an integer x and init it randomly to a value in [0,10] */
	int x = rand() % 11;

	/* Print the value and address of x */
	printf("Value of x: %i\n\n", x);
	printf("Address of x: %p\n\n", &x);

	/* Call fooA() with the address of x */
	fooA(&x);

	/* Print the value of x */
	printf("The value of x after fooA(...) is called: %i\n\n", x);

	/*
	 * The value of x is different than what was printed first 
	 * because fooA() increments the value by 5. fooA() is able
	 * to change the value because the pointer in fooA() 
	 * dereferences and changes the value that the memory
	 * block contains.
	 */

	/* Call fooB() with the address of x */
	fooB(&x);

	/* Print the value and address of x */
	printf("The value of x after fooB(...): %i\n\n", x);
	printf("The address of x after fooB(...): %p\n\n", &x);

	/* 
	 * The value and address of x is the same as the value and address
	 * prior to the call to fooB(). The value and address that were
	 * printed prior to the call to fooB() were the value and address
	 * pointed to by iptr. Although the address of iptr itself is 
	 * different than the one it contains, this is only because C
	 * does not pass values by reference. When variables are passed,
	 * the parameters are copied into a new memory block which has
	 * its own independant memory address.
	 */

	return 0;
}

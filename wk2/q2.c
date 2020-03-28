

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c) {

	/* Swap the addresses stored in the pointer variables a and b */
	int *temp = a;
	a = b;
	b = temp;

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
	
	/* Print the values of x,y,z */
	printf("x: %i, y: %i, z: %i\n\n", x, y, z);
	
	/* Call foo() appropriately, passing x,y,z as params */ 
	z = foo(&x,&y,z);

	/* Print the values of x,y,z */
	printf("x: %i, y: %i, z: %i\n\n", x, y, z);

	/* Print the value returned by foo */
	printf("foo(int*,int*,int) --> %i\n", z);

	/*
	 * a) The return value is different than the  original 
	 * 	value of integer z because foo(..) makes a copy 
	 * 	of the variable z found in main() as a parameter, 
	 * 	decrements the value of the copy and returns 
	 * 	it as a reassignment to variable z in main().
	 *
	 * b) The values of integers x any y are not different 
	 * 	before and after calling foo() because the C 
	 * 	programming language does not pass values by 
	 * 	reference. Since foo() takes pointers 
	 *	as parameters for a memory block big enough to 
	 * 	hold an integer, only copies of the memory 
	 * 	addresses of x and y are changed in foo(), not 
	 * 	the values themselves contained in main().	
	 * */
	return 0;
}

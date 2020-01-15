/*******
 * CS261: Assignment 1 - Q.2
 * Name: Alvin Johns
 * Date: 01/13/20
 * Solution Desc: Demonstration file to display how swap pointer values 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int *a, int *b, int c) {

	//printf("a: %p, b: %p\n", a, b);

	int *temp = a;
	a = b;
	b = temp;
	temp = NULL;
	c -= 1;

	//printf("a: %p, b: %p\n", a, b);

	return c;
}

int main(int some, char ** thing) {

	srand(time(NULL));

	int x = rand() % 11;
	int y = rand() % 11;
	int z = rand() % 11;

	// print the addresses
	// printf("addresses of x and y: %p %p\n", &x, &y);

	// print the values
	printf("x: %d, y: %d, z: %d\n", x, y, z);

	// call foo to swap
	z = foo(&x, &y, z);

	// print the addresses
	// printf("addresses of x and y: %p %p\n", &x, &y);

	// print the values
	printf("x: %d, y: %d, z: %d\n", x, y, z);

	// print the value returned by foo
	printf("foo(..): %d\n", z);

	return 0;
}

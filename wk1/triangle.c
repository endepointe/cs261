/***************************************************************************
** Filename: triangle.c
** Author: Alvin Johns
** Date: January 8, 2020
** Desc: This program will calculate the area of a triangle using
	Heron's formula.
** Input: None at command line
** Output: The area of a triangle
***************************************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc, char** arv) {

	float a = 4;
	float b = 13;
	float c = 15;
	float s = (a + b + c) / 2;
	float area = sqrtf( s * (s-a) * (s-b) * (s-c) );

	printf("s is: %f\n", s);
	printf("area is: %f\n", area);


	return 0;
}

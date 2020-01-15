/*******
 * CS261: Assignment 1 - Q.3
 * Name: Alvin Johns
 * Date: 01/13/20
 * Solution Desc: Demonstrate how to manipulate a string of alphanumeric
 * 	letters to form a camelCase output
 * */

#include <stdio.h>
#include <stdlib.h>

/* lower case is from 97 to 122
 * upper case is from 65 to 90
 */

char toUpperCase(char ch) {

	if ( (ch > 96) && (ch < 123) ) {
		ch -= 32;
	}	

	return ch;
}

char toLowerCase(char ch) {

	if ( (ch > 64) && (ch < 91) ) {
		ch += 32;
	}

	return ch;
}

int stringLength(char s[]) {

	int length = 0;

	while (s[length] != '\0') {
		length++;
	}

	return length;
}

void camelCase(char* word) {

	/* if the index of the word is lowercase and it is the first
	 * index of the word, keep the index a lower case.
	 *
	 * if the index of the word is not the first letter of the 
	 * word and the letter follows and underscore, ignore the 
	 * underscore and convert the character to uppercase
	 */

	int len = stringLength(word);
	int count = 0;

	for (int i = 0; i < len; ++i) {
		if ( (word[i] < 65'_') && (word[i] > 90) 
		  || (word[i] < 97') && (word[i] > 90)
		  || (word[i] < 65'_') && (word[i] > 90) ) {
			len++;
			word[i] = word[i+1];
			i++;
		}		
	}

	// _something should converto to something
	// set pos n to pos n + 1
	// to prevent duplicates after the removal of the 
	// underscore, like ssomething, move n + 1 to the
	// position of i and decrement the length of the
	// string. 
	//
	// This may be an opportunity to create a recursive function.
	// but how...

	printf("underscore should be removed ... %s\n", word);
}

int main(int some, char ** thing) {

	//char a;
	char str[256];

	/*
	printf("Please enter a lowercase character value: ");
	scanf("%c", &a);

	a = toUpperCase(a);

	printf("a should be uppercase - %c\n", a);

	printf("Please enter a string if characters: ");

	scanf("%s", str);

	printf("The length of characters entered is %d\n", stringLength(str));
	*/

	printf("Please enter a string of characters(with undercore): ");

	scanf("%s", str);

	camelCase(str);


	return 0;
}

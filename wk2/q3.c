/*******
 * CS261: Assignment 1 - Q.3
 * Name: Alvin Johns
 * Date: 01/13/20
 * Solution Desc: Demonstrate how to manipulate a string of alphanumeric
 * 	letters to form a camelCase output
 *
 * 	lower case is from 97 to 122
 * 	upper case is from 65 to 90
 *
 * */

#include <stdio.h>
#include <stdlib.h>

char toUpperCase(char ch) {

	if ( (ch > 96) && (ch < 123) ) { ch -= 32; }	

	return ch;
}

char toLowerCase(char ch) {

	if ( (ch > 64) && (ch < 91) ) { ch += 32; }

	return ch;
}

int stringLength(char s[]) {

	int length = 0;

	while (s[length] != '\0') { length++; }

	return length;
}

/* Todo: 
 * 	- get the length of string
 * 	- convert the entire string to lowercase
 * 	- check the first character of current string 
 * 		to see if it is an underscore
 * 	- if it is an underscore, call a function to 
 * 		create and return a new string to be parsed 
 * 		by camelCase(...) again. 
 * */

int isAlphaChar(char ch) {

	int result = -1;

	if ( (ch > 64)  && (ch < 91) ) {
		result = 1;
	} 
	
	if ( (ch > 96)  && (ch < 123) ) {
		result = 1;
	}

	return result;
}

void camelCase(char* word) {
	
	int length = stringLength(word);
	// pos is used for memory of alphetical char
	int pos = 0;
	// index is used for the final assignment of camelCase chars
	int index = 0;
	// str is dynamically allocated and free after its use of 
	// 	final string seen below
	char *str = malloc( (length+1) * sizeof(char));

	// get the entire length of initial, unformatted string
	for (int i = 0; word[i] != '\0'; i++) {
		str[i] = toLowerCase(word[i]);	

		// set any chars at index > 0 to _ for future parsing
		if (i > 0) {
			if ((str[i-1] != '_') && (isAlphaChar(str[i-1]) < 0)) {
				str[i-1] = '_';
			}
		}

		// once parsed to _, convert char at i+1 to upper case
		if ( str[i-1] == '_') {
			if ( isAlphaChar(str[i]) > 0 ) {
				str[i] = toUpperCase(str[i]);
			}
		}
	}


	// final parsing of all alphabetical chars 
	// 	using index and pos accordingly
	while (pos < length) {
		if (isAlphaChar(str[pos]) > 0) {
			str[index] = str[pos];
			index++;		
		}	
		pos++;
	}

	// Possibly could have used malloc here, which I did prior
	// 	to assigning a static array. 
	// 	However, doing so produced same result.
	char final[index];

	for (int i = 0; i < index; ++i) {
		final[i] = str[i];
	}
	
	final[index] = '\0';
	final[0] = toLowerCase(final[0]);

	// free unneeded array block
	free(str);

	printf("final: %s\n", final);

}


int main(int some, char ** thing) {

	char str[256];
	//char str[256] = "__FOUR_FIVE sIX SeveN_@_Eight_$NiNe";

	printf("Enter a string of letters: \n");

	fgets(str, 256, stdin);

	camelCase(str);

	return 0;
}

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

// camelCase contains 2 loops for O(n) time complexity where n is the
// length of the word.
//
void camelCase(char* word) {
	
	int length = stringLength(word);

	// pos is used for location of alphetical char
	int pos = 0;

	// index is used for the final assignment of camelCase chars
	int index = 0;

	// tempStr is dynamically allocated and freed after its use of 
	// 	final string seen below
	char *tempStr = malloc( (length+1) * sizeof(char));

	// get the entire length of initial, unformatted string
	// and set to lowercase for simplicity
	for (int i = 0; word[i] != '\0'; i++) {
		tempStr[i] = toLowerCase(word[i]);	

		// set any chars at index > 0 that are not an _ or char
		// in the alphabet to _ for future parsing
		if (i > 0) {
			if((tempStr[i-1]!='_')&&(isAlphaChar(tempStr[i-1])<0)){
				tempStr[i-1] = '_';
			}
		}

		// once parsed to _, convert char at i to upper case by 
		// checking that the previous char is an underscore.
		if (tempStr[i-1] == '_') {
			if ( isAlphaChar(tempStr[i]) > 0 ) {
				tempStr[i] = toUpperCase(tempStr[i]);
			}
		}
	}


	// final parsing of all alphabetical chars 
	// 	using index and pos accordingly
	while (pos < length) {
		if (isAlphaChar(tempStr[pos]) > 0) {
			tempStr[index] = tempStr[pos];
			index++;		
		}	
		pos++;
	}

	char *final = malloc((index+1) * sizeof(char));

	for (int i = 0; i < index; ++i) {
		final[i] = tempStr[i];
	}
	
	final[index] = '\0';
	final[0] = toLowerCase(final[0]);

	// free unneeded array block
	free(tempStr);

	printf("camelCase(...) prints: %s\n", final);

	// Until camelCase is supposed to return the char*, 
	// free the final array block.
	free(final);
}


int main(int some, char ** thing) {

	// ***********	
	// For quick checking, uncomment and comment apporpriate lines
	// ***********	

	///*	
	char str[256] = "_random_ _word_provided@$ptr*4con_ran dom word example word ANOTHER_Word";
	//*/

	/*
	char str[256];

	printf("Enter a string of letters: ");

	fgets(str, 256, stdin);
	*/

	camelCase(str);

	return 0;
}

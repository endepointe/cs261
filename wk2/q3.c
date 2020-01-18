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

/* lower case is from 97 to 122
 * upper case is from 65 to 90
 */

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
	int pos = 0;
	int index = 0;
	char *str = malloc( (length+1) * sizeof(char));

	for (int i = 0; word[i] != '\0'; i++) {
		str[i] = toLowerCase(word[i]);	
		// if the char at i is an underscore and 
		// 	the char at i+1 is between 97-122
		//	then convert char at i+1 to an uppercase.
		//	increment i by 2.
		
		if ((str[i] == '_') && ((str[i+1] > 96) && (str[i+1] < 123))) {
			str[i+1] = toUpperCase(str[i+1]);
			i = i + 2;
		}
	}

	while (pos < length) {
		if (isAlphaChar(str[pos]) > 0) {
			printf("%c position %i\n", str[pos], pos);	
			str[index] = str[pos];
			index++;		
		}	
		pos++;
	}

	char final[index];

	for (int i = 0; i < index; ++i) {
		final[i] = str[i];
	}
	
	final[index] = '\0';
	free(str);

	printf("The string entered is: %s\n", str);
	printf("pos: %i , index: %i\n", pos, index);
	printf("final: %s\n", final);
}


int main(int some, char ** thing) {

	//char str[256];
	char str[256] = "__FOUR_FIVE sIX SeveN_@_Eight_$NiNe";

	printf("Enter a string of letters: \n");

	//fgets(str, 256, stdin);

	camelCase(str);

	return 0;
}

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

void camelCase(char* word) {

	int len = stringLength(word);
	int count = 0;
	char temp[len + 1];

	printf("The length of the string is %d\n", len);

	for (int i = 0; i < len; ++i) {
		temp[i] = word[i];
		if (word[i] == '_') {		
			count++;
		}
	}

	printf("%d underscores should be removed ... %s\n", count, temp);
}

int main(int some, char ** thing) {

	char str[256];

	printf("Enter a string of letters: ");

	scanf("%s", str);

	camelCase(str);

/*
	printf("Enter a string of lowercase letters: ");

	scanf("%s", str);

	for (int i = 0; i < stringLength(str); ++i) {
		str[i] = toUpperCase(str[i]);
	}

	printf("After uppercase conversion: %s\n", str);

	printf("Enter a string of uppercase letters: ");

	scanf("%s", strl);

	for (int i = 0; i < stringLength(strl); ++i) {
		strl[i] = toLowerCase(strl[i]);
	}

	printf("After lowercase conversion: %s\n", strl);
*/

	return 0;
}

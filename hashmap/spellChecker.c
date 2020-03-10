#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);

    while (1)
    {
       	int c = fgetc(file);

        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
	assert(map != NULL);
	char *str = nextWord(file);

	while (str) {
		hashMapPut(map, str, HASH_FUNCTION(str));
		free(str);
		str = nextWord(file);
	}

	free(str);
}

/* Checks the distance between the two strings with an internal function
 * called distance.
 *
 * The lower the return value, the greater the similarity between the
 * two strings.
 *
 * @param s1 is the key
 * @param s2 is the string representing the closest string to the key.
 * Referenced https://en.wikipedia.org/wiki/Levenshtein_distance
 */
int spellCheck(const char *source, const char *target) 
{
	int sourceLength = strlen(source);
	int targetLength = strlen(target);

	// Holds the distance between the two strings.
	int mtx[sourceLength + 1][targetLength + 1];

	// Set each element in matrix, mtx, to zero
	for (int i = 0; i < sourceLength + 1; ++i) {
		for (int j = 0; j < targetLength + 1; ++j) {
			mtx[i][j] = 0;
		}
	}

	int distance(int i, int j) {
		if (mtx[i][j] > 0) { 
			return mtx[i][j]; 
		}
		
		int editCost;

		if (i == sourceLength) { 
			editCost = targetLength - j;
		} else if (j == targetLength) {
			editCost = sourceLength - i;	
		} else if (source[i] == target[i]) {
			editCost = distance(i + 1, j + 1);	
		} else { 
			editCost = distance(i + 1, j + 1);
			editCost++; 
		}

		mtx[i][j] = editCost;

		return mtx[i][j];
	}

	return distance(0,0);
}

/**
 * Checks the spelling of the word provded by the user. If the word is spelled incorrectly,
 * print the 5 closest words as determined by a metric like the Levenshtein distance.
 * Otherwise, indicate that the provded word is spelled correctly. Use dictionary.txt to
 * create the dictionary.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(977);
	
	//FILE* file = fopen("test.txt", "r");
   	FILE* file = fopen("dictionary.txt", "r");
	assert(file != NULL);
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);

	//hashMapPrint(map);

	printf("%i empty buckets. \n", hashMapEmptyBuckets(map));
	printf("%f = load factor. \n", hashMapTableLoad(map));

    char inputBuffer[256];
    int quit = 0;
	int s;
	HashLink *link;
	HashLink **arr = malloc(sizeof(char*) * 5);

    while (!quit)
    {
     	printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);

		for (int i = 0; i < strlen(inputBuffer); ++i) {
			inputBuffer[i] = tolower(inputBuffer[i]);
		}

        // Implement the spell checker code here..

		if (hashMapContainsKey(map, inputBuffer)) {
			s = HASH_FUNCTION(inputBuffer) % hashMapCapacity(map);
			link = map->table[s];
			while (link) {
				if (strcmp(inputBuffer, link->key) == 0) {
					printf("The inputted word '%s' ", link->key);	
					printf(" is spelled correctly.\n");
					break;
				}
				link = link->next;
			}	
		} else {
			printf("The inputted word ");
			printf("%s is spelled incorrectly.\n", inputBuffer);
			printf("Did you mean ______ ? \n");

			int count = 0;
			HashLink *curr;

			for (int i = 0; i < hashMapCapacity(map); ++i) {
				curr = map->table[i];
				if (curr != NULL) {
					while (curr) {
					  hashMapPut(map,curr->key,spellCheck(inputBuffer,curr->key));
						if (count > 5) {
							break;
						} else if (spellCheck(inputBuffer, curr->key) == 1 
					  	  && count < 5) {
							arr[count] = malloc(sizeof(char)*strlen(curr->key));
							arr[count]->key = curr->key;
							count++;
						} else if (spellCheck(inputBuffer, curr->key) == 2 
						  && count < 5) {
							arr[count] = malloc(sizeof(char)*strlen(curr->key));
							arr[count]->key = curr->key;
							count++;
						} else if (spellCheck(inputBuffer, curr->key) == 3 
						  && count < 5) {
							arr[count] = malloc(sizeof(char)*strlen(curr->key));
							arr[count]->key = curr->key;
							count++;
						}/* else if (spellCheck(inputBuffer, curr->key) >= 4
						  && count < 5) {
							arr[count] = malloc(sizeof(char)*strlen(curr->key));
							arr[count]->key = curr->key;
							count++;
						} else if (spellCheck(inputBuffer, curr->key) == 5 
						  && count < 5) {
							arr[count] = malloc(sizeof(char)*strlen(curr->key));
							arr[count]->key = curr->key;
							count++;
						}
						*/
						curr = curr->next;
					}
				}
			}
		
			printf("count is %i\n", count);	
			for (int i = 0; i < 5; i++) {
				///*
				if (arr[i] == NULL) {
					arr[i] = malloc(sizeof(char) * 10);
					arr[i]->key = "No match\0";	
				}	
				//*/
				printf("	- %s, %i\n", arr[i]->key, arr[i]->value);
				//free(arr[i]);
			}
			free(arr);
		}			

        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
   	}

    hashMapDelete(map);

    return 0;
}

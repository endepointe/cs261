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
	//printf("%s \n", str);

	while (str) {
		hashMapPut(map, str, HASH_FUNCTION(str));
		free(str);
		str = nextWord(file);
	}

	free(str);
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
	
	FILE* file = fopen("test.txt", "r");
   	//FILE* file = fopen("dictionary.txt", "r");
	assert(file != NULL);
    clock_t timer = clock();
    loadDictionary(file, map);
	//hashMapPrint(map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);

	hashMapPrint(map);

	printf("%i empty buckets. \n", hashMapEmptyBuckets(map));
	printf("%f = load factor. \n", hashMapTableLoad(map));

    char inputBuffer[256];
    int quit = 0;
	int s;

    while (!quit)
    {
     	printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);

		for (int i = 0; i < strlen(inputBuffer); ++i) {
			inputBuffer[i] = tolower(inputBuffer[i]);
		}

		printf("%i\n", HASH_FUNCTION(inputBuffer) % hashMapCapacity(map) );

        // Implement the spell checker code here..

		if (hashMapContainsKey(map, inputBuffer)) {
			//s = (hashMapGet(map, inputBuffer));
			s = HASH_FUNCTION(inputBuffer) % hashMapCapacity(map);
			printf("Dictionary contains key: %i\n", s);	
			printf("Key: %s\n", map->table[s]->key);
		}			

        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
   	}

    hashMapDelete(map);

    return 0;
}

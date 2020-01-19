/*******
 * CS261: Assignment 1 - Q.1
 * Name: Alvin Johns
 * Date: 01/13/20
 * Solution Desc: Demonstration file to display how create and
 * 	manipulate a block of memory 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	return (struct student*)malloc(10 * sizeof(struct student));
}

void generate(struct student* students) {

	srand(time(NULL));	

	int studentCount = 10;
	int maxScore = 10;
	int size = maxScore + 1;
	int *scores = malloc((maxScore+1) * sizeof(int));
	int score = 0;
	int id = 0;

	for (int i = 0; i <= maxScore; ++i) {
		scores[i] = i;	
	}

	while (size != 0) {
		score = rand() % maxScore;
		id = rand() % studentCount + 1;	
	}

	for (int i = 0; i < studentCount; ++i) {
		students[i].id = i + 1;
		students[i].score = rand() % maxScore + 1;
	}
}

void output(struct student* students) {
	
	for (int i = 0; i < 10; ++i) {
		printf("ID:%d Score:%d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students) {
	int min = students[0].score;
	int max = students[0].score;
	int avg = 0;

	for (int i = 0; i < 10; ++i) {
		if (students[i].score <= min) {
			min = students[i].score;
		}

		if (students[i].score >= max) {
			max = students[i].score;
		}
		avg += students[i].score;
	}

	avg /= 10;

	printf("min score: %d\n", min);
	printf("max score: %d\n", max);
	printf("average score: %d\n", avg);

}

void deallocate(struct student* stud) {

	if (stud != NULL) {
		free(stud);
		stud = NULL;
	}

}

int main(int some, char ** thing) {
	
	struct student *class = allocate();	

	//printf("student mem: %p\n", class);

	generate(class);
	output(class);
	summary(class);
	deallocate(class);

	return 0;
}

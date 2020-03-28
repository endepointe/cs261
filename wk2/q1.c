

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

void swap(int* a, int* b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void generate(struct student* students) {

	srand(time(NULL));	

	int studentCount = 10;
	int maxScore = 100;
	int *scores = malloc((maxScore+1) * sizeof(int));
	int temp;

	// fill in the scores for future randomization
	for (int i = 0; i <= maxScore; i++) {
		scores[i] = i;
	}

	// fill in the ids for future randomization
	for (int i = 0; i < studentCount; ++i) {
		students[i].id = i+1;
	}

	// randomize the student scores (fisher-yates)
	for (int i = 0; i <= maxScore; i++){
		temp = rand() % maxScore;
		swap(&scores[i], &scores[temp]);
	}

	// randomize the student ids (fisher-yates)
	// and assign the first [studentCount] random scores
	for (int i = 0; i < studentCount; i++){
		temp = rand() % studentCount;
		swap(&students[i].id, &students[temp].id);
		students[i].score = scores[i];
	}

/*
	for (int i = 0; i < studentCount; ++i) {
		printf("students[%i].id = %i\n", i, students[i].id);
		students[i].score = scores[i];
		printf("students[%i].score = %i\n", i,students[i].score);
	}
*/
	free(scores);
}

void output(struct student* students) {
	
	for (int i = 0; i < 10; ++i) {
		printf("ID:%d Score:%d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students) {
	int min = students[0].score;
	int max = students[0].score;
	float avg = 0;

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

	printf("\n\n==SCORES==\n");
	printf("Minimum: %i\n", min);
	printf("Maximum: %i\n", max);
	printf("Average: %.2f\n", avg);
	printf("==========\n\n");

}

void deallocate(struct student* stud) {

	if (stud != NULL) {
		free(stud);
		stud = NULL;
	}

}

int main(int some, char ** thing) {
	
	struct student *class = allocate();	

	generate(class);
	output(class);
	summary(class);
	deallocate(class);

	return 0;
}

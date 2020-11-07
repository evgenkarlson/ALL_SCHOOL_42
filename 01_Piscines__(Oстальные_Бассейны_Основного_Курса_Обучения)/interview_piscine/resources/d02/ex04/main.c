#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	unsigned char *utensils;
	int n = 1000;
	utensils = genRandomUstensils(&n); //if param == 0, the length of the list will be random between 1 and 1 million

	/*-------------------
	launch your test here
	--------------------*/
	printUtensils(utensils, n);

	//printf("sorting using count sort...\n");
	//countSort(utensils, n);

	//printUtensils(utensils, n);

	return (0);
}



// Function used for the test
// Don't go further :)

void printUtensils(unsigned char *utensils, int n)
{
	int order = 1;
	printf("{ ");
	for (int i = 0; i < n; i++){
		printf("%d%s", utensils[i], (i + 1 < n) ? ", " : " ");
		if (i >= 1 && utensils[i - 1] > utensils[i])
			order = 0;
	}
	printf("} (%s)\n", (order) ? "sorted" : "not sorted");
}


#define NUMBER_OF_USTENSILS 15

unsigned char *genRandomUstensils(int *n)
{
	unsigned char *utensils;

	srand(time(NULL));
	if ((*n) <= 0 || (*n) > 1000000000){
		(*n) = rand() % 1000000 + 1; //generating int between 1 and 1.000.000
	}
	utensils = malloc(sizeof(unsigned char) * (*n));
	for (int i = 0; i < (*n); i++){
		utensils[i] = rand() % NUMBER_OF_USTENSILS + 1;
	}
	return (utensils);
}

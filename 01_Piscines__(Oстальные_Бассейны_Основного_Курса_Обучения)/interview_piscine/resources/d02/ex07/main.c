#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	int n;
	int *ages;

	srand(time(NULL));
	n = rand() % 80 + 5;
	ages = createRandomArray(n);

	/*-------------------
	launch your test here
	--------------------*/

	printArray(ages, n);
	// printYoungest(ages, n);

	return (0);
}



// Function used for the test
// Don't go further :)

int randomAge(void) {
	return (rand() % 120 + 10);
}

int *createRandomArray(int n) {
	int *arr;

	if (!(arr = (int *)(malloc(sizeof(int) * n))))
		return (NULL);
	for (int i = 0; i < n; i++) {
		arr[i] = randomAge();
	}
	return (arr);
}

void printArray(int *arr, int n) {
	printf("Ages : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
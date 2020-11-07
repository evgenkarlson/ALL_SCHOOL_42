#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int elements;
	int minPercentage;

	if (ac >= 3){
		elements = atoi(av[1]);
		minPercentage = atoi(av[2]);
	}
	else {
		printf("Usage: ./minPersons elements minPercentage\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	// printf("%d\n", minPersons(elements, minPercentage));

	return (0);
}


// Function used for the test
// Don't go further :)


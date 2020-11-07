#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int a = 0;
	int b = 0;

	if (ac == 3) {
		a = atoi(av[1]);
		b = atoi(av[2]);
	}
	else {
		printf("Usage: ./isEqual a b (where a and b are integer)\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	printf("%d\n", isEqual(a, b));

	return (0);
}



// Function used for the test
// Don't go further :)


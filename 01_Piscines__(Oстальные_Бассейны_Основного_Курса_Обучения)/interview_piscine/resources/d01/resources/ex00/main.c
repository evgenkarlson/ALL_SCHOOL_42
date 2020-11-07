#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int *input;
	int size;

	//reading the input and putting it in an array of int
	size = ac - 1;
	if (!(input = (int *)malloc(sizeof(int) * (size + 1))))
		return (-1);
	for (int i = 0; i < size; i++) {
		input[i] = atoi(av[i + 1]);
	}
	input[size] = 0;

	/*-------------------
	launch your test here
	--------------------*/
	// printf("%s\n", precious(input, size));
	return (0);
}



// Function used for the test
// Don't go further :)

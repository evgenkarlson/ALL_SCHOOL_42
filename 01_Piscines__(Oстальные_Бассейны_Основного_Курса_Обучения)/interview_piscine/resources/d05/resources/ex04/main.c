#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	char *word = NULL;

	if (ac >= 2){
		word = av[1];
	}

	/*-------------------
	launch your test here
	--------------------*/
	// printPermutations(word);

	return (0);
}



// Function used for the test
// Don't go further :)


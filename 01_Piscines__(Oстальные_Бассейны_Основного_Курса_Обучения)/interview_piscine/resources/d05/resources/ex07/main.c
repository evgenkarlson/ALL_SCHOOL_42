#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	char *sequence = NULL;
	char *palindrome;
	int nDelete = 0;

	if (ac >= 2)
		sequence = av[1];
	if (ac >= 3)
		nDelete = atoi(av[2]);
	palindrome = NULL;

	/*-------------------
	launch your test here
	--------------------*/
	
	// palindrome = findPalindrome(sequence, nDelete);
	// if (palindrome)
	// 	printf("%s\n", palindrome);
	
	return (0);
}



// Function used for the test
// Don't go further :)

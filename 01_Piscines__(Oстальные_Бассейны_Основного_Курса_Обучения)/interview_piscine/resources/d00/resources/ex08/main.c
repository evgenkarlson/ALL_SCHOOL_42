#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	/*-------------------
	launch your test here
	--------------------*/
	if (ac >= 3) {
		//do your stuff
		printf("most closest word: %s\n", whatWasThat(av[1], av + 2));
	} else {
		printf("usage: ./whatWasThat word   dict1 dict2 dict3 ...\n");
	}
	return (0);
}



// Function used for the test
// Don't go further :)


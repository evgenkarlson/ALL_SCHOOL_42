#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

#define PLACES_ROW 20

int main(int ac, char **av)
{
	unsigned int parkingRow;
	int n;

	if (ac == 3 && (n = atoi(av[2])) >= 0 && n < PLACES_ROW) {
		parkingRow = atoi(av[1]);
	}else{
		printf("usage: ./clearBits parkingRow n\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/

	printf("Cleared parking row: %d\n", clearBits(parkingRow, n));

	return (0);
}



// Function used for the test
// Don't go further :)


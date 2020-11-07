#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	unsigned int parkingRow;
	int pos;

	if (ac == 3 && (pos = atoi(av[2])) >= 0 && pos < 20) {
		parkingRow = atoi(av[1]);
	}else{
		printf("usage: ./clearPlace parkingRow pos\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/

	printf("New parking row: %d\n", clearPlace(parkingRow, pos));

	return (0);
}



// Function used for the test
// Don't go further :)


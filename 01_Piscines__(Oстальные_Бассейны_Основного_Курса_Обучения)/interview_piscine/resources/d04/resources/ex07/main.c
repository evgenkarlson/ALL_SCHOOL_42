#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	unsigned int parkingRow;
	int pos;
	int value;

	if (ac == 4 && (pos = atoi(av[2])) >= 0 && pos < 20) {
		parkingRow = atoi(av[1]);
		value = atoi(av[3]);
	}else{
		printf("usage: ./updatePlace parkingRow pos value\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/

	printf("Updated parking row: %d\n", updatePlace(parkingRow, pos, value));

	return (0);
}



// Function used for the test
// Don't go further :)


#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int i, j, n, pos;
	double prob;
	uint64_t board;

	if (ac != 4) {
		printf("usage: %s i j n\n", av[0]);
		return (EXIT_FAILURE);
	}
	i = atoi(av[1]);
	j = atoi(av[2]);
	n = atoi(av[3]);

	if (i < 0 || i >= WIDTH || j < 0 || j >= WIDTH)
		return (EXIT_FAILURE);

	pos = i * WIDTH + j;
	board = (1ULL << pos);
	printBoard(board);
	prob = 0;

	/*-------------------
	launch your test here
	--------------------*/

	// prob = knightOut(board, n);
	// printf("Probability knight out in %d move(s) : %.10f\n", n, prob);

	return (0);
}



// Function used for the test
// Don't go further :)

int getBit(uint64_t board, int pos) {
	return ((board & (1ULL << pos)) != 0);
}

void printBoard(uint64_t board) {
	int pos;

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < WIDTH; j++) {
			pos = i * WIDTH + j;
			printf("%d ", getBit(board, pos));
		}
		printf("\n");
	}
}
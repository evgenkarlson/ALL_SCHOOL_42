#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int nStairs;
	int nPunch;
	int nephewStair;

	if (ac >= 4){
		nStairs = atoi(av[1]);
		nPunch = atoi(av[2]);
		nephewStair = atoi(av[3]);
	}
	else {
		printf("Usage: ./helpNephew nStairs nPunch nephewStair\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	// printf("%.2lf\n", probaNephewWillLive(nStairs, nPunch, nephewStair));

	return (0);
}



// Function used for the test
// Don't go further :)


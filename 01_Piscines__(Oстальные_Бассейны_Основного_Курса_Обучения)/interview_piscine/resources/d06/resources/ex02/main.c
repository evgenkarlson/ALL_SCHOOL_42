#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	double initDollars = 0.0;
	double desiredDollars = 0.0;
	int nbGame = 0;
	
	if (ac >= 4){
		initDollars = atof(av[1]);
		desiredDollars = atof(av[2]);
		nbGame = atoi(av[3]);
	}
	else{
		printf("Usage: ./roulette initDollars desiredDollars nbGame\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	// printf("%lf\n", probabilityWin(initDollars, desiredDollars, nbGame));
	return (0);
}



// Function used for the test
// Don't go further :)


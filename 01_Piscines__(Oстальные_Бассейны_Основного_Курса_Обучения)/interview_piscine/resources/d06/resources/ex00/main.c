#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int *arr;
	int n;
	int dist;

	if (ac >= 4){
		dist = atoi(av[1]);
		n = ac-2;
		arr = malloc(sizeof(int) * (n));
		for (int i = 2; i < ac; i++){
			arr[i-2] = atoi(av[i]);
		}
	}
	else {
		printf("Usage: ./distance dist nb1 nb2 ...\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	//printf("%lf\n", probaDistance(dist, arr, n));

	return (0);
}



// Function used for the test
// Don't go further :)


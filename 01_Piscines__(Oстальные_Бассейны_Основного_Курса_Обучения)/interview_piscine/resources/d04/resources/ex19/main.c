#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int *arr = NULL;
	int n = 0;

	if (ac >= 2) {
		n = ac-1;
		arr = malloc(sizeof(int) * n);
		for (int i = 0; i+1 < ac; i++){
			arr[i] = atoi(av[i+1]);
		}
	}
	else{
		printf("Usage: ./aloneCan n1 n2 n3 ... (where n* are integer)\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	//aloneCan(arr, n);

	return (0);
}



// Function used for the test
// Don't go further :)


#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	char *a;
	char *b;

	if (ac == 4 && strcmp(av[2], "+") == 0
		&& strlen(av[1]) == 6 && strlen(av[3]) == 6
		&& checkBinary(av[1]) && checkBinary(av[3])) {
		a = av[1];
		b = av[3];
	}else{
		printf("Usage: ./sum 000010 + 000001\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	//char *sum;

	//sum = getSum(a, b);
	//printf("%s (%d)\n", sum, toInt(sum));

	return (0);
}



// Function used for the test
// Don't go further :)

int checkBinary(char *str) {
	int i = 0;

	while (str[i]) {
		if (str[i] != '0' && str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	char	magic[10];
	int		n;
	int		white;
	int		**pic;
	
	if (ac != 2){
		printf("Usage: ./rotate image.pgm\n");
		return (0);
	}
	if (!(pic = import_pgm(av[1], magic, &n, &white))){
		printf("Error: Bad format\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	rotate(pic, n);
	print_pgm(pic, magic, n, white);

	return (0);
}



// Function used for the test
// Don't go further :)

int		**import_pgm(char *file, char *magic, int *n, int *white)
{
	int		**pic;
	FILE	*f;
	int		w;

	f = fopen(file, "r");
	fscanf(f, "%s\n", magic);
	fscanf(f, "%d %d\n", n, &w);
	if (w != *n)
		return (NULL);
	fscanf(f, "%d\n", white);
	if (!(pic = (int **)malloc(sizeof(int *) * *n)))
		return (NULL);
	for (int i = 0; i < *n; i++) {
		if (!(pic[i] = (int *)malloc(sizeof(int) * *n)))
			return (NULL);
		for (int j = 0; j < *n; j++) {
			fscanf(f, "%d", &(pic[i][j]));
		}
	}
	return (pic);
}

void	print_pgm(int **pic, char *magic, int n, int white)
{
	printf("%s\n", magic);
	printf("%d %d\n", n, n);
	printf("%d\n", white);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", pic[i][j]);
			printf((j ==  n - 1) ? "\n" : " ");
		}
	}

}

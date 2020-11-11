#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gold_gain.c"

//Reference code (passed Moulinette 2019.05.14)
int	ref_max_three(int a, int b, int c)
{
	if (a > b)
		return ((a > c) ? a : c);
	else
		return ((b > c) ? b : c);
}

int	ref_gold_gain(int **mine, int n)
{
	int row;
	int col = 1;
	int max = 0;

	while (col < n)
	{
		row = 0;
		while (row < n)
		{
			mine[row][col] += max_three(
					((row > 0) ? mine[row - 1][col - 1] : 0),
					mine[row][col - 1],
					((row < n - 1) ? mine[row + 1][col - 1] : 0)
				);
			if (col == n - 1 && max < mine[row][col])
				max = mine[row][col];
			row++;
		}
		col++;
	}
	return (max);
}

//Test main
int	main(int ac, char **av)
{
	int size = 1000;
	if (ac > 1)
	{
		size = atoi(av[1]);
		if (size < 3)
		{
			printf("Invalid size; defaulting to 1000\n");
			size = 1000;
		}
	}
	else
		printf("Defaulting to size=1000 (specify with '%s [number]')\n", av[0]);

	srand(time(NULL));
	int **mine = malloc(sizeof(int *) * size);
	int **ref_mine = malloc(sizeof(int *) * size);
	int i = -1;
	int j;
	while (++i < size)
	{
		j = -1;
		mine[i] = malloc(sizeof(int) * size);
		ref_mine[i] = malloc(sizeof(int) * size);
		while (++j < size)
			mine[i][j] = ref_mine[i][j] = rand();
	}

	printf("gold gain, %d x %d:\n", size, size);
	printf("   Test: %d\n", gold_gain(mine, size));
	printf("   Real: %d\n", ref_gold_gain(ref_mine, size));
}
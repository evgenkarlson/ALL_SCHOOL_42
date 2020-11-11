# gold_gain

## Conceptual Overview
### The Problem

We are asked to write a function that takes arguments of a square 2-dimensional array of integers, and an integer representing the dimensions of the array. It calculates and prints the largest possible sum of numbers on a path through the array according to the following rules: Starting at any point in the leftmost column, add one number from each column to the sum. Each step must travel one column to the right, and may travel one row up, one row down, or stay on the same row. All values will be positive or 0, and the solution must run in less than 2 seconds on a 1,000 x 1,000 array.

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : gold_gain
	Expected files   : gold_gain.c
	Allowed functions: malloc
	--------------------------------------------------------------------------------

	ALERT: OPTIMIZED SOLUTION REQUIRED.

	Given a matrix which represent a gold mine of n*n dimensions.
	Each field in this mine contains a positive integer which is the
	amount of gold in tons.

	Initially the miner is at first column but can be at any row.

	He can move only (right->,right up /,right down\) that is from a given cell,
	the miner can move to the cell diagonally up towards the right or right or
	diagonally down towards the right.

	implement an algorithm able to return the maximum amount of gold he can collect.

	The function must be declared as follows:

	int	gold_gain(int **mine, int n);

	Considerations:

	- Be careful: the brute force solution won't work on our big input, you have to
	find an optimized solution which use dynamic programming.
	- You don't have to handle error case, the matrix will be always squared.
	- The bigger test we will do is on matrix of 1 000 * 1 000,
	it should run in less than 2 seconds.

	Example 1:

	mine = [
	  [ 1, 0, 0 ],
	  [ 0, 3, 4 ],
	  [ 0, 0, 0 ]
	]

	n = 3

	In this example, your function should return 8,
	because taking the following path gain 8:
	(0,0) -> (1,1) -> (1,2)
	  1   ->   3   ->   4

	Example 2:

	mine = [
	  [ 1, 2, 3 ],
	  [ 3, 4, 8 ],
	  [ 9, 6, 7 ]
	]

	n = 3

	In this example, your function should return 23,
	because taking the following path gain 23:
	(2,0) -> (2,1) -> (1,3)


	Example 3:

	mine = [
	  [ 1, 3, 1, 5 ],
	  [ 2, 2, 4, 1 ],
	  [ 5, 0, 2, 3 ],
	  [ 0, 6, 1, 2 ]
	]

	n = 4

	In this example, your function should return 16,
	because there is 2 path which give this gain:
	(2,0) -> (1,1) -> (1,2) -> (0,3)
	or
	(2,0) -> (3,1) -> (2,2) -> (2,3)
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [gold_gain.c](gold_gain.c)
* [test_gold_gain.c (test main)](test_gold_gain.c)

### Approach

Starting in the second column, for each location in the column, take the largest of the numbers at the three adjacent locations in the previous column and add it to the number at the current location, updating the value at the current location to the result. Repeat for each column. While filling the last column, keep track of the largest value in the column. Print this value as the result.

### Code

```C
int	max_three(int a, int b, int c)
{
	if (a > b)
		return ((a > c) ? a : c)
	else
		return ((b > c) ? b : c)
}

int	gold_gain(int **mine, int n)
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
```

### Test Main
```C
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
```
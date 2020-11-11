// Passed Moulinette 2019.09.01

int	max_three(int a, int b, int c)
{
	if (a > b)
		return ((a > c) ? a : c);
	else
		return ((b > c) ? b : c);
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
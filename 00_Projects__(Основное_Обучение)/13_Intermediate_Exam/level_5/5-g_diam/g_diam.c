// Passed Moulinette 2019.09.01

#include <unistd.h>
#include <stdlib.h>

#define ISNUM(n) (n >= '0' && n <= '9')

static int LONGEST_CHAIN;

int		ft_atoi(char *str)
{
	int n = 0;
	while (ISNUM(*str))
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);

	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int		find_max_int(char *str)
{
	int max = 0;
	int cur;
	while (*str)
	{
		while (*str && !ISNUM(*str))
			str++;
		if (*str)
		{
			cur = ft_atoi(str);
			if (cur > max)
				max = cur;
		}
		while (ISNUM(*str))
			str++;
	}
	return (max);
}

void	populate_arr(int **arr, char *str)
{
	int a;
	int b;
	while (*str)
	{
		a = ft_atoi(str);
		while (ISNUM(*str))
			str++;
		while (*str == '-')
			str++;
		b = ft_atoi(str);
		while (ISNUM(*str))
			str++;
		arr[a][b] = 1;
		arr[b][a] = 1;
		while (*str && !ISNUM(*str))
			str++;
	}
}

void	recur(int *visited, int **arr, int max, int row, int local_len)
{
	visited[row] = 1;
	int col = -1;
	while (++col <= max)
	{
		if (visited[col] == 0 && arr[row][col] != 0)
		{
			if (LONGEST_CHAIN <= local_len)
				LONGEST_CHAIN = local_len + 1;
			recur(visited, arr, max, col, local_len + 1);
		}
	}
	visited[row] = 0;
}

void	find_longest_chain(int *visited, int **arr, int max)
{
	LONGEST_CHAIN = 2;
	int row = -1;

	while (++row <= max)
		recur(visited, arr, max, row, 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		int max = find_max_int(av[1]);

		int **arr = malloc(sizeof(int *) * (max + 1));
		int *visited = malloc(sizeof(int) * (max + 1));
		int i = -1;
		int j;
		while (++i < max + 1)
		{
			visited[i] = 0;
			j = -1;
			arr[i] = malloc(sizeof(int) * (max + 1));
			while (++j < max + 1)
				arr[i][j] = 0;
		}

		populate_arr(arr, av[1]);
		find_longest_chain(visited, arr, max);
		ft_putnbr(LONGEST_CHAIN);
	}
	write(1, "\n", 1);
	return (0);
}
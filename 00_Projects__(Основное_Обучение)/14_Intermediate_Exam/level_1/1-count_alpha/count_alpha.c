// Passed Moulinette 2019.09.01

#include <stdio.h>

#define TO_LOWER(c) (((c) >= 'a') ? (c) : (c) + ('a' - 'A'))

void	print_count(char *str)
{
	char c = TO_LOWER(*str);
	int count = 0;

	while (*str)
	{
		if (TO_LOWER(*str) == c)
		{
			*str = ' ';
			count++;
		}
		str++;
	}
	printf("%d%c", count, c);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *str = av[1];
		int first = 1;
		while (*str)
		{
			if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			{
				if (first == 0)
					printf(", ");
				print_count(str);
				first = 0;
			}
			str++;
		}
	}

	printf("\n");
}
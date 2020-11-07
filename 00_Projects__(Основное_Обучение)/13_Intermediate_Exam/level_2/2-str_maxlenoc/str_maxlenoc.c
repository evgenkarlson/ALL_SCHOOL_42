// Passed Moulinette 2019.09.01

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		++i;
	return (i);
}

int	ft_strncmp(char *a, char *b, int len)
{
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		if (a[i] != b[i] || !a[i] || !b[i])
			return (0);
	}
	return (1);
}

// substrn checks if the first nlen characters of needle appear in the same
//	order anywhere in haystack. If they do, substrn returns 1, otherwise 0.
int	substrn(char *needle, int nlen, char *haystack)
{
	int hlen = ft_strlen(haystack);
	//At each starting index of the haystack, check if that part of the haystack
	//	matches the needle
	for (int i = 0; i + nlen <= hlen; ++i)
	{
		if (ft_strncmp(needle, haystack + i, nlen))
			return (1);
	}
	return (0);
}

void	str_maxlenoc(int ac, char **av)
{
	int success;
	int max_len = ft_strlen(av[0]);
	// For each length of substring of the 0th argument, starting with the max:
	for (int test_len = max_len; test_len > 0; --test_len)
	{
		// For each starting position in the 0th arg, starting with the 0th:
		for (int start = 0; start + test_len <= max_len; ++start)
		{
			success = 1;
			// For each other argument:
			for (int arg = 1; arg < ac; ++arg)
			{
				// The test string is the part of the 0th argument beginning
				//	at start, with a length of test_len.
				// Check if the test string is a substring of the current arg:
				if (substrn(av[0] + start, test_len, av[arg]) == 0)
					success = 0;
			}
			if (success == 1)
			{
				write(1, av[0] + start, test_len);
				return;
			}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		str_maxlenoc(ac - 1, &av[1]);
	write(1, "\n", 1);
}

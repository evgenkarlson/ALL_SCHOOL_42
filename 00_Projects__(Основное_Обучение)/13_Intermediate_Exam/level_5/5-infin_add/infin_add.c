// Passed Moulinette 2019.09.01

#include <unistd.h>
#include <stdlib.h>
#define ABS(V) (((V) < 0) ? -(V) : (V))

int		max_two(int a, int b)
{
	return (a > b ? a : b);
}

int		ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return (i);
}

int		ft_strcmp(char *a, char *b)
{
	int i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*init_str(char *a, char *b)
{
	int result_len = 1 + max_two(ft_strlen(a), ft_strlen(b));
	char *result = malloc(sizeof(char) * (result_len + 1));
	result[result_len] = '\0';
	return (result);
}

void	biggest_first(char **big, char **small)
{
	char *a = *big;
	char *b = *small;
	if (*a == '-')
		a++;
	if (*b == '-')
		b++;
	if ((ft_strlen(a) < ft_strlen(b)) \
		|| ((ft_strlen(a) == ft_strlen(b) && ft_strcmp(a, b) < 0)))
		{
			char *tmp = *big;
			*big = *small;
			*small = tmp;
		}
}

int		check_negative(char **a, char **b)
{
	int ret = 0;
	if ((**a == '-' && **b != '-') || (**a != '-' && **b == '-'))
		ret = 1;

	if ((**a == '-' && **b == '-') || (**a == '-' && **b != '-'))
		write(1, "-", 1);

	if (**a == '-')
		(*a)++;
	if (**b == '-')
		(*b)++;

	return (ret);
}

void	add(char *big, char *small, char *out)
{
	int b = ft_strlen(big) - 1;
	int s = ft_strlen(small) - 1;
	int i = ft_strlen(out);
	int carry = 0;

	while (b >= 0 || carry)
	{
		carry += big[b] - '0';
		if (s >= 0)
			carry += small[s] - '0';
		out[--i] = (carry % 10) + '0';
		carry /= 10;
		--b;
		--s;
	}
	ft_putstr(out + i);
}

void	subtract(char *big, char *small, char *out)
{
	int b = ft_strlen(big) - 1;
	int s = ft_strlen(small) - 1;
	int i = ft_strlen(out);
	int carry = 0;

	while (b >= 0)
	{
		carry += big[b] - '0';
		if (s >= 0)
			carry -= small[s] - '0';
		if (carry < 0)
		{
			carry -= 10;
			out[--i] = (10 - ABS(carry % 10)) + '0';
		}
		else
			out[--i] = carry % 10 + '0';
		carry /= 10;
			--b;
			--s;
	}
	ft_putstr(out + i);
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		biggest_first(&av[1], &av[2]);
		char *output = init_str(av[1], av[2]);
		if (check_negative(&av[1], &av[2]) == 1)
			subtract(av[1], av[2], output);
		else
			add(av[1], av[2], output);
		free(output);
	}
	write(1, "\n", 1);
}
// Passed Moulinette 2019.09.01

#include <unistd.h>
#include <stdlib.h>

int 	ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return (i);
}

char	*init_str(int len)
{
	char *str = malloc(sizeof(char) * (len + 1));
	int i = -1;
	while (++i < len)
		str[i] = '0';
	str[i] = '\0';
	return (str);
}

void	print_str(char *str, int len)
{
	int i = 0;
	while (i < len && str[i] == '0')
		i++;
	write(1, str + i, len - i);
}

void	input_result(int value, char *out, int i)
{
	int carry = 0;
	while (value > 0 || carry > 0)
	{
		i--;
		value += carry;
		carry = (value % 10) + (out[i] - '0');
		out[i] = (carry % 10) + '0';
		carry /= 10;
		value /= 10;
	}
}

void	infin_mult(char *a, char *b, char *out, int len)
{
	int len_a = ft_strlen(a);
	int ia = len_a;
	int len_b = ft_strlen(b);
	int ib;
	int result;
	int place_offset;

	while (--ia >= 0)
	{
		ib = len_b;
		while (--ib >= 0)
		{
			result = (a[ia] - '0') * (b[ib] - '0');
			// Calculate how many places to shift the result left when inputting
			place_offset = (len_a - ia - 1) + (len_b - ib - 1);
			input_result(result, out, len - place_offset);
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		char *a = av[1];
		char *b = av[2];

		if (*a == '0' || *b == '0')
		{
			write(1, "0\n", 2);
			return (0);
		}

		// Print '-' if exactly one of the numbers is negative
		if ((*a == '-' && *b != '-') || (*b == '-' && *a != '-'))
			write(1, "-", 1);
		if (*a == '-')
			a++;
		if (*b == '-')
			b++;

		// Output length can be up to 1 digit longer than sum of input lengths
		int len = 1 + ft_strlen(a) + ft_strlen(b);
		char *out = init_str(len);
		infin_mult(a, b, out, len);
		print_str(out, len);
		free(out);
	}
	write(1, "\n", 1);
	return (0);
}
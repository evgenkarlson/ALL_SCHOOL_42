// Passed Moulinette 2019.09.01

// Please hit me up if you have a shorter solution!

#include <unistd.h>
#include <stdlib.h>

#define TO_LOWER(c) ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c)

int		ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		count_words(char *str)
{
	int first_printable = 1;
	int word_count = 0;

	while (*str)
	{
		if (*str != ' ' && *str != '\t' && first_printable == 1)
		{
			word_count++;
			first_printable = 0;
		}
		else if (*str == ' ' || *str == '\t')
			first_printable = 1;
		str++;
	}
	return (word_count);
}

char	**get_words(char *str)
{
	int word_count = count_words(str);
	char **words = malloc(sizeof(char *) * (word_count + 1));
	words[word_count] = 0;

	int first_printable = 1;
	int i = -1;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && first_printable == 1)
		{
			words[++i] = str;
			first_printable = 0;
		}
		else if (*str == ' ' || *str == '\t')
		{
			first_printable = 1;
			*str = '\0';
		}
		str++;
	}
	return (words);
}

int		compare_words(char *a, char *b)
{
	int len_a = ft_strlen(a);
	int len_b = ft_strlen(b);
	if (len_a != len_b)
		return (len_a - len_b);

	int i = 0;
	while (i < len_a && TO_LOWER(a[i]) == TO_LOWER(b[i]))
		++i;
	return (TO_LOWER(a[i]) - TO_LOWER(b[i]));
}

void	swap_words(char **a, char **b)
{
	char *swap = *a;
	*a = *b;
	*b = swap;
}

void	sort_words(char **words)
{
	int i;
	int swapped = 1;

	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (words[++i] != 0)
		{
			if (compare_words(words[i - 1], words[i]) > 0)
			{
				swap_words(&words[i - 1], &words[i]);
				swapped = 1;
			}
		}
	}
}

void	print_words(char **words)
{
	int i = -1;
	int len = (words[0]) ? ft_strlen(words[0]) : 0;
	int	cur_len;

	while (words[++i] != 0)
	{
		cur_len = ft_strlen(words[i]);
		if (i != 0)
		{
			if (cur_len == len)
				ft_putstr(" ");
			else
			{
				len = cur_len;
				ft_putstr("\n");
			}
		}
		ft_putstr(words[i]);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		char **words = get_words(av[1]);
		if (words[0])
			sort_words(words);
		print_words(words);
		free(words);
	}

	write(1, "\n", 1);
	return (0);
}
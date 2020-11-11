# str_maxlenoc

## Conceptual Overview
### The Problem

We are asked to write a program that takes arguments of one or more strings, finds the longest substring that appears in all of them, and prints it. If there are multiple substrings that appear in all arguments, the substring that appears first in the first argument will be printed.

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : str_maxlenoc
	Expected files   : str_maxlenoc.c
	Allowed functions: write, malloc, free
	--------------------------------------------------------------------------------

	Write a program that takes one or more strings and displays, followed by a
	newline, the longest string that appears in every parameter. If more that one
	string qualifies, it will display the one that appears first in the first
	parameter. Note that the empty string technically appears in any string.

	If there are no parameters, the program displays \n.

	Examples:

	$>./str_maxlenoc ab bac abacabccabcb
	a
	$>./str_maxlenoc bonjour salut bonjour bonjour
	u
	$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
	$
	$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
	os
	$>./str_maxlenoc | cat -e
	$
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [str_maxlenoc.c](str_maxlenoc.c) (passed moulinette on 2019.08.21)
* [str_maxlenoc.trace](str_maxlenoc.trace)

### Approach

Establish a test string with a test length equal to the length of the first argument, and with a starting position of the first character of the first argument. Check if the test string is a substring of each other argument. If it is, print it and exit. Otherwise, decrease the test length by 1, reset the test string's starting position to 0, and repeat.

Each time the test string fails to be found in the other arguments, increase the starting position by 1 until the test string runs past the end of the first argument. Each time this happens, decrease the test length by 1, reset the starting position to 0, and repeat until a substring is found.

### Code
```C
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
```

### Test Cases
```
$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc "bonjour an" "bonjour an" "confiserie an" "bonne annee" | cat -e
 an$
$>./str_maxlenoc | cat -e
$
$>./str_maxlenoc "" | cat -e
$
$>./str_maxlenoc "Bonjour"
Bonjour
```
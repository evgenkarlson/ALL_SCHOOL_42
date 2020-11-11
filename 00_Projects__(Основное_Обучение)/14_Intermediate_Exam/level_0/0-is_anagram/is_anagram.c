// Passed Moulinette 2019.09.01

int	is_anagram(char *a, char *b)
{
	int arr[127] = { [0 ... 126] = 0}; // Initialize all values to 0
	int i = -1;

	while (*a)
	{
		arr[(int)*a]++;		// Cast *a to type int to get ASCII value of char
		a++;
	}

	while (*b)
	{
		arr[(int)*b]--;
		b++;
	}

	while (++i < 127)
		if (arr[i] != 0)
			return (0);

	return (1);
}

//---------------------------------------------------------
// #include <stdio.h>
// int	main(void)
// {
// 	char a[] = "abcdeff";
// 	char b[] = "fabcde";
// 	printf("Should be 0: %d\n", is_anagram(a, b));

// 	char c[] = "abcdeff";
// 	char d[] = "fabcdef";
// 	printf("Should be 1: %d\n", is_anagram(c, d));

// 	char e[] = "abcdeff";
// 	char f[] = "fabcdef!";
// 	printf("Should be 0: %d\n", is_anagram(e, f));
// }
// Passed Moulinette 2019.09.01

int	count_2s(int n)
{
	int sum = 0;
	while (n != 0)
	{
		if (n % 10 == 2)
			sum++;
		n /= 10;
	}
	return (sum);
}

int	count_of_2(int n)
{
	int i = 1;
	int sum = 0;

	while (++i <= n)
		sum += count_2s(i);
	return (sum);
}

//---------------------------------------------------
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", count_of_2(25));
// }
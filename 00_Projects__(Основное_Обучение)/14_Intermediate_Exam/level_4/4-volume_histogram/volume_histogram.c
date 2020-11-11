// Passed Moulinette 2019.09.01

int		min_two(int a, int b)
{
	return (a < b ? a : b);
}

int		tallest(int *arr, int first, int last)
{
	if (first < 0 || first > last)
		return (0);
	int max = arr[first];
	while (++first <= last)
		(max < arr[first]) ? max = arr[first] : 0;
	return (max);
}

int		column_volume(int local_height, int local_max)
{
	if (local_height > local_max)
		return (0);
	return (local_max - local_height);
}

int		volume_histogram(int *histogram, int size)
{
	if (size < 3 || histogram == 0)
		return (0);
	int *h = histogram;
	int volume = 0;
	int local_max;

	int i = -1;
	while (++i < size)
	{
		local_max = min_two(tallest(h, 0, i - 1), tallest(h, i + 1, size - 1));
		volume += column_volume(h[i], local_max);
	}

	return (volume);
}

//----------------------------------------------------------------
// #include <stdio.h>
// int	main(void)
// {
// 	int	histogram1[] = {2, 1, 2};
// 	int	size1 = sizeof(histogram1) / sizeof(*histogram1);
// 	printf("Should be 1: %d\n", volume_histogram(histogram1, size1));

// 	int	histogram2[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
// 	int	size2 = sizeof(histogram2) / sizeof(*histogram2);
// 	printf("Should be 26: %d\n", volume_histogram(histogram2, size2));
// }
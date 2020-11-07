// Passed Moulinette 2019.09.01

int		sum_array(int *arr, int n)
{
	int i = 0;
	int sum = 0;

	while (i < n)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

int		find_pivot(int *arr, int n)
{
	int left = 0;
	int right = 0;
	int i = 1;

	right = sum_array(arr + 1, n - 1);	//set right to the sum of all but the first int in the array
	if (left == right)					//check if the current int is the equilibrium point
		return (0);

	while (i < n)
	{
		left += arr[i - 1];				//add the previous int to left
		right -= arr[i];				//subtract the current int from right
		if (left == right)				//check if the current int is the equilibrium point
			return (i);
		i++;
	}

	return (-1);
}

// //todo: remove
// #include <stdio.h>
// int		main(void)
// {
// 	int arra[] = { 1, 2, 3, 4, 0, 6 };
// 	int na = 6;
// 	printf("pivot a: %d\n", find_pivot(arra, na));

// 	int arrb[] = { 5, 0 };
// 	int nb = 2;
// 	printf("pivot b: %d\n", find_pivot(arrb, nb));

// 	int arrc[] = { 0, 8 };
// 	int nc = 2;
// 	printf("pivot c: %d\n", find_pivot(arrc, nc));

// 	int arrd[] = { -5, 10, 2, 5 };
// 	int nd = 4;
// 	printf("pivot d: %d\n", find_pivot(arrd, nd));

// 	int arre[] = { 1, 100, 0, 0, 1 };
// 	int ne = 5;
// 	printf("pivot e: %d\n", find_pivot(arre, ne));

// 	int arrf[] = { 7, 9, 8 };
// 	int nf = 3;
// 	printf("pivot f: %d\n", find_pivot(arrf, nf));

// 	int arrg[] = { 1 , 2 };
// 	int ng = 2;
// 	printf("pivot g: %d\n", find_pivot(arrg, ng));

// 	int arrh[1000001] = { [0 ... 100000] = 5 };
// 	int nh = 1000001;
// 	printf("pivot h: %d\n", find_pivot(arrh, nh));
// 	return (0);
// }
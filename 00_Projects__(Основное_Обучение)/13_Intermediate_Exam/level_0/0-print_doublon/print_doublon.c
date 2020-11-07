// Passed Moulinette 2019.09.01

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int ia = 0;
	int ib = 0;
	int first = 1;

	while (ia < na && ib < nb)
	{
		if (a[ia] == b[ib])
		{
			if (first)
			{
				printf("%d", a[ia]);
				first = 0;
			}
			else
				printf(" %d", a[ia]);
			ia++;
			ib++;
		}
		else if (a[ia] < b[ib])
			ia++;
		else if (b[ib] < a[ia])
			ib++;
	}
	printf("\n");
}

//-----------------------------------------------------------
// int	main(void)
// {
// 	int a[] = { -5,  1, 3, 15, 50, 71, 100, 200, 300, 1200, 5000 }; int na = 11;
// 	int b[] = {  2,  4,  5,  6,  7, 10,  40,  70 }                  ; int nb = 8;

// 	print_doublon(a, na, b, nb);
// 	return (0);
// }
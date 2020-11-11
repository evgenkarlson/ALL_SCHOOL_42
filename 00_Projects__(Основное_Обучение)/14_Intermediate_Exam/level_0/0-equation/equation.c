// Passed Moulinette 2019.09.01

#include <stdio.h>

void	equation(int n)
{
	int a = -1, b, c;

	while (++a < 10)
	{
		b = -1;
		while (++b < 10)
		{
			c = -1;
			while (++c < 10)
				if (10 * a + b + 10 * c + a == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
		}
	}
}

//-------------------------------------------------------------
// int		main(void)
// {
// 	equation(42);
// 	printf("\n");

// 	equation(111);
// 	printf("\n");

// 	equation(0);
// 	printf("\n");
// }
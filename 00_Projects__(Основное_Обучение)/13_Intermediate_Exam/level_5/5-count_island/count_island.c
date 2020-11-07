// Passed Moulinette 2019.09.01

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	fill_arr(int fd, char arr[1024][1024])
{
	char buf[1025] = {[0 ... 1024] = '\0'};
	int b;
	int	bytes_read = 0;
	int row = 0;
	int col = -1;
	int line_len = 0;

	while ((bytes_read = read(fd, buf, 1024)) > 0)
	{
		buf[bytes_read] = '\0';
		b = 0;
		while (buf[b] != '\0')
		{
			if (buf[b] == '\n')
			{
				if (line_len == 0)
					line_len = col;
				else if (line_len != col)
					return (0);
				arr[row][++col] = '\0';
				row++;
				col = -1;
			}
			else if (buf[b] == '.' || buf[b] == 'X')
				arr[row][++col] = buf[b];
			else
				return (0);
			b++;
		}
	}
	arr[++row][0] = '\0';
	return (1);
}

void	flood_fill(char arr[1024][1024], int row, int col, char fill)
{
	if (row < 0 || row > 1023 || arr[row][0] == '\0'
		|| col < 0 || col > 1023 || arr[row][col] == '\0'
		|| arr[row][col] != 'X')
		return;
	arr[row][col] = fill;
	flood_fill(arr, row - 1, col, fill);
	flood_fill(arr, row + 1, col, fill);
	flood_fill(arr, row, col - 1, fill);
	flood_fill(arr, row, col + 1, fill);
}

void	update_islands(char arr[1024][1024])
{
	char fill_index = '0' - 1;
	int row = -1;
	int col;
	while (arr[++row][0] != '\0')
	{
		col = -1;
		while (arr[row][++col] != '\0')
		{
			if (arr[row][col] == 'X')
				flood_fill(arr, row, col, ++fill_index);
			write(1, &arr[row][col], 1);
		}
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	int fd;
	if (ac == 2 && (fd = open(av[1], O_RDONLY)) != -1)
	{
		char arr[1024][1024];
		int result;
		if ((result = fill_arr(fd, arr)) != 0)
			update_islands(arr);
		else
			write(1, "\n", 1);
		close(fd);
	}
	else
		write(1, "\n", 1);
	return (0);
}
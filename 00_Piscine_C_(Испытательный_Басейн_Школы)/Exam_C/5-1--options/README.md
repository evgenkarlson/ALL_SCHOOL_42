# options

## Conceptual Overview
### The Problem
We are asked to write a program that takes arguments of an arbitrary number of strings, where alphabetical strings beginning with a '-' represent options. Each lowercase alphabetical character in each option turns on one bit of an int according to the map below, and the resulting integer is printed on the standard output. If the 'h' character appears in an option, print program's usage instead; if a character that isn't lower case alphabetical appears in an option, print "Invalid Option" instead.

```
00000000 00000000 00000000 00000000
******zy xwvutsrq ponmlkji hgfedcba
```

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : options
	Expected files   : *.c *.h
	Allowed functions: write
	--------------------------------------------------------------------------------

	Write a program that takes an undefined number of arguments and writes on
	standard output an integer representation of those options, stored as bit flags,
	followed by a newline.

	An option is an argument that begins by a '-' and has multiple characters which
	could be: abcdefghijklmnopqrstuvwxyz

	All options are stocked in a single int and each option represents a bit of that
	int, and should be stocked like this:

	00000000 00000000 00000000 00000000
	******zy xwvutsrq ponmlkji hgfedcba

	Launching the program without arguments, or with the '-h' flag, must print a
	usage on the standard output, as shown in the following examples.

	A wrong option must print "Invalid Option" followed by a newline.

	Examples:
	$>./options
	options: abcdefghijklmnopqrstuvwxyz
	$>./options -abc -ijk
	1799
	$>./options -z | cat -e
	33554432$
	$>./options -abc -hijk
	options: abcdefghijklmnopqrstuvwxyz
	$>./options -%
	Invalid Option
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [options.c](options.c) (passed moulinette on 2019.06.29.)
* [options.trace](options.trace)

### Approach
If there are no arguments, print the usage and exit. Otherwise, iterate through the arguments, ignoring arguments that do not begin with '-'. Create an int to hold the output, and initialize it to 0. For each argument beginning with '-', iterate through the characters. For each character:
* If the character is 'h', print "options: abcdefghijklmnopqrstuvwxyz\n" and exit.
* Otherwise, if the character is not alphabetical and lowercase, print "Invalid Option\n" and exit.
* Otherwise, 

Read from the memory address passed as argument in groups of up to 16 bytes. For each group:
* Print the value of each byte as a 2-digit hexadecimal number, inserting a space every 2 bytes or 4 digits, and padding groups of fewer than 16 bytes with spaces to insure a 40-character total.
* For each byte, if its value corresponds to a printable character, print that character, otherwise print a period ('.').
* Print a newline character ('\n').

### Code
```C
#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int		options(char *str, int flags)
{
	int i = 1;
	int bitflag;

	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (-1);
		else if (str[i] == 'h')
			return (-2);
		bitflag = 1 << (str[i] - 'a');
		flags = flags | bitflag;
		++i;
	}
	return (flags);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}

	int i = 1;
	int flags = 0;

	while (i < ac)
	{
		if (av[i][0] == '-' && (flags = options(av[i], flags)) < 0)
		{
			if (flags == -1)
				write(1, "Invalid Option\n", 15);
			else if (flags == -2)
				write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		++i;
	}

	ft_putnbr(flags);
	write(1, "\n", 1);
	return (0);
}
```

### Test Cases
```
./options
options: abcdefghijklmnopqrstuvwxyz
./options -abcz -w -ijfek -lildali -pirmakn -apizobouzaguoca
38993791
./options -z bonjour -cd -e
33554460
./options -a --a
Invalid Option
./options -ab% -zd
Invalid Option
./options -abcdefgijklmnopqrstuvwxyz
67108735
./options Bonjour
0
./options -
0
```
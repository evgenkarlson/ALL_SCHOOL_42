#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"
#include "dictionary.c"

int main(int ac, char **av)
{
	char *input;
	char *output;

	if (ac != 2)
		return (-1);
	if (!(input = get_content(av[1])))
		return (-1);
	output = NULL;

	/*-------------------
	launch your test here
	--------------------*/

	// if (!(output = neverForget(input, g_dict)))
	// 	return (-1);
	// printf("%s\n", output);
	
	return (0);
}



// Function used for the test
// Don't go further :)

char *get_content(char *file) {
	FILE *f = fopen(file, "r");
	char buffer[100];
	char *str;
	int count;
	int len;

	len = 0;
	for (count = 0; fscanf(f, "%s", buffer) > 0; count++) {
		len += strlen(buffer);
	}
	fclose(f);
	f = fopen(file, "r");
	if (!(str = (char *)malloc(sizeof(char) * (len + count + 1))))
		return (NULL);
	for (int i = 0; fscanf(f, "%s", buffer) > 0; i++) {
		strcat(str, buffer);
		if (i < count - 1)
			strcat(str, " ");
	}

	return (str);
}

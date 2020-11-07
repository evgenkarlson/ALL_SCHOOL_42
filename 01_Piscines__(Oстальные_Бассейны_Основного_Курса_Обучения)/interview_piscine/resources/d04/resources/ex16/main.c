#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	struct s_bit *bit = NULL;
	int l = -1;
	int **pianoNotes;

	if (ac == 2)
	{
		getPianoFile(av[1], &bit, &l);
	}
	else {
		printf("Usage: ./decompress song.piano\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/
	pianoNotes = pianoDecompress(bit, l);

	printPianoUncompressed(pianoNotes, l);
	return (0);
}

//don't go further :)

void	printPianoUncompressed(int **m, int l)
{
	for (int row = 0; m[row]; row++){
		for (int col = 0; col < l; col++){
			printf("%d ", m[row][col]);
		}
		printf("\n");
	}
}

char	*readFile(char *filename)
{
	char *fcontent = NULL;
	int size = 0;
	FILE *fp;

	if (NULL == (fp = fopen(filename, "r")))
		return (NULL);
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	if (NULL == (fcontent = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	fread(fcontent, 1, size, fp);
	fclose(fp);
	return (fcontent);
}

char	**split(char *str, char *delimiter){
	char **tab;
	int count;
	int a;
	int pos;
	int len_delimiter;
	int len_substring;

	len_delimiter = strlen(delimiter);
	len_substring = 0;
	count = 0;
	//first counting the number of substring
	for (int i = 0; str[i]; i++){
		if (strncmp(str + i, delimiter, len_delimiter) == 0) {
			if (len_substring > 0){
				len_substring = 0;
				count += 1;
			}
			i += len_delimiter - 1;
		} else {
			len_substring += 1;
		}
	}
	if (len_substring > 0){
		count += 1;
	}
	if (NULL == (tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[(a = 0)] = NULL;
	len_substring = 0;
	pos = 0;
	//then get the substring :)
	for (int i = 0; str[i]; i++){
		if (strncmp(str + i, delimiter, len_delimiter) == 0) {
			if (len_substring > 0){
				tab[(a++)] = strndup(str + pos, len_substring);
				len_substring = 0;
			}
			i += len_delimiter - 1;
			pos = i + 1;
		} else {
			len_substring += 1;
		}
	}
	if (len_substring > 0){
		tab[(a++)] = strndup(str + pos, len_substring);
	}
	tab[a] = NULL;
	return (tab);
}

void	getPianoFile_leave(void){
	dprintf(STDERR_FILENO, "failed to load the file.\n");
	exit(0);
}

void getPianoFile(char *filename, struct s_bit **bit, int *l)
{
	char **splitted1;
	char **splitted2;
	char *file;

	(*bit) = malloc(sizeof(struct s_bit));
	if (NULL == (file = readFile(filename)))
		return (getPianoFile_leave());
	splitted1 = split(file, "\n");
	if (splitted1[0])
	{
		(*l) = atoi(splitted1[0]);
	}
	splitted2 = split(splitted1[1], " ");
	for ((*bit)->n = 0; splitted2[(*bit)->n]; (*bit)->n++)
		;
	//creating the array
	if (NULL == ((*bit)->arr = malloc(sizeof(int) * ((*bit)->n))))
		getPianoFile_leave();

	//filling the array
	for (int i = 0; splitted2[i]; i++)
	{
		(*bit)->arr[i] = atoi(splitted2[i]);
	}
}

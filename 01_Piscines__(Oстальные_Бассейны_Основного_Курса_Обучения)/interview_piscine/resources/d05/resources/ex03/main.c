#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	int **map;

	map = readMap("map.txt");

	printMap(map);
	/*-------------------
	launch your test here
	--------------------*/
	// sinkIsland(map, 1, 1);
	// printMap(map);

	return (0);
}

// Function used for the test
// Don't go further :)

void	printMap(int **map)
{
	printf("map: \n");
	for (int row = 0; map[row]; row++)
	{
		for (int col = 0; map[row][col] != -1; col++)
		{
			printf("%d ", map[row][col]);
		}
		printf("\n");
	}
}

/*
**	PARSING
*/

char    *readFile(char *filename)
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

void    readMap_leave(void){
        dprintf(STDERR_FILENO, "failed to load the file.\n");
        exit(0);
}


char    **split(char *str, char *delimiter){
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

int **readMap(char *filename)
{
	int **map;
        char *file;
        char **splitted;
        char **secondSplit;
	int len2;
        int len;

        dprintf(STDOUT_FILENO, "(INFO) Loading the file... ");
        if (NULL == (file = readFile(filename)))
                readMap_leave();       
        splitted = split(file, "\n");
        for (len = 0; splitted[len]; len++)
                ;
        if (!(map = malloc(sizeof(int *) * (len+1))))
                readMap_leave();
        len = 0;
        for (int i = 0; splitted[i]; i++)
        {
                secondSplit = split(splitted[i], " ");
		for (len2 = 0; secondSplit[len2]; len2++)
			;
		map[len] = malloc(sizeof(int) * (len2 + 1));
		for (int a = 0; a < len2; a++){
			map[len][a] = atoi(secondSplit[a]);
		}
		map[len][len2] = -1;
                len += 1;
        }
	map[len] = NULL;
        printf("finish!\n");
        return (map);
}

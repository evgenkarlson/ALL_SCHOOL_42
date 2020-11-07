#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
        int pizzaSize = 3;
        struct s_prices *pricesCont; //just a container which store the array of prices and it's associated length

        pricesCont = readList();

        if (ac >= 2)
                pizzaSize = atoi(av[1]);
	/*-------------------
	launch your test here
	--------------------*/
        // printf("%d : %.2f\n", pizzaSize, optimizedBestPrice(pizzaSize, pricesCont->items));

	return (0);
}

// Function used for the test
// Don't go further :)

/*
**	PARSING
*/

#define FILENAME "list.txt"

char    *readFile(void)
{
        char *fcontent = NULL;
        int size = 0;
        FILE *fp;

        if (NULL == (fp = fopen(FILENAME, "r")))
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

void    readList_leave(void){
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

struct s_prices *readList()
{
        struct s_prices *list;
        char *file;
        char **splitted;
        char **secondSplit;
        int len;

        dprintf(STDOUT_FILENO, "(INFO) Loading the file... ");
        if (NULL == (file = readFile()))
                readList_leave();       
        splitted = split(file, "\n");
        for (len = 0; splitted[len]; len++)
                ;
        list = malloc(sizeof(struct s_prices));
        list->length = len+1;
        if (!(list->items = malloc(sizeof(double) * (len+1))))
                readList_leave();
        len = 1;
	list->items[0] = 0;
        for (int i = 0; splitted[i]; i++)
        {
                secondSplit = split(splitted[i], ":");
                if (!(secondSplit && secondSplit[0] && secondSplit[1] && !secondSplit[2]))
                        continue;
                if (len != atoi(secondSplit[0])){
                        dprintf(STDERR_FILENO, "error in the parsing!\n");
                        exit(0);
                }
                list->items[len] = atof(secondSplit[1]);
                len += 1;
        }
        printf("finish!\n");
        return (list);
}

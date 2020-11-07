#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_city *city;

	city = getCities();

	/*-------------------
	launch your test here
	--------------------*/
	//printf("%s\n", NthLastCity(city, 2)); //should return 'Kobylin'
	//printf("%s\n", NthLastCity(city, 10)); //should return 'Jastrzebie-Zdroj'

	return (0);
}



// Function used for the test
// Don't go further :)

#define FILENAME "cities.txt"

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

void    getCities_leave(void){
        dprintf(STDERR_FILENO, "failed to load the file.\n");
        exit(0);
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

struct s_city *getCities(void)
{
	char *str;
	char **tab;
	struct s_city *n;
	struct s_city *tmp;
	struct s_city *b;

	dprintf(STDOUT_FILENO, "loading the file... ");
	if (NULL == (str = readFile()))
		getCities_leave();
	b = NULL;
	tab = split(str, "\n");
	for (int i = 0; tab[i]; i++){
		tmp = malloc(sizeof(struct s_city));
		tmp->name = tab[i];
		tmp->next = NULL;
		if (!b){
			b = tmp;
			n = b;
		}else{
			n->next = tmp;
			n = n->next;
		}
	}
	dprintf(STDOUT_FILENO, "done!\n");
	return (b);
}

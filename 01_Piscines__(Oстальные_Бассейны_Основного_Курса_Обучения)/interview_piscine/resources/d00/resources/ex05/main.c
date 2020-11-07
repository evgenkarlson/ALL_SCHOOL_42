#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	char *book;
	char **words;
	int lenWords;

	//getting the book and the list of words
	book = readBookFile();
	readWordsFile(&words, &lenWords);
	
	/*-------------------
	launch your test here
	--------------------*/
	//struct s_dict *dict;
	//
	//dict = dictInit(lenWords);
	//
	//for (int i = 0; i < lenWords; i++)
	//	dictInsert(dict, words[i], i);
	//

	return (0);
}


// Function used for the test
// Don't go further :)

#define FILENAME "book.txt"

void	leave(void){
	dprintf(STDERR_FILENO, "Failed to load the file.\n");
	exit(0);
}

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

//get book

char	*readBookFile(void)
{
	return (readFile(FILENAME));
}

#define FILEWORDS "words.txt"

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

void readWordsFile(char ***pWords, int *pLenWords)
{
	(*pWords) = split(readFile(FILEWORDS), "\n");
	(*pLenWords) = 0;
	//count the number of items in words and put it inside lenWords
	for ((*pLenWords) = 0; (*pWords)[(*pLenWords)]; (*pLenWords)++)
		;
}

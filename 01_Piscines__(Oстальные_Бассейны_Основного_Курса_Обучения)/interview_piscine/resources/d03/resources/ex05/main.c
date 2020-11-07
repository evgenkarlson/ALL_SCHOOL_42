#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"
#include "dictionary.c"

int main(int ac, char **av)
{
	struct s_trie *trie;

	trie = NULL;
	
	if (ac >= 2){
		/*-------------------
		  launch your test here
		  --------------------*/
		// if (!(trie = createTrie(g_dict)))
		// 	return (-1);
		// printf("%s\n", understandAll(av[1], trie));
	}else{
		printf("Usage: %s 'wo?d'\n", av[0]);
	}

	return (0);
}



// Function used for the test
// Don't go further :)

#define SEPARATOR " !:;,.$&<>()+*-_=\n\t"

int	isInside(char c, char *string){
	for (int i = 0; string[i]; i++){
		if (string[i] == c)
			return (1);
	}
	return (0);
}

char *understandAll(char *sentence, struct s_trie *trie) {
	char *output;
	char *token;
	char *separator = SEPARATOR;
	char *tmp;
	char *replace;

	output = strdup(sentence);
	token = strtok(output, separator);
	while(token != NULL) 
	{
		if (strchr(token, '?')) {
			if (!(replace = understand(token, trie)))
				return (NULL);
			strcpy(token, replace);
			free(replace);
		}
		tmp = token + strlen(token);
		token = strtok(NULL, separator);
		*tmp = *(sentence + (int)(tmp - output));
	}
	return (output);
}

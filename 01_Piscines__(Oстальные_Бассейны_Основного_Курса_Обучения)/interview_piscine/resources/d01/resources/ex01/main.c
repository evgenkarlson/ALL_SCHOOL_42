#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	struct s_node *lst;

	if (ac >= 2)
		lst = createList(av + 1, ac - 1);
	else{
		printf("Usage: ./reverse word1 word2 ...\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/

	//printReverse(lst);

	return (0);
}



// Function used for the test
// Don't go further :)

struct s_node *createList(char **words, int n) {
	struct s_node *lst;
	struct s_node *tmp;
	int i;

	lst = NULL;
	i = n - 1;
	while (i >= 0) {
		if (!(tmp = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);
		tmp->word = words[i];
		tmp->next = lst;
		lst = tmp;
		i--;
	}
	return (lst);
}

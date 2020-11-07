#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <math.h>

#include "header.h"

int main(int ac, char **av)
{
	char *word = NULL;

	if (ac >= 2){
		word = av[1];
	}

	/*-------------------
	launch your test here
	--------------------*/
	// printUniquePermutations(word);

	return (0);
}



// Function used for the test
// Don't go further :)

size_t	hash(char *input){
	size_t prod;

	prod = 0;
	for (int i = 0; input[i]; i++){
		prod = prod * 6449 + input[i];
	}
	return (prod);
}

int	dictInsert(struct s_dict *dict, char *key, int value)
{
	int pos;
	struct s_item *tmp;
	struct s_item *tmpBefore;

	if (!dict || !key)
		return (-1);

	pos = hash(key) % dict->capacity;
	tmpBefore = NULL;
	tmp = dict->items[pos];

	//add the new item using push front method
	while (tmp){
		tmpBefore = tmp;
		tmp = tmp->next;
	}
	if (NULL == (tmp = malloc(sizeof(struct s_item))))
		return (0);
	if (tmpBefore != NULL)
		tmpBefore->next = tmp;
	else
		dict->items[pos] = tmp;
	tmp->key = strdup(key);
	tmp->value = value;
	tmp->next = NULL;
	return (1);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict;

	if (NULL == (dict = malloc(sizeof(struct s_dict))))
		return (NULL);

	dict->capacity = capacity;

	//calculate len
	if (NULL == (dict->items = malloc(sizeof(struct s_item *) * (dict->capacity))))
		return (NULL);

	//clearing the hashdict
	for (int i = 0; i < dict->capacity; i++){
		dict->items[i] = NULL;
	}

	return (dict);
}

int	dictSearch(struct s_dict *dict, char *key)
{
	int pos;
	struct s_item *tmp;

	pos = hash(key) % dict->capacity;
	tmp = dict->items[pos];
	while (tmp){
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (-1);
}

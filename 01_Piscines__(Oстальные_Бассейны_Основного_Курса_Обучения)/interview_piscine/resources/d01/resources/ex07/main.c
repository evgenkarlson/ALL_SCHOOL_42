#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	struct s_node *node;
	struct s_node *nodeCloned;

	node = genRandomSnakesAndLadders(5); //if the parameter == 0: generate a random game board with 1 to 1000 nodes
	nodeCloned = NULL;

	/*-------------------
	launch your test here
	--------------------*/
	//printSnakeAndLadders(node);
	//nodeCLoned = cloneGameBoard(node);

	return (0);
}



// Function used for the test
// Don't go further :)

void	printSnakeAndLadders(struct s_node *node)
{
	while (node){
		printf("[%d : %p , (%d : %p)]%c", node->value, node, (node->random) ? node->random->value : -1,
		node->random,
		(node->next) ? ' ' : '\n');
		node = node->next;
	}
}

struct s_node *genRandomSnakesAndLadders(int n)
{
	struct s_node *b;
	struct s_node *a;
	struct s_node *tmp;
	int r;
	int count;

        srand(time(NULL));
        if (n <= 1 || n > 1000){
                n = rand() % 1000 + 1; //generating int between 1 and 1.000
        }
	b = NULL;
	//first creating the node
	for (int i = 0; i < n; i++){
		tmp = malloc(sizeof(struct s_node));
		tmp->random = NULL;
		tmp->value = i;
		tmp->next = NULL;
		if (!b){
			b = tmp;
			a = b;
		}
		a->next = tmp;
		a = a->next;
	}
	//then gen the random access
	tmp = b;
	while (tmp){
		r = rand() % 100;
		//we create a random access in 1/3 of the case
		if (r <= 30){
			a = b;
			count = (rand() % n) + 1;
			for (int i = 0; i < count; i++){
				a = a->next;
			}
			tmp->random = a;
		}
		tmp = tmp->next;
	}
	return (b);
}

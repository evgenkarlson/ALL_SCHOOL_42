#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	struct s_node *root;
	struct s_node *node;

	root = getTreeOfLife();
	node = NULL;

       	/*-------------------
        launch your test here
        --------------------*/

	// node = findParent(root, "Dinosauria", "Homo sapiens");
	// if (node)
	// 	printf("%s\n", node->name);

	return (0);
}



// Function used for the test
// Don't go further :)

struct s_node **getNodes(FILE *f) {
	long int		id;
	int				i, size;
	struct s_node	**children;

	fscanf(f, "%d\n", &size);
	if (!(children = (struct s_node **)malloc(sizeof(struct s_node *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && fscanf(f, "%ld\n", &id) > 0) {
		children[i] = (struct s_node *)(id + 1);
		i++;
	}
	children[i] = NULL;
	return (children);
}

void update(struct s_node **nodes) {
	//struct s_node	*parent;
	struct s_node	**children;

	for (int i = 0; nodes[i]; i++) {
		//nodes[i]->parent= nodes[(int)(nodes[i]->parent)];
		children = nodes[i]->children;
		for (int j = 0; children[j]; j++) {
			children[j] = nodes[(int)(children[j]) - 1];
		}
	}
}

#define FILENAME "treeOfLife.txt"

struct s_node *getTreeOfLife(void)
{
	FILE			*f;
	struct s_node   **nodes;
	size_t 			linecap = 0;
	ssize_t 		linelen;
	int				i, size, id;
	char			*name = NULL;
	int parent;

	if (!(f = fopen(FILENAME, "r"))) {
		printf("Couldn't find %s\n", FILENAME);
		exit(1);
	}
	fscanf(f, "%d\n", &size);
	if (!(nodes = (struct s_node **)malloc(sizeof(struct s_node *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && fscanf(f, "%d\n", &id) > 0 && (linelen = getline(&name, &linecap, f)) > 0) {
		name[linelen - 1] = 0;
		if (!(nodes[id] = (struct s_node *)malloc((sizeof(struct s_node)))))
			return (NULL);
		nodes[id]->name = name;
		fscanf(f, "%d\n", &parent);
		if (!(nodes[id]->children = getNodes(f)))
			return (NULL);
		name = NULL;
		i++;
	}
	nodes[i] = NULL;
	update(nodes);
	return (nodes[0]);
}

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	struct s_graph *graph;

	if (ac == 2)
		graph = getGraph(av[1]);
	else {
		printf("Usage: %s filename\n", av[0]);
		return (0);
	}

	/*-------------------
	launch your test here
	--------------------*/

	// printf("Distance : Edges\n");
	// printMST(graph);

	return (0);
}



// Function used for the test
// Don't go further :)

struct s_edge **getNetwork(FILE *f) {
	long int		id2;
	int				i, size, dist;
	struct s_edge	**edges;

	fscanf(f, "%d\n", &size);
	if (!(edges = (struct s_edge **)malloc(sizeof(struct s_edge *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && fscanf(f, "%ld %d\n", &id2, &dist) > 0) {
		if (!(edges[i] = (struct s_edge *)malloc(sizeof(struct s_edge))))
			return (NULL);
		edges[i]->dest = (struct s_node *)(id2 + 1);
		edges[i]->dist = dist;
		i++;
	}
	edges[i] = NULL;
	return (edges);
}

void update(struct s_graph *graph) {
	struct s_node	**nodes;
	struct s_edge	**edges;

	nodes = graph->nodes;
	for (int i = 0; nodes[i]; i++) {
		edges = nodes[i]->edges;
		for (int j = 0; edges[j]; j++) {
			edges[j]->dest = nodes[(int)(edges[j]->dest) - 1];
		}
	}
}

struct s_graph *getGraph(char *filename) {
	FILE			*f;
	struct s_graph *graph;
	size_t 			linecap = 0;
	ssize_t 		linelen;
	int				i, size;
	char			*name = NULL;

	if (!(graph = (struct s_graph *)malloc(sizeof(struct s_graph))))
		return (NULL);
	if (!(f = fopen(filename, "r"))) {
		printf("Couldn't find %s\n", filename);
		exit(1);
	}
	fscanf(f, "%d\n", &size);
	if (!(graph->nodes = (struct s_node **)malloc(sizeof(struct s_node *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && (linelen = getline(&name, &linecap, f)) > 0) {
		name[linelen - 1] = 0;
		if (!(graph->nodes[i] = (struct s_node *)malloc((sizeof(struct s_node)))))
			return (NULL);
		graph->nodes[i]->id = i;
		graph->nodes[i]->name = name;
		if (!(graph->nodes[i]->edges = getNetwork(f)))
			return (NULL);
		name = NULL;
		i++;
	}
	graph->nodes[i] = NULL;
	update(graph);
	return (graph);
}

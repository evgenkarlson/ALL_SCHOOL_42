#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	struct s_graph *graph;
	struct s_sellers *sellers;

	char *place = NULL;
	if (ac >= 3)
		place = av[2];
	else{
		printf("Usage: ./junkFood squares.txt \"Place...\"\n");
		return (0);
	}

	graph = getSquares(av[1]);
	sellers = NULL;

	/*-------------------
	launch your test here
	--------------------*/
	// sellers = closestSellers(graph, place);

	// printSellers(sellers);

	return (0);
}



// Function used for the test
// Don't go further :)

void printSellers(struct s_sellers *sellers)
{
	if (!sellers)
		return ;
	printf("At a distance of %d, these places have cereal bars:\n", sellers->distance);
	for (int i = 0; sellers->placeNames[i]; i++)
	{
		printf("%s\n", sellers->placeNames[i]);
	}
}

//QUEUE

void enqueue(struct s_queue *queue, struct s_node *place) {
	struct s_queueItem* elem;

	if (!(elem = (struct s_queueItem *)malloc(sizeof(struct s_queueItem))))
		return;
	elem->place = place;
	elem->next = NULL;
	if (queue->last) {
		queue->last->next = elem;
	}
	queue->last = elem;
	if (queue->first == NULL) {
		queue->first = queue->last;
	}
}

struct s_node *dequeue(struct s_queue *queue) {
	struct s_queueItem *elem;
	struct s_node *place;

	if (queue->first == NULL)
		return (NULL);
	elem = queue->first;
	place = elem->place;
	queue->first = elem->next;
	if (queue->first == NULL) {
		queue->last = NULL;
	}
	free(elem);
	return (place);
}

void queuePrint(struct s_queue *queue) {
	struct s_queueItem* tmp;

	tmp = queue->first;
	printf("queue:\n");
	while (tmp) {
		printf("%s\n", tmp->place->name);
		tmp = tmp->next;
	}
}

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	queue = malloc(sizeof(struct s_queue));
	if (!queue)
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

//PARSING

struct s_node **getNetwork(FILE *f) {
	long int		id2;
	int				i, size;
	struct s_node	**connectedPlaces;

	fscanf(f, "%d\n", &size);
	if (!(connectedPlaces = (struct s_node **)malloc(sizeof(struct s_node *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && fscanf(f, "%ld\n", &id2) > 0) {
		connectedPlaces[i] = (struct s_node *)(id2 + 1);
		i++;
	}
	connectedPlaces[i] = NULL;
	return (connectedPlaces);
}

void update(struct s_graph *graph) {
	struct s_node	**places;
	struct s_node	**connectedPlaces;

	places = graph->places;
	for (int i = 0; places[i]; i++) {
		connectedPlaces = places[i]->connectedPlaces;
		for (int j = 0; connectedPlaces[j]; j++) {
			connectedPlaces[j] = places[(int)(connectedPlaces[j]) - 1];
		}
	}
}

struct s_graph *getSquares(char *filename) {
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
	if (!(graph->places = (struct s_node **)malloc(sizeof(struct s_node *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && (linelen = getline(&name, &linecap, f)) > 0) {
		name[linelen - 1] = 0;
		if (!(graph->places[i] = (struct s_node *)malloc((sizeof(struct s_node)))))
			return (NULL);
		graph->places[i]->name = name;
		graph->places[i]->visited = 0;
		fscanf(f, "%d\n", &(graph->places[i]->hasCerealBar));
		if (!(graph->places[i]->connectedPlaces = getNetwork(f)))
			return (NULL);
		name = NULL;
		i++;
	}
	graph->places[i] = NULL;
	update(graph);
	return (graph);
}

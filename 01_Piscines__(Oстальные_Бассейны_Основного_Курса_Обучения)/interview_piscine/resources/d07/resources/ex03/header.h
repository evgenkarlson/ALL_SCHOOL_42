#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

//GRAPH

struct s_node {
	char          *name;
	int           hasCerealBar; //0 = FALSE, 1 = TRUE
	int           visited;      //0 = FALSE, 1 = TRUE
	struct s_node **connectedPlaces;
};

struct s_graph {
	struct s_node **places; //places of Paris
};

//OTHER

struct s_sellers {
	int           distance;
	char          **placeNames;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

//QUEUE

struct s_queueItem {
  struct s_node *place;
  struct s_queueItem *next;
};

struct s_queue {
  struct s_queueItem *first;
  struct s_queueItem *last;
};

void enqueue(struct s_queue *queue, struct s_node *place);
struct s_node *dequeue(struct s_queue *queue);
void queuePrint(struct s_queue *queue);
struct s_queue *queueInit(void);

//PARSING

struct s_graph *getSquares(char *filename);

//OTHER

void printSellers(struct s_sellers *sellers);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

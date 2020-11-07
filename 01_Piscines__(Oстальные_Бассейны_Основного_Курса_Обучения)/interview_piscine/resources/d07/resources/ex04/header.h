#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_node {
    char          *name;
    int           population;
    int           visited; //0 = FALSE, 1 = TRUE
    struct s_node **connectedPlaces;
};

struct s_graph {
    struct s_node **places;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
float maxTraffic(struct s_graph *parisPlaces, char *eventHere);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

//QUEUE

struct s_queueItem {
  void *item;
  struct s_queueItem *next;
};

struct s_queue {
  struct s_queueItem *first;
  struct s_queueItem *last;
};

void enqueue(struct s_queue *queue, void *item);
void *dequeue(struct s_queue *queue);
struct s_queue *queueInit(void);

//OTHER

struct s_graph *getSquares(char *filename);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

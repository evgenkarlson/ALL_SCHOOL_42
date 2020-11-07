#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	int isFinal;
	struct s_node *random;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int	minimumMoves(struct s_node *begin); //you must return the minimum number of strokes to access to the final

/*--------------------------------
  ?? test function used in main
  --------------------------------*/

// STACK

struct s_stackNode {
  void *content;
  struct s_stackNode *next;
};

struct s_stack {
  struct s_stackNode *top;
};

struct s_stack *init(void);
void *pop(struct s_stack *stack);
void push(struct s_stack *stack, void *content);

// QUEUE

struct s_queueNode {
	void          *value;
	struct s_queueNode *next;
};

struct s_queue {
  struct s_queueNode *first;
	struct s_queueNode *last;
};


struct s_queue *queueInit(void);
void *dequeue(struct s_queue *queue);
void enqueue(struct s_queue *queue, void *value);

// DICTIONNARY

struct s_item {
  void          *key;
  int           value;
  struct s_item *next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};

struct s_dict *dictInit(int capacity);
int dictInsert(struct s_dict *dict, void *key, int value); //return -1 if fail
int dictSearch(struct s_dict *dict, void *key);

// PARSING

struct s_node *getBoardFromFile(char *file);

// OTHER

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_node {
	char	*word;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/

//STACK

struct s_item {
  char          *word;
  struct s_item *next;
};

struct s_stack {
	struct s_item *item;
};

struct s_stack *stackInit(void);

void *pop(struct s_stack *stack);

void push(struct s_stack *stack, char *word);

//OTHER

void printReverseV2(struct s_node *lst);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *createList(char **words, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

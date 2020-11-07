#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	struct s_node *random;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *cloneGameBoard(struct s_node *node);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *genRandomSnakesAndLadders(int n);
void    printSnakeAndLadders(struct s_node *node);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

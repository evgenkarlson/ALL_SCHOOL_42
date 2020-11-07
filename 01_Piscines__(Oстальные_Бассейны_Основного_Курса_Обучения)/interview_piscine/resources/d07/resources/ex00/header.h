#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_art {
	char *name;
	int price;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void heapSort(struct s_art **masterpiece, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_art **getArts(void);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

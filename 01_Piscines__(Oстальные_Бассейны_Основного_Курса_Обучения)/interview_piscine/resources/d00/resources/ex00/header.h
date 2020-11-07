#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
--------------------------------*/

struct  s_art {
    char *name;
    int price;
};


/*--------------------------------
  :) function you must implement
--------------------------------*/

int  searchPrice(struct s_art **arts, char *name);


/*--------------------------------
  ?? test function used in main 
--------------------------------*/

struct s_art		**getArts(void);


/*--------------------------------
  &  your own other function
--------------------------------*/


#endif

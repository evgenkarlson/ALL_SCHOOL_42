#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/

void rotate(int **picture, int n);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

int **import_pgm(char *file, char *magic, int *n, int *white);
void print_pgm(int **pic, char *magic, int n, int white);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

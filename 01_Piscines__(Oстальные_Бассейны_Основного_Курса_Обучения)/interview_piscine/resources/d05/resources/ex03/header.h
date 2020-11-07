#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
void sinkIsland(int **map, int row, int col);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

void	printMap(int **map);

//PARSER
int **readMap(char *filename);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

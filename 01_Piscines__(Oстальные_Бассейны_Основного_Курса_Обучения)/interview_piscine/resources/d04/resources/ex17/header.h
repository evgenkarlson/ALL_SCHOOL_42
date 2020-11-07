#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_bit {
	int *arr;
	int n;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
void	correctSong(struct s_bit *bit, int l, int row, int col, int dist);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
void getPianoFile(char *filename, struct s_bit **bit, int *l);
void	printPianoCompressed(struct s_bit *bit, int l);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

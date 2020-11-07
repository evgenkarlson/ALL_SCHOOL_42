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
int	**pianoDecompress(struct s_bit *bit, int l);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
void		getPianoFile(char *filename, struct s_bit **bit, int *l);
void		printPianoUncompressed(int **m, int l);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

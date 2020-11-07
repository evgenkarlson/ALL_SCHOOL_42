#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
# define DEPTH 3


/*--------------------------------
  :) function you must implement
  --------------------------------*/

# define ALPHAS "abcdefghijklmnopqrstuvwxyz"

char    *delete(char *word, int pos);
char    *replace(char *word, int pos, char c);
char    *add(char *word, int pos, char c);

char	*whatWasThat(char *word, char **dict);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

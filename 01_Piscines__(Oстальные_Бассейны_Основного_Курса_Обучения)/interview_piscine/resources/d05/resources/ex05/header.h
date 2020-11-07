#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void	printUniquePermutations(char *str);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// DICTIONNARY

struct s_item {
  char          *key;
  int           value;
  struct s_item *next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};

struct s_dict *dictInit(int capacity);
int dictInsert(struct s_dict *dict, char *key, int value); //return -1 if fail
int dictSearch(struct s_dict *dict, char *key);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

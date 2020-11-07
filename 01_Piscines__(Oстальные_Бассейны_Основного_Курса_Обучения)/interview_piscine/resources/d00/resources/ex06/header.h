#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_elem {
	char *word;
	int  occurence;
};

struct s_list {
	struct s_elem **elems;
	int           len;
};

struct s_string {
  char *content;
  int  length; //the current length of 'content'
  int  capacity; //the allocated size of 'content'
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DYNAMIC STRING

struct s_string *stringInit(void);
int	stringAppend(struct s_string *s, char *add); //return 0 = FAIL, 1 = SUCCESS

// OTHER

char *decompress(char *cBook);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

char *readFile(void);
char **mostUsedWords(char *book);
char *compress(char *book, char **words);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_prices
{
	double *items;
	int length;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
double optimizedBestPrice(int pizzaSize, double *prices);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// PARSING

struct s_prices *readList();

/*--------------------------------
  &  your own other function
  --------------------------------*/


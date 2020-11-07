#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_hotspot {
	int pos;
	int radius;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int selectHotspots(struct s_hotspot **hotspots);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_hotspot **readHotspots(char *filename);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

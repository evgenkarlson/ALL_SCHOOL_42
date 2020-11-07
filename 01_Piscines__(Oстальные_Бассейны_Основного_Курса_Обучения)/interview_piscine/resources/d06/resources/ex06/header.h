#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_edge;

struct s_node {
	int id;                // index of the node in the graph
	char *name;            // name of the node
	struct s_edge **edges; // null-terminated array of edges
};

struct s_edge {
	int dist;              // distance to the destination node 
	struct s_node *dest;   // destination node
};

struct s_graph {
	struct s_node **nodes; // null-terminated array of
};                       // all the nodes in the graph

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void printMST(struct s_graph *graph);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_graph *getGraph(char *filename);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

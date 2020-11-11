Assignment name  : perimeter
Expected files   : perimeter.c
Allowed functions: printf
--------------------------------------------------------------------------------

Implement a function which prints the perimeter of a binary tree.

The perimeter is defined as follows :
- leftmost nodes from top to bottom
- leaf nodes from left to right
- rightmost nodes from bottom to top

The binary tree uses the following node structure :

	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

The function prints on the standard output the value of the nodes
seperated by a single space and with a new line at the end.

The function must be declared as follows:

	void perimeter(struct s_node *root);


EXAMPLE :

	For the following tree :

	                 92
	                 / \
	                /   \
	               85   26
	              /       \
	             79       64
	              \       / \
	              10     /   \
	              /     /     \
	             39    /       \
	            /     /         \
	           35    /           \
	          /     /             \
	         96    /               \
	              /                 \
	             40                 78
	            / \                 / \
	           /   \               /   \
	          /     \             2    85
	         /       \           / \     \
	        /         \         /   \    51
	       /           \       /     \
	      /             \     33     11
	     88             10     \     /
	    / \             / \    55   99
	   /   \           /   \
	  12   55         52   87
	 /     / \       / \     \
	58    /   \     /   \    31
	     58   41   22   35

	the output would be :

	92 85 79 96 58 58 41 22 35 31 55 99 51 85 78 64 26


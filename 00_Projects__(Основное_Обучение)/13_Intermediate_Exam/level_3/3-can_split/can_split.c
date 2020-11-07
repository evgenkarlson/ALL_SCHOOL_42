// Passed Moulinette 2019.09.01

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	count_nodes(struct s_node *n, int *half_tree_size, int *answer_found)
{
	if (n == 0 || *answer_found == 1)
		return (0);

	int local_size = 1 + count_nodes(n->left, half_tree_size, answer_found) \
						+ count_nodes(n->right, half_tree_size, answer_found);
	if (local_size == *half_tree_size)
		*answer_found = 1;
	return (local_size);
}

int	can_split(struct s_node *n)
{
	int tree_size = -1;
	int answer_found = 0;
	tree_size = count_nodes(n, &tree_size, &answer_found);
	if (tree_size % 2 == 1)
		return (0);

	tree_size /= 2;
	count_nodes(n, &tree_size, &answer_found);

	return (answer_found);
}

//--------------------------------------------------------------
// #include <stdio.h>
// #define NODE(value, left, right) &(struct s_node){value, left, right}

// int	main(void)
// {
// 	//            10
// 	//            / \
// 	//           11  9
// 	//          / \   \
// 	//         /   \   \
// 	//        6     9   8
// 	//       / \         \
// 	//      /   \         \
// 	//     7   13          7
// 	//    /                 
// 	//   /                   
// 	//  8                     

// 	struct s_node *root1 = NODE(
// 		10,
// 		NODE(
// 			11,
// 			NODE(
// 				6,
// 				NODE(7, 
// 					NODE(8, NULL, NULL),
// 					NULL
// 					),
// 				NODE(13, NULL, NULL)
// 				),
// 			NODE(9, NULL, NULL)
// 			),
// 		NODE(
// 			9,
// 			NODE(
// 				8,
// 				NODE(
// 					7,
// 					0, //NODE(6, NULL, NULL),
// 					0
// 					),
// 				NULL
// 				),
// 			NULL)
// 		);
// 	printf("Should be 0: %d\n", can_split(root1));

// 	struct s_node *root2 = NODE(1, 0, 0);
// 	printf("Should be 0: %d\n", can_split(root2));

// 	struct s_node *root3 = NODE(1, NODE(2, 0, 0), 0);
// 	printf("Should be 1: %d\n", can_split(root3));

// 	struct s_node *root4 = 0;
// 	printf("Should be 0: %d\n", can_split(root4));
// }
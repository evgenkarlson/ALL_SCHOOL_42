// Passed Moulinette 2019.09.01

typedef struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
}				Node;

void reverse_tree(struct s_node *root)
{
	if (root == 0)
		return;

	struct s_node *swap = root->left;
	root->left = root->right;
	root->right = swap;

	reverse_tree(root->left);
	reverse_tree(root->right);
}

//--------------------------------------------------------------
// #include <stdio.h>
// #define NODE(value, left, right) &(struct s_node){value, left, right}

// void	print_in_order(struct s_node *node)
// {
// 	if (!node)
// 		return;

// 	if (node->left)
// 		print_in_order(node->left);
// 	printf("%d, ", node->value);
// 	if (node->right)
// 		print_in_order(node->right);
// }

// int	main(void)
// {
// /*
//            10
//            / \
//           11  9
//          / \   \
//         /   \   \
//        6     9   8
//       / \         \
//      /   \         \
//     7   13          7
//    /                 \
//   /                   \
//  8                     6

// Longest sequence: 3 (6 -> 7 -> 8)
// */
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
// 					NODE(6, NULL, NULL),
// 					NULL
// 					),
// 				NULL
// 				),
// 			NULL)
// 		);
// 	print_in_order(root1);
// 	printf("\n");
// 	reverse_tree(root1);
// 	print_in_order(root1);
// 	printf("\n");

// 	struct s_node *root2 = NULL;
// 	reverse_tree(root2);
// }
// Passed Moulinette 2019.09.01

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	max_three(int a, int b, int c)
{
	return ((a > b) ? ((a > c) ? a : c) : (b > c) ? b : c);
}

int	recur(struct s_node *node, int *longest_seq)
{
	if (node == 0)
		return (0);
	int left = recur(node->left, longest_seq);
	int right = recur(node->right, longest_seq);
	int continuity = 0;

	if (node->left && node->left->value == node->value + 1)
	{
		left++;
		continuity = 1;
	}
	if (node->right && node->right->value == node->value + 1)
	{
		right++;
		continuity = 1;
	}

	int local_longest = max_three(1, left, right);
	if (local_longest > *longest_seq)
		*longest_seq = local_longest;
	if (continuity == 1)
		return (local_longest);
	return (1);
}

int	longest_sequence(struct s_node *node)
{
	int longest_seq = 0;
	recur(node, &longest_seq);
	return (longest_seq);
}

//--------------------------------------------------------------
// #include <stdio.h>
// #define NODE(value, left, right) &(struct s_node){value, left, right}
// int	main(void)
// {
// /*
//            10
//            / \
//           16  9
//          / \   \
//         /   \   \
//        6     17  8
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
// 			16,
// 			NODE(
// 				6,
// 				NODE(7, 
// 					NODE(8, NULL, NULL),
// 					NULL
// 					),
// 				NODE(13, NULL, NULL)
// 				),
// 			NODE(17, NULL, NULL)
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
// 	printf("Should be 3: %d\n", longest_sequence(root1));

// 	struct s_node *root2 = NULL;
// 	printf("Should be 0: %d\n", longest_sequence(root2));

// 	struct s_node *root3 = NODE(1, NODE(2, NODE(3, NODE(4, NULL, NULL), NULL), NULL), NULL);
// 	printf("Should be 4: %d\n", longest_sequence(root3));
// }

//---------------------------------------------------

//Does not pass Moulinette

// #include <stdio.h>

// struct s_node 
// {
// 	int value;
// 	struct s_node *left;
// 	struct s_node *right;
// };

// int	max(int a, int b)
// {
// 	return ((a > b) ? a : b);
// }

// int	recur(struct s_node *node, int *max_len)
// {
// 	if (node == 0)
// 		return (0);

// 	int local_len;
// 	local_len = max(recur(node->left, max_len), recur(node->right, max_len));
// 	if ((node->left && node->value + 1 == node->left->value)
// 		|| (node->right && node->value + 1 == node->right->value))
// 	{
// 		local_len++;
// 		if (*max_len < local_len)
// 			*max_len = local_len;
// 	}
// 	else
// 		local_len = 1;

// 	return (local_len);
// }

// int	longest_sequence(struct s_node *node)
// {
// 	int max_len = 0;
// 	recur(node, &max_len);
// 	return (max_len);
// }

//--------------------------------------------------------------
// #include <stdio.h>
// #define NODE(value, left, right) &(struct s_node){value, left, right}
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
// 	printf("%d\n", longest_sequence(root1));

// 	struct s_node *root2 = NULL;
// 	printf("%d\n", longest_sequence(root2));

// 	struct s_node *root3 = NODE(1, NODE(2, NODE(3, NODE(4, NULL, NULL), NULL), NULL), NULL);
// 	printf("%d\n", longest_sequence(root3));
// }

//-------------------------------

// Does not pass Moulinette

// struct s_node 
// {
// 	int value;
// 	struct s_node *left;
// 	struct s_node *right;
// };

// int	max(int a, int b)
// {
// 	return ((a > b) ? a : b);
// }

// int	recur(struct s_node *node, int *max_len)
// {
// 	if (node == 0)
// 		return (1);

// 	int local_left = recur(node->left, max_len);
// 	int local_right = recur(node->right, max_len);
// 	if (node->left && node->value + 1 == node->left->value)
// 		local_left++;
// 	if (node->right && node->value + 1 == node->right->value)
// 		local_right++;

// 	int local_len = max(local_left, local_right);
// 	if (*max_len < local_len)
// 		*max_len = local_len;
// 	return (local_len);
// }

// int	longest_sequence(struct s_node *node)
// {
// 	int max_len = 0;
// 	recur(node, &max_len);
// 	return (max_len);
// }

//--------------------------------------------------------------
// #include <stdio.h>
// #define NODE(value, left, right) &(struct s_node){value, left, right}
// int	main(void)
// {
// /*
//            10
//            / \
//           16  9
//          / \   \
//         /   \   \
//        6     17  8
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
// 			16,
// 			NODE(
// 				6,
// 				NODE(7, 
// 					NODE(8, NULL, NULL),
// 					NULL
// 					),
// 				NODE(13, NULL, NULL)
// 				),
// 			NODE(17, NULL, NULL)
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
// 	printf("Should be 3: %d\n", longest_sequence(root1));

// 	struct s_node *root2 = NULL;
// 	printf("Should be 0: %d\n", longest_sequence(root2));

// 	struct s_node *root3 = NODE(1, NODE(2, NODE(3, NODE(4, NULL, NULL), NULL), NULL), NULL);
// 	printf("Should be 4: %d\n", longest_sequence(root3));
// }
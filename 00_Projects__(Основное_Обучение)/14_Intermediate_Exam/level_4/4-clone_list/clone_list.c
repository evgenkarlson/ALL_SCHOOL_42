// Passed Moulinette 2019.09.01

#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node	*create_node(int data)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->data = data;
	new->next = NULL;
	new->other = NULL;
	return (new);
}

int				find_node_index(struct s_node *needle, struct s_node *haystack)
{
	int i = 0;

	while (haystack)
	{
		if (needle == haystack)
			return (i);
		++i;
		haystack = haystack->next;
	}
	return (-1);
}

struct s_node	*get_node_by_index(int index, struct s_node *haystack)
{
	int i = 0;

	while (i < index)
	{
		++i;
		haystack = haystack->next;
	}
	return (haystack);
}

struct s_node	*clone_list(struct s_node *node)
{
	if (node == NULL)
		return (NULL);

	struct s_node *head = node;
	struct s_node *new_head = create_node(head->data);
	struct s_node *new_cur = new_head;
	node = node->next;
	while (node)
	{
		new_cur->next = create_node(node->data);
		new_cur = new_cur->next;
		node = node->next;
	}

	node = head;
	new_cur = new_head;
	while (node)
	{
		if (node->other != NULL)
			new_cur->other = get_node_by_index(find_node_index(node->other, head), new_head);
		new_cur = new_cur->next;
		node = node->next;
	}

	return (new_head);
}

//-------------------------------------------------------------------------
// #include <stdio.h>
// void	print_list(struct s_node *head)
// {
// 	while (head)
// 	{
// 		printf("Node: %p\nData: %d\nOther: %p; ", head, head->data, head->other);
// 		if (head->other)
// 			printf("%d", head->other->data);
// 		printf("\n---\n");
// 		head = head->next;
// 	}
// }

// int		main(void)
// {
// 	struct s_node *head = create_node(5);
// 	head->next = create_node(10);
// 	head->next->next = create_node(15);
// 	head->next->next->next = create_node(20);
// 	head->next->next->next->next = create_node(25);
// 	head->next->next->next->next->next = create_node(30);
// 	head->next->next->next->next->next->other = head->next->next->next->next; //25
// 	head->next->next->next->next->other = head; //5
// 	head->next->next->next->other = head->next; //10
// 	head->next->next->other = head->next->next; //15
// 	print_list(head);
// 	printf("\n\n");

// 	print_list(clone_list(head));
// }
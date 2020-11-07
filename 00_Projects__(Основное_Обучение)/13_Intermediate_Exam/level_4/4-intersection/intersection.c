// Passed Moulinette 2019.09.01

struct s_node {
	void *content;
	struct s_node *next;
};

int		find_match(struct s_node *needle, struct s_node *haystack)
{
	while (haystack)
	{
		if (needle == haystack)
			return (1);
		haystack = haystack->next;
	}
	return (0);
}

void	*intersection(struct s_node *lst1, struct s_node *lst2)
{
	while (lst1)
	{
		if (find_match(lst1, lst2))
			return (lst1);
		lst1 = lst1->next;
	}
	return (0);
}

//-----------------------------------------------------------
// #include <stdio.h>
// #include <stdlib.h>

// struct s_node *create_node(void)
// {
// 	struct s_node *cur = malloc(sizeof(struct s_node));
// 	cur->next = 0;
// 	cur->content = 0;
// 	return (cur);
// }

// int	main(void)
// {
// 	struct s_node *head1 = create_node();
// 	head1->next = create_node();
// 	head1->next->next = create_node();
// 	head1->next->next->next = create_node();
// 	head1->next->next->next->next = create_node();

// 	struct s_node *head2 = create_node();
// 	head2->next = create_node();
// 	head2->next->next = create_node();
// 	head2->next->next->next = create_node();
// 	head2->next->next->next->next = create_node();

// 	printf("%p\n", intersection(head1, head2));

// 	head2->next->next->next->next->next = head1->next->next->next->next;
// 	printf("%p\n", intersection(head1, head2));
// }
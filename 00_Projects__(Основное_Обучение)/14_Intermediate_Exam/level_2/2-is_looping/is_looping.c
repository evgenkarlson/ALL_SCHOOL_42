// Passed Moulinette 2019.09.01

#include <string.h>

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	if (node == NULL || node->next == NULL)
		return (0);
	struct s_node *slow = node;
	struct s_node *fast = node->next;

	while (fast->next && fast->next->next)
	{
		if (fast == slow)
			return (1);
		fast = fast->next->next;
		slow = slow->next;
	}
	return (0);
}


// //----------------------------
// #include <stdio.h>
// #include <stdlib.h>
// struct s_stack {
// 	struct s_node *top;
// };

// struct s_stack *init(void)
// {
// 	 struct s_stack *stack = malloc(sizeof(struct s_stack));
// 	 stack->top = NULL;
// 	return (stack);
// }

// int pop(struct s_stack *stack)
// {
// 	if (stack == NULL || stack->top == NULL)
// 		return (0);
// 	struct s_node *node = stack->top;
// 	int value = node->value;
// 	stack->top = node->next;
// 	free(node);
// 	return (value);
// }

// void push(struct s_stack *stack, int value)
// {
// 	if (stack == NULL)
// 		return ;

// 	struct s_node *node = malloc(sizeof(struct s_node));
// 	node->value = value;
// 	node->next = stack->top;
// 	stack->top = node;
// }

// int peek(struct s_stack *stack)
// {
// 	if (stack == NULL || stack->top == NULL)
// 		return (0);
// 	return (stack->top->value);
// }

// int isEmpty(struct s_stack *stack)
// {
// 	if (stack == NULL || stack->top == NULL)
// 		return (1);
// 	return (0);
// }

// int	main(void)
// {
// 	struct s_stack *stack = init();
	
// 	push(stack, 1);
// 	// push(stack, 2);
// 	// push(stack, 3);
// 	// push(stack, 4);
// 	// push(stack, 5);
// 	// push(stack, 6);
// 	// push(stack, 7);
// 	// push(stack, 8);
// 	// push(stack, 9);
// 	// push(stack, 10);

// 	stack->top->next = stack->top;

// 	printf("is looping? %d\n",
// 		is_looping(stack->top)
// 		);
// }
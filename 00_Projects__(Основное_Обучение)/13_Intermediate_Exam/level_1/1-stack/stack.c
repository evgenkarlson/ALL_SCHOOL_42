// Passed Moulinette 2019.09.01

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	 struct s_stack *stack = malloc(sizeof(struct s_stack));
	 stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return (NULL);
	struct s_node *node = stack->top;
	void *content = node->content;
	stack->top = node->next;
	free(node);
	return (content);
}

void push(struct s_stack *stack, void *content)
{
	if (stack == NULL)
		return ;

	struct s_node *node = malloc(sizeof(struct s_node));
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}

void *peek(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return (1);
	return (0);
}



// //--------------------------------------------
// #include <stdio.h>
// int 	main(void)
// {
// 	char a[] = "aaaaa";			(void)a;
// 	char b[] = "bbbbb";			(void)b;
// 	char c[] = "ccccc";			(void)c;
// 	char d[] = "dddddicks";		(void)d;
// 	struct s_stack *stack;

// 	stack = init(); 			(void)stack;
// 	printf("isEmpty: %d\n", isEmpty(stack));
// 	printf("peek: %s\n", peek(stack));
// 	printf("pop: %s\n", pop(stack));
// 	push(stack, a); push(stack, b); push(stack, c); push(stack, d);
// 	printf("isEmpty: %d\n", isEmpty(stack));
// 	printf("peek: %s\n", peek(stack));
// 	printf("pop: %s\n", pop(stack));
// 	printf("pop: %s\n", pop(stack));
// 	printf("pop: %s\n", pop(stack));
// 	printf("pop: %s\n", pop(stack));
// 	printf("pop: %s\n", pop(stack));
// 	printf("isEmpty: %d\n", isEmpty(stack));

// 	return (0);
// }
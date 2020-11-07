// Passed Moulinette 2019.09.01

#include <stdlib.h>

	struct s_node {
		void *content;
		struct s_node *next;
	};

	struct s_queue {
		struct s_node *first;
		struct s_node *last;
	};

struct s_queue *init(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return(queue);
}

void enqueue(struct s_queue *queue, void *content)
{
	if (queue == NULL)
		return;

	struct s_node *cur = malloc(sizeof(struct s_node));
	cur->content = content;
	cur->next = NULL;
	if (queue->first == NULL)
		queue->first = cur;
	else
		queue->last->next = cur;
	queue->last = cur;
}

void *dequeue(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (NULL);

	struct s_node *cur = queue->first;
	if (cur == queue->last)
		queue->last = NULL;
	queue->first = cur->next;
	void *content = cur->content;
	free(cur);
	return (content);
}

void *peek(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (1);
	return (0);
}

//------------------------------------------------------
// #include <stdio.h>
// int main(void)
// {
// 	char a[] = "Apples"; (void)a;
// 	char b[] = "Banananananas"; (void)b;
// 	char c[] = "Charlemagne"; (void)c;
// 	char d[] = "ddddduodenum"; (void)d;

// 	struct s_queue *queue = init();
// 	printf("isEmpty A: %d\n", isEmpty(queue));
// 	enqueue(queue, a);
// 	printf("isEmpty B: %d\n", isEmpty(queue));
// 	enqueue(queue, b);
// 	enqueue(queue, c);
// 	enqueue(queue, d);

// 	printf("Peek: %s\n", peek(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Pop: %s\n", dequeue(queue));
// 	printf("Peek: %s\n", peek(queue));
// 	printf("isEmpty C: %d\n", isEmpty(queue));
// 	return (0);
// }
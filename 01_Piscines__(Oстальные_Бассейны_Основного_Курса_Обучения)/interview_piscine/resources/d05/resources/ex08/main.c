#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>
#include <ctype.h>

#include "header.h"

int main(int ac, char **av)
{
	struct s_node *node = malloc(sizeof(struct s_node));

	if (ac == 2){
		node = getBoardFromFile(av[1]);
	}
	else {
		printf("Usage: ./slmSolver board.slm\n");
		return (0);
	}

	/*-------------------
	launch your test here
	--------------------*/
	// printf("%d\n", minimumMoves(node));
	
	return (0);
}



// Function used for the test
// Don't go further :)

// STACK

struct s_stack *init(void) {
	struct s_stack *stack;

	if (!(stack = (struct s_stack *)malloc(sizeof(struct s_stack))))
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack) {
	void *content;
	struct s_stackNode *tmp;

	if (stack->top == NULL)
		return (NULL);
	content = stack->top->content;
	tmp = stack->top;
	stack->top = tmp->next;
	free(tmp);
	return (content);
}

void push(struct s_stack *stack, void *content) {
	struct s_stackNode *node;

	if (!(node = (struct s_stackNode *)malloc(sizeof(struct s_stackNode))))
		return ;
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}

// QUEUE

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}


void enqueue(struct s_queue *queue, void * value)
{
	struct s_queueNode *tmp;

	if (!(tmp = (struct s_queueNode *)malloc(sizeof(struct s_queueNode))))
		return ;
	tmp->value = value;
	tmp->next = NULL;
	if (queue->last == NULL) {
		queue->last = tmp;
		queue->first = queue->last;
		return ;
	}
	queue->last->next = tmp;
	queue->last = tmp;
}

void	*dequeue(struct s_queue *queue)
{
	struct s_queueNode *tmp;
	void *value;

	if (queue->last == NULL)
		return (NULL);
	tmp = queue->first;
	value = tmp->value;
	queue->first = tmp->next;
	if (queue->first == NULL)
		queue->last = NULL;
	free(tmp);
	return (value);
}

//DICTIONNARY

int	dictInsert(struct s_dict *dict, void *key, int value)
{
	int pos;
	struct s_item *tmp;
	struct s_item *tmpBefore;

	if (!dict || !key)
		return (-1);

	pos = (unsigned int)key % dict->capacity;
	tmpBefore = NULL;
	tmp = dict->items[pos];


	//add the new item using push front method
	while (tmp){
		tmpBefore = tmp;
		tmp = tmp->next;
	}
	if (NULL == (tmp = malloc(sizeof(struct s_item))))
		return (0);
	if (tmpBefore != NULL)
		tmpBefore->next = tmp;
	else
		dict->items[pos] = tmp;
	tmp->key = key;
	tmp->value = value;
	tmp->next = NULL;
	return (1);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict;

	if (NULL == (dict = malloc(sizeof(struct s_dict))))
		return (NULL);

	dict->capacity = capacity;

	//calculate len
	if (NULL == (dict->items = malloc(sizeof(struct s_item *) * (dict->capacity))))
		return (NULL);

	//clearing the hashdict
	dict->items = memset(dict->items, 0, sizeof(struct s_item *) * dict->capacity);

	return (dict);
}

int	dictSearch(struct s_dict *dict, void *key)
{
	int pos;
	struct s_item *tmp;

	pos = (unsigned int)key % dict->capacity;
	tmp = dict->items[pos];
	while (tmp){
		if (tmp->key == key) 
			return (tmp->value);
		tmp = tmp->next;
	}
	return (-1);
}

//PARSING

char    *readFile(char *filename)
{
        char *fcontent = NULL;
        int size = 0;
        FILE *fp;

        if (NULL == (fp = fopen(filename, "r")))
                return (NULL);
        fseek(fp, 0L, SEEK_END);
        size = ftell(fp);
        rewind(fp);
        if (NULL == (fcontent = malloc(sizeof(char) * (size + 1))))
                return (NULL);
        fread(fcontent, 1, size, fp);
        fclose(fp);
        return (fcontent);
}


char	**split(char *str, char *delimiter) {
	char **tab;
	int count;
	int a;
	int pos;
	int len_delimiter;
	int len_substring;

	len_delimiter = strlen(delimiter);
	len_substring = 0;
	count = 0;
	//first counting the number of substring
	for (int i = 0; str[i]; i++){
		if (strncmp(str + i, delimiter, len_delimiter) == 0) {
			if (len_substring > 0){
				len_substring = 0;
				count += 1;
			}
			i += len_delimiter - 1;
		} else {
			len_substring += 1;
		}
	}
	if (len_substring > 0){
		count += 1;
	}
	if (NULL == (tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[(a = 0)] = NULL;
	len_substring = 0;
	pos = 0;
	//then get the substring :)
	for (int i = 0; str[i]; i++){
		if (strncmp(str + i, delimiter, len_delimiter) == 0) {
			if (len_substring > 0){
				tab[(a++)] = strndup(str + pos, len_substring);
				len_substring = 0;
			}
			i += len_delimiter - 1;
			pos = i + 1;
		} else {
			len_substring += 1;
		}
	}
	if (len_substring > 0){
		tab[(a++)] = strndup(str + pos, len_substring);
	}
	tab[a] = NULL;
	return (tab);
}

void	parseFail(char *msg){
	printf("PARSE ERROR: %s\n", msg);
	exit(3);
}

//first read, just get the linked list, no the access
struct s_node *readLine(char *line, int isBoard){
	char **elems;
	struct s_node *b;
	struct s_node *e;
	struct s_node *tmp;
	// int i;

	b = NULL;
	elems = split(line, "->");
	for (int i = 0; elems[i]; i++){ 
		tmp = malloc(sizeof(struct s_node));
		if (atoi(elems[i]) != i + 1){
			printf("(%s) __%s__ %d vs %d\n", line, elems[i], atoi(elems[i]),i+1); 
			parseFail("the list must be 1, 2, 3, 4...\n");
		}
		tmp->value = i + 1;
		tmp->next = NULL;
		tmp->isFinal = (isBoard == 1 && !elems[i + 1]) ? 1 : 0;
		tmp->random = NULL;
		if (!b){
			b = tmp;
			e = b;
		}else{
			e->next = tmp;
			e = e->next;
		}
	}
	return (b);
}

void	addAccess(struct s_node **branches, int len, char *nodeRepresentation, struct s_node *currentNode)
{
	int posAccess = 0;
	int nodeAccess = 0;
	char **splitted = split(nodeRepresentation, "(");
	if (!splitted[0] || !splitted[1])
		parseFail("each node must be like this: n()\n");
	char **access = split(splitted[1], ".");
	if (!access[0] || (access[0] && !access[1]))
		return ;
	if (strcmp(access[0], "b") == 0){
		posAccess = 0;
	}
	else if (strncmp(access[0], "m", 1) == 0 && isdigit(access[0][1]))
	{
		posAccess = atoi(access[0] + 1);
		if (posAccess >= len)
			parseFail("try to random access to a mirage which doesn\'t exist\n");
	}
	nodeAccess = atoi(access[1]);
	struct s_node *n;
	int i;

	n = branches[posAccess];
	for (i = 0; i + 1 < nodeAccess && n; i++){
		n = n->next;
	}
	if (i + 1 != nodeAccess){
		parseFail("Error while accessing a node which doesn't exist\n");
	}
	currentNode->random = n;
}

void	getAccess(struct s_node **branches, int len, int pos, char *line){
	char **elems = split(line, "->");
	struct s_node *n;

	n = branches[pos];
	for (int i = 0; elems[i]; i++){
		addAccess(branches, len, elems[i], n);
		n = n->next;
	}
}	

struct s_node *getBoardFromFile(char *file)
{
	char *str = readFile(file);
	char **lines = split(str, "\n");
	struct s_node **branches;
	int n;

	//first counting
	n = 0;
	for (int i = 0; lines[i]; i++){
		if (strcmp(lines[i], "b") == 0
				|| (strncmp(lines[i], "m", 1) == 0 && isdigit(lines[i][1]))) {
			n += 1;
		}
	}
	branches = malloc(sizeof(struct s_node *) * (n + 1));
	//now filling the branches
	int l = 0;
	for (int i = 0; lines[i]; i++){
		if (strcmp(lines[i], "b") == 0){
			if (l != 0)
				parseFail("you should put b on top\n");
			branches[l] = readLine(lines[i + 1], 1);
			l += 1;
		}
		else if (strncmp(lines[i], "m", 1) == 0
				&& isdigit(lines[i][1])){
			if (atoi(lines[i] + 1) != l)
				parseFail("bad index for a mirage\n");
			branches[l] = readLine(lines[i + 1], 0);
			l += 1;
		}
	}
	branches[l] = NULL;
	//now give the access
	int pos;
	for (int i = 0; lines[i]; i++){
		if (strcmp(lines[i], "b") == 0
				|| (strncmp(lines[i], "m", 1) == 0 && isdigit(lines[i][1]))) {
			if (strcmp(lines[i], "b") == 0)
				pos = 0;
			else
				pos = atoi(lines[i] + 1);
			getAccess(branches, n, pos, lines[i + 1]);
		}
	}
	/*for (int i = 0; i < n; i++){
		struct s_node *tmp = branches[i];
		while (tmp){
			printf("%d %s (%d) -> ", tmp->value, (tmp->isFinal) ? "FINAL" : "", (tmp->random) ? tmp->random->value : 0);
			tmp = tmp->next;
		}
		printf("END\n");
	}*/
	return (branches[0]);
}


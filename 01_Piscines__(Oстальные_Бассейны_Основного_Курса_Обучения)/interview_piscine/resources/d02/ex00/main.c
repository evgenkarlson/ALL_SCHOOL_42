#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	struct s_stone *stone;

	stone = genRandomStoneList(30); //if param == 0, the length of the list will be between 1 and 1 million

	printStone(stone);
	/*-------------------
	launch your test here
	--------------------*/
	//sortStones(&stone);
	//printStone(stone);

	return (0);
}


// Function used for the test
// Don't go further :)

void printStone(struct s_stone *stone){
	while (stone){
		printf("%d ", stone->size);
		stone = stone->next;
	}
	printf("\n");
}

struct s_stone *genRandomStoneList(int n)
{
	struct s_stone *begin;
	struct s_stone *tmp;
	struct s_stone *newStone;
	int repeat;
	int size;
	int total;

	srand(time(NULL));
	if (n <= 0 || n > 1000000){
		n = rand() % 1000000 + 1; //generating int between 1 and 1 million
	}
	tmp = NULL;
	begin = NULL;
	repeat = 0;
	total = 0;
	while (total < n){
		if (repeat <= 0){
			usleep(2);
			size = rand() % n + 1;
			usleep(2);
			repeat = rand() % ((n - total) / 2 + 1) + 1;
		}
		if (!(newStone = createStone(size)))
			exitWithMsg("failed to generating the linked list");
		if (tmp){
			tmp->next = newStone;
			tmp = tmp->next;
		}else{
			tmp = newStone;
			begin = tmp;
		}
		repeat -= 1;
		total += 1;
	}
	printf("generating a list of stones with %d element%c\n", n, (n > 1) ? 's' : '\0');
	return (begin);
}

struct s_stone *createStone(int size){
	struct s_stone *stone = malloc(sizeof(struct s_stone));
	if (stone)
	{
		stone->size = size;
		stone->next = NULL;
	}
	return (stone);
}

void exitWithMsg(char *msg){
	printf("%s\n", msg);
	exit(1);
}

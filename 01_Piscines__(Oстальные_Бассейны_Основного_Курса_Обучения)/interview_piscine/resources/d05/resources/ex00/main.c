#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int pizzaSize = 3;

	if (ac >= 2)
		pizzaSize = atoi(av[1]);

	printf("Slices with a pizza of size %d:\n", pizzaSize);
	/*-------------------
	launch your test here
	--------------------*/
	// printPossibleSlices(pizzaSize);

	return (0);
}



// Function used for the test
// Don't go further :)

struct s_array *arrayInit(void)
{
        struct s_array *arr;

        arr = malloc(sizeof(struct s_array));
        arr->length = 0;
		arr->sum = 0;
        arr->capacity = 1024; //array of 1024 int, at the beginning
        arr->content = malloc(sizeof(int) * (arr->capacity));
        return (arr);
}

//0 = FAIL, 1 = SUCCESS
int     arrayResize(struct s_array *arr)
{
        int    *new_content;

        arr->capacity *= 2;
        new_content = malloc(sizeof(int) * (arr->capacity));
        if (!new_content)
                return (0);
        for (int i = 0; i < arr->length; i++){
		new_content[i] = arr->content[i];
		}
        free(arr->content);
        arr->content = new_content;
        return (1);
}

//0 = FAIL, 1 = SUCCESS
int     arrayAppend(struct s_array *arr, int number)
{
        if (arr->length + 1 > arr->capacity){
                if (!arrayResize(arr))
                        return (0);
        }
        arr->content[arr->length] = number;
		arr->sum += number;
        arr->length += 1;
        return (1);
}


void	arrayPrint(struct s_array *arr)
{
	if (!arr){
		printf("NULL\n");
		return ;
	}
	printf("[");
	for (int i = 0; i < arr->length; i++){
		printf("%d", arr->content[i]);
		if (i + 1 < arr->length)
			printf(", ");
	}
	printf("]\n");
}

struct s_array *arrayClone(struct s_array *arr)
{
	struct s_array *copy;

	copy = malloc(sizeof(struct s_array));
	if (!copy)
		return (NULL);
	copy->content = malloc(sizeof(int) * (arr->capacity + 1));
	for (int i = 0; i < arr->length; i++){
		copy->content[i] = arr->content[i];
	}
	copy->length = arr->length;
	copy->sum = arr->sum;
	copy->capacity = arr->capacity;
	return (copy);
}

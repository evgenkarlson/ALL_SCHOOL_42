#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <sys/resource.h>
#include <sys/stat.h>

#include "header.h"


int main(void)
{
	/*-------------------
	launch your test here
	--------------------*/

	// externalSort(SCOREFILE, SORTEDFILE, 8000);
	// printf("The file %s is%s sorted\n", SORTEDFILE, (fileIsSorted(SORTEDFILE)) ? "" : " NOT");

	return (0);
}

// Function used for the test
// Don't go further :)


// struct s_block *fileGetBlock(char *filename, int start, int end)
// {
// 	 struct s_block *block;
// 	 char line[256];
// 	 int pos = 0;
// 	 int a = 0;
// 	 // int total;

// 	 block = malloc(sizeof(struct s_block));
// 	 block->n = end - start;
// 	 block->scores = malloc(sizeof(int) * (block->n));
// 	 FILE *fp = fopen (filename, "r");
// 	 fgets(line, sizeof(line), fp); //skipping the first one
// 	 while (fgets(line, sizeof(line), fp))
// 	 {
// 		 if (pos > end){
// 			 break;
// 		 }
// 		 if (pos >= start){
// 			 block->scores[a] = atoi(line);
// 			 a += 1;
// 		 }
// 		 pos += 1;
// 	 }
//    fclose(fp);
// 	 return (block);
// }

// int fileGetTotalScores(char *filename)
// {
//    FILE *fp = fopen (filename, "r");
// 	 char line[256];
// 	 int tmp;

// 	 fgets(line, sizeof(line), fp);
// 	 tmp  = atoi(line);
//    fclose(fp);
// 	 return (tmp);
// }

// int filePutBlock(char *filename, struct s_block *block)
// {
//   FILE *fp;
//   fp = fopen (filename, "w+");
// 	fprintf(fp, "%d\n", block->n);
// 	for (int i = 0; i < block->n; i++){
// 		fprintf(fp, "%d\n", block->scores[i]);
// 	}
// 	fclose(fp);
// 	return (1);
// }

FILE *openFile(char *filename, char *flag) {
	FILE *f;

	if (!(f = fopen(filename, flag))) {
		dprintf(STDERR_FILENO, "Couldn't find %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (f);
}

int readBlock(FILE *f, int *arr, int size) {
	int i = 0;

	while(i < size && fscanf(f, "%d", &(arr[i])) > 0) {
		i++;
	}
	return (i);
}

void writeFile(char *filename, int *arr, int n) {
	FILE *f = openFile(filename, "w");

	for (int i = 0; i < n; i++) {
		fprintf(f, "%d\n", arr[i]);
	}
	fclose(f);
}

int fileIsSorted(char *filename) {
	FILE *f = openFile(filename, "r");
	int isSorted = 1;
	int previous = -1;
	int current;

	while (fscanf(f, "%d", &current) > 0) {
		if (previous != -1 && current < previous){
			isSorted = 0;
			break;
		}
		previous = current;
	}
	fclose(f);
	return (isSorted);
}
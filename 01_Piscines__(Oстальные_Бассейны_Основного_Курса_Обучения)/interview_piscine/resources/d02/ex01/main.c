#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	struct s_player **players;

	players = genRandomPlayers(30); //if param == 0, the length of the list will be random between 1 and 1.000

	/*-------------------
	launch your test here
	--------------------*/
	printPlayers(players);
	//printf("doing the insertion sort...\n");
	//insertionSort(players);
	//printPlayers(players);

	return (0);
}


// Function used for the test
// Don't go further :)

void printPlayers(struct s_player **players)
{
	printf("⭐  LEADER BOARD ⭐ \n");
	for (int i = 0; players[i]; i++) {
		printf("%d: %s with %d\n", i + 1, players[i]->name, players[i]->score);
	}
}

struct s_player **genRandomPlayers(int n){
	struct s_player **players;
	char *names[] = { "Beatriz Leroy", "Fernando Fradin", "Claud Lannoy", "Heriberto Franceschi", "Joleen Olsen", "Zula Inesta", "Keturah Bidault", "Helaine Weibel", "Elba Corre", "Terisa Uberti", "Yoshie Taupin", "Hannah Hamza", "Enid Aubree", "Kimberlie Claudel", "Clora Tisserand", "Sadie Urbanek", "Pearlene Virot", "Monique Napolitano", "Madelene Ibouroi", "Richelle Arnal", "Mathilde Bernard", "Lolita Delamare", "Irina Oberle", "Delila Kayser", "Catrina Iglesias", "Louis Barbara", "Michel Willerval", "Freda Quennesson", "Lilli Quersin", "Marlene Nelson", "Coreen Triquet", "Lyda Gombert", "Cherilyn Zemouri", "Shawnee Kanza", "Pasty Witkowski", "Omar Theron", "Wilhelmina Valles", "Valery Stein", "Angelic Hell", "Bobby Ducrocq", "Holley Gillot", "Samatha Rogier", "Vina Wasser", "Lita Benali", "Jessica Habib", "Clelia Usan", "Marquitta Quetier", "Lynetta Kevin", "Alica Wallerand", "Stephaine Zoro", "Perla Julienne", "Alease Damiens", "Jeannie Erdmann", "Stella Abed", "Iraida Collet", "Josette Wasser", "Pasquale Khoury", "Gudrun Hagege", "Yee Der", "Jae Techer", "Lizbeth Vallon", "Kamilah Garde", "Van Queiroz", "Keena Grimaud", "Corinne Ordonneau", "Candyce Duthoit", "Claris Isard", "Annamaria Pochon", "Isabel Guen", "Misha Odiot", "Natalie Stoll", "Ralph Mike", "Josefa Taha", "Brandon Issert", "Meredith Uhmann", "Lilliana Naas", "Toi Nectoux", "Leeanne Espinasse", "Marcene Montana", "Maxine Lecerf", "Zachery Erdmann", "Nena Jourdan", "Waneta Gerardin", "Penney Moro", "Amelia Karam", "Mei Onfray", "Elodia Cauvin", "Jeanne Exposito", "Ladawn Uzan", "Lorina Farmer", "Rosalyn Westrelin", "Harriet Undostres", "Adrianne Guilloux", "Man Vassal", "Tamesha Soriano", "Logan Zurita", "Kathlyn Eschenbrenner", "Laverna Rousselot", "Manda Dore", "Shelba Gloaguen" };

	srand(time(NULL));
	if (n <= 0 || n > 1000){
		n = rand() % 1000 + 1; //generating int between 1 and 1.000
	}
	players = malloc(sizeof(struct s_player *) * (n + 1));
	for (int i = 0; i < n; i++)
	{
		players[i] = createRandomPlayer(names[rand() % 100]);
	}
	players[n] = NULL;
	return (players);
}

struct s_player *createRandomPlayer(char *name){
	struct s_player *player = malloc(sizeof(struct s_player));
	if (player){
		player->name = name;
		usleep(2);
		player->score = (rand() % 10000) / 10 * 10;
	}
	return (player);
}

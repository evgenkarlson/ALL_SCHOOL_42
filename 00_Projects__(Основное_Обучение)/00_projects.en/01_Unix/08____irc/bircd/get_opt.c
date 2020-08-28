
#include <stdio.h>
#include <stdlib.h>
#include "bircd.h"

void	get_opt(t_env *e, int ac, char **av)
{
  if (ac != 2)
    {
      fprintf(stderr, USAGE, av[0]);
      exit(1);
    }
  e->port = atoi(av[1]);
}


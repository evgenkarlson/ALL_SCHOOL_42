/*
** mlx_flush_event.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Wed Aug  2 18:58:11 2000 Charlie Root
** Last update Fri Feb 23 17:08:48 2001 Charlie Root
*/


#include	"mlx_int.h"




int	mlx_flush_event(t_xvar *xvar)
{
  XEvent	ev;

  while (XPending(xvar->display))
  {
     XNextEvent(xvar->display,&ev);
  }
}

/*
** mlx_int_get_visual.c for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Wed Oct  3 17:01:51 2001 Charlie Root
** Last update Thu Oct  4 15:00:45 2001 Charlie Root
*/



#include	"mlx_int.h"


/*
** We need a private colormap for non-default Visual.
*/


int		mlx_int_get_visual(t_xvar *xvar)
{
  XVisualInfo	*vi;
  XVisualInfo	template;
  int		nb_item;

  xvar->private_cmap = 0;
  xvar->visual = DefaultVisual(xvar->display,xvar->screen);
  if (xvar->visual->class == TrueColor)
    return (0);
  template.class = TrueColor;
  template.depth = xvar->depth;
  if (!(vi = XGetVisualInfo(xvar->display,VisualDepthMask|VisualClassMask,
			    &template,&nb_item)) )
    return (-1);
  xvar->visual = vi->visual;
  xvar->private_cmap = 1;
  return (0);
}

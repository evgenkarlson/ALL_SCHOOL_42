/*
** mlx_put_image_to_window.c for MiniLibX in raytraceur
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Aug 14 15:55:49 2000 Charlie Root
** Last update Sun Oct  2 09:53:00 2005 Olivier Crouzet
*/



#include	"mlx_int.h"


int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img,
				int x,int y)
{
  GC	gc;

  gc = win->gc;
  if (img->gc)
    {
      gc = img->gc;
      XSetClipOrigin(xvar->display, gc, x, y);
    }
  if (img->type==MLX_TYPE_SHM)
    XShmPutImage(xvar->display,img->pix, win->gc, img->image,0,0,0,0,
		 img->width,img->height,False);
  if (img->type==MLX_TYPE_XIMAGE)
    XPutImage(xvar->display,img->pix, win->gc, img->image,0,0,0,0,
	      img->width,img->height);
  XCopyArea(xvar->display,img->pix,win->window, gc,
	    0,0,img->width,img->height,x,y);
  if (xvar->do_flush)
    XFlush(xvar->display);
}

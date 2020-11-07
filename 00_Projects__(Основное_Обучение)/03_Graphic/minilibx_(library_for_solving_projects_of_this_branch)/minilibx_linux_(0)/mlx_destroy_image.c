/*
** mlx_destroy_image.c for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Tue Mar 12 10:25:15 2002 Charlie Root
** Last update Tue May 15 16:45:54 2007 Olivier Crouzet
*/


#include	"mlx_int.h"


int	mlx_destroy_image(t_xvar *xvar, t_img *img)
{
  if (img->type == MLX_TYPE_SHM_PIXMAP ||
      img->type == MLX_TYPE_SHM)
    {
      XShmDetach(xvar->display, &(img->shm));
      shmdt(img->shm.shmaddr);
      /* shmctl IPC_RMID already done */
    }
  XDestroyImage(img->image);  /* For image & shm-image. Also free img->data */
  XFreePixmap(xvar->display, img->pix);
  if (img->gc)
    XFreeGC(xvar->display, img->gc);
  free(img);
  if (xvar->do_flush)
    XFlush(xvar->display);
}

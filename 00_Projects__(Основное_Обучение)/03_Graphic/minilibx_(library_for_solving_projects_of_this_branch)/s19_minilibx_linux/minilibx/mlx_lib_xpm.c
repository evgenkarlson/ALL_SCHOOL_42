/*
** mlx_xpm.c for minilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Fri Dec  8 11:07:24 2000 Charlie Root
** Last update Thu Oct  4 16:00:22 2001 Charlie Root
*/


#include	"mlx_int.h"




void		*mlx_int_xpm_f_image(t_xvar *xvar,int *width,int *height,
				     int (*xpm_func)(),void *param)
{
  XImage	*img1;
  XImage	*img2;
  t_img		*im2;
  XpmAttributes	xpm_att;

  xpm_att.visual = xvar->visual;
  xpm_att.colormap = xvar->cmap;
  xpm_att.depth = xvar->depth;
  xpm_att.bitmap_format = ZPixmap;
  xpm_att.valuemask = XpmDepth|XpmBitmapFormat|XpmVisual|XpmColormap;
  if (xpm_func(xvar->display,param,&img1,&img2,&xpm_att))
    return ((void *)0);
  if (img2)
    XDestroyImage(img2);

  if (!(im2 = (void *)mlx_new_image(xvar,img1->width,img1->height)))
    {
      XDestroyImage(img1);
      return ((void *)0);
    }
  *width = img1->width;
  *height = img1->height;
  if (mlx_int_egal_img(im2->image,img1))
    {
      bcopy(img1->data,im2->data,img1->height*img1->bytes_per_line);
      XDestroyImage(img1);
      return (im2);
    }
  if (im2->type==MLX_TYPE_SHM_PIXMAP)
    {
      XFreePixmap(xvar->display,im2->pix);
      im2->pix = XCreatePixmap(xvar->display,xvar->root,
			       *width,*height,xvar->depth);
    }
  if (im2->type>MLX_TYPE_XIMAGE)
    {
      XShmDetach(xvar->display,&(im2->shm));
      shmdt(im2->data);
    }
  XDestroyImage(im2->image);
  im2->image = img1;
  im2->data = img1->data;
  im2->type = MLX_TYPE_XIMAGE;
  im2->size_line = img1->bytes_per_line;
  im2->bpp = img1->bits_per_pixel;
  return (im2);
}


int	mlx_int_egal_img(XImage *img1,XImage *img2)
{
  if (img1->width!=img2->width || img1->height!=img2->height ||
      img1->xoffset!=img2->xoffset || img1->format!=img2->format ||
      img1->byte_order!=img2->byte_order ||
      img1->bitmap_unit!=img2->bitmap_unit ||
      img1->bitmap_bit_order!=img2->bitmap_bit_order ||
      img1->bitmap_pad!=img2->bitmap_pad || img1->depth!=img2->depth ||
      img1->bytes_per_line!=img2->bytes_per_line ||
      img1->bits_per_pixel!=img2->bits_per_pixel ||
      img1->red_mask!=img2->red_mask || img1->green_mask!=img2->green_mask ||
      img1->blue_mask!=img2->blue_mask )
    return (0);
  return (1);
}


void	*mlx_xpm_file_to_image(t_xvar *xvar,char *filename,
			       int *width,int *height)
{
  return (mlx_int_xpm_f_image(xvar,width,height,XpmReadFileToImage,filename));
}


void	*mlx_xpm_to_image(t_xvar *xvar,char **data,int *width,int *height)
{
  return (mlx_int_xpm_f_image(xvar,width,height,XpmCreateImageFromData,(void *)data));
}

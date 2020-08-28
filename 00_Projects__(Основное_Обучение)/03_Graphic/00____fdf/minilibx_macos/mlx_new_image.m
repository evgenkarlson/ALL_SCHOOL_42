// mlx_new_image
//
// by Ol
//


#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>

#include "mlx_int.h"
#include "mlx_new_window.h"



void    *mlx_new_image(mlx_ptr_t *mlx_ptr, int width, int height)
{
  mlx_img_list_t        *newimg;

  //  if (mlx_ptr->win_list == NULL)
  //    return (NULL);  // need at leat one window created to have openGL context and create texture
  if ((newimg = malloc(sizeof(*newimg))) == NULL)
    return ((void *)0);
  newimg->next = mlx_ptr->img_list;
  mlx_ptr->img_list = newimg;
  newimg->width = width;
  newimg->height = height;
  newimg->vertexes[0] = 0.0;  newimg->vertexes[1] = 0.0;
  newimg->vertexes[2] = width;  newimg->vertexes[3] = 0.0;
  newimg->vertexes[4] = width;  newimg->vertexes[5] = -height;
  newimg->vertexes[6] = 0.0;  newimg->vertexes[7] = -height;
  newimg->buffer = malloc(UNIQ_BPP*width*height);
  bzero(newimg->buffer, UNIQ_BPP*width*height);

  return (newimg);
}

mlx_img_ctx_t	*add_img_to_ctx(mlx_img_list_t *img, mlx_win_list_t *win)
{
  mlx_img_ctx_t	*imgctx;

  imgctx = win->img_list;
  while (imgctx)
    {
      if (imgctx->img == img)
	return (imgctx);
      imgctx = imgctx->next;
    }

  imgctx = malloc(sizeof(*imgctx));
  imgctx->img = img;
  imgctx->next = win->img_list;
  win->img_list = imgctx;

  glGenTextures(1, &(imgctx->texture));
  glBindTexture(GL_TEXTURE_2D, imgctx->texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);
  glTexImage2D(
	       GL_TEXTURE_2D, 0,           /* target, level of detail */
	       GL_RGBA8,                    /* internal format */
	       img->width, img->height, 0,           /* width, height, border */
	       GL_BGRA, GL_UNSIGNED_BYTE,   /* external format, type */
	       img->buffer               /* pixels */
	       );

  glGenBuffers(1, &(imgctx->vbuffer));
  glBindBuffer(GL_ARRAY_BUFFER, imgctx->vbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(img->vertexes), img->vertexes, GL_DYNAMIC_DRAW); // 4 points buff

  return (imgctx);
}


void    mlx_put_image_to_window(mlx_ptr_t *mlx_ptr, mlx_win_list_t *win_ptr, mlx_img_list_t *img_ptr, int x, int y)
{
  mlx_img_ctx_t	*imgctx;

  if (!win_ptr->pixmgt)
    return ;

  [(id)(win_ptr->winid) selectGLContext];
  imgctx = add_img_to_ctx(img_ptr, win_ptr);

  // update texture
  glBindTexture(GL_TEXTURE_2D, imgctx->texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, img_ptr->width, img_ptr->height, 0,
	       GL_BGRA, GL_UNSIGNED_BYTE, img_ptr->buffer);

  [(id)(win_ptr->winid) mlx_gl_draw_img:img_ptr andCtx:imgctx andX:x andY:y];

  win_ptr->nb_flush ++;
}

// assume here 32bpp little endian

char    *mlx_get_data_addr(mlx_img_list_t *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
{
  *bits_per_pixel = UNIQ_BPP*8;
  *size_line = img_ptr->width*UNIQ_BPP;
  *endian = 0; // little endian for now on mac-intel
  return (img_ptr->buffer);
}

unsigned int    mlx_get_color_value(mlx_ptr_t *mlx_ptr, int color)
{
  return (color);
}

int mlx_string_put(mlx_ptr_t *mlx_ptr, mlx_win_list_t *win_ptr, int x, int y, int color, unsigned char *string)
{
  mlx_img_ctx_t	*imgctx;
  int		gX;
  int		gY;

  if (!win_ptr->pixmgt)
    return(0);

  [(id)(win_ptr->winid) selectGLContext];

  imgctx = add_img_to_ctx(mlx_ptr->font, win_ptr);

  while (*string)
    {
      if (*string >= 32 && *string <= 127)
	{
	  gX = (FONT_WIDTH+2)*(*string-32);
	  gY = 0;
	  //      printf("put char %c pos %d %d\n", *string, gX, gY);
	  [(id)(win_ptr->winid) mlx_gl_draw_font:mlx_ptr->font andCtx:imgctx andX:x andY:y andColor:color glyphX:gX glyphY:gY];
	  x += FONT_WIDTH;
	}
      string ++;
    }

  win_ptr->nb_flush ++;
  
  return (0);
}

int     mlx_destroy_image(mlx_ptr_t *mlx_ptr, mlx_img_list_t *img_todel)
{
  mlx_img_ctx_t	ctx_first;
  mlx_img_ctx_t	*ctx;
  mlx_img_ctx_t	*ctx_to_del;
  mlx_img_list_t img_first;
  mlx_img_list_t *img;
  mlx_win_list_t *win;

  img_first.next = mlx_ptr->img_list;
  img = &img_first;
  while (img && img->next)
    {
      if (img->next == img_todel)
	img->next = img->next->next;
      img = img->next;
    }
  mlx_ptr->img_list = img_first.next;


  win = mlx_ptr->win_list;
  while (win)
    {
      ctx_first.next = win->img_list;
      ctx = &ctx_first;
      while (ctx && ctx->next)
	{
	  if (ctx->next->img == img_todel)
	    {
	      [(id)(win->winid) selectGLContext];
	      glDeleteBuffers(1, &(ctx->next->vbuffer));
	      glDeleteTextures(1, &(ctx->next->texture));
	      ctx_to_del = ctx->next;
	      ctx->next = ctx->next->next;
	      free(ctx_to_del);
	    }
	  ctx = ctx->next;
	}
      win->img_list = ctx_first.next;
      win = win->next;
    }


  free(img_todel->buffer);
  free(img_todel);

  //  printf("destroy image done.\n");
  return (0);
}

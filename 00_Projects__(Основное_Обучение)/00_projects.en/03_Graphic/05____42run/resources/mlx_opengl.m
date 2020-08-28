// mlx_opengl.m

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <AppKit/NSOpenGLView.h>

#include <stdio.h>

#include "mlx_int.h"
#include "mlx_new_window.h"





NSOpenGLPixelFormatAttribute pfa_attrs_opengl[] =
  {
    NSOpenGLPFADepthSize, 32,
    NSOpenGLPFADoubleBuffer,
    NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core,
    0
  };



void	*mlx_new_opengl_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)
{
  mlx_win_list_t	*newwin;
  NSString		*str;

  if ((newwin = malloc(sizeof(*newwin))) == NULL)
    return ((void *)0);
  newwin->img_list = NULL;
  newwin->next = mlx_ptr->win_list;
  newwin->nb_flush = 0;
  newwin->pixmgt = 0;
  mlx_ptr->win_list = newwin;

  NSRect windowRect = NSMakeRect(100, 100, size_x, size_y);
  str = [NSString stringWithCString:title encoding:NSASCIIStringEncoding];
  newwin->winid = [[MlxWin alloc] initWithRect:windowRect andTitle:str pfaAttrs:pfa_attrs_opengl];

  return ((void *)newwin);
}


int	mlx_opengl_swap_buffers(mlx_win_list_t *win_ptr)
{
  [(id)(win_ptr->winid) flushGLContext];
  return (0);
}

int	mlx_opengl_window_set_context(mlx_win_list_t *win_ptr)
{
  [(id)(win_ptr->winid) selectGLContext];
  return (0);
}

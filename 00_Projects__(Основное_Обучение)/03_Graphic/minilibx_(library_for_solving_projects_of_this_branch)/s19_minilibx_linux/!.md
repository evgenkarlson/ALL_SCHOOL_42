# MINILIBX LINUX INSTALL
 - clone minilibx https://github.com/gcamerli/minilibx
 - cd minilibx
 - make
 - cp libmlx.a /usr/local/lib
 - cp include/mlx.h /usr/local/include
 - cp man/man3/mlx*.1 /usr/local/man/man3

# MINILIBX DOC
initialisation:
 - mlx_init()
 > connects to x-window
 
 > return NULL or non-null pointer as mlx identifier

window management:
 - void *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );
 >return NULL or non-null pointer as window identifier
 - int mlx_clear_window( void *mlx_ptr, void *win_ptr );
 - int mlx_destroy_window( void *mlx_ptr, void *win_ptr )

pixel output:
 - int mlx_pixel_put( void *mlx_ptr, void *win_ptr, int x, int y, int color );
 - int mlx_string_put( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
 - color int = 0 + r + g + b

image manipulation:
 - void *mlx_new_image ( void *mlx_ptr, int width, int height );
 - int mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
 - char *mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
  >  bits_per_pixel : bits for one pixel
  >  size_line      : bits for one line
  >  endian         : 0 for small 1 for big
 -int mlx_destroy_image ( void *mlx_ptr, void *img_ptr );

image manipulation v2:
 - unsigned int mlx_get_color_value ( void *mlx_ptr, int color );
 - void *mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );
 - void *mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );

events:
 > mlx_loop is basically update() in other engines
 - int mlx_loop ( void *mlx_ptr );
 - int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
 - int mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
 - int mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
 - int mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );

compile :
 > gcc FILE -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

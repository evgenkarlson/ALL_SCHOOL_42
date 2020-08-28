/*
** mlx.h for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@staff.42.fr>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Tue Oct 01 16:23:28 2014 Olivier Crouzet
*/

/*
**   MinilibX -  Please report bugs
*/


/*
** FR msg - FR msg - FR msg
**
** MacOSX
** La MinilibX utilise 2 frameworks Mac : OpenGL et AppKit
**    qu'il faut ajouter a la compilation :
**   -framework OpenGL -framework AppKit
**
** UNIX / Linux
** La MinilibX utilise 2 librairies supplementaires qu'il
**      est necessaire de rajouter a la compilation :
**   -lmlx -lXext -lX11
**
** La MinilibX permet le chargement des images de type Xpm.
** Notez que cette implementation est incomplete.
**
** Il y a des differences entre X11 et MacOS.
** les numeros des touches ne sont pas les memes,
** les numeros des boutons souris ne sont pas les memes.
** Egalement l'expose est gere differemment, et sous MacOS
** il est preferable d'entrer le plus tot possible dans mlx_loop,
** il est normal que les fenetres n'apparaissent pas avant mlx_loop
** (ou bien forcez avec mlx_do_sync mais c'est pas genial).
** Sous MacOS, l'octet Alpha est pris en compte dans toutes les
** images, et represente la transparence et non l'opacite comme
** c'est normalement le cas.
*/


#ifndef MLX_H

#define	MLX_H


void	*mlx_init();
/*
**  needed before everything else.
**  return (void *)0 if failed
*/


/*
** Basic actions
*/

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
/*
**  return void *0 if failed
*/
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
*/


/*
** Image stuff
*/

void	*mlx_new_image(void *mlx_ptr,int width,int height);
/*
**  return void *0 if failed
*/
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
/*
**  endian : 0 = sever X is little endian, 1 = big endian
**  endian : useless on macos, client and graphical framework have the same endian
*/
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);


/*
** dealing with Events
*/

int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop (void *mlx_ptr);


/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/


/*
**  Usually asked...
*/

int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
		       char *string);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height);
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int	mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param);

int	mlx_do_key_autorepeatoff(void *mlx_ptr);
int	mlx_do_key_autorepeaton(void *mlx_ptr);
int	mlx_do_sync(void *mlx_ptr);

#endif /* MLX_H */

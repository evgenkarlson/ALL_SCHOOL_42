/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:15:30 by wescande          #+#    #+#             */
/*   Updated: 2016/12/26 20:21:57 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mise a la nrome par wescande
** mlx_init.c for MiniLibX in
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Mon Jul 31 16:52:42 2000 Charlie Root
** Last update Fri Jan 28 17:05:09 2005 Olivier Crouzet
*/

#include "mlx_int.h"

void		*mlx_init(void)
{
	t_xvar	*xvar;

	if (!(xvar = malloc(sizeof(*xvar)))
		|| (xvar->display = XOpenDisplay("")) == 0)
		return ((void *)0);
	xvar->screen = DefaultScreen(xvar->display);
	xvar->root = DefaultRootWindow(xvar->display);
	xvar->cmap = DefaultColormap(xvar->display, xvar->screen);
	xvar->depth = DefaultDepth(xvar->display, xvar->screen);
	if (mlx_int_get_visual(xvar) == -1)
	{
		printf(ERR_NO_TRUECOLOR);
		exit(1);
	}
	xvar->win_list = 0;
	xvar->loop_hook = 0;
	xvar->loop_param = (void *)0;
	xvar->do_flush = 1;
	mlx_int_deal_shm(xvar);
	if (xvar->private_cmap)
		xvar->cmap = XCreateColormap(xvar->display, xvar->root,
				xvar->visual, AllocNone);
	mlx_int_rgb_conversion(xvar);
	return (xvar);
}

/*
** pshm_format of -1 :  Not XYBitmap|XYPixmap|ZPixmap
** alpha libX need a check of the DISPLAY env var, or shm is allowed
** in remote Xserver connections.
*/

int			mlx_int_deal_shm(t_xvar *xvar)
{
	int		use_pshm;
	int		bidon;
	char	*dpy;
	char	buff[33];

	xvar->use_xshm = XShmQueryVersion(xvar->display,
										&bidon, &bidon, &(use_pshm));
	if (xvar->use_xshm && use_pshm)
		xvar->pshm_format = XShmPixmapFormat(xvar->display);
	else
		xvar->pshm_format = -1;
	gethostname(buff, 32);
	dpy = getenv(ENV_DISPLAY);
	if (dpy && strlen(dpy) && *dpy != ':' && strncmp(dpy, buff, strlen(buff)) &&
		strncmp(dpy, LOCALHOST, strlen(LOCALHOST)))
	{
		xvar->pshm_format = -1;
		xvar->use_xshm = 0;
	}
}

/*
** TrueColor Visual is needed to have *_mask correctly set
*/

int			mlx_int_rgb_conversion(t_xvar *xvar)
{
	bzero(xvar->decrgb, sizeof(int) * 6);
	while (!(xvar->visual->red_mask & 1) && ++xvar->decrgb[0])
		xvar->visual->red_mask >>= 1;
	while (xvar->visual->red_mask & 1 && ++xvar->decrgb[1])
		xvar->visual->red_mask >>= 1;
	while (!(xvar->visual->green_mask & 1) && ++xvar->decrgb[2])
		xvar->visual->green_mask >>= 1;
	while (xvar->visual->green_mask & 1 && ++xvar->decrgb[3])
		xvar->visual->green_mask >>= 1;
	while (!(xvar->visual->blue_mask & 1) && ++xvar->decrgb[4])
		xvar->visual->blue_mask >>= 1;
	while (xvar->visual->blue_mask & 1 && ++xvar->decrgb[5])
		xvar->visual->blue_mask >>= 1;
}

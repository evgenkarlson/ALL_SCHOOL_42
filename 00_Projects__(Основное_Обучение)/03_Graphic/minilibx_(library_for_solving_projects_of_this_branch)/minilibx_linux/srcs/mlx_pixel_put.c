/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:39:56 by wescande          #+#    #+#             */
/*   Updated: 2016/12/26 20:40:23 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mise a la norme par wescande
** mlx_pixel_put.c for MiniLibX in
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Mon Jul 31 19:01:33 2000 Charlie Root
** Last update Tue Sep 25 17:09:49 2001 Charlie Root
*/

#include "mlx_int.h"

int		mlx_pixel_put(t_xvar *xvar, t_win_list *win,
		int x, int y, int color)
{
	XGCValues	xgcv;

	xgcv.foreground = mlx_int_get_good_color(xvar,color);
	XChangeGC(xvar->display, win->gc, GCForeground, &xgcv);
	XDrawPoint(xvar->display, win->window, win->gc, x, y);
	if (xvar->do_flush)
		XFlush(xvar->display);
}
